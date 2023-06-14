#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"
#include "Err_Type.h"


#include "DIO_interface.h"

#include "CLDC_interface.h"
#include "CLCD_cfg.h"
#include "CLCD_prv.h"

#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static void voideSetHalfDataPort(uint8 copy_u8FourBitData)
{
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_u8D4_PIN,GET_BIT(copy_u8FourBitData,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_u8D5_PIN,GET_BIT(copy_u8FourBitData,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_u8D6_PIN,GET_BIT(copy_u8FourBitData,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_u8D7_PIN,GET_BIT(copy_u8FourBitData,3));
}
#endif
static void voidSendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_PIN_LOW);
}

void CLCD_voidSendCommand(uint8 copy_u8Command)
{
	/*set Rs to low  pins for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_LOW);
	/*set Rw to loW for write */
#if CLCD_u8READ_OPERATION_ENEBLED == ENABLED
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_LOW);
#endif
	/*send the command*/
#if CLCD_u8CONNECTION_MODE == FOUR_BIT
/*sending most sig 4bits of command*/
	voideSetHalfDataPort(copy_u8Command>>4);
	/* send Enable Pulse*/
	voidSendEnablePulse();
/*sending the least sig 4bits*/
	voideSetHalfDataPort(copy_u8Command);
	/* send Enable Pulse*/
	voidSendEnablePulse();
#elif CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Command);
	/* send Enable Pulse*/
	voidSendEnablePulse();
#endif


}
void CLCD_voidSendData(uint8 copy_u8Data)
{
	/*set Rs to high  pins for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_PIN_HIGH);
	/*set Rw to loW for write */
#if CLCD_u8READ_OPERATION_ENEBLED == ENABLED
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_PIN_HIGH);
#endif
	/*send the data*/
#if CLCD_u8CONNECTION_MODE == FOUR_BIT
/*sending most sig 4bits of command*/
	voideSetHalfDataPort(copy_u8Data>>4);
	/* send Enable Pulse*/
	voidSendEnablePulse();
/*sending the least sig 4bits*/
	voideSetHalfDataPort(copy_u8Data);
	/* send Enable Pulse*/
	voidSendEnablePulse();
#elif CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Data);
	/* send Enable Pulse*/
	voidSendEnablePulse();
#endif


}
void CLCD_voidInit(void)
{
	/*wait for more then 30 seconds after power is on*/
	_delay_ms(40);
	/*function set command*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
/*0b0011NFxx
 * N->for one line then = 0,or 2 lines then = 1
 * f-> for font size :small(0 )or big(1) */
	CLCD_voidSendCommand(0b00111000);
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT
	voideSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voideSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voideSetHalfDataPort(0b1000);
	voidSendEnablePulse();
#endif
	/*display on of control :display on ,cursor off ,blink cursor off */
	CLCD_voidSendCommand(0b00001100);
	/*display clear*/
	CLCD_voidSendCommand(1);


}
void CLCD_voidGoToXY(uint8 copy_u8xPosition ,uint8 copy_u8YPosition )
{
	uint8 Local_u8DDRAMAddress = (copy_u8YPosition*0x40u) + copy_u8xPosition;

	/*set bit 7 for  ddram address command */
	SET_BIT(Local_u8DDRAMAddress,7u);
	/*send the setting ram addres command*/
	CLCD_voidSendCommand(Local_u8DDRAMAddress);


}
uint8 CLCD_u8WriteSpecialCharacter(uint8 copy_u8PatternNumber,uint8 copy_pu8PatternArr[],uint8 copy_u8XPos,uint8 copy_u8YPos)
{
	uint8 Local_u8ErrorStatus=OK;

	if(copy_pu8PatternArr!=NULL)
	{
		uint8 Local_u8Iterator;
		uint8 Local_u8CGRamAdd=copy_u8PatternNumber*8u;

		/*set bit 6 and clear bit 7 for setting CGRam address command*/
		SET_BIT(Local_u8CGRamAdd,6u);


		/*set  CGRam address */
		CLCD_voidSendCommand(Local_u8CGRamAdd);

		/* write the pattern inside CGRam*/
		for(Local_u8Iterator=0u;Local_u8Iterator<8u;Local_u8Iterator++)
		{
			CLCD_voidSendData(copy_pu8PatternArr[Local_u8Iterator]);
		}

		/* set DDRam address*/
		CLCD_voidGoToXY(copy_u8XPos,copy_u8YPos);

		/*write the corresponding pattern number to display from CGRam*/
		CLCD_voidSendData(copy_u8PatternNumber);


	}
	else
	{
		Local_u8ErrorStatus=NULL_PTR;
	}




	return Local_u8ErrorStatus;
}





void CLCD_voidSendDataAsString(char* const copy_u8pString )

{
	uint8 Local_u8LoopCounter=0;
	while (copy_u8pString[Local_u8LoopCounter]!='\0')
	{
		CLCD_voidSendData(copy_u8pString[Local_u8LoopCounter]);
		Local_u8LoopCounter++;

	}
}
void CLCD_voidSendDataAsNumbers(sint32 copy_s32Number)
{

	sint8 Local_s8LoopIter;
	uint8 Local_u8RightDigit,Local_u8Counter=0;
	char Local_chNumber[10];
	if (copy_s32Number==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	else if (copy_s32Number<0)//number is negative
	{
		CLCD_voidSendData('-');
		copy_s32Number*=-1;
	}
	while(copy_s32Number != 0)
	{
		Local_u8RightDigit=copy_s32Number % 10;//get the right most digit
		copy_s32Number /= 10;
		Local_chNumber[Local_u8Counter]=Local_u8RightDigit+'0';
		Local_u8Counter++;
	}
	for (Local_s8LoopIter=(sint8)Local_u8Counter-1;Local_s8LoopIter>=0;Local_s8LoopIter--)
	{
		CLCD_voidSendData(Local_chNumber[(uint8)Local_s8LoopIter]);
	}

}



