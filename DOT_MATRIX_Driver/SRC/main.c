/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */
#include "DIO.h"
#include "DELAY.h"
#include "DOT_MATRIX_interface.h"


int main(void)
{
	uint8_t arr[8]=
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


	DOT_MATRIX_Init();

	while(1)
	{
		DOT_MATRIX_displayNumber(arr);

	}
}
