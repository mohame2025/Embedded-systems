

/*
 * KEYPAD_interface.h
 *
 *  Created on: Nov 7, 2025
 *      Author: Mohamed
 */

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#include "STD_TYPES.h"

#define NOT_PRESSED  0xFF   // القيمة اللي بترجع لما مفيش زر مضغوط

/* ==========[  PROTOTYPES  ]========== */
void KEYPAD_Init(void);
uint8_t Keypad_u8GetPressedKey(void);

#endif /* KEYPAD_INTERFACE_H */
