/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_PROGRAM_C                          */
/*********************************************************/

/**************************************************************************/
/******** This file defines Function Definitions for Timer Driver *********/
/**************************************************************************/

/*Included files*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_interface.h"
#include"TIMER_register.h"
#include"TIMER_private.h"
#include"TIMER_config.h"


/*function definitions*/

void TIM_setMode(TIMER* TIMER_MODULE , u8 TIMER_MODE)
{
	/*SET MODE IN GPTM_CFG REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))
	{TIMER_MODULE->GPTM_CFG =0;}
	else if(TIMER_MODE == TIM_RTC)
	{TIMER_MODULE->GPTM_CFG =1;}
	else{TIMER_MODULE->GPTM_CFG =4;}

	/*SET MODE IN GPTM_AMR REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT))
	{SET(TIMER_MODULE->GPTM_TAMR , TAMR0);
	 CLR(TIMER_MODULE->GPTM_TAMR , TAMR1);}

	else if((TIMER_MODE == TIM_CONCAT_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC))
	{CLR(TIMER_MODULE->GPTM_TAMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_TAMR , TAMR1);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT))
	{SET(TIMER_MODULE->GPTM_TAMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_TAMR , TAMR1);
	 CLR(TIMER_MODULE->GPTM_TAMR , TACMR);
	 CLR(TIMER_MODULE->GPTM_TAMR , TAAMS);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME))
	{SET(TIMER_MODULE->GPTM_TAMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_TAMR , TAMR1);
	 SET(TIMER_MODULE->GPTM_TAMR , TACMR);
	 CLR(TIMER_MODULE->GPTM_TAMR , TAAMS);}

	else if((TIMER_MODE == TIM_CONCAT_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
	{CLR(TIMER_MODULE->GPTM_TAMR , TAAMS);}

	/*SET MODE IN GPTM_BMR REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT))
	{SET(TIMER_MODULE->GPTM_TBMR , TBMR0);
	 CLR(TIMER_MODULE->GPTM_TBMR , TBMR1);}

	else if((TIMER_MODE == TIM_CONCAT_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC))
	{CLR(TIMER_MODULE->GPTM_TBMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_TBMR , TBMR1);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT))
	{SET(TIMER_MODULE->GPTM_TBMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_TBMR , TBMR1);
	 CLR(TIMER_MODULE->GPTM_TBMR , TBCMR);
	 CLR(TIMER_MODULE->GPTM_TBMR , TBAMS);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME))
	{SET(TIMER_MODULE->GPTM_TBMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_TBMR , TBMR1);
	 SET(TIMER_MODULE->GPTM_TBMR , TBCMR);
	 CLR(TIMER_MODULE->GPTM_TBMR , TBAMS);}

	else if((TIMER_MODE == TIM_CONCAT_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
	{CLR(TIMER_MODULE->GPTM_TBMR , TBAMS);}

}

void TIM_init(timer_config * t_config , TIMER* TIMER_MODULE)
{
	/*SET TIMER MODE*/
	TIM_setMode(TIMER_MODULE , t_config->TIMER_MODE);
	
	/*SET COUNTER DIRECTION */
	if(t_config->TIMER_DIRECTION == DOWN_COUNT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TACDIR);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBCDIR);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TACDIR);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBCDIR);break ;
		}

	}
	else if(t_config->TIMER_DIRECTION == UP_COUNT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TACDIR);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBCDIR);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TACDIR);
					   SET(TIMER_MODULE->GPTM_TBMR , TBCDIR);break ;
		}
	}

	/*SET MATCH INTERRUPT ENABLE */
	if(t_config->TIMER_MATCH_INT == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAMIE);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBMIE);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAMIE);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBMIE);break ;
		}

	}
	else if(t_config->TIMER_MATCH_INT == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAMIE);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBMIE);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAMIE);
					   SET(TIMER_MODULE->GPTM_TBMR , TBMIE);break ;
		}
	}
	
	/*SET WAIT TRIG CASE  */
	if(t_config->TIMER_WAIT_TRIG == NO_WAIT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAWOT);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBWOT);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAWOT);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBWOT);break ;
		}

	}
	else if(t_config->TIMER_WAIT_TRIG == WAIT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAWOT);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBWOT);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAWOT);
					   SET(TIMER_MODULE->GPTM_TBMR , TBWOT);break ;
		}
	}
	
	/*SET SNAPSHOT MODDE */
	if(t_config->TIMER_SNAPSHOT_MODE == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TASNAPS);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBSNAPS);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TASNAPS);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBSNAPS);break ;
		}

	}
	else if(t_config->TIMER_SNAPSHOT_MODE == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TASNAPS);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBSNAPS);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TASNAPS);
					   SET(TIMER_MODULE->GPTM_TBMR , TBSNAPS);break ;
		}
	}
	
	/*SET REG UPDATE CASE MODDE */
	if(t_config->REG_UPDATE_CASE == NEXT_CYCLE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAILD);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBILD);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAILD);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBILD);break ;
		}

	}
	else if(t_config->REG_UPDATE_CASE == NEXT_TIMEOUT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAILD);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBILD);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAILD);
					   SET(TIMER_MODULE->GPTM_TBMR , TBILD);break ;
		}
	}
	
	/*SET MATCH UPDATE CASE MODDE */
	if(t_config->MATCH_UPDATE_CASE == NEXT_CYCLE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAMRSU);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBMRSU);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAMRSU);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBMRSU);break ;
		}

	}
	else if(t_config->MATCH_UPDATE_CASE == NEXT_TIMEOUT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAMRSU);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBMRSU);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAMRSU);
					   SET(TIMER_MODULE->GPTM_TBMR , TBMRSU);break ;
		}
	}

	/*SET PWM INTERRUPT MODE */
	if(t_config->TIMER_PWM_INT == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAPWMIE);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBPWMIE);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAPWMIE);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBPWMIE);break ;
		}

	}
	else if(t_config->TIMER_PWM_INT == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAPWMIE);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBPWMIE);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAPWMIE);
					   SET(TIMER_MODULE->GPTM_TBMR , TBPWMIE);break ;
		}
	}

	/*SET PWM INTERRUPT MODE */
	if(t_config->TIMER_PWM_LEGACY == LOW_DRIVEN)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_TAMR , TAPLO);break ;
			case B   : CLR(TIMER_MODULE->GPTM_TBMR , TBPLO);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_TAMR , TAPLO);
					   CLR(TIMER_MODULE->GPTM_TBMR , TBPLO);break ;
		}

	}
	else if(t_config->TIMER_PWM_LEGACY == HIGH_DRIVEN)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_TAMR , TAPLO);break ;
			case B   : SET(TIMER_MODULE->GPTM_TBMR , TBPLO);break ;
			case A_B : SET(TIMER_MODULE->GPTM_TAMR , TAPLO);
					   SET(TIMER_MODULE->GPTM_TBMR , TBPLO);break ;
		}
	}
	
	/*SET OUTPUT TRIGGER */
	if(t_config->TIMER_OUT_TRIG == ADC_TRIG_DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_CTL , TAOTE);break ;
			case B   : CLR(TIMER_MODULE->GPTM_CTL , TBOTE);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_CTL , TAOTE);
					   CLR(TIMER_MODULE->GPTM_CTL , TBOTE);break ;
		}

	}
	else if(t_config->TIMER_OUT_TRIG == ADC_TRIG_ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_CTL , TAOTE);break ;
			case B   : SET(TIMER_MODULE->GPTM_CTL , TBOTE);break ;
			case A_B : SET(TIMER_MODULE->GPTM_CTL , TAOTE);
					   SET(TIMER_MODULE->GPTM_CTL , TBOTE);break ;
		}
	}
	
	/*SET PWM OUTPUT LEVEL */
	if(t_config->TIMER_PWM_OUT_LEVEL == NON_INVERT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_CTL , TAPWML);break ;
			case B   : CLR(TIMER_MODULE->GPTM_CTL , TBPWML);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_CTL , TAPWML);
					   CLR(TIMER_MODULE->GPTM_CTL , TBPWML);break ;
		}

	}
	else if(t_config->TIMER_PWM_OUT_LEVEL == INVERTED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_CTL , TAPWML);break ;
			case B   : SET(TIMER_MODULE->GPTM_CTL , TBPWML);break ;
			case A_B : SET(TIMER_MODULE->GPTM_CTL , TAPWML);
					   SET(TIMER_MODULE->GPTM_CTL , TBPWML);break ;
		}
	}

	/*SET TIMER_STALL */
	if(t_config->TIMER_STALL == NO_HALT)
	{
		CLR(TIMER_MODULE->GPTM_CTL , RTCEN);
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_CTL , TASTALL);break ;
			case B   : CLR(TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_CTL , TASTALL);
					   CLR(TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
		}

	}
	else if(t_config->TIMER_STALL == HALTED)
	{
		SET(TIMER_MODULE->GPTM_CTL , RTCEN);
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_CTL , TASTALL);break ;
			case B   : SET(TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
			case A_B : SET(TIMER_MODULE->GPTM_CTL , TASTALL);
					   SET(TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
		}
	}
	/*SET TIMER EVENT MODE */
	if(t_config->TIMER_EVENT_MODE == POSITIVE_EDGE)
	{
		
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : CLR(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}

	}
	else if(t_config->TIMER_EVENT_MODE == NEGATIVE_EDGE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : SET(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : SET(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}
	else if(t_config->TIMER_EVENT_MODE == BOTH_EDGE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : SET(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : SET(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}
	else
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : CLR(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   CLR(TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}

}
void TIM_startCount(TIMER* TIMER_MODULE , u8 TIMER_MODE)
{
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))
	   	/*START BOTH A AND B*/
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);
	 SET(TIMER_MODULE->GPTM_CTL , TBEN);}
	 
	else if(TIMER_MODE == TIM_RTC)
	{/*******/}

	else if((TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_PWM))
		/*START A TIMER*/
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);}
	
		
	else if((TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_PWM))
			/*START B TIMER*/	
	{SET(TIMER_MODULE->GPTM_CTL , TBEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
		/*START BOTH A AND B */
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);
	 SET(TIMER_MODULE->GPTM_CTL , TBEN);}
			
}

