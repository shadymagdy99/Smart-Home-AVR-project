/*
 * EEPROM_int.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Shady_Magdy
 */

#ifndef EEPROM_EEPROM_INT_H_
#define EEPROM_EEPROM_INT_H_


void H_EEPROM_void_Init(void);
/*
 *   H_EEPROM_u8_WriteByte is used to write 1 byte data to EEPROM address
 *   inputs : Address , data
 *   output : true in case of success , false in case of fail
 */
u8 H_EEPROM_u8_WriteByte(u16 copy_u16Add , u8 copy_u8Byte);
u8 H_EEPROM_u8_ReadByte(u16 copy_u16Add ,u8 * ptr);
#endif /* EEPROM_EEPROM_INT_H_ */
