#ifndef TIMER_CFG_H
#define TIMER_CFG_H

#define TIMER_PRELOADVALUE                                                   247
#define TIMER_COV                                                            62



/*TIMER0 operation mode: chose from two options :1-NORMAL
 *                                               2-CTC
 *                                               3-PWM_PHASE_CORRECT
 *                                               4-FAST_PWM
 **/
#define TIMER_MODE         FAST_PWM

/*CTC operation mode :options:1-NORMAL_PORT_OC0_DISCONNECTED
 *                            2-TOGGLE_OC0
 *                            3-CLEAR_OC0
 *                            4-SET_OC0*/
#define COMPARE_OUTPUT_MODE     CLEAR_OC0

/*select prescaler configuration :options :1-NO_PRESCALING
 *                                         2-DIVISION_BY_8
 *                                         3-DEVISION_BY_64
 *                                         4-DIVISION_BY_256
 *                                         5-DIVISION_BY_1024
 *                                         6-External_clock_source_on_T0_pin_Clock_on_falling_edge
 *                                         7-External_clock_source_on_T0_pin_Clock_on_rising_edge
 **/
#define PRESCALER                     DEVISION_BY_64



/*timer1 configuration */

/*HW Action "OCA1/OCAB1*/
/*FAST PWM operation mode :options:1-NORMAL_PORT_OCA1_DISCONNECTED
 *                                 2-TOGGLE_OCA1_ON_COMPARE
 *                                 3-CLEAR_OCA1_ON_COMPARE
 *                                 4-SET_OCA1_ON_TOP
 **/
#define TIMER1_COMPARE_OUTPUT_MODE              CLEAR_OCA1_ON_COMPARE


/*configuration for timer1 modes :Options :-
 *                                1-TIMER1_NORMAL_MODE
                                  2-TIMER1_PWM_PHASE_CORRECT_8_BIT
                                  3-TIMER1_PWM_PHASE_CORRECT_9_BIT
                                  4-TIMER1_PWM_PHASE_CORRECT_10_BIT
                                  5-TIMER1_CTC_MODE
                                  6-TIMER1_FAST_PWM_8_BIT
                                  7-TIMER1_FAST_PWM_9_BIT
                                  8-TIMER1_FAST_PWM_10_BIT
                                  9-TIMER1_FAST_PWM_ICR1             */
#define TIMER1_MODE             TIMER1_FAST_PWM_ICR1


#define INTERRUPT_STATUS         DISABLE


#endif
