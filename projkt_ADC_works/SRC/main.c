/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD.h"




#define ADMUX        (*((volatile uint8_t*)0x27))
#define ADCSRA       (*((volatile uint8_t*)0x26))
#define ADCH         (*((volatile uint8_t*)0x25))
#define ADCL         (*((volatile uint8_t*)0x24))
#define SFIOR        (*((volatile uint8_t*)0x50))
#define ADC_VALUE    (*((volatile uint16_t*)0x24))


int main(void)
{

    LCD_init();

    SET_BIT( ADMUX,  6);
    SET_BIT( ADCSRA, 7);
    SET_BIT( ADCSRA, 0);
    SET_BIT( ADCSRA, 1);
    SET_BIT( ADCSRA, 2);
    while(1){


    	SET_BIT(ADCSRA, 6);
    	while(GET_BIT(ADCSRA, 4) ==0);
    	SET_BIT(ADCSRA, 4);

    	uint8_t adc_val = ADC_VALUE;

    	_delay_ms(500);
    	LCD_set_cursor(0, 0);
    	LCD_write_number(adc_val);

    	}

}







