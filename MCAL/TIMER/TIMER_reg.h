#ifndef TIMER_REG_H
#define TIMER_REG_H

#define OCR0         *((volatile uint8*)0x5C)    // output compare match register

#define TCCR0              *((volatile uint8*)0x53)   // timer0 counter control reg
#define TCCR0_WGM00        6u  //wave form generation mode bit0
#define TCCR0_WGM01        3u  //wave form generation mode bit1
#define TCCR0_COM00        4u  //compare match output mode bit0
#define TCCR0_COM01        5u  //compare match output mode bit1

#define TCCR1A             *((volatile uint8*)0x4F)  // timer1 counter control Channel A reg
#define TCCR1A_WGM10       0u   //wave form generation mode bit0
#define TCCR1A_WGM11       1u   //wave form generation mode bit1
#define TCCR1A_COM1A0      6u  // compare output mode for channel A Bit6
#define TCCR1A_COM1A1      7u  // compare output mode for channel A Bit7


#define TCCR1B              *((volatile uint8*)0x4E)  // timer1 counter control Channel B reg
#define TCCR1B_WGM13        4u      //wave form generation mode bit 3
#define TCCR1B_WGM12        3u      //wave form generation mode bit 2
#define TCCR1B_CS12         2u      //prescaler bit 2
#define TCCR1B_CS11         1u      //prescaler bit 1
#define TCCR1B_CS10         3u      //prescaler bit 0

#define TCNT1         *((volatile uint16* )0x4C)    /*timer 1 register */

#define TCNT0         *((volatile uint8*)0x52)  // timer counter control reg

#define TIMSK         *((volatile uint8*)0x59) //  timer mask register
#define TIMSK_TOIE0         0u     //timer over flow interrupt enable
#define TIMSK_OCIE0         1u     //timer0 compare match interrupt enable
#define OCR1A              *((volatile uint16*)0x4A)
#define ICR1               *((volatile uint16*)0x46)
#endif
