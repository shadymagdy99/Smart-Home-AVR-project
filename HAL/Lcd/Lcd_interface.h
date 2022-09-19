/*
 * Lcd_interface.h
 *
 *  Created on: Aug 10, 2022
 *      Author: zeyad
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/*****************************************INCLUDES***************************************************************/
#include "StandardTypes.h"
#include "Dio_Interface.h"
#include "Lcd_configuration.h"
#include "util/delay.h"
/****************************************PROTOTYPES***********************************************************************/
void H_Lcd_void_LcdInit(void);
void H_Lcd_void_LcdSendCommand(u8);
void H_Lcd_void_LcdSendCharacter(u8);
void H_Lcd_void_LcdSendString(u8*);
void H_Lcd_void_LcdSendNumber(f64);
void H_Lcd_void_LcdClear(void);
void H_Lcd_void_LcdGoTo(u8,u8);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
