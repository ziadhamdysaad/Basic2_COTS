#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "stepper_cfg.h"
#include "stepper_interface.h"
#include <util/delay.h>




void STEPPER_voidRotatCW(uint16 copy_u16Angle )
{

	uint16 Local_u16RequieredNumberOfSteps ,Local_u16Iterator;

	Local_u16RequieredNumberOfSteps=(uint16)((uint32)copy_u16Angle * (uint32)STEPPER_FULL_STEPS / 360UL);

	for (Local_u16Iterator=0;Local_u16Iterator<Local_u16RequieredNumberOfSteps;Local_u16Iterator++)
	{
		if (Local_u16Iterator%4==0)
		{

			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_LOW);
			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==1)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_LOW);
			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==2)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_LOW);
			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==3)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_LOW);
			_delay_ms(2);

		}
	}


}
void STEPPER_voidRotatCCW(uint16 copy_u16Angle )
{

	uint16 Local_u16RequieredNumberOfSteps ,Local_u16Iterator;

	Local_u16RequieredNumberOfSteps=(uint16)((uint32)copy_u16Angle * (uint32)STEPPER_FULL_STEPS / 360UL);

	for (Local_u16Iterator=0;Local_u16Iterator<Local_u16RequieredNumberOfSteps;Local_u16Iterator++)
	{
		if (Local_u16Iterator%4==0)
		{

			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_LOW);

			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==1)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_LOW);

			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==2)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_LOW);

			_delay_ms(2);


		}
		else if (Local_u16Iterator%4==3)
		{
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_WIRE,DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_WIRE,DIO_PIN_LOW);
			_delay_ms(2);

		}
	}
}

