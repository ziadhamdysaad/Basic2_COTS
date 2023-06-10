#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
	int0=0,
	int1,
	int2

}EXTI_INTNUM_t;



#define    EXTI_FallingEdge     1u
#define	   EXTI_RisingEdge      2u
#define	   EXTI_OnChange        3u
#define	   EXTI_LowLevel        4u



void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);
uint8 EXTI_u8SetSenseControl( EXTI_INTNUM_t copy_IntNum ,uint8 copy_u8SenseCTRL);
uint8 EXTI_u8IntrupptEnable(EXTI_INTNUM_t copy_IntNum);
uint8 EXTI_u8IntrupptDisable(EXTI_INTNUM_t copy_IntNum);

uint8 EXTI_u8SetCallBack(EXTI_INTNUM_t copy_IntNum,void(*copy_pvFuncPtr)(void));



#endif