void TIM_stopCount(TIMER* TIMER_MODULE , u8 TIMER_MODE)
{
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))
	   /*STOP BOTH A AND B */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);
	 CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
	 
	else if(TIMER_MODE == TIM_RTC)
	{/*******/}

	else if((TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_PWM))
			/*STOP A */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_PWM))
			   /*STOP B */	
	{CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
	   /*STOP BOTH A AND B */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);
	 CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
}

void TIM_enableTimeOutInterrupt(TIMER* TIMER_MODULE , u8 TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_IMR , TATOIM);break ;
			case B   : SET(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
			case A_B : SET(TIMER_MODULE->GPTM_IMR , TATOIM);
					   SET(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
		}
}

void TIM_disableTimeOutInterrupt(TIMER* TIMER_MODULE , u8 TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_IMR , TATOIM);break ;
			case B   : CLR(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_IMR , TATOIM);
					   CLR(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
		}
}

void TIM_clearTimeOutInterruptFlag(TIMER* TIMER_MODULE , u8 TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_IMR , TATOCINT);break ;
			case B   : SET(TIMER_MODULE->GPTM_IMR , TBTOCINT);break ;
			case A_B : SET(TIMER_MODULE->GPTM_IMR , TATOCINT);
					   SET(TIMER_MODULE->GPTM_IMR , TBTOCINT);break ;
		}
}

void TIM_setLoadeValue_TA(TIMER* TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TAILR = copy_value ;
}

void TIM_setLoadeValue_TB(TIMER* TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TBILR = copy_value ;
}

void TIM_setPrescalValue_TA(TIMER* TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TAPR = prescal_value ;

}
void TIM_setPrescalValue_TB(TIMER* TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TBPR = prescal_value ;

}


void TIM_setMatchValue_TA(TIMER* TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TAMATCHR = copy_value ;
}

void TIM_setMatchValue_TB(TIMER* TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TBMATCHR = copy_value ;
}

void TIM_setPrescalMatchValue_TA(TIMER* TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TAPMR = prescal_value ;

}
void TIM_setPrescalMatchValue_TB(TIMER* TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TBPMR = prescal_value ;

}

void (*WTIMER0A_CallBack) (void);

void WTIMER0A_SetCallBack( void (*ptr) (void) )
{
	WTIMER0A_CallBack = ptr;
}
void WTIMER0A_Handler(void)
{
	WTIMER0A_CallBack();
	TIM_clearTimeOutInterruptFlag(TIM0_Wide , A);
}

