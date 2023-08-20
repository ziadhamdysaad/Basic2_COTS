#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR				*((volatile uint8*)0x2C)
		
#define UCSRA			*((volatile uint8*)0x2B)
#define UCSRB			*((volatile uint8*)0x2A)
#define UCSRC			*((volatile uint8*)0x40)
#define UCSRC_URSEL		7u 							/*Register select*/
#define UCSRC_UMSEL		6u                          /*Mode select*/
#define UCSRC_UPM1		5u                          /*Parity mode select bit 1*/
#define UCSRC_UPM0		4u                          /*Parity mode select bit 0*/
#define UCSRC_USBS		3u                          /*Stop bit select*/
#define UCSRC_UCSZ1		2u                          /*Character size bit 1*/
#define UCSRC_UCSZ0		1u                          /*Character size bit 0*/
#define UCSRC_UCPOL		0u                          /*Clock polarity*/

#define UBRRH			*((volatile uint8*)0x40)
#define UBRRL			*((volatile uint8*)0x29)

#endif