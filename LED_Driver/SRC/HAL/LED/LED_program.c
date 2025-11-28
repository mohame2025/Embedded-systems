/*
 * LED_program.c
 *
 *  Created on: Nov 5, 2025
 *      Author: moham
 */



#include "DIO.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "DELAY.h"

void LED_init(uint8_t port, uint8_t pin){


	DIO_set_pin_direction(port, pin, PIN_OUTPUT);
	DIO_write_pin_value(port, pin,  LOGIC_LOW);
}

void LED_on(uint8_t port, uint8_t pin){
	DIO_write_pin_value(port, pin,  LOGIC_HIGH);

}


void LED_off(uint8_t port, uint8_t pin){
	DIO_write_pin_value(port, pin,  LOGIC_LOW);

}


void LED_toggle(uint8_t port, uint8_t pin){
	DIO_toggle_pin_value(port, pin);
}



void LED_init_all(void){
	LED_init(LED1_PORT, LED1_PIN );
	LED_init(LED2_PORT, LED2_PIN );
	LED_init(LED3_PORT, LED3_PIN );
	/*LED_init(LED4_PORT, LED4_PIN );
	LED_init(LED5_PORT, LED5_PIN );
	LED_init(LED6_PORT, LED6_PIN );
	LED_init(LED7_PORT, LED7_PIN );*/
}



void LED_sequence(void){

		LED_on(LED1_PORT, LED1_PIN);
    	_delay_ms(300);

        LED_on(LED2_PORT, LED2_PIN);
      	_delay_ms(300);

        LED_on(LED3_PORT, LED3_PIN);
      	_delay_ms(300);



/*      	LED_off(LED1_PORT, LED1_PIN);
          	      	_delay_ms(300);

      	LED_off(LED2_PORT, LED2_PIN);
          	      	_delay_ms(300);

      	LED_off(LED3_PORT, LED3_PIN);
      	      	_delay_ms(300);

	*/
}


void LED_blink_all(uint8_t port, uint8_t pin, uint8_t delay_ms, uint8_t times ){

	for(uint8_t i = 0; i < times; i++){

		LED_on(port, pin);
		_delay_ms(delay_ms);
		LED_off(port, pin);
		_delay_ms(delay_ms);
	}


}



