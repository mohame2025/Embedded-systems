/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */
#include "DIO.h"
#include "DELAY.h"
#include "EXTI.h"
#include "GI.h"


void LED_ON(void);
void LED_OFF(void);

int main(void)
{

	DIO_set_pin_direction(PORTC_ID, PIN2_ID, PIN_OUTPUT);
	GI_enable();

	EXTI_enable(INT0, 0, LED_ON);
	EXTI_enable(INT1, 0, LED_OFF);


	while(1)
	{

        }

}


void LED_ON(void)
{
	DIO_write_pin_value(PORTC_ID, PIN2_ID, LOGIC_HIGH);

}


void LED_OFF(void)
{
	DIO_write_pin_value(PORTC_ID, PIN2_ID, LOGIC_LOW);
}
