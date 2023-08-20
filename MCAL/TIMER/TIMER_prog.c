#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TIMER_prv.h"
#include "TIMER_reg.h"
#include "TIMER_cfg.h"

#include "TIMER_interface.h"


static void (*TIMER_pfFuncPtr[3])(void)= {NULL,NULL,NULL};



void Timer0_init(void)
{
	/*Overflow Mode */
#if TIMER_MODE == NORMAL
	/*setting timer0 to normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*prescalar : NO_PRESCALING*/

#if PRESCALER == NO_PRESCALING
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

#if INTERRUPT_STATUS == ENABLE
	/*Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
	/*Overflow Interrupt Disable*/
#elif INTERRUPT_STATUS == DISABLE

	CLR_BIT(TIMSK,TIMSK_TOIE0);

#endif

#elif TIMER_MODE == CTC             	/*setting timer0 to CTC mode*/


	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	/*setting CTC Output compare mode*/
#if COMPARE_OUTPUT_MODE == NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == TOGGLE_OC0
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == CLEAR_OC0
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == SET_OC0
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif
	/*prescaler section */
#if PRESCALER == NO_PRESCALING
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

	/*output compare interrupt enable  */
	SET_BIT(TIMSK,TIMSK_OCIE0);

#elif TIMER_MODE == FAST_PWM     //setting timer0 mode to fast PWM
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

#if COMPARE_OUTPUT_MODE == NORMAL_PORT_OC0_DISCONNECTED
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == TOGGLE_OC0
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == CLEAR_OC0
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE == SET_OC0
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif



#if INTERRUPT_STATUS == ENABLE
	/*Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
	/*Overflow Interrupt Disable*/
#elif INTERRUPT_STATUS == DISABLE

	CLR_BIT(TIMSK,TIMSK_TOIE0);

#endif

#if PRESCALER == NO_PRESCALING
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;


	/*prescalar : division by 8*/
#elif PRESCALER == DIVISION_BY_8
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_8;

	/*prescalar : division by 64*/
#elif PRESCALER == DEVISION_BY_64
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DEVISION_BY_64;

	/*prescalar : division by 256*/
#elif PRESCALER == DIVISION_BY_256
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_256;

	/*prescalar : division by 1024*/
#elif PRESCALER == DIVISION_BY_1024
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= DIVISION_BY_1024;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;


#elif PRESCALER == External_clock_source_on_T0_pin_Clock_on_falling_edge
	TCCR0 &= PRESCALAR_MASK;
	TCCR0 |= External_clock_source_on_T0_pin_Clock_on_falling_edge;
#endif

#endif



}

/*timer1 init function  */
void Timer1_init(void)
{
	/*normal mode */
#if TIMER1_MODE == TIMER1_NORMAL_MODE
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_8_BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_9_BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_10_BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_CTC_MODE
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_FAST_PWM_8_BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_FAST_PWM_9_BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_FAST_PWM_10_BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
#elif TIMER1_MODE == TIMER1_FAST_PWM_ICR1

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

#endif




#if TIMER1_COMPARE_OUTPUT_MODE == CLEAR_OCA1_ON_COMPARE
	/*OC1A configuration to clear on top set on compare for channel A*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif TIMER1_COMPARE_OUTPUT_MODE == NORMAL_PORT_OCA1_DISCONNECTED
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif TIMER1_COMPARE_OUTPUT_MODE == TOGGLE_OCA1_ON_COMPARE
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
#elif TIMER1_COMPARE_OUTPUT_MODE == CLEAR_OCA1_ON_COMPARE
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#endif


	/*configure prescaler to division by 8 */
	TCCR1B &= 0b11111000;
	TCCR1B |= 0b11111010;



}
void Timer1_voidSetOverFlowVal(uint16 copy_u16OverFlowVal)
{
	ICR1 = copy_u16OverFlowVal;
}
void Timer1_voidSetCompVal(uint16 copy_u16CompVal)
{
	OCR1A = copy_u16CompVal;
}
void TIMER1_voidSetTimerVal(uint16 copy_u16Val)
{
	TCNT1= copy_u16Val;
}
uint16 Timer1_u16GetTimer1Val(void)
{
	return TCNT1;
}


/*timer0 changing compare value function */
void Timer0_voidSetCompVal(uint8 copy_u8CompVal)
{
	OCR0 = copy_u8CompVal;
}


uint8 TIMER_u8SetCallBack(TIMER_IntNum_t copy_IntNum, void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;

	if(copy_pvFuncPtr != NULL)
	{
		if((copy_IntNum>= TIMER0) && (copy_IntNum <=TIMER2))
		{
			TIMER_pfFuncPtr[copy_IntNum] = copy_pvFuncPtr;
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}

	return Local_u8ErrorState;
}




/*TIMER0 CTC Mode  ISR */

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (TIMER_pfFuncPtr[TIMER0] != NULL)
	{
		TIMER_pfFuncPtr[TIMER0]();
	}
	else
	{
		/*do nothing*/
	}
}





