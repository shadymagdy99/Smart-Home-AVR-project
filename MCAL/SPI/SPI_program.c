/*
 * SPI_program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Shady
 */
#include "SPI_interface.h"
#include "SPI_private.h"

void M_SPI_MasterInit(void)
{
	//step 1 : Enable SPI and configure MASTER mode
	SPCR_REG = (1<<SPE_BIT)|(1<<MSTR_BIT);
	//step 2 : config data order
#if(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)
	SET_BIT(SPCR_REG,DORD_BIT);
#elif(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_FIRST)
	CLR_BIT(SPCR_REG,DORD_BIT)
#endif
	//step 3 : config clock polarity
#if(SPI_CLK_POL ==SPI_CLK_POL_IDLE_LOW)
	CLR_BIT(SPCR_REG,CPOL_BIT);
#elif(SPI_CLK_POL ==SPI_CLK_POL_IDLE_HIGH)
	SET_BIT(SPCR_REG,CPOL_BIT);
#endif
	//step 4 : config clock phase
#if(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)
	CLR_BIT(SPCR_REG,CPH_BIT);

#elif(SPI_CLK_PHASE==SPI_CLK_PHASE_SAMPLE_LAS)
	SET_BIT(SPCR_REG,CPH_BIT);
#endif
	//step 5 : normal mode or douple speed mode
#if(SPI_SPEED_MODE == SPI_SPEED_MODE_NORMAL_SPEED)
	CLR_BIT(SPCR_REG,SPI2X_BIT);

#elif(SPI_SPEED_MODE == SPI_SPEED_MODE_NORMAL_SPEED)
	SET_BIT(SPCR_REG,SPI2X_BIT);
#endif

	//step 6 : config clk

    SPCR_REG &= SPI_PRESCALER_MASK;
    SPCR_REG |= SPI_CLK_SPEED;

}
void M_SPI_SlaveInit(void)
{
	//step 1 : Enable SPI and configure SLAVE mode
	SPCR_REG = (1<<SPE_BIT);
	CLR_BIT(SPCR_REG,MSTR_BIT);
	//step 2 : config data order
	#if(SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST)
		SET_BIT(SPCR_REG,DORD_BIT);
	#elif(SPI_DATA_ORDER == SPI_DATA_ORDER_MSB_FIRST)
		CLR_BIT(SPCR_REG,DORD_BIT)
	#endif
		//step 3 : config clock polarity
	#if(SPI_CLK_POL ==SPI_CLK_POL_IDLE_LOW)
		CLR_BIT(SPCR_REG,CPOL_BIT);
	#elif(SPI_CLK_POL ==SPI_CLK_POL_IDLE_HIGH)
		SET_BIT(SPCR_REG,CPOL_BIT);
	#endif
		//step 4 : config clock phase
	#if(SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE_FIRST)
		CLR_BIT(SPCR_REG,CPH_BIT);

	#elif(SPI_CLK_PHASE==SPI_CLK_PHASE_SAMPLE_LAS)
		SET_BIT(SPCR_REG,CPH_BIT);
	#endif
}

u8 M_SPI_u8_TransferByte(u8 copy_u8data)
{
	//1-write data to be transmitted
	SPDR_REG = copy_u8data;
	// 2-wait until transfer is complete
	while(GET_BIT(SPSR_REG,SPIF_BIT)==0);
	//3-return recieved data
	return SPDR_REG;


}

