#ifndef TIMER_CFG_H
#define TIMER_CFG_H

#define TIMER_PRELOADVALUE                                                   247
#define TIMER_COV                                                            62



/*TIMER0 operation mode: chose from two options :1-NORMAL
 *                                               2-CTC
 *                                               3-PWM_PHASE_CORRECT
 *                                               4-FAST_PWM
 **/
#define TIMER_MODE         CTC

/*CTC operation mode :options:1-NORMAL_PORT_OC0_DISCONNECTED
 *                            2-TOGGLE_OC0
 *                            3-CLEAR_OC0
 *                            4-SET_OC0*/
#define COMPARE_OUTPUT_MODE     NORMAL_PORT_OC0_DISCONNECTED

/*select prescaler configuration :options :1-NO_PRESCALING
 *                                         2-DIVISION_BY_8
 *                                         3-DEVISION_BY_64
 *                                         4-DIVISION_BY_256
 *                                         5-DIVISION_BY_1024
 *                                         6-External_clock_source_on_T0_pin_Clock_on_falling_edge
 *                                         7-External_clock_source_on_T0_pin_Clock_on_rising_edge
 **/
#define PRESCALER                     DEVISION_BY_64
#endif
