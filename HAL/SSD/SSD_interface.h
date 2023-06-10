#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

typedef enum
{
	SSD_CommonAnode,
	SSD_CommonCathode,
	SSD_EtaKite
}SSD_TYPE_t;
typedef enum
{
	SSD_LEDAPin0,
	SSD_LEDAPin1
}SSD_LEDANum_t;
typedef struct
{
	SSD_TYPE_t     SSD_Type;
	DIO_Port_t     SSD_PortName;
	SSD_LEDANum_t  SSD_LEDAPin;
	DIO_Port_t     SSD_EnablePort;
	DIO_Pin_t      SSD_EnablePin;
}SSD_confg_t;


uint8 SSD_u8SetNumber(const SSD_confg_t* copy_pSSD_Obj , uint8 copy_u8number);
uint8 SSD_u8Enable   (const SSD_confg_t* copy_pSSD_Obj);
uint8 SSD_u8Disable  (const SSD_confg_t* copy_pSSD_Obj);





#endif
