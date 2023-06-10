#include  "STD_TYPES.h"
#include "DCMOTOR_interface.h"
#include "Err_Type.h"
#include "DIO_interface.h"

uint8 DCMotor_u8RotatCW(uint8 copy_u8PortNumber,uint8 copy_u8CWPin,uint8 copy_u8CCWPin )
{
	uint8 Local_ErrType=OK;

	if ((copy_u8CWPin>=DIO_PIN0)&&(copy_u8CWPin<=DIO_PIN7)&&(copy_u8CCWPin>=DIO_PIN0)&&(copy_u8CCWPin<=DIO_PIN7))
	{
		switch(copy_u8PortNumber)
		{
		case DIO_PORTA :DIO_u8SetPinValue(DIO_PORTA,copy_u8CCWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,copy_u8CWPin,DIO_PIN_HIGH);break;
		case DIO_PORTB :DIO_u8SetPinValue(DIO_PORTB,copy_u8CCWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTB,copy_u8CWPin,DIO_PIN_HIGH);break;
		case DIO_PORTC :DIO_u8SetPinValue(DIO_PORTC,copy_u8CCWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTC,copy_u8CWPin,DIO_PIN_HIGH);break;
		case DIO_PORTD :DIO_u8SetPinValue(DIO_PORTD,copy_u8CCWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTD,copy_u8CWPin,DIO_PIN_HIGH);break;
		default:Local_ErrType=NOK; break;

		}
	}
	else
	{
		Local_ErrType=NOK;
	}
	return Local_ErrType;
}
uint8 DCMOTOR_u8RotatCCW(DIO_Port_t copy_PortNum,DIO_Pin_t copy_u8CWPin,DIO_Pin_t copy_u8CCWPin)
{
	uint8 Local_ErrType=OK;

	if ((copy_u8CWPin>=DIO_PIN0)&&(copy_u8CWPin<=DIO_PIN7)&&(copy_u8CCWPin>=DIO_PIN0)&&(copy_u8CCWPin<=DIO_PIN7))
	{
		switch(copy_PortNum)
		{
		case DIO_PORTA :DIO_u8SetPinValue(DIO_PORTA,copy_u8CWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,copy_u8CCWPin,DIO_PIN_HIGH);break;
		case DIO_PORTB :DIO_u8SetPinValue(DIO_PORTB,copy_u8CWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTB,copy_u8CCWPin,DIO_PIN_HIGH);break;
		case DIO_PORTC :DIO_u8SetPinValue(DIO_PORTC,copy_u8CWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTC,copy_u8CCWPin,DIO_PIN_HIGH);break;
		case DIO_PORTD :DIO_u8SetPinValue(DIO_PORTD,copy_u8CWPin,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTD,copy_u8CCWPin,DIO_PIN_HIGH);break;
		default:Local_ErrType=NOK; break;

		}
	}
	else
	{
		Local_ErrType=NOK;
	}
	return Local_ErrType;
}
uint8 DCMOTOR_u8Stop(DIO_Port_t copy_PortNum,DIO_Pin_t copy_u8CWPin,DIO_Pin_t copy_u8CCWPin)
{
	uint8 Local_ErrType=OK;

		if ((copy_u8CWPin>=DIO_PIN0)&&(copy_u8CWPin<=DIO_PIN7)&&(copy_u8CCWPin>=DIO_PIN0)&&(copy_u8CCWPin<=DIO_PIN7))
		{
			switch(copy_PortNum)
			{
			case DIO_PORTA :DIO_u8SetPinValue(DIO_PORTA,copy_u8CWPin,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTA,copy_u8CCWPin,DIO_PIN_LOW);break;
			case DIO_PORTB :DIO_u8SetPinValue(DIO_PORTB,copy_u8CWPin,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTB,copy_u8CCWPin,DIO_PIN_LOW);break;
			case DIO_PORTC :DIO_u8SetPinValue(DIO_PORTC,copy_u8CWPin,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTC,copy_u8CCWPin,DIO_PIN_LOW);break;
			case DIO_PORTD :DIO_u8SetPinValue(DIO_PORTD,copy_u8CWPin,DIO_PIN_LOW);
			DIO_u8SetPinValue(DIO_PORTD,copy_u8CCWPin,DIO_PIN_LOW);break;
			default:Local_ErrType=NOK; break;

			}
		}
		else
		{
			Local_ErrType=NOK;
		}
		return Local_ErrType;
}




