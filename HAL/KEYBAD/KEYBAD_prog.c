#include "STD_TYPES.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "KEYBAD_interface.h"
#include "KEYBAD_cfg.h"
#include "KEYBAD_prv.h"
uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8RowCounter, Local_u8ColCounter, Local_u8KeyState,Local_u8PressedKey= KPD_u8NO_PRESSED_KEY_VAL;

	static uint8 Local_u8ColArr[COLUMN_SIZE]= {KPD_u8C0,KPD_u8C1,KPD_u8C2,KPD_u8C3};
	static uint8 Local_u8RowArr[ROW_SIZE]= {KPD_u8R0,KPD_u8R1,KPD_u8R2,KPD_u8R3};
	static uint8 Local_u8KPDArr[ROW_SIZE][COLUMN_SIZE] = KPD_BUTTON_ARR;

	/*Activate the column pins*/
	for(Local_u8ColCounter =0u ; Local_u8ColCounter < COLUMN_SIZE ; Local_u8ColCounter++)
	{
		/*Activate he current column*/
		DIO_u8SetPinValue(KPD_u8COLUMN_PORT,Local_u8ColArr[Local_u8ColCounter],DIO_PIN_LOW);

		/*Read the row pins*/
		for(Local_u8RowCounter =0u; Local_u8RowCounter< ROW_SIZE; Local_u8RowCounter++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_u8ROW_PORT,Local_u8RowArr[Local_u8RowCounter],&Local_u8KeyState);

			if(Local_u8KeyState == DIO_PIN_LOW)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];

				/*wait until key is released (polling with blocking on pin reading)*/
				while(Local_u8KeyState == DIO_PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_u8ROW_PORT,Local_u8RowArr[Local_u8RowCounter],&Local_u8KeyState);
				}

				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_u8COLUMN_PORT,Local_u8ColArr[Local_u8ColCounter],DIO_PIN_HIGH);
	}
	return Local_u8PressedKey;
}
