#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "TIMER_reg.h"
#include "TIMER_interface.h"


static void(*TIMER_vpFuncPtr)(void)=NULL;



void Timer0_init(void)
{
	/*setting timer0 to normal mode*/
	CLR_BIT(TIMER_TCCR0,Timer_WGM00);
	CLR_BIT(TIMER_TCCR0,Timer_WGM01);
	/*configure prescaler value to 256 */
	CLR_BIT(TIMER_TCCR0,Timer_CS00);
	CLR_BIT(TIMER_TCCR0,Timer_CS01);
	SET_BIT(TIMER_TCCR0,Timer_CS02);
	/*Overflow Interrupt Enabl*/
	SET_BIT(TIMER_TIMSK,Timer_TOIE0);
}
uint8 TIMER_SetCallBack(void(*copy_vpFuncPtr)(void))
{
	uint8 Local_ErrorState=OK;
	if (copy_vpFuncPtr!=NULL)
	{
		TIMER_vpFuncPtr=copy_vpFuncPtr;
	}
	else
	{
		Local_ErrorState=NULL_PTR;
	}
	return Local_ErrorState;
}



/*TIMER0 ISR */

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	TIMER_vpFuncPtr();
}





