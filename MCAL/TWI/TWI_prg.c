/*
 * TWI_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: aya_enan
 */
#include "StandardTypes.h"
#include "BitMath.h"
#include "TWI_priv.h"
#include "TWI_config.h"
#include "TWI_int.h"

void M_TWI_void_Init(void)
{
   // speed  400 kbits , FCPU = 8 MHz , prescaler =1
	CLR_BIT(TWSR_REG , TWPS0_BIT);
	CLR_BIT(TWSR_REG , TWPS1_BIT);
	TWBR_REG = 0x02;
   // Enable TWI
	SET_BIT(TWCR_REG,TWEN_BIT);
}
void M_TWI_void_sendStart(void)
{
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);
	while(GET_BIT(TWCR_REG ,TWINT_BIT) == 0);// wait until flag is raised
}
void M_TWI_void_sendStop(void)
{
	TWCR_REG  = (1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWSTO_BIT);
	//TWCR_REG  |= (1<<TWINT_BIT) |(1<<TWSTO_BIT);
}
void M_TWI_void_SendByte(u8 copy_u8Byte)
{
  TWDR_REG = copy_u8Byte;
  TWCR_REG  = (1<<TWINT_BIT)|(1<<TWEN_BIT);
  while(GET_BIT(TWCR_REG ,TWINT_BIT) == 0);// wait until flag is raised
}
u8 M_TWI_u8_ReceiveByte_ACK(void)
{
	 //step 1 : clear flag , Enable ACK
	 TWCR_REG  = (1<<TWEA_BIT)|(1<<TWINT_BIT)|(1<<TWEN_BIT);
	 while(GET_BIT(TWCR_REG ,TWINT_BIT) == 0);//step 2: wait until flag is raised
	 // step 3 : return received data
	 return  TWDR_REG;

}
u8 M_TWI_u8_ReceiveByte_NACK(void)
{
	//step 1 : clear flag ,
	 TWCR_REG  = (1<<TWEA_BIT)|(1<<TWINT_BIT);
	 while(GET_BIT(TWCR_REG ,TWINT_BIT) == 0);//step 2: wait until flag is raised
	 // step 3 : return received data
	 return  TWDR_REG;

}
u8 M_TWI_u8_GetStatus(void )
{
	u8 status ;
	status =  (TWI_STATUS_CODE_MASK & TWSR_REG);
	return status;
}
