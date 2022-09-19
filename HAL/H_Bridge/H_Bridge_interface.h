/*
 * H_Bridge_interface.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Shady
 */

#ifndef H_BRIDGE_H_BRIDGE_INTERFACE_H_
#define H_BRIDGE_H_BRIDGE_INTERFACE_H_
#include "Dio_interface.h"
#include "StandardTypes.h"
#include "H_Bridge_configuration.h"
#include "Timer_0_interface.h"

void H_H_Bride_void_init(void);
void H_H_Bride_void_SetClockWise(void);
void H_H_Bride_void_SetAntiClockWise(void);
void H_H_Bride_void_ControlSpeed(u8 copy_DutyCycle);
void H_H_Bride_void_Stop(void);



#endif /* H_BRIDGE_H_BRIDGE_INTERFACE_H_ */
