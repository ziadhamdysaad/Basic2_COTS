#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"


#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cnfg.h"
#include "ADC_reg.h"

static uint16* ADC_pu16DigResult=NULL;
static void (*ADC_pvNotificationFunc)(void)=NULL;
static uint8 ADC_u8BusyFlage=IDLE;
static uint8 ADC_u8AsyncType;
static ADC_ChainConvertionStruct_t* ADC_pChainStructPointer=NULL;
static uint8 ADC_u8ArrayIndex=0u;
void ADC_voidInit (void)
{

	/*Reference Selection:AVCC Pin*/

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*Activate left adjust for 8-bit resolution*/

#if ADC_RESOLUTION == EIGHT_BITS

	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_RESOLUTION == TEN_BITS

	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error Worng ADC_RESOLUTION configuration value
#endif

	/*check on pre scalar configuration setting */
	ADCSRA &=PRESCALER_MASK;

	ADCSRA |=ADC_u8PRESCALER;

	/*ADC Enable*/

	SET_BIT(ADCSRA,ADCSRA_ADEN);




}
uint8 ADC_u16StartConvesionSynch(ADC_Chanel_t copy_channel, uint16* copy_pu16DigResult)
{
	uint8 Local_ErrorState = OK;
	if (copy_pu16DigResult != NULL)
	{
		if (ADC_u8BusyFlage == IDLE)
		{
			uint32 Local_u32Counter=0u;
			/*ADC is busy now */
			ADC_u8BusyFlage=BUSY;

			/*SET THE REQUIERED  CHANNEL*/
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= copy_channel;

			/*START CONVIRSION*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*wait until conversion is completed or the time out has not finished*/
			while ((GET_BIT(ADCSRA,ADCSRA_ADIF)) && (Local_u32Counter<ADC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
			/*loop is broken because of time out has passed */
			if (Local_u32Counter==ADC_u32TIMEOUT_COUNT)
			{
				Local_ErrorState=TIMEOUT_ERR;
			}
			/*loop is broken due to flag is raised  */
			else
			{
				/*clear conversion control flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);
#if ADC_RESOLUTION == EIGHT_BITS
				*copy_pu16DigResult = (uint16) ADCH;
#elif ADC_RESOLUTION == TEN_BITS
				*copy_pu16DigResult = (uint16) ADC ;
#endif
				/*Task is done ADC is now idle*/
				ADC_u8BusyFlage = IDLE;
			}


		}
		else
		{
			Local_ErrorState = BUSY_ERR;
		}
	}

	else
	{
		Local_ErrorState=NULL_PTR;

	}

	return Local_ErrorState;


}
uint8 ADC_u16StartConvesionSingleASynch(ADC_Chanel_t copy_channel, uint16* copy_pu16DigResult, void (*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
	ADC_u8AsyncType = SINGLE ;

	if ((copy_pu16DigResult!=NULL) && (copy_pvNotificationFunc!=NULL))
	{
		if (ADC_u8BusyFlage == IDLE)
		{
			/*ADC is Busy Now */
			ADC_u8BusyFlage = BUSY;
			/*convert the digital result and the notification function local variables into global*/
			ADC_pu16DigResult=copy_pu16DigResult;
			ADC_pvNotificationFunc=copy_pvNotificationFunc;

			/*SET THE REQUIERED  CHANNEL*/
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= copy_channel;

			/*START CONVIRSION*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);


		}
		else
		{
			Local_u8ErrorState=BUSY_ERR;
		}

	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}



uint8 ADC_u8StartChainConversionAsynch(ADC_ChainConvertionStruct_t* copy_pChainConverstionObj)
{
	uint8 Local_u8ErrorState=OK;

	/*checking on pointer validation*/
	if ((copy_pChainConverstionObj != NULL ) && (copy_pChainConverstionObj->convertionChanelArray != NULL) && (copy_pChainConverstionObj->Notification_function!=NULL))
	{
		if (ADC_u8BusyFlage == IDLE)
		{
			ADC_u8BusyFlage = BUSY;
			/*will use this in ISR*/
			ADC_u8AsyncType = CHAIN;
			/*converting this pointer into global */
			ADC_pChainStructPointer = copy_pChainConverstionObj;
			uint8 ADC_u8ArrayIndex=0u;
			/*SET THE REQUIERED  CHANNEL*/
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= copy_pChainConverstionObj->convertionChanelArray[ADC_u8ArrayIndex];
			/*START CONVIRSION*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			Local_u8ErrorState = BUSY_ERR;
		}

	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}

/*ADC conversion complete ISR*/

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if (ADC_u8AsyncType == CHAIN)
	{
#if ADC_RESOLUTION == EIGHT_BITS
		ADC_pChainStructPointer-> ArrayOfResults[ADC_u8ArrayIndex] = (uint16) ADCH ;
#elif ADC_RESOLUTION == TEN_BITS
		ADC_pChainStructPointer-> ArrayOfResults[ADC_u8ArrayIndex] = ADC ;
#endif

		ADC_u8ArrayIndex++;
		if (ADC_u8ArrayIndex == ADC_pChainStructPointer->ConverstionNumber)
		{
			ADC_u8ArrayIndex = 0;

			/*ADC interrupt disable */
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
			/*Task is finished and ADC is now idle */
			ADC_u8BusyFlage = IDLE;
			//invoke the call back notification function
			if (ADC_pChainStructPointer->Notification_function != NULL)
			{
				ADC_pChainStructPointer->Notification_function();
			}
			else
			{
				//do nothing
			}
		}
		else
		{
			/*SET THE REQUIERED  CHANNEL*/
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= ADC_pChainStructPointer->convertionChanelArray[ADC_u8ArrayIndex];
			/*START CONVIRSION*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*Enable ADC conversion complete interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}


	}
	else if(ADC_u8AsyncType == SINGLE)
	{
#if ADC_RESOLUTION == EIGHT_BITS
		*ADC_pu16DigResult = (uint16) ADCH;
#elif ADC_RESOLUTION == TEN_BITS
		*ADC_pu16DigResult= ADC ;
#endif


		/*ADC interrupt disable */
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
		/*Task is finished and ADC is now idle */
		ADC_u8BusyFlage = IDLE;
		//invoke the call back notification function
		if (ADC_pvNotificationFunc != NULL)
		{
			ADC_pvNotificationFunc();
		}
		else
		{
			//do nothing
		}


	}

}


