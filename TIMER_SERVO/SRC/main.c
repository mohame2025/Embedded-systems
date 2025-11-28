/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"

#define TCCR1A       (*((volatile uint8_t*)0x4F))
#define TCCR1B       (*((volatile uint8_t*)0x4E))
#define TCNT1L        (*((volatile uint8_t*)0x4C))
#define OCR1AL        (*((volatile uint8_t*)0x4A))
#define OCR1A        (*((volatile uint16_t*)0x4A))
#define OCR1BL        (*((volatile uint8_t*)0x48))
#define OCR1B        (*((volatile uint16_t*)0x48))
#define ICR1L        (*((volatile uint8_t*)0x46))
#define ICR1H        (*((volatile uint8_t*)0x47))
#define TIFR        (*((volatile uint8_t*)0x58))
#define TIMSK       (*((volatile uint8_t*)0x59))

//void __vector_9(void)__attribute__((signal));
int main(void)
{
	DIO_set_pin_direction(PORTD_ID, PIN4_ID, PIN_OUTPUT);

	OCR1A = 20000;
	TCCR1A  =  0b00100011;
	TCCR1B  =  0b00011010;
	while(1)
	{
/* 1000 > 2000 | -90 > 90 */
for(uint16_t angle = 1000; angle <= 2000; angle++){
	while(GET_BIT(TIFR, 2) == 0);
	SET_BIT(TIFR, 2);
	OCR1B = angle;
 }
/* 2000 > 1000 | 90 > -90 */
for(uint16_t angle = 2000; angle <= 1000; angle++){
	while(GET_BIT(TIFR, 2) == 0);
	SET_BIT(TIFR, 2);
	OCR1B = angle;
 }


	}
}

