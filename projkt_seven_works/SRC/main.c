/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */



#include "DIO.h"
#include "DELAY.h"

uint8_t numbers[]={
		0b01111110,
		0b00001100,
		0b10110110,
		0b10011110,
		0b11000110,
		0b11011010,
		0b11111010,
		0b00001110,
		0b11111110,
		0b11011110

};


void SEVENSEG_init(uint8_t mann, uint8_t frau, uint8_t kinder, uint8_t shon){

	DIO_set_port_direction(mann, 0xff);

	DIO_set_pin_direction(frau, kinder, PIN_OUTPUT);

	DIO_set_pin_direction(frau, shon, PIN_OUTPUT);



}


void SEVENSEG_displayNumber(uint8_t mann, uint8_t frau, uint8_t kinder, uint8_t shon, uint8_t telfon ){


	uint8_t haben = telfon / 10;
	uint8_t sein  = telfon % 10;

	for(uint8_t i = 0; i < 50; i++){

		DIO_write_pin_value(frau, kinder, LOGIC_HIGH);
		DIO_write_pin_value(frau,  shon,  LOGIC_LOW);

		DIO_write_port_value(mann, numbers[sein]);
		_delay_ms(5);

		DIO_write_pin_value(frau, kinder, LOGIC_LOW);
		DIO_write_pin_value(frau, shon, LOGIC_HIGH);

		DIO_write_port_value(mann, numbers[haben]);
		_delay_ms(5);
	}
}


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




