/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : RCC_REGISTER_H                            */
/*********************************************************/

/**************************************************************************/
/******** This file defines Register Description for RCC Driver *********/
/**************************************************************************/

/*Header Guard*/
#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H

#define RCGCWD 			*((volatile u32*)0x400FE600)
#define RCGCTIMER 		*((volatile u32*)0x400FE604)
#define RCGCGPIO 		*((volatile u32*)0x400FE608)
#define RCGCDMA 	 	*((volatile u32*)0x400FE60C)
#define RCGCHIB 	 	*((volatile u32*)0x400FE614)
#define RCGCUART	 	*((volatile u32*)0x400FE618)
#define RCGCSSI 	 	*((volatile u32*)0x400FE61C)
#define RCGCI2C 	 	*((volatile u32*)0x400FE620)
#define RCGCUSB 	 	*((volatile u32*)0x400FE628)
#define RCGCCAN 	 	*((volatile u32*)0x400FE634)
#define RCGCADC 	 	*((volatile u32*)0x400FE638)
#define RCGCACMP	 	*((volatile u32*)0x400FE63C)
#define RCGCPWM 	 	*((volatile u32*)0x400FE640)
#define RCGCQEI 	 	*((volatile u32*)0x400FE644)
#define RCGCEEPROM 		*((volatile u32*)0x400FE658)
#define RCGCWTIMER 		*((volatile u32*)0x400FE65C)


