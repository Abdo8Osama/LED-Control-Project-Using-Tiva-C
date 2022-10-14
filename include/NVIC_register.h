/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : NVIC_REGISTER_H                           */
/*********************************************************/

/*********************************************************************/
/******** This file defines Register Description for NVIC Driver *********/
/*********************************************************************/

/*Header Guard*/
#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

typedef struct{
	/**/
	volatile u32 NVIC_EN[5] 		;//0x100	
	//volatile u32 NVIC_EN1 		;//0x104
	//volatile u32 NVIC_EN2 		;//0x108
	//volatile u32 NVIC_EN3 		;//0x10C
	//volatile u32 NVIC_EN4 		;//0x110
	
	volatile u32 RESERVED1[27] 	;//0x114 - 0x17C
	
	volatile u32 NVIC_DIS[5]		;//0x180
	//volatile u32 NVIC_DIS1		;//0x184
	//volatile u32 NVIC_DIS2		;//0x188
	//volatile u32 NVIC_DIS3		;//0x18C	
	//volatile u32 NVIC_DIS4		;//0x190
	
	volatile u32 RESERVED2[27] 	;//0x194 - 0x1fC

	volatile u32 NVIC_PEND[5]		;//0x200
	//volatile u32 NVIC_PEND1		;//0x204
	//volatile u32 NVIC_PEND2		;//0x208	
	//volatile u32 NVIC_PEND3		;//0x20C
	//volatile u32 NVIC_PEND4		;//0x210
	
	volatile u32 RESERVED3[27] 	;//0x214 - 0x27C

	volatile u32 NVIC_UNPEND[5] 	;//0x280
	//volatile u32 NVIC_UNPEND1 	;//0x284	
	//volatile u32 NVIC_UNPEND2 	;//0x288
	//volatile u32 NVIC_UNPEND3 	;//0x28C
	//volatile u32 NVIC_UNPEND4 	;//0x290
	
	volatile u32 RESERVED4[27] 	;//0x294 - 0x29C
	
	volatile u32 NVIC_ACTIVE[5] 	;//0x300	
	//volatile u32 NVIC_ACTIVE1 	;//0x304
	//volatile u32 NVIC_ACTIVE2 	;//0x308
	//volatile u32 NVIC_ACTIVE3 	;//0x30C
	//volatile u32 NVIC_ACTIVE4 	;//0x310
	
	volatile u32 RESERVED5[59] 	;//0x314 - 0x39C
	
	volatile u32 NVIC_PRI[35] 		;//0x400
	//volatile u32 NVIC_PRI1 		;//0x404
	//volatile u32 NVIC_PRI2 		;//0x408
	//volatile u32 NVIC_PRI3 		;//0x40C	
	//volatile u32 NVIC_PRI4 		;//0x410
	//volatile u32 NVIC_PRI5 		;//0x414
	//volatile u32 NVIC_PRI6 		;//0x418
	//volatile u32 NVIC_PRI7 		;//0x41C	
	//volatile u32 NVIC_PRI8 		;//0x420
	//volatile u32 NVIC_PRI9 		;//0x424
	//volatile u32 NVIC_PRI10		;//0x428
	//volatile u32 NVIC_PRI11		;//0x42C	
	//volatile u32 NVIC_PRI12		;//0x430
	//volatile u32 NVIC_PRI13		;//0x434
	//volatile u32 NVIC_PRI14		;//0x438
	//volatile u32 NVIC_PRI15		;//0x43C	
	//volatile u32 NVIC_PRI16		;//0x440
	//volatile u32 NVIC_PRI17		;//0x444
	//volatile u32 NVIC_PRI18		;//0x448
	//volatile u32 NVIC_PRI19		;//0x44C	
	//volatile u32 NVIC_PRI20		;//0x450
	//volatile u32 NVIC_PRI21		;//0x454
	//volatile u32 NVIC_PRI22		;//0x458
	//volatile u32 NVIC_PRI23		;//0x45C	
	//volatile u32 NVIC_PRI24		;//0x460
	//volatile u32 NVIC_PRI25		;//0x464
	//volatile u32 NVIC_PRI26		;//0x468
	//volatile u32 NVIC_PRI27		;//0x46C
	//volatile u32 NVIC_PRI28		;//0x470
	//volatile u32 NVIC_PRI29		;//0x474
	//volatile u32 NVIC_PRI30		;//0x478
	//volatile u32 NVIC_PRI31		;//0x47C
	//volatile u32 NVIC_PRI32		;//0x480
	//volatile u32 NVIC_PRI33		;//0x484
	//volatile u32 NVIC_PRI34		;//0x488
	
	volatile u32 RESERVED6[669] ;//0x48C - 0xEFC
	
	volatile u32 NVIC_SWTRIG 	;//0xF00
		                                                                                                
}NVIC;                                                
                                                       	 
#define M_NVIC ((volatile NVIC*)0xE000E100)            
 

//SCB
typedef struct{

	volatile u32 CPUID 	    ;   //0x000
	volatile u32 INTCTRL 	;   //0x004
	volatile u32 VTABLE 	;   //0x008
	volatile u32 APINT 	    ;   //0x00C
	volatile u32 SYSCTRL 	;   //0x010
	volatile u32 CFGCTRL 	;   //0x014
	volatile u32 SYSPRI1 	;   //0x018
	volatile u32 SYSPRI2 	;   //0x01C
	volatile u32 SYSPRI3 	;   //0x020
	volatile u32 SYSHNDCTRL ;   //0x024
	volatile u32 FAULTSTAT	;   //0x028
	volatile u32 HFAULTSTAT ;   //0x02C
	volatile u32 RESERVED   ;   //0x030
	volatile u32 MMADDR 	;   //0x034
	volatile u32 FAULTADDR  ;   //0x038

}SCB;

#define MSCB ((volatile SCB *) 0xE000ED00 )
 
#endif                                                 
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
