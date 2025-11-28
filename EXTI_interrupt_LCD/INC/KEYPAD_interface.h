/*
 * LCD.h
 *
 *  Created on: Oct 31, 2025
 *      Author: moham
 */

#ifndef _KEPYAD_INTERFACE_H_
#define _KEPYAD_INTERFACE_H_

#include "STD_TYPES.h"

#define NOT_PRESSED  0xFF

/* PROTOTYPE OF THE MAIN FUNCTION*/
void KEYPAD_Init(void);
uint8_t Keypad_u8GetPressedKey(void);


#endif /* INC_KEYPAD_INTERFACE_H_ */
