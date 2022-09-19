/*
 * TWI_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: aya_enan
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_

#define TWI_MT_START_SUCCESS            0x08
#define TWI_MT_REPEATED_START_SUCCESS   0x10
#define TWI_MT_SLA_W_ACK                0x18
#define TWI_MT_SLA_W_NOACK              0x20
#define TWI_MT_DATA_SENT_ACK            0x28
#define TWI_MT_DATA_SENT_NOACK          0x30

#define TWI_MR_START_SUCCESS            0x08
#define TWI_MR_REPEATED_START_SUCCESS   0x10
#define TWI_MR_SLA_R_ACK                0x40
#define TWI_MR_SLA_R_NOACK              0x48
#define TWI_MR_DATA_RECEIVE_ACK         0x50
#define TWI_MT_DATA_RECEIVE_NOACK       0x58

void M_TWI_void_Init(void);
void M_TWI_void_sendStart(void);
void M_TWI_void_sendStop(void);
void M_TWI_void_SendByte(u8 copy_u8Byte);
u8 M_TWI_u8_ReceiveByte_ACK(void);
u8 M_TWI_u8_ReceiveByte_NACK(void);
u8 M_TWI_u8_GetStatus(void );

#endif /* TWI_TWI_INT_H_ */
