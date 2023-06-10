#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_reg.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "EXTI_interface.h"
#include "Err_Type.h"

static void (*EXTI_pfFuncPtr[3])(void)={NULL};

void EXTI_voidInt0Init(void)
{
#if EXTI_INT0_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT0);
#endif

#if EXTI_INT0_TRIG ==EXTI_FallingEdge

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif	EXTI_INT0_TRIG ==EXTI_RisingEdge
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif   EXTI_INT0_TRIG ==EXTI_OnChange


	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);


#elif   EXTI_INT0_TRIG ==EXTI_LowLevel

	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#else
#error "wrong EXTI_INT0_TRIG configuration "
#endif
#if EXTI_INT0_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT0);
#elif EXTI_INT0_INIT_STATE==DISABLE
	CLR_BIT(GICR,GICSR_INT0);
#else
#error "wrong EXTI_INT0_INIT_STATE configuration option "
#endif

}
void EXTI_voidInt1Init(void)
{


#if EXTI_INT1_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT1);
#endif


#if EXTI_INT1_TRIG ==EXTI_FallingEdge

	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif	EXTI_INT1_TRIG ==EXTI_RisingEdge
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif   EXTI_INT1_TRIG ==EXTI_OnChange


	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);


#elif   EXTI_INT1_TRIG ==EXTI_LowLevel

	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#else
#error "wrong EXTI_INT1_TRIG configuration "
#endif
#if EXTI_INT1_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT1);
#elif EXTI_INT1_INIT_STATE==DISABLE
	CLR_BIT(GICR,GICSR_INT1);
#else
#error "wrong EXTI_INT1_INIT_STATE configuration option "
#endif

}
void EXTI_voidInt2Init(void)
{




#if EXTI_INT2_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT2);
#endif


#if EXTI_INT2_TRIG ==EXTI_FallingEdge

	CLR_BIT(MCUCSR,MCUCSR_ISC2);


#elif	EXTI_INT2_TRIG ==EXTI_RisingEdge
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error "wrong EXTI_INT2_TRIG configuration "


#endif
#if EXTI_INT2_INIT_STATE==ENABLE
	SET_BIT(GICR,GICSR_INT2);
#elif EXTI_INT2_INIT_STATE==DISABLE
	CLR_BIT(GICR,GICSR_INT2);
#else
#error "wrong EXTI_INT2_INIT_STATE configuration option "
#endif

}


uint8 EXTI_u8SetSenseControl( EXTI_INTNUM_t copy_IntNum ,uint8 copy_u8SenseCTRL)
{
	uint8 Local_u8StateError=OK;
	if(copy_IntNum==int0)
	{
		switch(copy_u8SenseCTRL)
		{
		case EXTI_FallingEdge:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);break;
		case EXTI_RisingEdge:
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);break;
		case EXTI_OnChange:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);break;
		case EXTI_LowLevel:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);break;

		default :	Local_u8StateError=NOK;break;


		}
	}
	else if (copy_IntNum==int1)
	{
		switch(copy_u8SenseCTRL)
		{
		case EXTI_FallingEdge:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);break;
		case EXTI_RisingEdge:
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);break;
		case EXTI_OnChange:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);break;
		case EXTI_LowLevel:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);break;
		default :	Local_u8StateError=NOK;break;
		}

	}
	else if (copy_IntNum==int2)
	{
		switch(copy_u8SenseCTRL)
		{
		case EXTI_FallingEdge:CLR_BIT(MCUCSR,MCUCSR_ISC2);break;

		case EXTI_RisingEdge:SET_BIT(MCUCSR,MCUCSR_ISC2);break;
		default :	Local_u8StateError=NOK;break;
		}

	}
	else
	{
		Local_u8StateError=NOK;

	}
	return Local_u8StateError;

}

uint8 EXTI_u8IntrupptEnable(EXTI_INTNUM_t copy_IntNum)
{
	uint8 Local_u8StateError=OK;
	switch(copy_IntNum)
	{
	case int0:	SET_BIT(GICR,GICSR_INT0);break;
	case int1: 	SET_BIT(GICR,GICSR_INT1);break;
	case int2:  SET_BIT(GICR,GICSR_INT2);break;
	default:Local_u8StateError=NOK;break;


	}
	return Local_u8StateError;
}
uint8 EXTI_u8IntrupptDisable(EXTI_INTNUM_t copy_IntNum)
{
	uint8 Local_u8StateError=OK;
	switch(copy_IntNum)
	{
	case int0:	CLR_BIT(GICR,GICSR_INT0);break;
	case int1: 	CLR_BIT(GICR,GICSR_INT1);break;
	case int2:  CLR_BIT(GICR,GICSR_INT2);break;
	default:Local_u8StateError=NOK;break;


	}
	return Local_u8StateError;
}



uint8 EXTI_u8SetCallBack(EXTI_INTNUM_t copy_IntNum,void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState=OK;
	if (copy_pvFuncPtr!=NULL)
	{
		if ((copy_IntNum >= int0)&&(copy_IntNum<=int2))
		{
			EXTI_pfFuncPtr[copy_IntNum]=copy_pvFuncPtr;
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;
}

/*int0 ISR  */
 void __vector_1(void)__attribute__((signal));
 void __vector_1(void)
{
	if (EXTI_pfFuncPtr[int0]!=NULL)
	{
		EXTI_pfFuncPtr[int0]();
	}
	else
	{
		/*do nothing */
	}

}


/*int1 ISR  */
 void __vector_2(void)__attribute__((signal));
 void __vector_2(void)
{
	if (EXTI_pfFuncPtr[int1]!=NULL)
	{
		EXTI_pfFuncPtr[int1]();
	}
	else
	{
		/*do nothing */
	}

}


/*int0 ISR  */
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if (EXTI_pfFuncPtr[int2]!=NULL)
	{
		EXTI_pfFuncPtr[int2]();
	}
	else
	{
		/*do nothing */
	}

}

