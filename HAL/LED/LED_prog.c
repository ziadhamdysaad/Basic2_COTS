#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"





uint8 LED_u8SetOn(LED_configuration_t* copy_pLEDObject)
{
	uint8 Local_ErrorState=OK;
	/*checking the pointer validation */
	if (copy_pLEDObject!=NULL)
	{
		/*checking the pin number validation */
		if ((copy_pLEDObject->LED_Pin>=DIO_PIN0)&&(copy_pLEDObject->LED_Pin<=DIO_PIN7))
		{
			/*checking the activity type validation */
			if (copy_pLEDObject->LED_ActivityType==LED_Active_High)
			{
				/*checking the PORT validation */
				switch(copy_pLEDObject->LED_Port)
				{
				case DIO_PORTA:DIO_u8SetPinValue(DIO_PORTA,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTB:DIO_u8SetPinValue(DIO_PORTB,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTC:DIO_u8SetPinValue(DIO_PORTC,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTD:DIO_u8SetPinValue(DIO_PORTD,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				default:Local_ErrorState=NOK;break;
				}
			}
			else if(copy_pLEDObject->LED_ActivityType==LED_Active_Low)
			{
				switch(copy_pLEDObject->LED_Port)
				{
				case DIO_PORTA:DIO_u8SetPinValue(DIO_PORTA,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTB:DIO_u8SetPinValue(DIO_PORTB,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTC:DIO_u8SetPinValue(DIO_PORTC,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTD:DIO_u8SetPinValue(DIO_PORTD,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				default:Local_ErrorState=NOK;break;
				}
			}
			else
			{
				Local_ErrorState=NOK;
			}
		}
		else
		{
			Local_ErrorState=NOK;
		}

	}
	else
	{
		Local_ErrorState=NULL_PTR;
	}
	return Local_ErrorState;
}

uint8 LED_u8SetOff(LED_configuration_t* copy_pLEDObject)
{

	uint8 Local_ErrorState=OK;
	if (copy_pLEDObject!=NULL)
	{
		if ((copy_pLEDObject->LED_Pin>=DIO_PIN0)&&(copy_pLEDObject->LED_Pin<=DIO_PIN7))
		{
			if (copy_pLEDObject->LED_ActivityType==LED_Active_High)
			{
				switch(copy_pLEDObject->LED_Port)
				{
				case DIO_PORTA:DIO_u8SetPinValue(DIO_PORTA,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTB:DIO_u8SetPinValue(DIO_PORTB,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTC:DIO_u8SetPinValue(DIO_PORTC,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				case DIO_PORTD:DIO_u8SetPinValue(DIO_PORTD,copy_pLEDObject->LED_Pin,DIO_PIN_LOW);break;
				default:Local_ErrorState=NOK;break;
				}
			}
			else if(copy_pLEDObject->LED_ActivityType==LED_Active_Low)
			{
				switch(copy_pLEDObject->LED_Port)
				{
				case DIO_PORTA:DIO_u8SetPinValue(DIO_PORTA,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTB:DIO_u8SetPinValue(DIO_PORTB,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTC:DIO_u8SetPinValue(DIO_PORTC,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				case DIO_PORTD:DIO_u8SetPinValue(DIO_PORTD,copy_pLEDObject->LED_Pin,DIO_PIN_HIGH);break;
				default:Local_ErrorState=NOK;break;
				}
			}
			else
			{
				Local_ErrorState=NOK;
			}
		}
		else
		{
			Local_ErrorState=NOK;
		}

	}
	else
	{
		Local_ErrorState=NULL_PTR;
	}
	return Local_ErrorState;


}

uint8 LED_u8SetToggle(LED_configuration_t* copy_pLEDObject)
{

	uint8 Local_ErrorState=OK;
	if (copy_pLEDObject!=NULL)
	{
		if ((copy_pLEDObject->LED_Pin>=DIO_PIN0)&&(copy_pLEDObject->LED_Pin<=DIO_PIN7))
		{

				switch(copy_pLEDObject->LED_Port)
				{
				case DIO_PORTA:DIO_u8TogglePin(DIO_PORTA,copy_pLEDObject->LED_Pin);break;
				case DIO_PORTB:DIO_u8TogglePin(DIO_PORTB,copy_pLEDObject->LED_Pin);break;
				case DIO_PORTC:DIO_u8TogglePin(DIO_PORTC,copy_pLEDObject->LED_Pin);break;
				case DIO_PORTD:DIO_u8TogglePin(DIO_PORTD,copy_pLEDObject->LED_Pin);break;
				default:Local_ErrorState=NOK;break;
				}


		}
		else
		{
			Local_ErrorState=NOK;
		}

	}
	else
	{
		Local_ErrorState=NULL_PTR;
	}
	return Local_ErrorState;

}
