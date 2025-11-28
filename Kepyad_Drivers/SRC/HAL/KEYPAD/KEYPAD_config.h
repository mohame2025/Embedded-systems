/*
 * KEYPAD_config.h
 *
 *  Created on: Oct 31, 2025
 *      Author: moham
 */

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#include "DIO.h"

/*-------------------------------
   Keypad connections (4x4)
   Rows → Inputs  (Pull-up)
   Cols → Outputs
--------------------------------*/

// ✅ صفوف الكيباد (Rows)
#define KEYPAD_PORT_ROW   PORTB_ID
#define KEYPAD_ROW0_PIN   PIN0_ID
#define KEYPAD_ROW1_PIN   PIN1_ID
#define KEYPAD_ROW2_PIN   PIN2_ID
#define KEYPAD_ROW3_PIN   PIN3_ID

// ✅ أعمدة الكيباد (Columns)
#define KEYPAD_PORT_COL   PORTD_ID
#define KEYPAD_COL0_PIN   PIN4_ID
#define KEYPAD_COL1_PIN   PIN5_ID
#define KEYPAD_COL2_PIN   PIN6_ID
#define KEYPAD_COL3_PIN   PIN7_ID

#endif /* KEYPAD_CONFIG_H */
