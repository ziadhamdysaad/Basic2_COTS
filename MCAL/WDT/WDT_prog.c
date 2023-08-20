#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_reg.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"
#include "WDT_interface.h"






void WDT_voidWatchDogEnable(void)
{
	WDTCR |= (1<<WDE);

}



void WDT_voidWatchDogDisable(void)
{
	WDTCR |= (1<<WDTOE)|(1<<WDE);
	//WDTCR=0b00011110;        >>>>>>   alternative way
	WDTCR=0;
}
