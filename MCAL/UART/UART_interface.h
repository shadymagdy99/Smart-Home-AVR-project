/*
 * UART_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Shady
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "UART_private.h"
#include "UART_configuration.h"

void M_UART_void_Init(void);
void M_UART_void_SendByte(u8 copy_u8_Byte);
u8 M_UART_u8_RecieveByte(void);
void M_UART_void_SendString(u8 *str);

#endif /* UART_UART_INTERFACE_H_ */
