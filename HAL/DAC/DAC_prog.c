#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Err_Type.h"

#include "DAC_interface.h"
#include "DAC_cfg.h"
#include "DAC_prv.h"
#include <util/delay.h>

uint8 DAC_voidSetAnalogVolt(sint16 copy_u16AnalogVolt)
{
	uint8 Local_u8ErrorState=OK;

	if (copy_u16AnalogVolt<=DAC_u16REFERANCE_VOLT)
	{
		uint8 Local_f32Digital=copy_u16AnalogVolt/DAC_STEPSIZE;
		DIO_u8SetPortValue(DAC_PORT,Local_f32Digital);


	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;

}

