/*******************************************************************/
/***               Date: 16/11/2025	Day: Friday		             ***/
/*** 	 TIMER driver for the microcontroller ATMega 32			 ***/
/***     Created By: MOHAMED MAHROUS	 Version= 2.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

	/* Note 1: The timer driver works well with the 8MHz crystal, and all
	   functions will not be acurate in case of changing the sys frequency */


/* Timer  IDs */

#define TIMER0ID            0
#define TIMER1ID            2
#define TIMER2ID            1
#define TIMER1ID_OC1B       3


/* Timer 0/1 Prescaler value */

#define  TIMER_1PRE        1
#define  TIMER_8PRE        2
#define  TIMER_64PRE       3
#define  TIMER_256PRE      4
#define  TIMER_1024PRE     5
#define  TIMER_EXT_0       6
#define  TIMER_EXT_1       7

/* Timer 2 presceler  values */

#define  TIMER2_1PRE       1
#define  TIMER2_8PRE       2
#define  TIMER2_32PRE      3
#define  TIMER2_64PRE      4
#define  TIMER2_128PRE     5
#define  TIMER2_256PRE     6
#define  TIMER2_1024PRE    7


/* Delay functions decleration*/

u8 TIMER_u8Delay_mS(u8, u16, void (*ptr_callback)(void) );
u8 TIMER_u8Delay_us(u8, u16, void (*ptr_callback)(void) );

/* Periodic functions decleration */

u8 TIMER_u8CreatePeriodictask(u8, u16, void(*ptr_callback)(void) );
u8 TIMER_u8deletePeriodictask(u8);


/* Counter functions decleration*/

u8 TIMER_u8CounterStart(u8, u8, u32*);
u8 TIMER_u8CounterStop (u8);


/* PWM Functions  decleration*/

u8 TIMER_u8FastPWM(u8, u8, u8);
u8 TIMER_u8PhaseCorrectPWM(u8, u8, u8);
// u8 TIMER_u8PijoinPWM(u8, u8, u8);
u8 TIMER_u8StopPWM(u8);



/* TIMER 1 ICU Functions decleration */


u8 TIMER_u8StartICU(u8, f64*, f64*);
u8 TIMER_u8StopICU(void);

#endif /* end TIMER_INTERFACE_H */
