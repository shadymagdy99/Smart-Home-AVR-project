/*
 * Lcd_program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: zeyad
 */

#include "Lcd_interface.h"
#include "Lcd_private.h"



void H_Lcd_void_LcdInit(void)
{
#if LCD_MODE == _8_BIT_MODE
	M_Dio_Void_PinMode(LCD_D0_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D1_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D2_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D3_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_D7_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_Rs_PIN,OUTPUT);
	M_Dio_Void_PinMode(LCD_En_PIN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_void_LcdSendCommand(LCD_8_BIT_MODE_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE == _4_BIT_MODE
	M_Dio_void_PinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D7_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_Rs_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_En_PIN,OUTPUT);
	_delay_ms(1000);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
#endif
}

void H_Lcd_void_LcdSendCommand(u8 Copy_u8_Command)
{
	M_Dio_void_PinWrite(LCD_Rs_PIN,LOW);
#if LCD_MODE == _8_BIT_MODE
	M_Dio_Void_PinWrite(LCD_D0_PIN,Copy_u8_Command >> 0 & 0x01);
	M_Dio_Void_PinWrite(LCD_D1_PIN,Copy_u8_Command >> 1 & 0x01);
	M_Dio_Void_PinWrite(LCD_D2_PIN,Copy_u8_Command >> 2 & 0x01);
	M_Dio_Void_PinWrite(LCD_D3_PIN,Copy_u8_Command >> 3 & 0x01);
	M_Dio_Void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_Void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_Void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_Void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	M_Dio_Void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_Void_PinWrite(LCD_En_PIN,LOW);
#elif LCD_MODE == _4_BIT_MODE
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_En_PIN,LOW);
	Copy_u8_Command = Copy_u8_Command << 4;
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_En_PIN,LOW);
#endif
}

void H_Lcd_void_LcdSendCharacter(u8 Copy_u8_Character)
{
	M_Dio_void_PinWrite(LCD_Rs_PIN,HIGH);
#if LCD_MODE == _8_BIT_MODE
	M_Dio_void_PinWrite(LCD_D0_PIN,Copy_u8_Character >> 0 & 0x01);
	M_Dio_void_PinWrite(LCD_D1_PIN,Copy_u8_Character >> 1 & 0x01);
	M_Dio_void_PinWrite(LCD_D2_PIN,Copy_u8_Character >> 2 & 0x01);
	M_Dio_void_PinWrite(LCD_D3_PIN,Copy_u8_Character >> 3 & 0x01);
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_En_PIN,LOW);
#elif LCD_MODE == _4_BIT_MODE
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_En_PIN,LOW);
	Copy_u8_Character = Copy_u8_Character << 4;
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_En_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_En_PIN,LOW);
#endif
}

void H_Lcd_void_LcdClear(void)
{
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
}

void H_Lcd_void_LcdSendString(u8 *Copy_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Copy_u8_Ptr[Local_u8_Counter]!= '\0')
	{
		H_Lcd_void_LcdSendCharacter(Copy_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}

void H_Lcd_void_LcdSendNumber(f64 Copy_f64_Number)
{
	u8 Local_u8_Integer[11];
	s8 Local_u8_Counter = 0;
	if((u32)Copy_f64_Number<0)
	{
		H_Lcd_void_LcdSendCharacter('-');
		Copy_f64_Number*=-1;
	}
	do
	{
		Local_u8_Integer[Local_u8_Counter] = (u32)Copy_f64_Number%10;
		Copy_f64_Number/=10;
		Local_u8_Counter++;
	}while((u32)Copy_f64_Number !=0);
	Local_u8_Counter--;
	for(;Local_u8_Counter>=0;Local_u8_Counter--)
	{
		H_Lcd_void_LcdSendCharacter(Local_u8_Integer[Local_u8_Counter]+48);
	}
}

void H_Lcd_void_LcdGoTo(u8 Copy_u8_Row,u8 Copy_u8_Col)
{
	u8 Local_u8_arr[2] = {0x80,0xC0};
	H_Lcd_void_LcdSendCommand(Local_u8_arr[Copy_u8_Row]+Copy_u8_Col);
}
