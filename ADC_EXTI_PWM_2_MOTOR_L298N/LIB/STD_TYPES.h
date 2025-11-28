/**
 * @file STD_TYPES.h
 * @author mohamedMahrous ()
 * @brief Standard data types for AVR microcontrollers
 * @version 1.0
 * @date 2025-10-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef STD_types_h
#define STD_types_h

	// Decimal type unsigned value with 8 bits size
	typedef unsigned char uint8_t;
	typedef signed char int8_t;
	typedef unsigned short uint16_t;
	typedef signed short int16_t;
	typedef unsigned long uint32_t;
	typedef signed long int32_t;
	typedef unsigned long long int uint64_t;
	typedef signed long long int int64_t;
	typedef float float32_t;
	typedef double float64_t;

	typedef unsigned char STD_ReturnType;
	
	#define STD_TRUE	1
	#define STD_FALSE	0

	typedef union{
		struct{
			uint8_t BIT0:1;
			uint8_t BIT1:1;
			uint8_t BIT2:1;
			uint8_t BIT3:1;
			uint8_t BIT4:1;
			uint8_t BIT5:1;
			uint8_t BIT6:1;
			uint8_t BIT7:1;
		}BitAccess;
		uint8_t ByteAccess;
	}Register_8Bit;
	
#endif
