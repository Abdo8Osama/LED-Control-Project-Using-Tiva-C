/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : RCC_INTERFACE_H                           */
/*********************************************************/

/*********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for RCC Driver *********/
/*********************************************************************************************/

/*Header Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define	PORTA	0
#define	PORTB	1
#define	PORTC	2
#define	PORTD	3
#define	PORTE	4
#define	PORTF	5

#define	TIMER_0		0
#define	TIMER_1		1
#define	TIMER_2		2
#define	TIMER_3		3
#define	TIMER_4		4
#define	TIMER_5		5

#define	WTIMER_0		0
#define	WTIMER_1		1
#define	WTIMER_2		2
#define	WTIMER_3		3
#define	WTIMER_4		4
#define	WTIMER_5		5



void GPIO_enableClock(u8 PORT_ID);
void GPIO_disableClock(u8 PORT_ID);

void TIMER_enableClock(u8 TIMER_ID);
void TIMER_disableClock(u8 TIMER_ID);

void WTIMER_enableClock(u8 WTIMER_ID);
void WTIMER_disableClock(u8 WTIMER_ID);

#endif
