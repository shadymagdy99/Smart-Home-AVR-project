/*
 * H_Bridge_configuration.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Shady
 */

#ifndef H_BRIDGE_H_BRIDGE_CONFIGURATION_H_
#define H_BRIDGE_H_BRIDGE_CONFIGURATION_H_
/*
 * CONFIGURE IN PINS
 */
#define IN1_PIN   PC3_PIN
#define IN2_PIN   PC4_PIN
#define IN3_PIN   PA5_PIN
#define IN4_PIN   PA6_PIN
/*
 * Enable pin will be connected to PB3_PIN (OC0 PIN) to control motor speed
 */
#define ENABLE_PIN   PB3_PIN


#endif /* H_BRIDGE_H_BRIDGE_CONFIGURATION_H_ */
