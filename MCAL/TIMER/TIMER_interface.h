#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/*this two macros to chose between modes */


#define Timer_CS00       0u
#define Timer_CS01       1u
#define Timer_CS02       2u
#define Timer_WGM01      3u
#define Timer_COM00      4u
#define Timer_COM01      5u
#define Timer_WGM00      6u
#define Timer_FOC0       7u

/*for timer0 over flow */
#define Timer_TOIE0      0u

#define Timer_OCIE0      1u

void Timer0_init(void);
uint8 TIMER_SetCallBack(void(*copy_vpFuncPtr)(void));



#endif

