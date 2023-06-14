#ifndef ADC_PRV_H
#define ADC_PRV_H
#define EIGHT_BITS    1u
#define TEN_BITS      2u

#define PRESCALER_MASK          0b11111000U // we need first 3 bits only
#define CHANNEL_SELECTION_MASK            0b11100000U

#define DIVISION_BY_2            0u
#define DIVISION_BY_4            2u
#define DIVISION_BY_8            3u
#define DIVISION_BY_16           4u
#define DIVISION_BY_32           5u
#define DIVISION_BY_64           6u
#define DIVISION_BY_128          7u

#define IDLE                     0u
#define BUSY                     1u

#define CHAIN                    1u
#define SINGLE                   2u


#endif
