#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef enum
{
	LED_Active_High,
	LED_Active_Low
	
}LED_ACT_t;
typedef struct 
{
	DIO_Port_t LED_Port;
	DIO_Pin_t  LED_Pin;
	LED_ACT_t  LED_ActivityType;
}LED_configuration_t;

/*setting the LED On*/
uint8 LED_u8SetOn(LED_configuration_t* copy_pLEDObject);

/*setting the LED Of*/
uint8 LED_u8SetOff(LED_configuration_t* copy_pLEDObject);
/*Toggle the LED between On and OFF*/
uint8 LED_u8SetToggle(LED_configuration_t* copy_pLEDObject);






#endif
