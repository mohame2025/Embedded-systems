/*
 * main.c
 *
 *  Created on: ظ ظ¦â€ڈ/ظ،ظ â€ڈ/ظ¢ظ ظ¢ظ¥
 *      Author: orginal
 */

#include "DIO.h"
#include "DELAY.h"


int main(void)

{
 uint8_t arr[]=
		{
				0b00000000,
				0b10111111,
				0b11011111,
				0b11101111,
				0b11101111,
				0b11011111,
				0b10111111,
				0b00000000,
		};



	while(1)
	{
		for(uint8_t i=0;i<8;i++)
					{
						DIO_write_pin_value(PORTC_ID,i,LOGIC_HIGH);
						DIO_write_port_value(PORTD_ID,arr[i]);
						_delay_ms(5);
						DIO_write_pin_value(PORTC_ID,i,LOGIC_LOW);
					}

   }
}
