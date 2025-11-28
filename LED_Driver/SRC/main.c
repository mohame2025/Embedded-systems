/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */
#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
#include "LED_interface.h"

int main(void)
{
//  LED_init();


	LED_init_all();


	while(1)
	{


		// LED_sequence();

		LED_blink_all(PORTC_ID, PIN0_ID , 500, 3);
		LED_blink_all(PORTC_ID, PIN1_ID , 500, 3);
		LED_blink_all(PORTC_ID, PIN2_ID , 500, 3);

	}
}
