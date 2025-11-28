/*
 * STEPPER_private.h
 *
 *  Created on: Nov 25, 2025
 *      Author: moham
 */

#ifndef _STEPPER_PRIVATE_H_
#define _STEPPER_PRIVATE_H_



#define FULL_STEP   1
#define HALF_STEP   2


static const uint8_t  FULL_STEP_SEQUENCE[4][4]={
		                                {1, 0, 1, 0},
		                                {0, 1, 1, 0},
		                                {0, 1, 0, 1},
		                                {1, 0, 0, 1}

};

static const uint8_t HALF_STEP_SEQUENCE[8][4]={
		                               {1, 0, 0, 0},
		                               {1, 1, 0, 0},
									   {0, 1, 0, 0},
									   {0, 1, 1, 0},
									   {0, 0, 1, 0},
									   {0, 0, 1, 1},
									   {0, 0, 0, 1},
									   {1, 0, 0, 1}

};

#endif /* HAL_STEPPER_MOTOR_STEPPER_PRIVATE_H_ */
