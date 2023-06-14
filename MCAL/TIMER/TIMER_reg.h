#ifndef TIMER_REG_H
#define TIMER_REG_H

#define TIMER_TCCR0     *((volatile uint8*)0x53)
#define TIMER_TCNT0     *((volatile uint8*)0x52)
#define TIMER_TIMSK     *((volatile uint8*)0x59)
#define TIMER_OCR0      *((volatile uint8*)0x5C)

#endif
