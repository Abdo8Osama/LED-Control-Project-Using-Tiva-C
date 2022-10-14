/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : NVIC_INTERFACE_H                          */
/*********************************************************/

/**********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for NVIC Driver *********/
/**********************************************************************************************/

/*Header Guard*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define NO_GRP_BIT 		 0x05FA0400//0 bit for group & 3 bit For sub   << 0
#define ONE_GRP_BIT      0x05FA0500//1 bit for group & 2 bit For sub   << 1
#define TWO_GRP_BIT      0x05FA0600//2 bit for group & 1 bit For sub   << 2
#define THREE_GRP_BIT    0x05FA0700//3 bit for group & 0 bit For sub   << 3




#define 	GPIO_Port_A				    0
#define 	GPIO_Port_B                 1
#define 	GPIO_Port_C                 2
#define 	GPIO_Port_D                 3
#define 	GPIO_Port_E                 4
#define 	UART0                       5
#define 	UART1                       6
#define 	SSI0                        7
#define 	I2C0                        8
#define 	PWM0_Fault                  9
#define 	PWM0_Generator_0            10
#define 	PWM0_Generator_1            11
#define 	PWM0_Generator_2            12
#define 	QEI0                        13
#define 	ADC0_Sequence_0             14
#define 	ADC0_Sequence_1             15
#define 	ADC0_Sequence_2             16
#define 	ADC0_Sequence_3             17
#define 	Watchdog_Timers_0_1         18
#define 	Timer_0A                    19
#define 	Timer_0B                    20
#define 	Timer_1A                    21
#define 	Timer_1B                    22
#define 	Timer_2A                    23
#define 	Timer_2B                    24
#define 	Analog_Comparator_0         25
#define 	Analog_Comparator_1         26
#define 	System_Control              28
#define 	Flash_Memory_EEPROM_Control 29
#define 	GPIO_Port_F                 30
#define 	Reserved                    48
#define 	UART2                       33
#define 	SSI1                        34
#define 	Timer_3A                    35
#define 	Timer_3B                    36
#define 	I2C1                        37
#define 	QEI1                        38
#define 	CAN0                        39
#define 	CAN1                        40
#define 	Hibernation_Module          43
#define 	USB                         44
#define 	PWM_Generato_3              45
#define 	mDMA_Software               46
#define 	mDMA_Error                  47
#define 	ADC1_Sequence_0             48
#define 	ADC1_Sequence_1             49
#define 	ADC1_Sequence_2             50
#define 	ADC1_Sequence_3             51
#define 	SSI2                        57
#define 	SSI3                        58
#define 	UART3                       59
#define 	UART4                       60
#define 	UART5                       61
#define 	UART6                       62
#define 	UART7                       63
#define 	I2C2                        68
#define 	I2C3                        69
#define 	Timer_4A                    70
#define 	Timer_4B                    71
#define 	Timer_5A                    92
#define 	Timer_5B                    93
#define 	Wide_Timer_0A               94
#define 	Wide_Timer_0B               95
#define 	Wide_Timer_1A               96
#define 	Wide_Timer_1B               97
#define 	Wide_Timer_2A               98
#define 	Wide_Timer_2B               99
#define 	Wide_Timer_3A               100
#define 	Wide_Timer_3B               101
#define 	Wide_Timer_4A               102
#define 	Wide_Timer_4B               103
#define 	Wide_Timer_5A               104
#define 	Wide_Timer_5B               105
#define 	System_Exception_imprecise  106
#define 	PWM1_Generator_0            134
#define 	PWM1_Generator_1            135
#define 	PWM1_Generator_2            136
#define 	PWM1_Generator_3            137
#define 	PWM1_Fault                  138

/*Function declarations*/
void NVIC_enableInterrupt(u8 peripheral_ID);
void NVIC_disableInterrupt(u8 peripheral_ID);

void NVIC_SetPendingFlag(u8 peripheral_ID);
void NVIC_ClearPendingFlag(u8 peripheral_ID);

void NVIC_SetPriority(u8 peripheral_ID, u8 peripheral_Periority);
void NVIC_SetGroupPriority(u8 group_Periority);

u8 NVIC_getPendingFlag(u8 peripheral_ID);
u8 NVIC_getActiveFlag( u8 peripheral_ID );


#endif
