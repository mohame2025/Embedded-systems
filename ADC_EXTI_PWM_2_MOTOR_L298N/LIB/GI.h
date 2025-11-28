/*
 * GI.h
 *
 *  Created on: Nov 10, 2025
 *      Author: mohamedMahrous
 */

#ifndef _GI_H_
#define _GI_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"


inline void GI_enable(void){

	SET_BIT(*(volatile uint8_t*)0x5f , 7);

}

inline void GI_disable(void){

	RESET_BIT(*(volatile uint8_t*)0x5f , 7);
}


#endif /* LIB_GI_H_ */
