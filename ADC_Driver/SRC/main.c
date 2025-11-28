/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: mohamed
 */

#include "DIO.h"
#include "DELAY.h"
#include "ADC.h"


int main(void)
{
DIO_set_pin_direction(PORTC_ID, PIN4_ID, PIN_OUTPUT);
ADC_init(VCC, RIGHT_ADJUST, PRESCALLER_128);


	while(1)
	{
  ADC_start_conversion();

  uint8_t adc_val= ADC_get_analog_value();

  if(adc_val < 512){
	  DIO_write_pin_value(PORTC_ID, PIN4_ID, LOGIC_HIGH);
  }
  else{
	  DIO_write_pin_value(PORTC_ID, PIN4_ID, LOGIC_LOW);
  }
	_delay_ms(100);
	}
}
