/*******************************************************************/
/***               Date: 09/6/2023	Day: Friday		             ***/
/*** 	 TIMER driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 2.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#include "DIO.h"
#include "BIT_MAth.h"
#include "STD_TYPES.h"
#include "TIMER_REGISTER.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

/* Global variables */
/* Timers occupation flag (0: disabled , 1: clear, 2: occupied by delay mS function,
   3: occupied by delay uS function, 4: occupied by counter function, 5: occupied by
   PWM function, 6: occupied by periodic functions)  */

u8 Timerx_occupation_flag[3] = {
		TIMER_ENABLE, TIMER_ENABLE, TIMER_ENABLE};


// Delay variables
static TIMER_t Timer_base[2];

// counter pointers
static u32* counter_ptr[2];

/* General functions Implementation */

void TIMERx_vClear(u8 copy_u8TimerID){
	//
	//
	//



// Disable the timer interrupt

 switch(copy_u8TimerID){

     case TIMER0ID:

    	 /* RESET TIMER CONFIGURATIONS*/
    	 TIMER0_TCCR = TIMER_TCCR_Reset;

    	/* Disable interrupt */
        TIMER_TIMSK &= TIMER0_TIMSK_Reset;
        break;

     case TIMER2ID:
    	// Reset timer configurations
    	TIMER2_TCCR = TIMER_TCCR_Reset;

       // DISABLE interrupt
    	TIMER_TIMSK &= TIMER2_TIMSK_Reset;
    	break;
     default:
    	break;
   }
}


/* Delay functions Implementation */


u8 TIMER_u8Delay_mS(u8 copy_u8TimerID, u16 copy_DelayTime_mS, void(*ptr_caallback)(void) ){


	if((copy_u8TimerID <= TIMER1ID) && (copy_DelayTime_mS >= MIN_TIME) && (copy_DelayTime_mS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Timer_base[copy_u8TimerID]. TIMER_OVF = 0;
			Timer_base[copy_u8TimerID]. TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID]. TIMER_Preload = 0;
		    Timer_base[copy_u8TimerID]. ptr_callback_t = Null;


		    // Raise the occupation flag
		    Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_ms;

		    // caculate number of ticks
		    f64 clc_NO_Tics = ((f64)copy_DelayTime_mS * Mills_to_Micro) / Mills_TickTime;

		    // calculate the rest of the nano second
	        Timer_base[copy_u8TimerID]. TIMER_RestTime = ((copy_DelayTime_mS * Mills_to_Micro) - ((u32)clc_NO_Tics  * Mills_TickTime ));

		   // Calculate the Preload value
		    Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - ((u32)clc_NO_Tics % OVF_MAX));

		    // Calculate the number of OVF
	        Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_DelayTime_mS].TIMER_Preload != 0) ? (((u32)clc_NO_Tics / OVF_MAX) + 1) : ((u32)clc_NO_Tics / OVF_MAX);

	        //Set parameters for callback
	        Timer_base[copy_u8TimerID]. ptr_callback_t = ptr_caallback;



	        if(copy_u8TimerID == TIMER0ID){

	        	//Set preload value
	        	TIMER0_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

	        	//Enable interrupt
	        	 TIMER_TIMSK &= TIMER0_TIMSK_Reset;
	        	 TIMER_TIMSK |= TIMER_ENABLE;

	        	// Enable Global Interrupt
	        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

	        	// Reset timer  configurations
	        	TIMER0_TCCR = TIMER_TCCR_Reset;

	        	// Set prescaller to 1024
	        	TIMER0_TCCR |= TIMER_1024PRE;

	           }
	        else{

	        	// Set preload value

	        	TIMER2_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

	        	//Enable interrupt
	        	TIMER_TIMSK &= TIMER2_TIMSK_Reset;
	        	TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;

	        	// Enable Global Interrupt
	        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

	        	// Reset timer  configurations
	        	TIMER2_TCCR = TIMER_TCCR_Reset;

	        	//Set prescaller to 1024
	        	TIMER2_TCCR |= TIMER_1024PRE;

	           }
	        return 1;}

		    else{
			return 1;}}

	        else{
			return 0;}}


