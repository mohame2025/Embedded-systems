/*
 * DOT_MATRIX_program.c
 *
 *  Created on: Nov 10, 2025
 *      Author: moham
 */



#include "DIO.h"
#include "DELAY.h"

#include "STD_TYPES.h"
#include "DOT_MATRIX_config.h"
#include "DOT_MATRIX_private.h"
#include "DOT_MATRIX_interface.h"






void DOT_MATRIX_Init(void){

for(uint8_t i = 0; i <  DOTMATRIX_COLS; i++){

	DIO_set_pin_direction(DOT_MATRIX_COL_PORT, i, PIN_OUTPUT);
	DIO_set_port_direction(DOT_MATRIX_ROW_PORT, 0xff);


   }

}

void DOT_MATRIX_displayNumber(const uint8_t *pattern){

for(uint8_t col = 0; col <  DOTMATRIX_COLS; col++)
		{
			DIO_write_pin_value(DOT_MATRIX_ROW_PORT, col, LOGIC_HIGH);
			DIO_write_port_value(DOT_MATRIX_ROW_PORT, pattern[col]);
			_delay_ms(2);
			DIO_write_pin_value(DOT_MATRIX_COL_PORT, col, LOGIC_LOW);
		}
}
