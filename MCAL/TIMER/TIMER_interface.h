#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

typedef enum
{
	TIMER0=0,
	TIMER1,
	TIMER2,
}TIMER_IntNum_t;
/*this two macros to chose between modes */


#define Timer_CS00       0u
#define Timer_CS01       1u
#define Timer_CS02       2u
/*compare output mode bits (CTC) */
#define Timer_COM00      4u
#define Timer_COM01      5u

#define Timer_FOC0       7u

/*for timer0 over flow */


void Timer0_init(void);
uint8 TIMER_u8SetCallBack(TIMER_IntNum_t copy_IntNum, void(*copy_pvFuncPtr)(void));
void Timer0_voidSetCompVal(uint8 copy_u8CompVal);
void Timer1_init(void);
uint16 Timer1_u16GetTimer1Val(void);
void Timer1_voidSetCompVal(uint16 copy_u16CompVal);
void Timer1_voidSetOverFlowVal(uint16 copy_u16OverFlowVal);

void TIMER1_voidSetTimerVal(uint16 copy_u16Val);




#endif

