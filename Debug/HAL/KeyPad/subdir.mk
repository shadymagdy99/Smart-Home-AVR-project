################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad/KeyPad_program.c 

OBJS += \
./HAL/KeyPad/KeyPad_program.o 

C_DEPS += \
./HAL/KeyPad/KeyPad_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad/%.o: ../HAL/KeyPad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Workspace Eclipse\Project\APP" -I"D:\Workspace Eclipse\Project\HAL\DC_Motor" -I"D:\Workspace Eclipse\Project\HAL\EEPROM" -I"D:\Workspace Eclipse\Project\MCAL\TWI" -I"D:\Workspace Eclipse\Project\HAL\H_Bridge" -I"D:\Workspace Eclipse\Project\HAL" -I"D:\Workspace Eclipse\Project\HAL\KeyPad" -I"D:\Workspace Eclipse\Project\HAL\Lcd" -I"D:\Workspace Eclipse\Project\HAL\Led" -I"D:\Workspace Eclipse\Project\HAL\PushButton" -I"D:\Workspace Eclipse\Project\HAL\TempSensor" -I"D:\Workspace Eclipse\Project\LIB" -I"D:\Workspace Eclipse\Project\MCAL" -I"D:\Workspace Eclipse\Project\MCAL\ADC" -I"D:\Workspace Eclipse\Project\MCAL\Dio" -I"D:\Workspace Eclipse\Project\MCAL\Ext_Int" -I"D:\Workspace Eclipse\Project\MCAL\GIE" -I"D:\Workspace Eclipse\Project\MCAL\SPI" -I"D:\Workspace Eclipse\Project\MCAL\Timer_0" -I"D:\Workspace Eclipse\Project\MCAL\Timer_1" -I"D:\Workspace Eclipse\Project\MCAL\UART" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


