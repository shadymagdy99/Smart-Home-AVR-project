/*
 * EEPROM_prg.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Shady_Magdy
 */
#include "StandardTypes.h"
#include "TWI_int.h"
#include "EEPROM_priv.h"
#include "EEPROM_config.h"
#include "EEPROM_int.h"

void H_EEPROM_void_Init(void)
{
  M_TWI_void_Init();
}

u8 H_EEPROM_u8_WriteByte(u16 copy_u16Add , u8 copy_u8Byte)
{
	u8 _3MSB  ;
	u8 status ;
  //step 1 : send start
	M_TWI_void_sendStart();
  // step 2 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_START_SUCCESS != status )
	{
		return 0;
	}
  // step 3 : send A + 3MSB of byte address + w
	_3MSB =  (u8)((copy_u16Add & 0x0700)>> 7) ;
	M_TWI_void_SendByte( _3MSB | 0xA0);
  // step 4 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_SLA_W_ACK  != status )
	{
		return 0;
	}
  // step 5 :  send the rest of Byte address
	M_TWI_void_SendByte((u8)copy_u16Add);
  // step 6 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_DATA_SENT_ACK  != status )
	{
		return 0;
	}
  // step 7 : send data byte to be written in EEPROM
	M_TWI_void_SendByte(copy_u8Byte);
  //step 8 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_DATA_SENT_ACK  != status )
	{
		return 0;
	}
 // step 9 : send stop
	M_TWI_void_sendStop();
	return 1;
}
u8 H_EEPROM_u8_ReadByte(u16 copy_u16Add ,u8 * ptr)
{
	u8 _3MSB  ;
	u8 status ;
  //step 1 : send start
	M_TWI_void_sendStart();
  // step 2 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_START_SUCCESS != status )
	{
		return 0;
	}
  // step 3 : send A + 3MSB of byte address + w
	_3MSB =  (u8)((copy_u16Add & 0x0700)>> 7) ;
	M_TWI_void_SendByte( _3MSB | 0xA0);
  // step 4 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_SLA_W_ACK  != status )
	{
		return 0;
	}
  // step 5 :  send the rest of Byte address
	M_TWI_void_SendByte((u8)copy_u16Add);
  // step 6 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MT_DATA_SENT_ACK  != status )
	{
		return 0;
	}
     //step 7 : send Repeated Start
	M_TWI_void_sendStart();
	 //step 8 : check status
	status = M_TWI_u8_GetStatus();
	if(TWI_MR_REPEATED_START_SUCCESS != status )
	{
		return 0;
	}
	 //step 9 : send SLA+R
	M_TWI_void_SendByte(0xA0 | 0x01);
	 //step 10: check status

	status = M_TWI_u8_GetStatus();
	if(TWI_MR_SLA_R_ACK != status )
	{
		return 0;
	}
	 //step 11 : receive data from EEPROM
	*ptr = M_TWI_u8_ReceiveByte_ACK();
	 //step 12 : check status

	status = M_TWI_u8_GetStatus();
	if(TWI_MR_DATA_RECEIVE_ACK!= status )
	{
		return 0;
	}
	 //step 13 : send stop
	M_TWI_void_sendStop();
	return 1;

}
