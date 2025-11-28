/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "GI.h"


#define MCUCR   *((volatile uint8_t *)0x55)
#define MCUCSR	*((volatile uint8_t *)0x54)
#define GICR    *((volatile uint8_t *)0x5B)
#define GIFR    *((volatile uint8_t *)0x5A)

void __vector_1(void)__attribute__((signal));


int main(void)
{

	DIO_set_pin_direction(PORTC_ID, PIN2_ID, PIN_OUTPUT);
	DIO_set_pin_direction(PORTC_ID, PIN1_ID, PIN_OUTPUT);

	GI_enable();
	SET_BIT(GICR, 6);
	while(1)
	{
	/*	uint8_t fg_value = GET_BIT(GIFR, 6);
		if(fg_value == 1){

			DIO_toggle_pin_value(PORTC_ID, PIN2_ID);
			SET_BIT(GIFR, 6);
		}
		_delay_ms(500);*/

		DIO_toggle_pin_value(PORTC_ID, PIN1_ID);
		_delay_ms(1000);
	}
}


void __vector_1(void){
	DIO_toggle_pin_value(PORTC_ID, PIN2_ID);
}


