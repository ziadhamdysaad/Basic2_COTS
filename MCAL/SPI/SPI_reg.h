#ifndef SPI_REG_H
#define SPI_REG_H


/*SPI Control Register */
#define SPCR                      *(( volatile uint8*) 0x2D)
#define SPCR_SPIE                 7u /*SPI interrupt enable */
#define SPCR_SPE                  6u /* SPI enable*/
#define SPCR_DORD                 5u /*Data Order Bit*/
#define SPCR_MSTR                 4u /*Master Slave select*/
#define SPCR_CPOL                 3u /*Clock Polarity*/
#define SPCR_CPHA                 2u /*clock phase*/
#define SPCR_SPR1                 1u /*clock rate select bit1*/
#define SPCR_SPR0                 0u /*clock rate select bit0*/

/*SPI Status Register */
#define SPSR                       *(( volatile uint8*) 0x2E)
#define SPSR_SPIF                 7u /*SPI interrupt flag bit */
#define SPSR_WCOL                 6u /*write collision flag bit */
#define SPSR_SPI2X                0u /*double SPI speed bit */

/*SPI Data Register */
#define SPDR                      *(( volatile uint8*) 0x2F)
#define SPDR_MSB                  7u
#define SPDR_LSB                  0u




#endif
