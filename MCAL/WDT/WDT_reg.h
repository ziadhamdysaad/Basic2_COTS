#ifndef WDT_REG_H
#define WDT_REG_H




#define WDTCR                    *((volatile uint8*)0x41)


#define WDTOE                    4u
#define WDE                      3u
#define WDP2                     2u
#define WDP1                     1u
#define WDP0                     0u


#endif
