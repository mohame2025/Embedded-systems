/*
 * STEPPER_interface.h
 *
 *  Created on: Nov 25, 2025
 *      Author: moham
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#include "STD_TYPES.h"


void Stepper_init(void);
void Stepper_step_CW(uint16_t steps);
void Stepper_step_CCW(uint16_t steps);


#endif /* INC_STEPPER_INTERFACE_H_ */
