/*
 * SPI_interface.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Shady
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_
#include "StandardTypes.h"
#include "SPI_configuration.h"
#include "BitMath.h"
void M_SPI_MasterInit(void);
void M_SPI_SlaveInit(void);
u8 M_SPI_u8_TransferByte(u8 copy_u8data);




#endif /* SPI_SPI_INTERFACE_H_ */