/*
typedef struct{
	volatile u32 DID0 				;//0x000	
	volatile u32 DID1 				;//0x004
	volatile u32 DC0 				;//0x008	
	volatile u32 DC1 				;//0x010	
	volatile u32 DC2 				;//0x014	
	volatile u32 DC3 				;//0x018	
	volatile u32 DC4 				;//0x01C	
	volatile u32 DC5 				;//0x020	
	volatile u32 DC6 				;//0x024	
	volatile u32 DC7 				;//0x028	
	volatile u32 DC8 				;//0x02C	
	volatile u32 PBORCTL 			;//0x030

	
	volatile u32 SRCR0 				;//0x040
	volatile u32 SRCR1 				;//0x044
	volatile u32 SRCR2 				;//0x048
	
	volatile u32 RIS 				;//0x050	
	volatile u32 IMC 				;//0x054	
	volatile u32 MISC				;//0x058	
	volatile u32 RESC				;//0x05C	
	volatile u32 RCC 				;//0x060

	
	volatile u32 GPIOHBCTL 			;//0x06C
	volatile u32 RCC2 				;//0x070
	
	volatile u32 MOSCCTL 			;//0x07C
	
	
	
	volatile u32 RCGC0 				;//0x100
	volatile u32 RCGC1 				;//0x104
	volatile u32 RCGC2 				;//0x108
	volatile u32 SCGC0 				;//0x110
	volatile u32 SCGC1 				;//0x114
	volatile u32 SCGC2 				;//0x118
	volatile u32 DCGC0 				;//0x120
	volatile u32 DCGC1 				;//0x124
	volatile u32 DCGC2 				;//0x128
	

	volatile u32 DSLPCLKCFG 		;//0x144
	volatile u32 RESERVED5	 		;
	
	volatile u32 SYSPROP 			;//0x14C	
	volatile u32 PIOSCCAL 			;//0x150	
	volatile u32 PIOSCSTAT			;//0x154
	volatile u32 RESERVED6[2] 		;
	
	volatile u32 PLLFREQ0 			;//0x160	
	volatile u32 PLLFREQ1 			;//0x164	
	volatile u32 PLLSTAT 			;//0x168
	volatile u32 RESERVED7[7] 		;

	volatile u32 SLPPWRCFG			;//0x188	
	volatile u32 DSLPPWRCFG 		;//0x18C
	
	volatile u32 DC9 				;//0x190	
	volatile u32 NVMSTAT 			;//0x1A0

	volatile u32 LDOSPCTL 			;//0x1B4	
	volatile u32 LDOSPCAL 			;//0x1B8	
	volatile u32 LDODPCTL 			;//0x1BC	
	volatile u32 LDODPCAL 			;//0x1C0
	
	volatile u32 SDPMST 			;//0x1CC	
	
	volatile u32 PPWD 				;//0x300	
	volatile u32 PPTIMER			;//0x304	
	volatile u32 PPGPIO 			;//0x308	
	volatile u32 PPDMA 				;//0x30C
	volatile u32 PPHIB 				;//0x314
	volatile u32 PPUART				;//0x318
	volatile u32 PPSSI 				;//0x31C
	volatile u32 PPI2C 				;//0x320
	
	volatile u32 PPUSB 				;//0x328
	
	volatile u32 PPCAN 				;//0x334
	volatile u32 PPADC 				;//0x338
	volatile u32 PPACMP				;//0x33C
	volatile u32 PPPWM 				;//0x340
	volatile u32 PPQEI 				;//0x344
	
	volatile u32 PPEEPROM			;//0x358	
	volatile u32 PPWTIMER			;//0x35C
	
	volatile u32 SRWD 				;//0x500	
	volatile u32 SRTIMER 			;//0x504	
	volatile u32 SRGPIO				;//0x508
	volatile u32 SRDMA 				;//0x50C
	volatile u32 SRHIB 				;//0x514
	volatile u32 SRUART				;//0x518
	volatile u32 SRSSI 				;//0x51C
	volatile u32 SRI2C 				;//0x520
	
	volatile u32 SRUSB 				;//0x528
	
	volatile u32 SRCAN 				;//0x534
	volatile u32 SRADC 				;//0x538
	volatile u32 SRACMP				;//0x53C
	volatile u32 SRPWM 				;//0x540
	volatile u32 SRQEI 				;//0x544
	
	volatile u32 SREEPROM			;//0x558	
	volatile u32 SRWTIMER			;//0x55C
	
	volatile u32 RCGCWD 			;//0x600	
	volatile u32 RCGCTIMER 			;//0x604
	volatile u32 RCGCGPIO 			;//0x608	
	volatile u32 RCGCDMA 			;//0x60C	
	volatile u32 RCGCHIB 			;//0x614	
	volatile u32 RCGCUART			;//0x618	
	volatile u32 RCGCSSI 			;//0x61C	
	volatile u32 RCGCI2C 			;//0x620	
	volatile u32 RCGCUSB 			;//0x628
	
	volatile u32 RCGCCAN 			;//0x634	
	volatile u32 RCGCADC 			;//0x638	
	volatile u32 RCGCACMP			;//0x63C	
	volatile u32 RCGCPWM 			;//0x640	
	volatile u32 RCGCQEI 			;//0x644
	
	volatile u32 RCGCEEPROM			;//0x658
	volatile u32 RCGCWTIMER			;//0x65C
	
	volatile u32 SCGCWD 			;//0x700	
	volatile u32 SCGCTIMER			;//0x704	
	volatile u32 SCGCGPIO			;//0x708	
	volatile u32 SCGCDMA 			;//0x70C	
	volatile u32 SCGCHIB 			;//0x714	
	volatile u32 SCGCUART			;//0x718	
	volatile u32 SCGCSSI 			;//0x71C	
	volatile u32 SCGCI2C 			;//0x720
	
	volatile u32 SCGCUSB 			;//0x728
	
	volatile u32 SCGCCAN 			;//0x734	
	volatile u32 SCGCADC 			;//0x738	
	volatile u32 SCGCACMP			;//0x73C	
	volatile u32 SCGCPWM 			;//0x740	
	volatile u32 SCGCQEI 			;//0x744
	
	volatile u32 SCGCEEPROM 		;//0x758	
	volatile u32 SCGCWTIMER 		;//0x75C
	
	volatile u32 DCGCWD 			;//0x800	
	volatile u32 DCGCTIMER 			;//0x804
	volatile u32 DCGCGPIO 			;//0x808	
	volatile u32 DCGCDMA 			;//0x80C	
	volatile u32 DCGCHIB 			;//0x814	
	volatile u32 DCGCUART			;//0x818	
	volatile u32 DCGCSSI 			;//0x81C	
	volatile u32 DCGCI2C 			;//0x820
	
	volatile u32 DCGCUSB 			;//0x828
	
	volatile u32 DCGCCAN 			;//0x834	
	volatile u32 DCGCADC 			;//0x838	
	volatile u32 DCGCACMP			;//0x83C	
	volatile u32 DCGCPWM 			;//0x840	
	volatile u32 DCGCQEI 			;//0x844
	
	volatile u32 DCGCEEPROM 		;//0x858	
	volatile u32 DCGCWTIMER 		;//0x85C
	
	volatile u32 PRWD 				;//0xA00	
	volatile u32 PRTIMER			;//0xA04	
	volatile u32 PRGPIO 			;//0xA08	
	volatile u32 PRDMA 				;//0xA0C
	volatile u32 PRHIB 				;//0xA14
	volatile u32 PRUART				;//0xA18
	volatile u32 PRSSI 				;//0xA1C
	volatile u32 PRI2C 				;//0xA20
	
	volatile u32 PRUSB 				;//0xA28
	
	volatile u32 PRCAN 				;//0xA34
	volatile u32 PRADC 				;//0xA38
	volatile u32 PRACMP				;//0xA3C
	volatile u32 PRPWM 				;//0xA40
	volatile u32 PRQEI 				;//0xA44
	
	volatile u32 PREEPROM 			;//0xA58	
	volatile u32 PRWTIMER 			;//0xA5C	
}SYSCTRL;
#define MSYSCTRL ((volatile SYSCTRL *)0x400FE000)
*/

#endif
