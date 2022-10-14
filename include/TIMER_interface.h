/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_INTERFACE_H                          */
/*********************************************************/

/***********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for Timer Driver *********/
/***********************************************************************************************/

#include"TIMER_register.h"
#include"TIMER_private.h"

/*Header Guard*/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


/*GPTMTAMR BITS*/
#define  TAPLO      11
#define  TAMRSU     10
#define  TAPWMIE    9
#define  TAILD      8
#define  TASNAPS    7
#define  TAWOT      6
#define  TAMIE      5
#define  TACDIR		4
#define  TAAMS      3
#define  TACMR      2
#define  TAMR1		1
#define  TAMR0      0
/*GPTMTBMR BITS*/
#define  TBPLO      11
#define  TBMRSU     10
#define  TBPWMIE    9
#define  TBILD      8
#define  TBSNAPS    7
#define  TBWOT      6
#define  TBMIE      5
#define  TBCDIR		4
#define  TBAMS      3
#define  TBCMR      2
#define  TBMR1		1
#define  TBMR0      0
/*GPTMCTL BITS*/
#define  TBPWML     14
#define  TBOTE      13
#define  TBEVENT1   11
#define  TBEVENT0   10
#define  TBSTALL    9
#define  TBEN       8
#define  TAPWML     6
#define  TAOTE      5
#define  RTCEN      4
#define  TAEVENT1   3
#define  TAEVENT0   2
#define  TASTALL    1
#define  TAEN       0
/*INTERRUPT MASK BITS*/
#define TATOIM  0
#define	CAMIM   1
#define	CAEIM   2
#define	RTCIM   3
#define	TAMIM   4
#define TBTOIM  8
#define	CBMIM   9
#define	CBEIM   10
#define	TBMIM   11
#define	WUEIM   16

/*RAW INTERRUPT STATUS BITS*/
#define   TATORIS   0
#define	CAMRIS   1
#define	CAERIS   2
#define	RTCRIS   3
#define	TAMRIS   4
#define   TBTORIS   8
#define	CBMRIS   9
#define	CBERIS   10
#define	TBMRIS   11
#define	WUERIS   16
/*MASKED INTERRUPT STATUS BITS*/
#define	TATOMIS   0
#define	CAMMIS   1
#define	CAEMIS   2
#define	RTCMIS   3
#define	TAMMIS   4
#define	TBTOMIS   8
#define	CBMMIS   9
#define	CBEMIS   10
#define	TBMMIS   11
#define	WUEMIS 16
/*INTERRUPT CLEAR BITS*/
#define	TATOCINT   0
#define	CAMCINT   1
#define	CAECINT   2
#define	RTCCINT   3
#define	TAMCINT   4
#define	TBTOCINT   8
#define	CBMCINT   9
#define	CBECINT   10
#define	TBMCINT   11
#define	WUECINT 16


/*TIMER MODULE TYPE*/

#define		TIM_CONCAT_ONE_SHOT 0
#define		TIM_CONCAT_PERIODIC 1
#define		TIM_CONCAT_CAPTURE_EDGE_COUNT  2
#define		TIM_CONCAT_CAPTURE_EDGE_TIME   3
#define		TIM_CONCAT_PWM 4
#define		TIM_RTC  5
#define		TIM_INDIVIDUAL_A_ONE_SHOT 6
#define		TIM_INDIVIDUAL_A_PERIODIC 7
#define		TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT  8
#define		TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME   9
#define		TIM_INDIVIDUAL_A_PWM 10
#define		TIM_INDIVIDUAL_B_ONE_SHOT 11
#define		TIM_INDIVIDUAL_B_PERIODIC 12
#define		TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT  13
#define		TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME  14
#define		TIM_INDIVIDUAL_B_PWM 15
#define		TIM_INDIVIDUAL_A_B_ONE_SHOT 16
#define		TIM_INDIVIDUAL_A_B_PERIODIC 17
#define		TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT  18
#define		TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME  19
#define		TIM_INDIVIDUAL_A_B_PWM 20