u8 TIMER_u8Delay_uS(u8 copy_u8TimerID, u16 copy_DelayTime_uS, void (*ptr_callback)(void)){

	if((copy_u8TimerID <= TIMER1ID) && (copy_DelayTime_uS >= MIN_TIME) && (copy_DelayTime_uS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){

			Timer_base[copy_u8TimerID]. TIMER_OVF = 0;
			Timer_base[copy_u8TimerID]. TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID]. TIMER_Preload = 0;
		    Timer_base[copy_u8TimerID]. ptr_callback_t = Null;

		    // Raise the occupation flag
		 Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_us;

		  // Calculate the preload value
		 Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - (copy_DelayTime_uS % OVF_MAX));

		 // Calculate the number of OVF
		 Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_u8TimerID].TIMER_Preload != 0)  ? ((copy_DelayTime_uS / OVF_MAX) + 1) : (copy_DelayTime_uS / OVF_MAX);

		 //Set parameters for Callback
		 Timer_base[copy_u8TimerID].ptr_callback_t = ptr_callback;


		 if(copy_u8TimerID == TIMER0ID){

				           //Set preload value
		TIMER0_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

				        	//Enable interrupt
				        	 TIMER_TIMSK &= TIMER0_TIMSK_Reset;
				        	 TIMER_TIMSK |= TIMER_ENABLE;

				        	// Enable Global Interrupt
				        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

				        	// Reset timer  configurations
				        	TIMER0_TCCR = TIMER_TCCR_Reset;

			               //Set Prescaller  to 8, configuration  to (wGM: Normal, COM: Normal)
	                       TIMER0_TCCR |= TIMER_8PRE;
				       }
		 else{

			                // Set preload value

			 	        	TIMER2_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

			 	        	//Enable interrupt
			 	        	TIMER_TIMSK &= TIMER2_TIMSK_Reset;
			 	        	TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;

			 	        	// Enable Global Interrupt
			 	        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

			 	        	// Reset timer  configurations
			 	        	TIMER2_TCCR = TIMER_TCCR_Reset;

			 	        	//Set Prescaller  to 8, configuration  to (wGM: Normal, COM: Normal)
			 	           TIMER2_TCCR |= TIMER2_8PRE;}

		    return 1;}
	  else{

			return 1;}}
	  else{

		   return 0;}}


void TIMER_vDelay_callback(u8 copy_u8TimerID){

	   //Decrement the OVF counter the check the over flow counter if zero then delay in mS is finished
	   if((--(Timer_base[copy_u8TimerID].TIMER_OVF)) == 0){

	   // check the  rest time i uS  in case of mS delay if  zero ther total delay is  finished
	   if((Timer_base[copy_u8TimerID].TIMER_RestTime) == 0){

	   //Clear the ossupation flag
		Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;

		//call the function
		(Timer_base[copy_u8TimerID].ptr_callback_t)();

		//clear timer data
		TIMERx_vClear(copy_u8TimerID);

}
    // I case of false continue the delay  in uS

	   else{

		   // Clear the occupation flag
		   Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;

	      // Call the uS delay fuction

	      TIMER_u8Delay_uS(copy_u8TimerID, (Timer_base[copy_u8TimerID].TIMER_RestTime), (Timer_base[copy_u8TimerID].ptr_callback_t));

   }
}

	// In case of false then decrement the OVF counter and continue
	   else{

	}
}

