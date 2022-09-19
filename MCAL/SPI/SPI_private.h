/*
 * SPI_private.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Shady
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

#define SPCR_REG     (*((volatile u8*)0x2D))
#define SPDR_REG     (*((volatile u8*)0x2F))
#define SPSR_REG     (*((volatile u8*)0x2E))

//SPCR_REG
#define SPIE_BIT       7     //interrupt enable
#define SPE_BIT        6     //SPI enable
#define DORD_BIT       5     //MSB first or LSB first
#define MSTR_BIT       4     //master or slave bit
#define CPOL_BIT       3     //clock polarity
#define CPH_BIT        2     //clock Phase
#define SPR1_BIT       1     //prescaller  1
#define SPR0_BIT       0     //prescaller  0


//SPSR_REG
#define SPIF_BIT       7     //interrupt flag
#define WC0L_BIT       6     //Collesiton flag
#define SPI2X_BIT      0     //douple speed mode
//CLK polarity
#define SPI_CLK_POL_IDLE_HIGH   1
#define SPI_CLK_POL_IDLE_LOW    0
//CLK phase
#define SPI_CLK_PHASE_SAMPLE_FIRST  0
#define SPI_CLK_PHASE_SAMPLE_LAST   1
//Data Order
#define SPI_DATA_ORDER_MSB_FIRST     0
#define SPI_DATA_ORDER_LSB_FIRST     1

//CLK Speed
#define SPI_CLK_SPEED_PRESCALER_NORMAL_4    0
#define SPI_CLK_SPEED_PRESCALER_NORMAL_16   1
#define SPI_CLK_SPEED_PRESCALER_NORMAL_64   2
#define SPI_CLK_SPEED_PRESCALER_NORMAL_128  3


#define SPI_CLK_SPEED_PRESCALER_DOUBLE_2     0
#define SPI_CLK_SPEED_PRESCALER_DOUBLE_8     1
#define SPI_CLK_SPEED_PRESCALER_DOUBLE_32    2
#define SPI_CLK_SPEED_PRESCALER_DOUBLE_64    3

#define SPI_SPEED_MODE_NORMAL_SPEED          0
#define SPI_SPEED_MODE_DOUBLE_SPEED          1

#define SPI_PRESCALER_MASK    0b11111100





#endif /* SPI_SPI_PRIVATE_H_ */
