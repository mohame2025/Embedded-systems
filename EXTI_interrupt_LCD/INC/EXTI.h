/*
 * EXIT.h
 *
 *  Created on: Oct 24, 2025
 *      Author: OmarAbdulqadir
 */

#ifndef _EXIT_H_
#define _EXIT_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define INT0	0
#define INT1	1
#define INT2	2


#define SENSE_LOW				0
#define SENSE_LVL_CHANGE		1
#define SENSE_FALLING_EDGE		2
#define	SENSE_RISING_EDGE		3

void EXTI_enable(uint8_t int_num, uint8_t sense_lvl, void(*clbk)(void));
void EXTI_disable(uint8_t int_num);

#endif /* INC_EXIT_H_ */
