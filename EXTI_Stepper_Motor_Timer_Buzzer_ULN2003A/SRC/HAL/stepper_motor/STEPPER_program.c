/*
 * STEPPER_program.c
 *
 *  Created on: Nov 25, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"


void Stepper_init(void){


	DIO_set_pin_direction(STEPPER_PORT, STEPPER_IN1, PIN_OUTPUT);
	DIO_set_pin_direction(STEPPER_PORT, STEPPER_IN2, PIN_OUTPUT);
	DIO_set_pin_direction(STEPPER_PORT, STEPPER_IN3, PIN_OUTPUT);
	DIO_set_pin_direction(STEPPER_PORT, STEPPER_IN4, PIN_OUTPUT);


}


static void Stepper_apply_step(uint8_t step){

	if(STEPPER_MODE == FULL_STEP){

		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN1, FULL_STEP_SEQUENCE[step][0]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN2, FULL_STEP_SEQUENCE[step][1]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN3, FULL_STEP_SEQUENCE[step][2]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN4, FULL_STEP_SEQUENCE[step][3]);
   }


	else if(STEPPER_MODE == HALF_STEP){

		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN1, HALF_STEP_SEQUENCE[step][0]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN2, HALF_STEP_SEQUENCE[step][1]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN3, HALF_STEP_SEQUENCE[step][2]);
		DIO_write_pin_value(STEPPER_PORT, STEPPER_IN4, HALF_STEP_SEQUENCE[step][3]);

		}

}


void Stepper_step_CW(uint16_t steps){


uint8_t max_step = (STEPPER_MODE == FULL_STEP) ? 4 : 8 ;

	for(uint16_t i = 0; i < steps; i++){

		for(uint8_t s = 0; s < max_step; s++){

		Stepper_apply_step(s);

		_delay_ms(STEPPER_SPEED_MS);
	 }
   }
}




void Stepper_step_CCW(uint16_t steps){



	uint8_t max_step = (STEPPER_MODE == FULL_STEP) ? 4 : 8 ;



	for(uint16_t i = 0; i < steps; i++){

		for(uint8_t s = max_step-1; s >= 0; s--){

		Stepper_apply_step(s);

		_delay_ms(STEPPER_SPEED_MS);
	 }
   }
}