u8 TIMER_u8CreatePeriodictask(u8 copy_u8TimerID, u16 copy_TimePeriod_mS, void(*ptr_callback)(void) ){


	if((copy_u8TimerID <= TIMER1ID) && (copy_TimePeriod_mS >= MIN_TIME) && (copy_TimePeriod_mS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Timer_base[copy_u8TimerID]. TIMER_OVF      =  TIMER_BOTTOM;
			Timer_base[copy_u8TimerID]. TIMER_RestTime =  TIMER_BOTTOM;
			Timer_base[copy_u8TimerID]. TIMER_Preload  =  TIMER_BOTTOM;
		    Timer_base[copy_u8TimerID]. ptr_callback_t =  Null;

		    //set timer flag to the assign task
		   Timerx_occupation_flag[copy_u8TimerID] = TIMER_Ptask;


           // caculate number of ticks
		    f64 clc_NO_Tics = ((f64)copy_TimePeriod_mS * Mills_to_Micro) / Mills_TickTime;

		    // calculate the rest of the micro second
	        Timer_base[copy_u8TimerID].TIMER_RestTime  = ((copy_TimePeriod_mS * Mills_to_Micro) - ((u32)clc_NO_Tics  * Mills_TickTime ));

		   // Calculate the Preload value
		    Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - ((u32)clc_NO_Tics % OVF_MAX));

		    // Calculate the number of OVF
	        Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_u8TimerID].TIMER_Preload != 0) ? (((u32)clc_NO_Tics / OVF_MAX) + 1) : ((u32)clc_NO_Tics / OVF_MAX);

	        //Set parameters for callback
	        Timer_base[copy_u8TimerID]. ptr_callback_t = ptr_callback;




	        if(copy_u8TimerID == TIMER0ID){

	      	        	//Set preload value
	      	        	TIMER0_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

	      	        	//Enable interrupt
	      	        	 TIMER_TIMSK &= TIMER0_TIMSK_Reset;
	      	        	 TIMER_TIMSK |= TIMER_ENABLE;

	      	        	// Enable Global Interrupt
	      	        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

	      	        	// Reset timer  configurations
	      	        	TIMER0_TCCR = TIMER_TCCR_Reset;

	      	        	// Set prescaller to 1024
	      	        	TIMER0_TCCR |= TIMER_1024PRE;

	      	           }
	      	        else{

	      	        	// Set preload value

	      	        	TIMER2_TCNT = Timer_base[copy_u8TimerID]. TIMER_Preload;

	      	        	//Enable interrupt
	      	        	TIMER_TIMSK &= TIMER2_TIMSK_Reset;
	      	        	TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;

	      	        	// Enable Global Interrupt
	      	        	TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;

	      	        	// Reset timer  configurations
	      	        	TIMER2_TCCR = TIMER_TCCR_Reset;

	      	        	//Set prescaller to 1024
	      	        	TIMER2_TCCR |= TIMER_1024PRE;
	      	   }
	      }

	 }
	      	        return 0;
}


u8 TIMER_u8deleteperiodicTask(u8 copy_u8TimerID){

if(((copy_u8TimerID <= TIMER1ID)&&(Timerx_occupation_flag[copy_u8TimerID] == TIMER_Ptask))){

	Timer_base[copy_u8TimerID].TIMER_OVF = TIMER_BOTTOM;
	Timer_base[copy_u8TimerID].TIMER_RestTime = TIMER_BOTTOM;
	Timer_base[copy_u8TimerID].TIMER_Preload = TIMER_BOTTOM;
	Timer_base[copy_u8TimerID].ptr_callback_t = Null;

	if(copy_u8TimerID == TIMER0ID){
		// Rest timer cofigurations
		TIMER0_TCCR = TIMER_TCCR_Reset;
		// set timer flag to the assign task
		Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;


	}

	else if(copy_u8TimerID == TIMER1ID){


	}

	else{
		// Reset Timer configurations
		TIMER2_TCCR = TIMER_TCCR_Reset;
		// set timer flag to the assign task
		Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;

	}

	TIMERx_vClear(copy_u8TimerID);

	return 1;
}

else{

// return fail code
	return 0;

  }

}


