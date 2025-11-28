/*
 * LED_interface.h
 *
 *  Created on: Nov 5, 2025
 *      Author: moham
 */

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "STD_TYPES.h"


void LED_init(uint8_t port, uint8_t pin);
void LED_on(uint8_t port, uint8_t pin);
void LED_off(uint8_t port, uint8_t pin);
void LED_toggle(uint8_t port, uint8_t pin);




void LED_init_all(void);
void LED_sequence(void);
void LED_blink_all(uint8_t port, uint8_t pin, uint8_t delay_ms, uint8_t times );




#endif /* INC_LED_INTERFACE_H_ */
