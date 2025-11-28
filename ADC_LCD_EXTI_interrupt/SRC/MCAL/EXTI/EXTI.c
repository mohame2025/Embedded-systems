/*
 * EXTI.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Mohamed
 */

#include "EXTI.h"
#include "EXTI_REG.h"
#include "EXTI_PRIVATE.h"

void (*int_0_clbk)(void) = NULL;
void (*int_1_clbk)(void) = NULL;
void (*int_2_clbk)(void) = NULL;




void EXTI_enable(uint8_t int_num, uint8_t sense_lvl, void(*clbk)(void))
{
	switch(int_num)
	{
		case INT0:
		{
			SET_BIT(GICR, VIE_INT0);
			int_0_clbk = clbk;
		}break;
		case INT1:
		{
			SET_BIT(GICR, VIE_INT1);
			int_1_clbk = clbk;
		}break;
		case INT2:
		{
			SET_BIT(GICR, VIE_INT2);
			int_2_clbk = clbk;
		}break;
		default: break;
	}
}

void EXTI_disable(uint8_t int_num)
{
	switch(int_num)
	{
		case INT0:
		{
			RESET_BIT(GICR, VIE_INT0);
			int_0_clbk = NULL;
		}break;
		case INT1:
		{
			RESET_BIT(GICR, VIE_INT1);
			int_1_clbk = NULL;
		}break;
		case INT2:
		{
			RESET_BIT(GICR, VIE_INT2);
			int_2_clbk = NULL;
		}break;
		default: break;
	}
}

void __vector_1(void)
{
	if(int_0_clbk != NULL)int_0_clbk();
}

void __vector_2(void)
{
	if(int_1_clbk != NULL)int_1_clbk();
}
