#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_

#include "STD_TYPES.h"

void SEVENSEG_Init(uint8_t port, uint8_t enablePort, uint8_t enablePin1, uint8_t enablePin2);
void SEVENSEG_DisplayNumber(uint8_t port, uint8_t enablePort, uint8_t enablePin1, uint8_t enablePin2, uint8_t number);


#endif

