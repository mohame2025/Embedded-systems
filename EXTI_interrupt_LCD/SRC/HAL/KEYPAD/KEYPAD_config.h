/*
 * KEYPAD_config.h
 *
 *  Created on: Oct 31, 2025
 *      Author: moham
 */

#ifndef _KEPYAD_CONFIG_H_
#define _KEPYAD_CONFIG_H_

#include "DIO.h"

/* define keypad port*/
#define KEYPAD_PORT  PORTD_ID

/*define     ROW        AND       COL */

#define KEPYAD_ROW0_PIN     PIN0_ID
#define KEPYAD_ROW1_PIN     PIN1_ID
#define KEPYAD_ROW2_PIN     PIN2_ID
#define KEPYAD_ROW3_PIN     PIN3_ID


#define KEPYAD_COL0_PIN     PIN4_ID
#define KEPYAD_COL1_PIN     PIN5_ID
#define KEPYAD_COL2_PIN     PIN6_ID
#define KEPYAD_COL3_PIN     PIN7_ID


#endif /*_KEYPAD_CONFIG_H_ */
