/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */



#include "DIO.h"
#include "EXTI.h"
#include "DELAY.h"
#include "GI.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define TCCR0       (*((volatile uint8_t*)0x53))
#define TCNT0       (*((volatile uint8_t*)0x52))
#define OCR0        (*((volatile uint8_t*)0x5C))
#define TIFR        (*((volatile uint8_t*)0x58))
#define TIMSK       (*((volatile uint8_t*)0x59))

#define TOIE0   0

void TIMR_ON(void);
void __vector_11(void) __attribute__((signal));
uint8_t OVF_Counter = 0;

int main(void)
{


	    DIO_set_pin_direction(PORTC_ID, PIN5_ID, PIN_OUTPUT);
		DIO_write_pin_value(PORTC_ID, PIN5_ID, LOGIC_LOW);

	    GI_enable();

	    EXTI_enable(INT0, SENSE_LOW, TIMR_ON);

	while(1)
	{

	}
	  return 0;
}

void TIMR_ON(void)
{
	//_delay_ms(50);
	/* Start the timer */

	SET_BIT(TIMSK, 0);
	TCCR0 = 0x05;
	DIO_write_pin_value(PORTC_ID, PIN5_ID, LOGIC_HIGH);
}

void __vector_11(void)
{
	OVF_Counter++;
	if(OVF_Counter >= 200){

		OVF_Counter = 0;
		TCCR0 = 0;
		DIO_write_pin_value(PORTC_ID, PIN5_ID, LOGIC_LOW);

	}
	//DIO_write_pin_value(PORTC_ID, PIN4_ID, LOGIC_LOW);

}


