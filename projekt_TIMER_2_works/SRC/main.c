/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */




#include "DIO.h"
#include "DELAY.h"
#include "GI.h"

#define TCCR0       (*((volatile uint8_t*)0x53))
#define TCNT0       (*((volatile uint8_t*)0x52))
#define OCR0        (*((volatile uint8_t*)0x5C))
#define TIFR        (*((volatile uint8_t*)0x58))
#define TIMSK       (*((volatile uint8_t*)0x59))

void __vector_10(void)__attribute__((signal));
void __vector_11(void)__attribute__((signal));

int main(void)
{
	GI_enable();
	DIO_set_pin_direction(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	OCR0 = 50;
	TIMSK = 0x03;
    TCCR0 = 0b01001101;
    while(1)
    {

    }
}

void __vector_10(void)
{
	DIO_write_pin_value(PORTC_ID, PIN0_ID, 0);
}


void __vector_11(void)
{
	DIO_write_pin_value(PORTC_ID, PIN0_ID, 1);
}
