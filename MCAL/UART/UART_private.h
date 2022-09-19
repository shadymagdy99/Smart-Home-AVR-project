/*
 * UART_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Shady
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

#define UDR    *((volatile u8*)0x2C)
#define UCSRA  *((volatile u8*)0x2B)
#define UCSRB  *((volatile u8*)0x2A)
#define UCSRC  *((volatile u8*)0x40)
#define UBRRH  *((volatile u8*)0x40)
#define UBRRL  *((volatile u8*)0x29)

//UCSRC
#define URSEL   7   //selects between UCSRC AND UBRRH
#define UMSEL   6   //synchronus or Asynchrounus
#define UPM1    5   //parity bit 1
#define UPM0    4   //parity bit 0
#define USBS    3   //stop bit
#define UCSZ1   2   //Data length 1
#define UCSZ0   1   //Data length 0
#define UCPOL   0

//UCSRB
#define RXCIE   7  //RX Complete Interrupt Enable
#define TXCIE   6  //TX  Complete Interrupt Enable
#define UDRIE   5  //DATA register Empty Interrupt Enable
#define RXEN    4  //RX Enable
#define TXEN    3  //TX Enable
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

//UCSRB
#define  RXC     7    //RX copmplete flag
#define  TXC     6    //TX copmplete flag
#define  UDRE    5    //Data Register Empty Flag
#define  FE      4    //Frame Error Flag
#define  DOR     3    //Data Over run flag
#define  PE      2    //Parity Error Flag
#define  U2X     1    //Double speed
#define  MPCM    0


#define UART_DATA_SIZE_MASK   0b11111001
#define UART_PARITY_MASK      0b11001111
#define UART_STOP_BIT_MASK    0b11110111


#define UART_DATA_SIZE_5_BITS      0   // 00
#define UART_DATA_SIZE_6_BITS      1   // 01
#define UART_DATA_SIZE_7_BITS      2   // 10
#define UART_DATA_SIZE_8_BITS      3   // 11


#define UART_PARITY_ODD            3
#define UART_PARITY_EVEN           2
#define UART_PARITY_NO_PARITY      0

#define UART_STOP_BITS_1           0
#define UART_STOP_BITS_2           1

#define  UART_BR_16MHZ_2400        416
#define  UART_BR_16MHZ_9600        103
#define  UART_BR_16MHZ_115200       8

#define  UART_BR_8MHZ_2400        207
#define  UART_BR_8MHZ_9600        51
#define  UART_BR_8MHZ_115200       3


#endif /* UART_UART_PRIVATE_H_ */
