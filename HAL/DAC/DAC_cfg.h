#ifndef DAC_CFG_H
#define DAC_CFG_H

/*please chose the port configuration of the DAC :
 *                                                 1-PORTA
 *                                                 2-PORTB
 *                                                 3-PORTC
 *                                                 4-PORTD
 **/
#define DAC_PORT     DIO_PORTA


#define DAC_u16REFERANCE_VOLT          5000u                                      //5000 mVolt
#define DAC_RESOLUTION                 256u                                       //8 pins so 2^8=256



#endif
