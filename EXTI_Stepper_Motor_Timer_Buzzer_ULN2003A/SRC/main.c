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
#include "STEPPER_interface.h"


#define BUZZER_PORT   PORTD_ID
#define BUZZER_PIN    PIN0_ID
#define  MOVE_STEPS      50


#define TCCR0       (*((volatile uint8_t*)0x53))
#define TCNT0       (*((volatile uint8_t*)0x52))
#define OCR0        (*((volatile uint8_t*)0x5C))
#define TIFR        (*((volatile uint8_t*)0x58))
#define TIMSK       (*((volatile uint8_t*)0x59))


volatile uint8_t flag_CW = 0;
volatile uint8_t flag_CCW = 0;
volatile uint16_t steps_done = 0;
volatile uint8_t moving = 0;

void ISR_BUTTON_A(void);
void ISR_BUTTON_B(void);

void __vector_11(void) __attribute__((signal));  // Timer0 OVF ISR

void beep(void);

int main(void)
{

	DIO_set_pin_direction(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);

	Stepper_init();

	TCCR0 = (1 << 0) | (1 << 2);
	TIMSK |= (1 << 0);  //Enable Timer0 overflow interrupts


    EXTI_enable(INT0, SENSE_FALLING_EDGE, ISR_BUTTON_A);
    EXTI_enable(INT1, SENSE_FALLING_EDGE, ISR_BUTTON_B);

    GI_enable();

	while(1)
	{

		if(flag_CW && ! moving){
		moving = 1;
		steps_done = 0;
		flag_CW = 0;
		}


		if(flag_CCW && ! moving){
			moving = 2;
		    steps_done = 0;
			flag_CW = 0;

		}
	}
	return 0;
}

// External interrupts
void ISR_BUTTON_A(void)
{
	flag_CW = 1;

}

void ISR_BUTTON_B(void)
{

	flag_CCW = 1;
}


// Timer overflow ISR


void __vector_11(void){

	static uint16_t tick = 0;
	   tick++;

     if(tick >= 8){
	   tick = 0;

	 if(moving == 1){
		 Stepper_step_CW(1);
		 steps_done++;

	if(steps_done >= MOVE_STEPS){
		moving = 0;
		beep();
	}
}
	 else if(moving == 2){

		 Stepper_step_CCW(1);
		 		 steps_done++;

		 	if(steps_done >= MOVE_STEPS){
		 		moving = 0;
		 		beep();
		 	}
	    }
	}
}


void beep(void){




  DIO_write_pin_value(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
         _delay_ms(80);
  DIO_write_pin_value(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);

}

