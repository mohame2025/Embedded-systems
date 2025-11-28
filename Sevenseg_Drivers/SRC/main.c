/*
 * main.c
 *
 *  Created on: Nov 7, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "SEVENSEG_interface.h"
#include "STD_TYPES.h"

uint8_t count = 0;
uint8_t paused = 0;
int main(void){


	SEVENSEG_init(PORTA_ID, PORTC_ID, PIN6_ID, PIN7_ID);



while(1){

	if(!paused){



	SEVENSEG_displayNumber(PORTA_ID, PORTC_ID, PIN6_ID, PIN7_ID, count);
	_delay_ms(300);

	 count++;

	if(count == 100) count = 0;

		}
    }
	return 0;
}
