#ifndef EXTI_REG_H
#define EXTI_REG_H

#define MCUCR     (*(volatile uint8*)0x55)
#define GICR      (*(volatile uint8*) 0x5B)
#define SREG      (*(volatile uint8*) 0x5F)
#define MCUCSR    (*(volatile uint8*) 0x54)


#endif
