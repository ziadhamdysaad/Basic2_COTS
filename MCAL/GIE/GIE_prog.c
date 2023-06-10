#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_reg.h"
#include "GIE_interface.h"



void GIE_voidEnable (void)
{
	//SET_BIT(SREG,SREG_I);


	/*we can set/clear this bit with assembly instruction
	 * we can add this instruction this way called inline assembly
	 * with CLI & SEI
	 * this way consume only one clock cycle  */
	__asm volatile("SEI");
}
void GIE_voidDisable (void)
{

	//CLR_BIT(SREG,SREG_I);
	__asm volatile("CLI");
}
