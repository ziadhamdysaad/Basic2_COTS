#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H


#define COLUMN_SIZE          4
#define ROW_SIZE             4


// configuration for row port and pins for each row
#define KPD_u8ROW_PORT          DIO_PORTB
#define KPD_u8R0                DIO_PIN4
#define KPD_u8R1                DIO_PIN5
#define KPD_u8R2                DIO_PIN6
#define KPD_u8R3                DIO_PIN7

// configuration for column port and pins for each column


#define KPD_u8COLUMN_PORT       DIO_PORTD
#define KPD_u8C0                DIO_PIN2
#define KPD_u8C1                DIO_PIN3
#define KPD_u8C2                DIO_PIN4
#define KPD_u8C3                DIO_PIN5
/*key pad configuration*/
#define KPD_BUTTON_ARR             {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#define KPD_u8NO_PRESSED_KEY_VAL      0xff
#endif
