/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : NVIC_PROGRAM_C                            */
/*********************************************************/

/*************************************************************************/
/******** This file defines Function Definitions for NVIC Driver *********/
/*************************************************************************/

/*Included files*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"NVIC_private.h"
#include"NVIC_interface.h"
#include"NVIC_register.h"

/*function definitions*/

void NVIC_enableInterrupt(u8 peripheral_ID)
{
	M_NVIC->NVIC_EN[ peripheral_ID / 32 ] = 1 << ( peripheral_ID % 32 ) ;
}
	
void NVIC_disableInterrupt(u8 peripheral_ID)
{
	M_NVIC->NVIC_DIS[ peripheral_ID / 32 ] = 1 << ( peripheral_ID % 32 ) ;
}
	
void NVIC_SetPendingFlag(u8 peripheral_ID)
{
	M_NVIC->NVIC_PEND[ peripheral_ID / 32 ] = 1 << ( peripheral_ID % 32 ) ;
}

void NVIC_ClearPendingFlag(u8 peripheral_ID)
{
	M_NVIC->NVIC_UNPEND[ peripheral_ID / 32 ] = 1 << ( peripheral_ID % 32 ) ;
}

void NVIC_SetPriority(u8 peripheral_ID, u8 peripheral_Periority)
{
	M_NVIC->NVIC_PRI[ peripheral_ID /4] = ( peripheral_Periority << (((peripheral_ID % 4) * 8) + 5)  );
}

void NVIC_SetGroupPriority(u8 group_Periority)
{
	MSCB->APINT = group_Periority ;
}


u8 NVIC_getPendingFlag(u8 peripheral_ID)
{
	u8 state_Pending = GET( (M_NVIC->NVIC_PEND[ peripheral_ID/32 ]) , ( peripheral_ID % 32 ) );
	return state_Pending ;
}

u8 NVIC_getActiveFlag( u8 peripheral_ID )
{
	u8 state_Active = GET( (M_NVIC->NVIC_ACTIVE[ peripheral_ID/32 ]) , ( peripheral_ID % 32 ) );
	return state_Active ;
}

