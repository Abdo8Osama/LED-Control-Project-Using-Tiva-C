/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : GPIO_INTERFACE_H                          */
/*********************************************************/

/***********************************************************************************************/
/******** This file  defines Function prototypes and Macro Definitions for GPIO Driver *********/
/***********************************************************************************************/

/*Header Guard*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*APIs*/

#define PORT_HIGH	255
#define PORT_LOW	0

/*BUS TYPE*/
#define APB	0
#define AHB	1

/*LEVEL TYPE*/
#define LOW	    0
#define HIGH	1

/*PIN TYPE*/
#define PIN0 0
#define	PIN1 1
#define	PIN2 2
#define	PIN3 3
#define	PIN4 4
#define	PIN5 5
#define	PIN6 6
#define	PIN7 7

/*PORT TYPE*/
#define PORTA 0
#define	PORTB 1
#define	PORTC 2
#define	PORTD 3
#define	PORTE 4
#define	PORTF 5


#define DIO 	0
#define	EXT_INT 1
#define	AF 		2
#define	AF_ADC 	3
#define	AF_DMA 	4

#define	INPUT   0
#define	OUTPUT  1

#define	PULL_UP    0
#define	PULL_DOWN  1
#define	OPEN_DRAIN 2

#define	_2MA   0
#define	_4MA   1
#define	_8MA   2



#define	FALLING    0
#define	RISING     1
#define	LOW_LEVEL  2
#define	HIGH_LEVEL 3
#define	BOTH_EDGES 4

struct PIN_CONFIG{
		u8	PIN_TYPE  ;
		u8	PORT_TYPE ;
		u8 	PIN_MODE ;
		u8	PIN_DIRECTION ;
		u8	PIN_LEVEL  ;
		u8	PIN_INTERNAL_ATTACH;
		u8	PIN_OUTPUT_CURRENT ;
		u8	PIN_EXT_INT_SENSE_LEVEL ;
};



/* functions prototype*/
u8 DIO_Read_Pin (u8 DIO_port ,u8 DIO_pin);
void DIO_Write_Pin (u8 DIO_port ,u8 DIO_pin , u8 DIO_pin_level);
u8 DIO_Read_Port (u8 DIO_port);
void DIO_Write_port (u8 DIO_port , u8 DIO_port_level);
void DIO_toggle_Pin (u8 DIO_port ,u8 DIO_pin);

void DIO_init_port( struct PIN_CONFIG * DIO_pin_config);

#endif
