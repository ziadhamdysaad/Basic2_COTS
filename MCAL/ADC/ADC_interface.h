#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
typedef enum
{
	ADC0_SINGLE_ENDED=0,
	ADC1_SINGLE_ENDED,
	ADC2_SINGLE_ENDED,
	ADC3_SINGLE_ENDED,
	ADC4_SINGLE_ENDED,
	ADC5_SINGLE_ENDED,
	ADC6_SINGLE_ENDED,
	ADC7_SINGLE_ENDED,
	ADC0_POS_ADC0_NEG_10X_GAIN,
	ADC1_POS_ADC0_NEG_10X_GAIN,
	ADC0_POS_ADC0_NEG_200X_GAIN,
	ADC1_POS_ADC0_NEG_200X_GAIN,
	ADC2_POS_ADC2_NEG_10X_GAIN,
	ADC3_POS_ADC2_NEG_10X_GAIN,
	ADC2_POS_ADC2_NEG_200X_GAIN,
	ADC3_POS_ADC2_NEG_200X_GAIN,
	ADC0_POS_ADC1_NEG_1X_GAIN,
	ADC1_POS_ADC1_NEG_1X_GAIN,
	ADC2_POS_ADC1_NEG_1X_GAIN,
	ADC3_POS_ADC1_NEG_1X_GAIN,
	ADC4_POS_ADC1_NEG_1X_GAIN,
	ADC5_POS_ADC1_NEG_1X_GAIN,
	ADC6_POS_ADC1_NEG_1X_GAIN,
	ADC7_POS_ADC1_NEG_1X_GAIN,
	ADC0_POS_ADC2_NEG_1X_GAIN,
	ADC1_POS_ADC2_NEG_1X_GAIN,
	ADC2_POS_ADC2_NEG_1X_GAIN,
	ADC3_POS_ADC2_NEG_1X_GAIN,
	ADC4_POS_ADC2_NEG_1X_GAIN,

}ADC_Chanel_t;

typedef struct
{
	uint8 ConverstionNumber;
	ADC_Chanel_t* convertionChanelArray;
	uint16* ArrayOfResults;
	void   (*Notification_function)(void);
} ADC_ChainConvertionStruct_t ;
void ADC_voidInit(void);
uint8 ADC_u16StartConvesionSynch(ADC_Chanel_t copy_channel, uint16* copy_pu16DigResult);
uint8 ADC_u16StartConvesionSingleASynch(ADC_Chanel_t copy_channel, uint16* copy_pu16DigResult, void (*copy_pvNotificationFunc)(void));

uint8 ADC_u8StartChainConversionAsynch(ADC_ChainConvertionStruct_t* copy_pChainConverstionObj);

#endif
