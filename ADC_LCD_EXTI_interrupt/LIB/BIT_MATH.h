/**
 * @file BIT_MATH.h
 * @author MohamedMahrous ()
 * @brief Bit manipulation macros for AVR microcontrollers
 * @version 1.0
 * @date 2025-10-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef BIT_math_h
#define BIT_math_h

	#define  SET_BIT(var, bit_no)         	(var) 	|=	(1			<<	(bit_no))
	#define  RESET_BIT(var, bit_no)       	(var)	&=	(~(1		<<	(bit_no)))
	#define  GET_BIT(var, bit_no)         	((var)	>>	(bit_no)	& 	(1))
	#define  TOGGLE_BIT(var, bit_no)      	(var)	^=	((1)		<<	(bit_no))
	#define  ASSIGN_BIT(var, bit_no, val)	do{ if(val) SET_BIT(var, bit_no); 	\
												else RESET_BIT(var, bit_no);	\
											}while(0);

#endif