#define		ONE_SHOT 0
#define		PERIODIC 1
#define		CAPTURE_EDGE_COUNT  2
#define		CAPTURE_EDGE_TIME   3
#define		PWM 4

#define		A 0
#define		B 1
#define		A_B  2

#define		DOWN_COUNT 0
#define		UP_COUNT 1

#define		DISABLED 0
#define		ENABLED 1

#define		NEXT_CYCLE 0
#define		NEXT_TIMEOUT 1

#define		NO_WAIT 0
#define		WAIT 1

#define		LOW_DRIVEN 0
#define		HIGH_DRIVEN 1

#define		NO_HALT 0
#define		HALTED 1

#define		ADC_TRIG_DISABLED 0
#define		ADC_TRIG_ENABLED 1

#define		NON_INVERT 0
#define		INVERTED 1

#define		POSITIVE_EDGE 0
#define		NEGATIVE_EDGE 1
#define		BOTH_EDGE 3
#define		RESERVED 2


#define TIM0_Wide ((volatile TIMER*)0x40036000)
#define TIM1_Wide ((volatile TIMER*)0x40037000)
#define TIM2_Wide ((volatile TIMER*)0x4004C000)
#define TIM3_Wide ((volatile TIMER*)0x4004D000)
#define TIM4_Wide ((volatile TIMER*)0x4004E000)
#define TIM5_Wide ((volatile TIMER*)0x4004F000)


/*CONFIGURATION PARAMETERS*/
typedef struct{
	u8    	    TIMER_MODE      ;
	u8			TIMER_A_B		  ;
	u8     	    TIMER_DIRECTION ;

	u8	 		TIMER_MATCH_INT			;
	u8		    TIMER_SNAPSHOT_MODE		;
	u8		    TIMER_PWM_INT				;
	u8		 	TIMER_WAIT_TRIG			;
	u8 			TIMER_PWM_LEGACY			;
	u8		  	TIMER_STALL				;
	u8		 	TIMER_OUT_TRIG			;
	u8	  		TIMER_PWM_OUT_LEVEL		;
	u8			TIMER_EVENT_MODE			;

	u8			REG_UPDATE_CASE	    ;
	u8			MATCH_UPDATE_CASE	;

}timer_config ;


/* functions prototype*/

void TIM_init(timer_config * t_config  , TIMER* TIMER_MODULE);
void TIM_startCount(TIMER* TIMER_MODULE , u8 TIMER_MODE);
void TIM_stopCount(TIMER* TIMER_MODULE , u8 TIMER_MODE);
void TIM_setMode(TIMER* TIMER_MODULE , u8 TIMER_MODE);

void TIMER0A_SetCallBack( void (*ptr) (void) );

void TIM_enableTimeOutInterrupt(TIMER* TIMER_MODULE , u8 TIMER_A_B);
void TIM_disableTimeOutInterrupt(TIMER* TIMER_MODULE , u8 TIMER_A_B);
void TIM_clearTimeOutInterruptFlag(TIMER* TIMER_MODULE , u8 TIMER_A_B);

void TIM_setLoadeValue_TA(TIMER* TIMER_MODULE , u32 copy_value);
void TIM_setLoadeValue_TB(TIMER* TIMER_MODULE , u32 copy_value);
void TIM_setPrescalValue_TA(TIMER* TIMER_MODULE , u16 prescal_value);
void TIM_setPrescalValue_TB(TIMER* TIMER_MODULE , u16 prescal_value);

void TIM_setMatchValue_TA(TIMER* TIMER_MODULE , u32 copy_value);
void TIM_setMatchValue_TB(TIMER* TIMER_MODULE , u32 copy_value);
void TIM_setPrescalMatchValue_TA(TIMER* TIMER_MODULE , u16 prescal_value);
void TIM_setPrescalMatchValue_TB(TIMER* TIMER_MODULE , u16 prescal_value);




#endif
