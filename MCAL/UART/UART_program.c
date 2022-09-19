/*
 * UART_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Shady
 */

#include "UART_interface.h"
void M_UART_void_Init(void)
{
	//step 1 : config mode as Asynchrounce
	//select register UCSRC
	SET_BIT(UCSRC,URSEL);
	CLR_BIT(UCSRC,UMSEL);

	//step 2 : Enable Tx and Rx
	SET_BIT(UCSRC,TXEN);
	SET_BIT(UCSRC,RXEN);
	//Step 3 : data length
	UCSRC &= UART_DATA_SIZE_MASK;
	UCSRC |= UART_DATA_SIZE_MASK <<1;
    CLR_BIT(UCSRB,UCSZ2);
	//step 4 : config stop bits
    UCSRC &= UART_STOP_BIT_MASK;
    UCSRC |= UART_STOP_BITS <<3;
	//step 5 : config parity bits
    UCSRC &= UART_PARITY_MASK;
    UCSRC |= UART_PARITY_MASK << 4;
	//step 6 : config BR
    // select UBRRH
    CLR_BIT(UBRRH,URSEL);
    UBRRL = UART_BOUD_RATE;

}
void M_UART_void_SendByte(u8 copy_u8_Byte)
{
	while (GET_BIT(UCSRA,UDRE)==0);  //busy waiting
	UDR = copy_u8_Byte;

}
u8 M_UART_u8_RecieveByte(void)
{
	while (GET_BIT(UCSRA,RXC)==0);

	return UDR;
}
void M_UART_void_SendString(u8 *str)
{
	u32 i = 0;
	while (str[i] != '\0')
	{
		M_UART_void_SendByte(str[i]);
		i ++;
	}

}
