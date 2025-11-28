/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
int main(void)
{


	DIO_set_pin_direction(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	DIO_set_pin_direction(PORTC_ID, PIN1_ID, PIN_OUTPUT);
    DIO_set_pin_direction(PORTC_ID, PIN2_ID, PIN_OUTPUT);

	while(1)
	{


	DIO_write_pin_value(PORTC_ID, PIN0_ID, LOGIC_HIGH);
	_delay_ms(500);
	DIO_write_pin_value(PORTC_ID, PIN0_ID, LOGIC_LOW);

	DIO_write_pin_value(PORTC_ID, PIN1_ID, LOGIC_HIGH);
	_delay_ms(500);
	DIO_write_pin_value(PORTC_ID, PIN1_ID, LOGIC_LOW);

	DIO_write_pin_value(PORTC_ID, PIN2_ID, LOGIC_HIGH);
	_delay_ms(500);

	DIO_write_pin_value(PORTC_ID, PIN2_ID, LOGIC_LOW);

	}
	return(0);
}
