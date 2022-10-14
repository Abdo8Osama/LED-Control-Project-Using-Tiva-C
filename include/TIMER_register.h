/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_REGISTER_H                          */
/*********************************************************/

/**************************************************************************/
/******** This file defines Register Description for Timer Driver *********/
/**************************************************************************/

/*Header Guard*/
#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H


typedef struct{
	/*CONFIGURATION REGISTERS*/
	volatile u32 GPTM_CFG        ;//0x000	
	volatile u32 GPTM_TAMR       ;//0x004
	volatile u32 GPTM_TBMR       ;//0x008
	volatile u32 GPTM_CTL        ;//0x00C
	/*SYNCH REGISTER*/
	volatile u32 GPTM_SYNC       ;//0x010
	volatile u32 RESE_RVED       ;//0x014
	/*iNTERRUPT REGISTERS*/
	volatile u32 GPTM_IMR        ;//0x018
	volatile u32 GPTM_RIS        ;//0x01C
	volatile u32 GPTM_MIS        ;//0x020
	volatile u32 GPTM_ICR        ;//0x024
	/*INTERVAL LOAD REGISTERS*/
	volatile u32 GPTM_TAILR      ;//0x028
	volatile u32 GPTM_TBILR      ;//0x02C
	/*MATTCH AND PRESCALAR REGISTERS*/
	volatile u32 GPTM_TAMATCHR   ;//0x030
	volatile u32 GPTM_TBMATCHR   ;//0x034
	volatile u32 GPTM_TAPR       ;//0x038
	volatile u32 GPTM_TBPR       ;//0x03C
	volatile u32 GPTM_TAPMR      ;//0x040
	volatile u32 GPTM_TBPMR      ;//0x044
	volatile u32 GPTM_TAR        ;//0x048
	volatile u32 GPTM_TBR        ;//0x04C
	                 
	volatile u32 GPTM_TAV        ;//0x050
	volatile u32 GPTM_TBV        ;//0x054
	volatile u32 GPTM_RTCPD      ;//0x058
	volatile u32 GPTM_TAPS       ;//0x05C
	volatile u32 GPTM_TBPS       ;//0x060
	volatile u32 GPTM_TAPV       ;//0x064
	volatile u32 GPTM_TBPV       ;//0x068
	volatile u32 RESE_RVED1 [981] ;
	volatile u32 GPTM_PP         ;//0xFC0

}TIMER;

#define TIMER0_16_32 ((volatile TIMER*)0x40030000)
#define TIMER1_16_32 ((volatile TIMER*)0x40031000)
#define TIMER2_16_32 ((volatile TIMER*)0x40032000)
#define TIMER3_16_32 ((volatile TIMER*)0x40033000)
#define TIMER4_16_32 ((volatile TIMER*)0x40034000)
#define TIMER5_16_32 ((volatile TIMER*)0x40035000)

#define TIMER0_32_64 ((volatile TIMER*)0x40036000)
#define TIMER1_32_64 ((volatile TIMER*)0x40037000)
#define TIMER2_32_64 ((volatile TIMER*)0x4004C000)
#define TIMER3_32_64 ((volatile TIMER*)0x4004D000)
#define TIMER4_32_64 ((volatile TIMER*)0x4004E000)
#define TIMER5_32_64 ((volatile TIMER*)0x4004F000)




#define TIM0 ((volatile TIMER*)0x40030000)
#define TIM1 ((volatile TIMER*)0x40031000)
#define TIM2 ((volatile TIMER*)0x40032000)
#define TIM3 ((volatile TIMER*)0x40033000)
#define TIM4 ((volatile TIMER*)0x40034000)
#define TIM5 ((volatile TIMER*)0x40035000)

#define TIM0_Wide ((volatile TIMER*)0x40036000)
#define TIM1_Wide ((volatile TIMER*)0x40037000)
#define TIM2_Wide ((volatile TIMER*)0x4004C000)
#define TIM3_Wide ((volatile TIMER*)0x4004D000)
#define TIM4_Wide ((volatile TIMER*)0x4004E000)
#define TIM5_Wide ((volatile TIMER*)0x4004F000)


#endif
