#ifndef TIMER_PRV_H
#define TIMER_PRV_H

#define NORMAL                                                               0U
#define CTC                                                                  2U
#define FAST_PWM                                                             3u
#define NORMAL_PORT_OC0_DISCONNECTED                                         0U
#define TOGGLE_OC0                                                           1U
#define CLEAR_OC0                                                            2U
#define SET_OC0                                                              3U


#define PRESCALAR_MASK                                                       0b11111000

#define NO_PRESCALING                                                        1U
#define DIVISION_BY_8                                                        2U
#define DEVISION_BY_64                                                       3U
#define DIVISION_BY_256                                                      4U
#define DIVISION_BY_1024                                                     5U
#define External_clock_source_on_T0_pin_Clock_on_falling_edge                6U
#define External_clock_source_on_T0_pin_Clock_on_rising_edge                 7U

#define NORMAL_PORT_OCA1_DISCONNECTED                                        0U
#define TOGGLE_OCA1_ON_COMPARE                                               1U
#define CLEAR_OCA1_ON_COMPARE                                                2U
#define SET_OCA1_ON_TOP                                                      3U


#define TIMER1_NORMAL_MODE                                                   0U
#define TIMER1_PWM_PHASE_CORRECT_8_BIT                                       1U
#define TIMER1_PWM_PHASE_CORRECT_9_BIT                                       2U
#define TIMER1_PWM_PHASE_CORRECT_10_BIT                                      3U
#define TIMER1_CTC_MODE                                                      4U
#define TIMER1_FAST_PWM_8_BIT                                                5U
#define TIMER1_FAST_PWM_9_BIT                                                6U
#define TIMER1_FAST_PWM_10_BIT                                               7U
#define TIMER1_FAST_PWM_ICR1                                                 14U

#define ENABLE        1u
#define DISABLE       0u



#endif
