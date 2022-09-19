/*
 * main.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Shady
 */
/*******************_INCLUDES_************************/
#include "StandardTypes.h"
#include "KeyPad_Interface.h"
#include "Lcd_interface.h"
#include "Led_interface.h"
#include "Timer_0_interface.h"
#include <util/delay.h>
#include "TempSensor_interface.h"
#include "EEPROM_int.h"
#include "H_Bridge_interface.h"
#include "DC_Motor_interface.h"
/*******************_MACROS_********************************/
#define BLOCK_TIME       	 120
#define MOTOR_HALF_SPEED  	 50
#define MOTOR_FULL_SPEED  	 99
#define PASSWORD_DIGITS      4
#define FIRST_TIME_LOGIN     255
#define PASSWORD_SET_FLAG    2
/***************_GLOPAL_VARABLES_***************************/
u8 Local_password[5]={0};
u8 InputPassword[5]={0};
 u8 i = 0;  //password counter
 u8 x=0;    //counter
 u8 c=0;    //counter 2

 u8 check_password = 0;
 u8 wrong_pass_counter=0;
 u8 buff;   //check password buffer
 u8 buff1; //set password buffer
 u8 d =0;  //Wrong Password delay counter
 u8 led_buff =0 ; //leds buffer
 u8 led__color_buff =0;
 u16 temperature_reading = 0; // temperature readings buffer
 /*
  * password_status : these variable will read value from EEPROM
  * if this value = PASSWORD_SET_FLAG : then password is set and it isn't first time to use
  * if this value = FIRST_TIME_LOGIN :  first time to use
  */
 u8 password_status =FIRST_TIME_LOGIN;
