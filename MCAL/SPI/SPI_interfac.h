#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



#define MASTER                   1u
#define SLAVE                    0u


/*serial clock speed */
#define DIVISION_BY_2            0u
#define DIVISION_BY_4            1u
#define DIVISION_BY_8            2u
#define DIVISION_BY_16           3u
#define DIVISION_BY_32           4u
#define DIVISION_BY_64           5u
#define DIVISION_BY_128          6u



/*this Function is to initialize the SPI chose if the node will work as master or slave  */

uint8 SPI_voidInit(uint8 copy_u8Role);

uint8 SPI_u8Transcieve(uint8 copy_u8Data);


#endif
