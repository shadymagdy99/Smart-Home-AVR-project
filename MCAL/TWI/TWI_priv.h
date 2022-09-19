/*
 * TWI_priv.h
 *
 *  Created on: Aug 29, 2022
 *      Author: aya_enan
 */

#ifndef TWI_TWI_PRIV_H_
#define TWI_TWI_PRIV_H_

#define TWBR_REG (*((volatile u8 *)0x20)) // Bit Rate => speed
#define TWCR_REG (*((volatile u8 *)0x56)) // send start / stop / Enable ACK / Enable Int
#define TWSR_REG (*((volatile u8 *)0x21)) // prescaler (config) , stuts code(read)
#define TWAR_REG (*((volatile u8 *)0x22)) // my Address as a Slave + disable/Enable broadcast response
#define TWDR_REG (*((volatile u8 *)0x23)) // 1 byte data sent/received

//TWCR_REG
#define TWINT_BIT 7  // Interrupt flag
#define TWEA_BIT  6  // ACK enable
#define TWSTA_BIT 5  // send Start
#define TWSTO_BIT 4  // send stop
#define TWWC_BIT  3  // write collision flag
#define TWEN_BIT  2 // Enable TWI
#define TWIE_BIT  0 // Enable Interrupt

//TWSR_REG

#define TWPS1_BIT  1
#define TWPS0_BIT  0

// TWAR_REG
#define TWGCE_BIT 0

#define TWI_STATUS_CODE_MASK 0b11111000
#endif /* TWI_TWI_PRIV_H_ */