void TIMER_vPtask_callback(u8 copy_u8TimerID){

	// Create a alocal variable to count number of overflows
	static u16 OVF_counter = TIMER_BOTTOM;

	// check if the target number of  overflows is reached
	if(++OVF_counter == Timer_base[copy_u8TimerID].TIMER_OVF){
		if(copy_u8TimerID == TIMER0ID){
			// stop the timer
			TIMER0_TCCR = TIMER_TCCR_Reset;
			// feed the rest time to the counter
			TIMER0_TCNT = (OVF_MAX - Timer_base[copy_u8TimerID].TIMER_RestTime);
			// Set Prescaller to 8, confguration to (WGM: ormal, Com: Normal)
			TIMER0_TCCR |= TIMER_8PRE;

		 }
		else if(copy_u8TimerID == TIMER1ID){

			// feed the rest time to the counter

			//change the prescaled value to us
		}
		else{
			// stop the timer
			TIMER2_TCCR = TIMER_TCCR_Reset;
			// feed the rest time to the counter
			TIMER2_TCNT = (OVF_MAX - Timer_base[copy_u8TimerID].TIMER_RestTime);
			// Set prescaller to 8, confgurtion to (WGM: Normal, COM: Normal)

			}
	}


	else if(OVF_counter > Timer_base[copy_u8TimerID].TIMER_OVF){
		if(copy_u8TimerID == TIMER0ID){

			// stop the timer
		TIMER0_TCCR = TIMER_TCCR_Reset;
		// call the periodic function
		Timer_base[copy_u8TimerID].ptr_callback_t();
		// feed the preload value
		TIMER0_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
		// Set prescaller to 1024, confguration to (WGM: NORMAL, COM: NORMAL)
		TIMER0_TCCR |= TIMER_1024PRE;
		// clear the OVF counter
		OVF_counter = TIMER_BOTTOM;
		}
		else if(copy_u8TimerID == TIMER1ID){
			// call the periodic function
			//feed the preload value
			// Set Prescaller to 1024, confguration to (WGM: NORMAL, COM: NOrmal)
			//clear the ovf counter
		}
		else{
			// stop the timer
			TIMER2_TCCR = TIMER_TCCR_Reset;
			//call the periodic  function
			Timer_base[copy_u8TimerID].ptr_callback_t();
			// feed the preload value
			TIMER2_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
			// Set Prescaller to 1024, confguration to (WGM: Normal, CoM: ormal)
			TIMER2_TCCR |= TIMER2_1024PRE;
			//clear the ovf counter
			OVF_counter = TIMER_BOTTOM;
		}

	}
	else{
	}
}
		/* Counter functions IMplementation*/

u8 TIMER_u8CounterStrart(u8 copy_u8TimerID, u8 copy_u8TimerPrescaler, u32* ptr_return_variable){

	if((copy_u8TimerPrescaler <= TIMER1ID) && (copy_u8TimerPrescaler <= TIMER2_1024PRE) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		//Clear timer data
		Timer_base[copy_u8TimerID]. TIMER_OVF = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID]. TIMER_RestTime = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID]. TIMER_Preload = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID]. ptr_callback_t = Null;

		// Set occupation flag
		Timerx_occupation_flag[copy_u8TimerID] = TIMER_Counter;
		if(copy_u8TimerID == TIMER0ID){
			// Clear timer config

		TIMER0_TCCR =  TIMER_TCCR_Reset;
		// clear counter
		TIMER0_TCNT = TIMER_BOTTOM;
		// Enable Global Interrupt
		TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
		//Set prescaler value
		switch(copy_u8TimerPrescaler){

		case TIMER_1PRE:
		    TIMER0_TCCR = TIMER_1PRE;
		    break;


		case TIMER_8PRE:
			TIMER0_TCCR = TIMER_8PRE;
		    break;

		case TIMER_64PRE:
		    TIMER0_TCCR = TIMER_64PRE;
		     break;


		case TIMER_256PRE:
			  TIMER0_TCCR = TIMER_256PRE;
			  break;

		case TIMER_1024PRE:
			    TIMER0_TCCR = TIMER_1024PRE;
			     break;

		default:
		    break;
		}

	// saving the counter pointer
	counter_ptr[copy_u8TimerID] = ptr_return_variable;
		// Clear the counter variable
		*(counter_ptr[copy_u8TimerID]) = TIMER_BOTTOM;

}
		else if(copy_u8TimerID == TIMER1ID){

		}

		else{
			switch(copy_u8TimerPrescaler){
			// clear timer config
			TIMER2_TCCR = TIMER_TCCR_Reset;
			// clear counter
			TIMER2_TCNT = TIMER_BOTTOM;
			// Enable interrupts
			TIMER_TIMSK &= TIMER2_TIMSK_Reset;
			TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;
			// Enable Global Interrupt
			TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
			// set prescaler value

			case TIMER2_1PRE:
				TIMER2_TCCR = TIMER2_1PRE;
				break;

			case TIMER2_8PRE:
			TIMER2_TCCR = TIMER2_8PRE;
				break;

			case TIMER2_32PRE:
			 TIMER2_TCCR = TIMER2_32PRE;
				break;

			case TIMER2_64PRE:
			 TIMER2_TCCR = TIMER2_64PRE;
				break;

			case TIMER2_128PRE:
			 TIMER2_TCCR = TIMER2_128PRE;
				break;

			case TIMER2_256PRE:
				TIMER2_TCCR = TIMER2_256PRE;
				break;
			case TIMER2_1024PRE:
			TIMER2_TCCR = TIMER2_1024PRE;
				break;
			default:
				break;
			}
		// saving the counter pointer
	counter_ptr[copy_u8TimerID] = ptr_return_variable;
			//clear the counter variable
	*(counter_ptr[copy_u8TimerID]) = TIMER_BOTTOM;

		}
	return 1;
	}
	else{
		return 0;
	}
}

