/*
 * STEPPER_config.h
 *
 *  Created on: Nov 25, 2025
 *      Author: moham
 */


/************************************************/
/*          Stepper Motor Config File           */
/************************************************/


#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

/* Port المتصل عليه ULN2003 */
#define STEPPER_PORT   PORTC_ID

/* Pins الخاصة بالـ 4 ملفات */
#define STEPPER_IN1     PIN0_ID
#define STEPPER_IN2     PIN1_ID
#define STEPPER_IN3     PIN2_ID
#define STEPPER_IN4     PIN3_ID

/* نوع Step Sequence */
#define STEPPER_MODE   FULL_STEP

/* سرعة الموتور بالمللي ثانية لكل خطوة */
#define STEPPER_SPEED_MS    5






#endif /* HAL_STEPPER_MOTOR_STEPPER_CONFIG_H_ */