u8 data [5] = {0};
int main (void)
{
	//init LED
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	H_Led_void_LedInit(GRN_LED);
	//init KeyPad
     H_KeyPad_void_KeyPadInit();
	//init LCD
	H_Lcd_void_LcdInit();
	//init TEMP Sensor
	H_TempSensor_void_Init();
	//Timer0 initialize
	M_Timer_0_void_Init();
	//H Bridge initialize , set direction as clockwise , DC motor
	H_H_Bride_void_init();
	H_H_Bride_void_SetClockWise();
	H_DC_Motor_void_Init();
	//Initialize EEPROM
	H_EEPROM_void_Init();


	/****************************************************/
	//set password for first time login
	 H_Lcd_void_LcdSendString("Welcome to");
	 H_Lcd_void_LcdGoTo(1,1);
	 H_Lcd_void_LcdSendString("Smart Home");
	 H_Lcd_void_LcdGoTo(2,1);
	 _delay_ms(2000);
	  H_Lcd_void_LcdClear();

	 //H_EEPROM_u8_WriteByte(12, 255);


	  /****************************************************************/
	  /*
	   * check if it is the first time to use : set password and store it in EEPROM
	   * if it isn't first time to use we continue
	   */
	 H_EEPROM_u8_ReadByte(12, &password_status);
	 _delay_ms(100);

	  if(password_status == FIRST_TIME_LOGIN)
	  {
	  //set password for first Time
	 H_Lcd_void_LcdSendString("Please set");
	 H_Lcd_void_LcdGoTo(1,1);
	 H_Lcd_void_LcdSendString("Password");
	 H_Lcd_void_LcdGoTo(2,1);
	 _delay_ms(2000);
	H_Lcd_void_LcdClear();
		while(x<PASSWORD_DIGITS)
		{
			buff1 = H_KeyPad_void_KeyPadRead();
			if(buff1!=0)
			{
		   Local_password[x] = buff1;
		   H_Lcd_void_LcdSendCharacter(Local_password[x]);
			x++;
			}
		}
		//store Password in EEPROM

		H_EEPROM_u8_WriteByte(1, Local_password[0]);
		_delay_ms(100);
		H_EEPROM_u8_WriteByte(3, Local_password[1]);
		_delay_ms(100);
		H_EEPROM_u8_WriteByte(5, Local_password[2]);
		_delay_ms(100);
		H_EEPROM_u8_WriteByte(7, Local_password[3]);
		_delay_ms(100);

		//Flag for setting password stored in EEPROM
		H_EEPROM_u8_WriteByte(12, PASSWORD_SET_FLAG );
		_delay_ms(100);
	  }
	  else if(password_status == PASSWORD_SET_FLAG )
	  {
		  /*
		   * Read stored value from EEPROM
		   * store it in Local password Array
		   */

			H_EEPROM_u8_ReadByte(1, &Local_password[0]);
			_delay_ms(100);
			H_EEPROM_u8_ReadByte(3, &Local_password[1]);
			_delay_ms(100);
			H_EEPROM_u8_ReadByte(5, &Local_password[2]);
			_delay_ms(100);
			H_EEPROM_u8_ReadByte(7, &Local_password[3]);
			_delay_ms(100);

	  }
		H_Lcd_void_LcdClear();
		/*********************************************************/

	//Password check
    do
	{
		H_Lcd_void_LcdSendString("Please Enter");
		H_Lcd_void_LcdGoTo(1,1);
		H_Lcd_void_LcdSendString("Password");
		H_Lcd_void_LcdGoTo(2,1);
		_delay_ms(2000);
		H_Lcd_void_LcdClear();
		while(i<PASSWORD_DIGITS)
		{
			buff = H_KeyPad_void_KeyPadRead();
			if(buff!=0)
			{
		   InputPassword[i] = buff;
           H_Lcd_void_LcdSendCharacter('*');
			i++;
			}
			else{continue;}

		}
		H_Lcd_void_LcdClear();
		i = 0;
		//This Loop checks if the password is correct
		for(c=0;c<PASSWORD_DIGITS;c++)
		{
			if(InputPassword[c]==Local_password[c])
			{
				check_password ++;
			}
			else
			{
				//check_password=0;
			}

		}
		c = 0;
		if(check_password < 4)
		{
			H_Lcd_void_LcdSendString("Wrong password");
			_delay_ms(500);
			H_Lcd_void_LcdClear();
			wrong_pass_counter++;
		}
		if(wrong_pass_counter>3)
		{
			H_Lcd_void_LcdSendString("System Blocked");
			_delay_ms(1000);
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdSendString("Wait 2 minutes");
			_delay_ms(1000);
			H_Lcd_void_LcdClear();
			for(d=0;d< BLOCK_TIME;d++)
			{
				H_Lcd_void_LcdSendNumber(BLOCK_TIME-d);
				H_Lcd_void_LcdSendString("  Sec left");
				_delay_ms(1000);
				H_Lcd_void_LcdClear();
			}
			wrong_pass_counter = 0;
			continue;
		}

	}while((check_password != 4));

/****************************************************************/

	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString("Welcome shady");
	_delay_ms(1000);
	H_Lcd_void_LcdClear();

	/*
	 * Run Time program :
	 * 1- turns on specific led or turns it off during Run time.
	 * 2-Check House Temperature and turns the fan on if needed with specific power
	 *
	 */
	while(1)
	{

    /*
     * Home screen will display always (LEDS ON/OFF)
     */
	H_Lcd_void_LcdSendString("1-LEDS ON");
	H_Lcd_void_LcdGoTo(1,1);
	H_Lcd_void_LcdSendString("2-LEDS OFF");
	H_Lcd_void_LcdGoTo(2,1);
	/*
	 * This section controls LEDS :
	 * user can choose which lED he want to turn ON.
	 * user can choose to turn OFF lEDS.
	 */
	led_buff = H_KeyPad_void_KeyPadRead();
	if(led_buff != 0)
	{
		if(led_buff == '1')
		{
			H_Lcd_void_LcdClear();
			while(1)
			{
			H_Lcd_void_LcdSendString("1-BLU 2-RED");
			H_Lcd_void_LcdGoTo(1,1);
			H_Lcd_void_LcdSendString("3-GREEN");
			H_Lcd_void_LcdGoTo(2,1);
			led__color_buff = H_KeyPad_void_KeyPadRead();
				if(led__color_buff != 0)
				{
				if(led__color_buff == '1')
				{
					H_Led_void_LedOn(BLU_LED);
					H_Lcd_void_LcdClear();
					break;
				}
				else if(led__color_buff == '2')
				{
					H_Led_void_LedOn(RED_LED);
					H_Lcd_void_LcdClear();
					break;
				}
				else if(led__color_buff == '3')
				{
					H_Led_void_LedOn(GRN_LED);
					H_Lcd_void_LcdClear();
					break;
				}
				else{}

			}

		}
	}

		else if (led_buff == '2')
		{
			H_Lcd_void_LcdClear();
			H_Led_void_LedOff(BLU_LED);
			H_Led_void_LedOff(RED_LED);
			H_Led_void_LedOff(GRN_LED);
		}
	}

		/*
		 * This section controls Temperature :
		 * if temp <= 25 ->  DC motor is off
		 * if temp > 25 & temp < 30 -> DC motor is on half speed
		 * if temp >= 30 -> DC motor is ON with full speed
		 *
		 */
	temperature_reading = H_TempSensor_u16_Read();
	if(temperature_reading<=25)
	{
		//H_H_Bride_void_Stop();
		H_DC_Motor_void_DCMode(DC_MOTOR_STOP);


	}
	else if ((temperature_reading>25)&&(temperature_reading>30))
	{

		H_H_Bride_void_SetClockWise();
		H_H_Bride_void_ControlSpeed(MOTOR_HALF_SPEED);


		/*
		 * we will connect PB3 TO RED_LED_PIN JUST for testing
		 */
	}
	else if (temperature_reading>30)
	{
		H_H_Bride_void_SetClockWise();
		H_H_Bride_void_ControlSpeed(MOTOR_FULL_SPEED);




		 /*
		 * we will connect PB3 TO RED_LED_PIN JUST for testing
		 */
	}



	}


	return 0;
}