u8 TIMER_u8CounterStop(u8 copy_u8TimerID){

	if((copy_u8TimerID <= TIMER1ID) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Counter)){

		// clear timer data
		Timer_base[copy_u8TimerID].TIMER_OVF = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID].TIMER_RestTime = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID].TIMER_Preload = TIMER_BOTTOM;
		Timer_base[copy_u8TimerID].ptr_callback_t = Null;

		if(copy_u8TimerID == TIMER0ID){
			// Reset timer configurations
			TIMER0_TCCR = TIMER_TCCR_Reset;

			// clear the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Counter;
			// ADD the rest value to the counter variable
			*(counter_ptr[copy_u8TimerID]) +=  TIMER0_TCNT;

			// clear the timer
			TIMER0_TCNT = TIMER_BOTTOM;
			}
		else if(copy_u8TimerID == TIMER1ID){
			}

		else{
			// Reset timer configurations
			TIMER2_TCCR = TIMER_TCCR_Reset;
			//clear the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Counter;
			// Add the rest value to the counter variable
			*(counter_ptr[copy_u8TimerID]) += TIMER2_TCNT;
			// clear the timer
			TIMER2_TCNT = TIMER_BOTTOM;
			}
		TIMERx_vClear(copy_u8TimerID);
		return 1;
		}
	else{
		return 0;
	}

}


void TIMER_vCounter_callback(u8 copy_u8TimerID){

	if(copy_u8TimerID <= TIMER1ID){
		// check which timer called the function
		if(copy_u8TimerID <= TIMER1ID){
		// Add the OVF value to the counter variable
	}

		else{
			// Add the OVF value to the counter variable
			*(counter_ptr[copy_u8TimerID]) += TIMER_MAX;

		}
	}

}



/* PWM functions Implementation*/

u8 TIMER_U8FastPWM(u8 copy_u8TimerID, u8 copy_u8Prescaler, u8 copy_u8DutyCycle){

	if((copy_u8TimerID <= TIMER1ID) && (copy_u8Prescaler <= TIMER2_1024PRE) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
       return 1;
	}
	else{
		return 0;
	}
}

u8 TIMER_u8PhaseCorrectPWM(u8 copy_u8TimerID, u8 copy_u8Prescaler, u8 copy_u8DutyCycle){

	return 0;
}
	/* u8 TIMER_u8pINJOINPWM(u8 copy_u8TimerID, u8 copy_u8pORTnUMBER, u8 copy_u8pinnumber){
	 * return 0;
	 */

