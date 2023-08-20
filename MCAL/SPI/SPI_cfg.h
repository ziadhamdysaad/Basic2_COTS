#ifndef SPI_CFG_H
#define SPI_CFG_H



/*chose from 1-DIVISION_BY_2
 *           2-DIVISION_BY_4
 *           3-DIVISION_BY_8
 *           4-DIVISION_BY_16
 *           5-DIVISION_BY_32
 *           6-DIVISION_BY_64
 *           7-DIVISION_BY_128*/
#define SPI_CLK_RATE             DIVISION_BY_4
/*CLOCK Polarity configuration chose from:- 1-IDLE_AT_ZERO
 *                                          2-IDLE_AT_ONE*/
#define SPI_CLK_POLARITY          IDLE_AT_ZERO
/*clock phase configuration:chose from :1-FIRST_SAMPLING
 *                                      2-FIRST_SETUP*/
#define CLK_PHASE                    FIRST_SAMPLING
/*Data order configuration :chose from :1-LSB
 *                                      2-MSB*/
#define DATA_ORDER                        MSB
#endif
