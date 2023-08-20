#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TIMER_prv.h"
#include "TIMER_reg.h"
#include "TIMER_cfg.h"

#include "TIMER_interface.h"


static void(*TIMER_pvFuncPtr)(void)=NULL;



void Timer0_init(void)
{

#if TIMER_MODE == NORMAL
	/*setting timer0 to normal mode*/
	CLR_BIT(TIMER_TCCR0,TIMER_WGM00);
	CLR_BIT(TIMER_TCCR0,TIMER_WGM01);

	/*prescalar : NO_PRESCALING*/

#if PRESCALER == NO_PRESCALING
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

	/*Overflow Interrupt Enable*/
	SET_BIT(TIMER_TIMSK,TIMER_TOIE0);

#elif TIMER_MODE == CTC             	/*setting timer0 to CTC mode*/


	SET_BIT(TIMER_TCCR0,TIMER_WGM01);
	CLR_BIT(TIMER_TCCR0,TIMER_WGM00);
	/*setting CTC Output compare mode*/
#if COMPARE_OUTPUT_MODE == NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TIMER_TCCR0,TIMER_COM00);
	CLR_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == TOGGLE_OC0
	SET_BIT(TIMER_TCCR0,TIMER_COM00);
	CLR_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == CLEAR_OC0
	CLR_BIT(TIMER_TCCR0,TIMER_COM00);
	SET_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == SET_OC0
	SET_BIT(TIMER_TCCR0,TIMER_COM00);
	SET_BIT(TIMER_TCCR0,TIMER_COM01);
#endif
	/*prescaler section */
#if PRESCALER == NO_PRESCALING
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

	/*output compare interrupt enable  */
	SET_BIT(TIMER_TIMSK,TIMER_OCIE0);

#elif TIMER_MODE == FAST_PWM     //setting timer0 mode to fast PWM
	SET_BIT(TIMER_TCCR0,TIMER_WGM01);
	SET_BIT(TIMER_TCCR0,TIMER_WGM00);

#if COMPARE_OUTPUT_MODE == NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TIMER_TCCR0,TIMER_COM00);
	CLR_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == TOGGLE_OC0
	SET_BIT(TIMER_TCCR0,TIMER_COM00);
	CLR_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == CLEAR_OC0
	CLR_BIT(TIMER_TCCR0,TIMER_COM00);
	SET_BIT(TIMER_TCCR0,TIMER_COM01);
#elif COMPARE_OUTPUT_MODE == SET_OC0
	SET_BIT(TIMER_TCCR0,TIMER_COM00);
	SET_BIT(TIMER_TCCR0,TIMER_COM01);
#endif

	/*OUTPUT COMPARE VALUE 64*/
	TIMER_OCR0=64u;
	/*output compare interrupt Disable  */
	CLR_BIT(TIMER_TIMSK,TIMER_OCIE0);

#if PRESCALER == NO_PRESCALING
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TIMER_TCCR0 &= PRESCALAR_MASK;
	TIMER_TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

#endif



}





/*timer0 changing compare value function */
void Timer0_voidSetCompVal(uint8 copy_u8CompVal)
{
	TIMER_OCR0 = copy_u8CompVal;
}


uint8 TIMER_SetCallBack(void(*copy_pvFuncPtr)(void))
{
	uint8 Local_ErrorState=OK;
	if (copy_pvFuncPtr!=NULL)
	{
		TIMER_pvFuncPtr=copy_pvFuncPtr;
	}
	else
	{
		Local_ErrorState=NULL_PTR;
	}
	return Local_ErrorState;
}



/*TIMER0 ISR */

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (TIMER_pvFuncPtr != NULL)
	{
		TIMER_pvFuncPtr();
	}
	else
	{
		/*do nothing*/
	}
}