u8 TIMER_u8StopPWM(u8 copy_u8TimerID){

	if((copy_u8TimerID <= TIMER2ID) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_PWM)){
		// Clear occupation flag
		Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;
		if(copy_u8TimerID == TIMER0ID){
			// clear timer config
			TIMER0_TCCR = TIMER_TCCR_Reset;
			// Clear counter
			TIMER0_TCNT = TIMER_BOTTOM;
			//Set the OCR value
			TIMER0_OCR = TIMER_BOTTOM;
}

		else if(copy_u8TimerID == TIMER1ID){

}

		else{
			//clear timer config
			TIMER2_TCCR = TIMER_TCCR_Reset;
			//clear counter
			TIMER2_TCNT = TIMER_BOTTOM;
			//set the OCR value
			TIMER2_OCR = TIMER_BOTTOM;
		}
		return 1;
}
	else{
		return 0;
	}

}

void TIMER_vPWM_callback(u8 copy_u8TimerID){

	/*
	 *
	 *
	*/

}

u8 TIMER_u8StartICU(u8 copy_u8Prescaler, f64* ptr_f64Ton, f64* ptr_f64Toff){
/*
 *
 *
 *  */

	return 0;
}

u8 TIMER_u8StopICU(void){
	/*
	 *
	 */
	return 0;

}


void TIMER_vICU_callback(void){
	/*
	 *
	 *
	 */
}

// ISR of Timer/counter0 OVerflow

void __vector_11(void){


	switch(Timerx_occupation_flag[TIMER0ID]){
	case TIMER_Clear:
        TIMERx_vClear(TIMER0ID);
	   break;

	case TIMER_Delay_ms:
	    TIMER_vDelay_callback(TIMER0ID);
	    break;

	case TIMER_Delay_us:
        TIMER_vDelay_callback(TIMER0ID);
       break;


	case TIMER_Counter:
	    TIMER_vCounter_callback(TIMER0ID);
          break;

	case TIMER_PWM:
	    TIMER_vPWM_callback(TIMER0ID);
         break;


	case TIMER_Ptask:
        TIMER_vPtask_callback(TIMER0ID);
        break;

	default:
		break;
   }

}

// ISR of Timer/counter1 OVerflow
void __vector_9(void){


	switch(Timerx_occupation_flag[TIMER1ID]){
	case TIMER_Clear:
        TIMERx_vClear(TIMER1ID);
 	   break;

	case TIMER_Delay_ms:
	    TIMER_vDelay_callback(TIMER1ID);
	    break;

	case TIMER_Delay_us:
        TIMER_vDelay_callback(TIMER1ID);
        break;


	case TIMER_Counter:
	    TIMER_vCounter_callback(TIMER1ID);
        break;

	case TIMER_PWM:
	    TIMER_vPWM_callback(TIMER1ID);
        break;


	case TIMER_Ptask:
        TIMER_vPtask_callback(TIMER1ID);
        break;

	default:
		break;
	   }

}

// ISR of Timer/counter1 Input Capture unit
void __vector_6(void){
	 /*
	  *
	  */

	 }


// ISR of Timer/counter2 OVerflow
void __vector_5(void){
	 /*
	  *
	  */

	switch(Timerx_occupation_flag[TIMER2ID]){
	case TIMER_Clear:
           TIMERx_vClear(TIMER2ID);
 break;

	case TIMER_Delay_ms:
	    TIMER_vDelay_callback(TIMER2ID);
	    break;

	case TIMER_Delay_us:
        TIMER_vDelay_callback(TIMER2ID);
        break;


	case TIMER_Counter:
	    TIMER_vCounter_callback(TIMER2ID);
        break;

	case TIMER_PWM:
	    TIMER_vPWM_callback(TIMER2ID);
        break;


	case TIMER_Ptask:
        TIMER_vPtask_callback(TIMER2ID);
        break;

	default:
		break;
 }
}

