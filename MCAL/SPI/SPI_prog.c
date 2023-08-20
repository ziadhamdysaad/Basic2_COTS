#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Err_Type.h"
#include "SPI_prv.h"
#include "SPI_reg.h"
#include "SPI_cfg.h"
#include "SPI_interfac.h"


/*SPI Initialization Function*/
uint8 SPI_voidInit(uint8 copy_u8Role)
{
	uint8 Local_u8StateErr=OK;

	if (copy_u8Role==MASTER)
	{
		/*configure master bit in SPI control register to master  */
		SET_BIT(SPCR,SPCR_MSTR);
		/*configuring SPI clock rate  */
#if SPI_CLK_RATE == DIVISION_BY_2
		CLR_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1) ;
		SET_BIT(SPSR,SPSR_SPI2X);

#elif SPI_CLK_RATE == DIVISION_BY_4
		CLR_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1) ;
		CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_RATE == DIVISION_BY_8
		SET_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1) ;
		SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_RATE == DIVISION_BY_16
		SET_BIT(SPCR,SPCR_SPR0);
		CLR_BIT(SPCR,SPCR_SPR1) ;
		CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_RATE == DIVISION_BY_32
		CLR_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1) ;
		SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_RATE == DIVISION_BY_64
		CLR_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1) ;
		CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_RATE == DIVISION_BY_128
		SET_BIT(SPCR,SPCR_SPR0);
		SET_BIT(SPCR,SPCR_SPR1) ;
		CLR_BIT(SPSR,SPSR_SPI2X);
#endif
		/*clock polarity*/
#if SPI_CLK_POLARITY == IDLE_AT_ZERO
		CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_CLK_POLARITY == IDLE_AT_ONE
		SET_BIT(SPCR,SPCR_CPOL);

#endif*/
		/*clock phase */
#if CLK_PHASE == FIRST_SAMPLING
		CLR_BIT(SPCR,SPCR_CPHA);
#elif CLK_PHASE == FIRST_SETUP
		SET_BIT(SPCR,SPCR_CPHA);
#endif
#if DATA_ORDER == LSB
		SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER == MSB
		CLR_BIT(SPCR,SPCR_DORD);
#endif

	}
	/*if the user chose slave */
	else if (copy_u8Role == SLAVE)
	{
		/*configure master bit in SPI control register to slave*/
		CLR_BIT(SPCR,SPCR_MSTR);
		/*clock polarity*/
#if SPI_CLK_POLARITY == IDLE_AT_ZERO
		CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_CLK_POLARITY == IDLE_AT_ONE
		SET_BIT(SPCR,SPCR_CPOL);

#endif
		/*clock phase */
#if CLK_PHASE == FIRST_SAMPLING
		CLR_BIT(SPCR,SPCR_CPHA);
#elif CLK_PHASE == FIRST_SETUP
		SET_BIT(SPCR,SPCR_CPHA);
#endif
#if DATA_ORDER == LSB
		SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER == MSB
		CLR_BIT(SPCR,SPCR_DORD);
#endif

	}
	else
	{
		Local_u8StateErr= NOK;
	}


	/*Enabling SPI*/
	SET_BIT(SPCR,SPCR_SPE);
	return Local_u8StateErr;
}

/*Send and Receive Function  */
uint8 SPI_u8Transcieve(uint8 copy_u8Data)
{
	SPDR = copy_u8Data;
	while (GET_BIT(SPSR,SPSR_SPIF)==0);
	return SPDR;
}

