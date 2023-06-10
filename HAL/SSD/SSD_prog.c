#include "STD_TYPES.h"

#include "BIT_MATH.h"
#include "Err_Type.h"
#include "DIO_interface.h"
#include "SSD_interface.h"



uint8 SSD_u8SetNumber(const SSD_confg_t* copy_pSSD_Obj , uint8 copy_u8number)
{
	uint8 Local_u8LoopIterrator , Local_u8ErrTypes=OK;

	if (copy_pSSD_Obj!=NULL)
	{
		if ((copy_pSSD_Obj->SSD_Type ==SSD_CommonCathode)||(copy_pSSD_Obj->SSD_Type ==SSD_EtaKite))
		{

			if (copy_u8number<=9)
			{
				static uint8 Local_SSDArray[]={0b00111111,0b00000110,0b01011011,0b01001111,
						0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
				switch(copy_pSSD_Obj->SSD_PortName)
				{
				case DIO_PORTA : if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0u;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTA,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTA,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTB :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTB,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTB,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTC :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTC,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTC,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTD :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTD,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTD,Local_u8LoopIterrator,GET_BIT(Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;

				default:Local_u8ErrTypes=NOK;
				}
			}

		}
		else if (copy_pSSD_Obj-> SSD_Type==SSD_CommonAnode)
		{


			if (copy_u8number<=9)
			{
				static uint8 Local_SSDArray[]={0b00111111,0b00000110,0b01011011,0b01001111,
						0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
				switch(copy_pSSD_Obj->SSD_PortName)
				{
				case DIO_PORTA : if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTA,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTA,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTB :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTB,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTB,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTC :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTC,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTC,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;
				case DIO_PORTD :if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin0)
				{
					for (Local_u8LoopIterrator=0;Local_u8LoopIterrator<=6u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTD,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator));
					}
				}
				else if (copy_pSSD_Obj->SSD_LEDAPin==SSD_LEDAPin1)
				{
					for (Local_u8LoopIterrator=1;Local_u8LoopIterrator<=7u;Local_u8LoopIterrator++)
					{
						DIO_u8SetPinValue(DIO_PORTD,Local_u8LoopIterrator,GET_BIT(~Local_SSDArray[copy_u8number],Local_u8LoopIterrator-1));
					}
				}break;

				default:Local_u8ErrTypes=NOK;
				}
			}



		}

	}
	else
	{
		return NULL_PTR;
	}

	return Local_u8ErrTypes;

}
uint8 SSD_u8Enable   (const SSD_confg_t* copy_pSSD_Obj)
{
	uint8 Local_u8ErrTypes=OK;
	if (copy_pSSD_Obj!=NULL)
	{
		if (copy_pSSD_Obj->SSD_Type==SSD_CommonCathode)
		{
			if (copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN0||copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN7)
			{
				switch(copy_pSSD_Obj->SSD_EnablePort)
				{
				case DIO_PORTA : DIO_u8SetPinValue(DIO_PORTA,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
				case DIO_PORTB : DIO_u8SetPinValue(DIO_PORTB,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
				case DIO_PORTC : DIO_u8SetPinValue(DIO_PORTC,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
				case DIO_PORTD : DIO_u8SetPinValue(DIO_PORTD,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
				default	:Local_u8ErrTypes=NOK;
				}
			}
			else
			{
				Local_u8ErrTypes=NOK;
			}
		}
		else if ((copy_pSSD_Obj->SSD_Type==SSD_CommonAnode)||(copy_pSSD_Obj->SSD_Type==SSD_EtaKite))
		{
			if (copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN0||copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN7)
			{
				switch(copy_pSSD_Obj->SSD_EnablePort)
				{
				case DIO_PORTA : DIO_u8SetPinValue(DIO_PORTA,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
				case DIO_PORTB : DIO_u8SetPinValue(DIO_PORTB,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
				case DIO_PORTC : DIO_u8SetPinValue(DIO_PORTC,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
				case DIO_PORTD : DIO_u8SetPinValue(DIO_PORTD,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
				default	:Local_u8ErrTypes=NOK;
				}
			}
			else
			{
				Local_u8ErrTypes=NOK;
			}
		}


	}
	else
	{
		Local_u8ErrTypes= NULL_PTR;

	}
	return Local_u8ErrTypes;

}
uint8 SSD_u8Disable  (const SSD_confg_t* copy_pSSD_Obj)
{
	uint8 Local_u8ErrTypes=OK;
		if (copy_pSSD_Obj!=NULL)
		{
			if (copy_pSSD_Obj->SSD_Type==SSD_CommonCathode)
			{
				if (copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN0||copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN7)
				{
					switch(copy_pSSD_Obj->SSD_EnablePort)
					{
					case DIO_PORTA : DIO_u8SetPinValue(DIO_PORTA,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
					case DIO_PORTB : DIO_u8SetPinValue(DIO_PORTB,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
					case DIO_PORTC : DIO_u8SetPinValue(DIO_PORTC,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
					case DIO_PORTD : DIO_u8SetPinValue(DIO_PORTD,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_HIGH);break;
					default	:Local_u8ErrTypes=NOK;
					}
				}
				else
				{
					Local_u8ErrTypes=NOK;
				}
			}
			else if ((copy_pSSD_Obj->SSD_Type==SSD_CommonAnode)||(copy_pSSD_Obj->SSD_Type==SSD_EtaKite))
			{
				if (copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN0||copy_pSSD_Obj->SSD_EnablePin>=DIO_PIN7)
				{
					switch(copy_pSSD_Obj->SSD_EnablePort)
					{
					case DIO_PORTA : DIO_u8SetPinValue(DIO_PORTA,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
					case DIO_PORTB : DIO_u8SetPinValue(DIO_PORTB,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
					case DIO_PORTC : DIO_u8SetPinValue(DIO_PORTC,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
					case DIO_PORTD : DIO_u8SetPinValue(DIO_PORTD,copy_pSSD_Obj->SSD_EnablePin,DIO_PIN_LOW);break;
					default	:Local_u8ErrTypes=NOK;
					}
				}
				else
				{
					Local_u8ErrTypes=NOK;
				}
			}


		}
		else
		{
			Local_u8ErrTypes= NULL_PTR;
		}
		return Local_u8ErrTypes;


}
