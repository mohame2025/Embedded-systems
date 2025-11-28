/*
 * EXTI.h
 *
 *  Created on: Nov 10, 2025
 *      Author: moham
 */

#ifndef _EXTI_H_
#define _EXTI_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define  INT0                  0
#define  INT1                  1
#define  INT2                  2


#define SENSE_LOW              0
#define SENSE_LVL_CHANGE       1
#define SENSE_FALLING_EDGE     2
#define SENSE_RISING_EDGE      3


void EXTI_enable(uint8_t int_num, uint8_t sense_lVl, void(*clbk)(void));
void EXTI_disable(uint8_t int_num);

#endif /* INC_EXTI_H_ */
