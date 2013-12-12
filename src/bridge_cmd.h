/*
 * bridge_cmd.h
 *
 *  Created on: Dec 12, 2013
 *      Author: kjell
 */

#ifndef BRIDGE_CMD_H_
#define BRIDGE_CMD_H_

#define BR_STATUS			0x00

#define BR_USART_CONNECT	0x00
#define BR_USART_TX			0x11
#define BR_USART_RX			0x12

#define BR_I2C_CONNECT		0x20
#define BR_I2C_TX			0x21
#define BR_I2C_RX			0x22

#define BR_PWM_CONNECT		0x30
#define BR_PWM_ON			0x31
#define BR_PWM_OFF			0x32
#define BR_PWM_DC			0x33
#define BR_PWM_FREQ			0x34



#endif /* BRIDGE_CMD_H_ */
