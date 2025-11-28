

/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_interface.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define NOTPRESSED 0xff

void KPD_Init(void);
 uint8_t  KPD_u8GetPressed( void );

#endif /* KPD_INTERFACE_H_ */










/*
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STD_TYPES.h"

void KEYPAD_Init(void);
uint8_t KEYPAD_Press(void);

#define NOTPRESSED 0xFF

#endif
*/
