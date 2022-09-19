/*
 * H_Bridge_program.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Shady
 */
#include "H_Bridge_interface.h"
void H_H_Bride_void_init(void)
{
	M_Dio_void_PinMode(IN1_PIN,OUTPUT);
	M_Dio_void_PinMode(IN2_PIN,OUTPUT);
	M_Dio_void_PinMode(IN3_PIN,OUTPUT);
	M_Dio_void_PinMode(IN4_PIN,OUTPUT);
	/*
	 * Enable pin will be connected to PB3_PIN (OC0 PIN) to control motor speed
	 */
	M_Dio_void_PinMode(ENABLE_PIN,OUTPUT);


}
void H_H_Bride_void_SetAntiClockWise(void)
{
	M_Dio_void_PinWrite(IN1_PIN,HIGH);
	M_Dio_void_PinWrite(IN2_PIN,LOW);
	M_Dio_void_PinWrite(IN3_PIN,HIGH);
	M_Dio_void_PinWrite(IN4_PIN,LOW);

}
void H_H_Bride_void_SetClockWise(void)
{
	M_Dio_void_PinWrite(IN1_PIN,LOW);
	M_Dio_void_PinWrite(IN2_PIN,HIGH);
	M_Dio_void_PinWrite(IN3_PIN,LOW);
	M_Dio_void_PinWrite(IN4_PIN,HIGH);
}
void H_H_Bride_void_ControlSpeed(u8 copy_DutyCycle)
{
	//Initialize timer0 to set Duty cycle to control motor speed
	M_Timer_0_void_Init();
	M_Timer_0_void_SetPhaseCorrectPWM(copy_DutyCycle);
	M_Timer_0_void_Start();

}
void H_H_Bride_void_Stop(void)
{
	M_Dio_void_PinWrite(IN1_PIN,LOW);
	M_Dio_void_PinWrite(IN2_PIN,LOW);
	M_Dio_void_PinWrite(IN3_PIN,LOW);
	M_Dio_void_PinWrite(IN4_PIN,LOW);
}
