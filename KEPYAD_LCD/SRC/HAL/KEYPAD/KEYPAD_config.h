/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_config.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_ROW_INIT  PIN0_ID
#define KPD_ROW_END   PIN3_ID

#define KPD_COL_INIT  PIN4_ID
#define KPD_COL_END   PIN7_ID

                         /* C0   C1  C2  C3  */
static const uint8_t KPD_u8Buttons[4][4] = {
		                   {'7','8','9','/'}, /* Row0 */
		                   {'4','5','6','*'},
						   {'1','2','3','-'}, /* Row2 */
						   {'?','0','=','+'}  /* Row3 */};


/*
 	 Options:-

 	 	 1-DIO_PORTA
 	 	 2-DIO_PORTB
 	 	 3-DIO_PORTC
 	 	 4-DIO_PORTD

 */

#define KPD_PORT  PORTD_ID

/*
 Options :-

 	 1-DIO_PIN0
 	 2-DIO_PIN1
 	 3-DIO_PIN2
 	 4-DIO_PIN3
 	 5-DIO_PIN4
 	 6-DIO_PIN5
 	 7-DIO_PIN6
 	 8-DIO_PIN7

 * */

#define KPD_R0    PIN0_ID
#define KPD_R1    PIN1_ID
#define KPD_R2    PIN2_ID
#define KPD_R3    PIN3_ID

#define KPD_C0    PIN4_ID
#define KPD_C1    PIN5_ID
#define KPD_C2    PIN6_ID
#define KPD_C3    PIN7_ID

#endif /* KPD_CONFIG_H_ */











/*


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "STD_TYPES.h"



#define KEYPAD_PORT_ROW   PORTB_ID
#define KEYPAD_PORT_COL   PORTD_ID



#endif  KEYPAD_CONFIG_


*/
