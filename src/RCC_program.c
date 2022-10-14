/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : RCC_PROGRAM_C                             */
/*********************************************************/

/*************************************************************************/
/******** This file  defines Function Definitions for RCC Driver *********/
/*************************************************************************/

/*Included files*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_private.h"
#include"RCC_interface.h"
#include"RCC_register.h"

/*function definitions*/

void GPIO_enableClock(u8 PORT_ID)
{
	SET( RCGCGPIO , PORT_ID);
}

void GPIO_disableClock(u8 PORT_ID)
{
	CLR( RCGCGPIO , PORT_ID);
}

void TIMER_enableClock(u8 TIMER_ID)
{
	SET( RCGCTIMER , TIMER_ID);
}
void TIMER_disableClock(u8 TIMER_ID)
{
	CLR( RCGCTIMER , TIMER_ID);
}

void WTIMER_enableClock(u8 WTIMER_ID)
{
	SET( RCGCWTIMER , WTIMER_ID);
}

void WTIMER_disableClock(u8 WTIMER_ID)
{
	CLR( RCGCWTIMER , WTIMER_ID);
}
