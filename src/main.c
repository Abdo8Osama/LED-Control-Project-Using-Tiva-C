/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 2022                               */
/* File_Name : LED_Control_mainApp_C                     */
/*********************************************************/

/******************************************************************************/
/** This program Controls blinking LED for a user-defined ON and OFF periods **/
/******************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"TIMER_interface.h"
#include"NVIC_interface.h"

volatile u32 Ton = 0 ;
volatile u32 Toff = 0 ;
volatile u8 Led_state = 0 ;
volatile u32 loaded_value =0;

timer_config  t0_config = { TIM_INDIVIDUAL_A_PERIODIC , A , DOWN_COUNT , DISABLED , DISABLED
		, DISABLED , NO_WAIT , LOW_DRIVEN , NO_HALT , ADC_TRIG_DISABLED , NON_INVERT , BOTH_EDGE
		, NEXT_CYCLE , NEXT_CYCLE} ;

struct PIN_CONFIG PA0 ={PIN0  , PORTA , DIO , OUTPUT , LOW , 99 , _2MA , LOW };

 void blinkLed (u32 ON_Time_sec ,u32 OFF_Time_sec)
 {
	 /* blinkLed function is an App layer function that takes as an input from the user
		a specific ON time and OFF time in seconds .

		It lights the LED for the given ON time, and dim it for the given OFF time.
		This function implements implicitly the PWM module using Timer Overflow.
	 */
	 Ton  = (ON_Time_sec * 16000000 );
	 Toff = (OFF_Time_sec * 16000000 );

		TIM_setLoadeValue_TA(TIM0_Wide , Toff);
		Led_state = 0 ;
 }

void LED_Control_Tout_Isr()
{
	/*Toggle Led State */
	DIO_toggle_Pin (PORTA ,PIN0);
	Led_state ^= 1 ;

	if(Led_state == 1)
	{
		loaded_value = Ton ;
	}else{
		loaded_value = Toff ;
	}
	/*LOAD TIMER WITH NEW VALUE*/
	TIM_setLoadeValue_TA(TIM0_Wide , loaded_value);
}



 int main(void)
 {
	 WTIMER_enableClock(WTIMER_0);
	 /*ENABL GPIO CLOCK AND TIMER CLOCK*/
	 GPIO_enableClock(PORTA);

	 /*initialise GPIO Pin as output */
	 DIO_init_port( &PA0);
	 /*initialise Interrupt Driver for Timer overflow*/
	 NVIC_enableInterrupt(Wide_Timer_0A);

	 /*SET TIMER CALLBACK*/
	 WTIMER0A_SetCallBack( LED_Control_Tout_Isr);
	 /*initialise Timer Driver to generate pwm signal */
	 TIM_init(&t0_config  , TIM0_Wide);
	 TIM_enableTimeOutInterrupt(TIM0_Wide , A);

	/*Ask the User to enter the off and on times in sec*/
	 /*pass the on and off time to the timer to start counting */
	 blinkLed (1 , 1);

	 /*START COUNTING ...*/
	 TIM_startCount( TIM0_Wide,  TIM_INDIVIDUAL_A_PERIODIC);

	 /*when overflow happens it will fire interrupt and jump to the LED_Control_TIME_OUT_Isr function */

	while(1)
	{
	
	}
return 0 ;
 }
