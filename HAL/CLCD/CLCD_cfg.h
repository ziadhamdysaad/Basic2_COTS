#ifndef CLCD_CFG_H
#define CLCD_CFG_H


/* CLCD connection type configuration macro,
 * select between:  1- FOUR_BIT
 *  				2- EIGHT_BIT
 * */

#define CLCD_u8CONNECTION_MODE		FOUR_BIT



#if CLCD_u8CONNECTION_MODE == FOUR_BIT
#define CLCD_u8D4_PIN 					DIO_PIN3
#define CLCD_u8D5_PIN 					DIO_PIN4
#define CLCD_u8D6_PIN 					DIO_PIN5
#define CLCD_u8D7_PIN 					DIO_PIN6
#endif



/* CLCD Read operation enable configuration macro,
 * select between:  1- ENABLED
 *  				2- DISABLED
 * */
#define CLCD_u8READ_OPERATION_ENABLE 	   DISABLED

#if CLCD_u8READ_OPERATION_ENABLE == ENABLED
#define CLCD_u8RW_PIN					DIO_PIN1
#endif


#define CLCD_DATA_PORT 				    DIO_PORTA
#define CLCD_CTRL_PORT       			DIO_PORTA

#define CLCD_RS_PIN					DIO_PIN1
#define CLCD_E_PIN					DIO_PIN2






#endif
