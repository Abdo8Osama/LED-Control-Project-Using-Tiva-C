/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 2022                              */
/* File_Name : GPIO_PROGRAM_C                            */
/*********************************************************/

/*************************************************************************/
/******** This file defines Function Definitions for GPIO Driver *********/
/*************************************************************************/

/*Included files*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_private.h"
#include"GPIO_config.h"
#include"GPIO_interface.h"
#include"GPIO_register.h"


#if BUS_TYPE == APB

/* functions definitions */

u8 DIO_Read_Pin (u8 DIO_port , u8 DIO_pin)
{
	u8 LOC_u8Result = 0 ;

	if((DIO_port <= PORTF)&&(DIO_port >=PORTA))
	{
		switch(DIO_port)
		{
		case PORTA : LOC_u8Result = GET(((MGPIOA_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		case PORTB : LOC_u8Result = GET(((MGPIOB_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		case PORTC : LOC_u8Result = GET(((MGPIOC_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		case PORTD : LOC_u8Result = GET(((MGPIOD_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		case PORTE : LOC_u8Result = GET(((MGPIOE_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		case PORTF : LOC_u8Result = GET(((MGPIOF_APB->GPIODATA)+(1<<DIO_pin)), DIO_pin); break ;
		}
	}

	return LOC_u8Result ;
}
void DIO_Write_Pin (u8 DIO_port ,u8 DIO_pin , u8 DIO_pin_level)
{
	if((DIO_port <= PORTF)&&(DIO_port >=PORTA))
	{
		if(DIO_pin_level == HIGH)
		{

			if(DIO_port == PORTA)
			{
				SET(MGPIOA_APB->GPIODATA , DIO_pin);
				//((MGPIOA_APB->GPIODATA)+(1<<DIO_pin))=255;
			}else if(DIO_port == PORTB)
			{
				SET(MGPIOB_APB->GPIODATA , DIO_pin);
				//((MGPIOB_APB->GPIODATA)+(1<<DIO_pin))=255;
			}else if(DIO_port == PORTC)
			{
				SET(MGPIOC_APB->GPIODATA , DIO_pin);
				//((MGPIOC_APB->GPIODATA)+(1<<DIO_pin))=255;
			}else if(DIO_port == PORTD)
			{
				SET(MGPIOD_APB->GPIODATA , DIO_pin);
				//((MGPIOD_APB->GPIODATA)+(1<<DIO_pin))=255;
			}else if(DIO_port == PORTE)
			{
				SET(MGPIOE_APB->GPIODATA , DIO_pin);
				//((MGPIOE_APB->GPIODATA)+(1<<DIO_pin))=255;
			}else if(DIO_port == PORTF)
			{
				SET(MGPIOF_APB->GPIODATA , DIO_pin);
				//((MGPIOF_APB->GPIODATA)+(1<<DIO_pin))=255;
			}

		}else if(DIO_pin_level == LOW)
		{
			if(DIO_port == PORTA)
			{
				CLR(MGPIOA_APB->GPIODATA , DIO_pin);
				//((MGPIOA_APB->GPIODATA)+(1<<DIO_pin))=0;
			}else if(DIO_port == PORTB)
			{
				CLR(MGPIOB_APB->GPIODATA , DIO_pin);
				//((MGPIOB_APB->GPIODATA)+(1<<DIO_pin))=0;
			}else if(DIO_port == PORTC)
			{
				CLR(MGPIOC_APB->GPIODATA , DIO_pin);
				//((MGPIOC_APB->GPIODATA)+(1<<DIO_pin))=0;
			}else if(DIO_port == PORTD)
			{
				CLR(MGPIOD_APB->GPIODATA , DIO_pin);
				//((MGPIOD_APB->GPIODATA)+(1<<DIO_pin))=0;
			}else if(DIO_port == PORTE)
			{
				CLR(MGPIOE_APB->GPIODATA , DIO_pin);
				//((MGPIOE_APB->GPIODATA)+(1<<DIO_pin))=0;
			}else if(DIO_port == PORTF)
			{
				CLR(MGPIOF_APB->GPIODATA , DIO_pin);
				//((MGPIOF_APB->GPIODATA)+(1<<DIO_pin))=0;

			}


		}else{
			/*Do nothing*/
		}
	}
}
u8 DIO_Read_Port (u8 DIO_port)
{
	u8 LOC_u8Result = 0 ;

	if((DIO_port <=5)&&(DIO_port >=0))
	{
		switch(DIO_port)
		{
		case PORTA : LOC_u8Result = ((MGPIOA_APB->GPIODATA)+255); break ;
		case PORTB : LOC_u8Result = ((MGPIOB_APB->GPIODATA)+255); break ;
		case PORTC : LOC_u8Result = ((MGPIOC_APB->GPIODATA)+255); break ;
		case PORTD : LOC_u8Result = ((MGPIOD_APB->GPIODATA)+255); break ;
		case PORTE : LOC_u8Result = ((MGPIOE_APB->GPIODATA)+255); break ;
		case PORTF : LOC_u8Result = ((MGPIOF_APB->GPIODATA)+255); break ;
		}
	}

	return LOC_u8Result ;
}
void DIO_Write_port (u8 DIO_port , u8 DIO_port_level)
{
	if((DIO_port <=5)&&(DIO_port >=0))
	{
		if(DIO_port == PORTA)
		{
			*(&(MGPIOA_APB->GPIODATA)+255)=DIO_port_level;
		}else if(DIO_port == PORTB)
		{
			*(&(MGPIOB_APB->GPIODATA)+255)=DIO_port_level;
		}else if(DIO_port == PORTC)
		{
			*(&(MGPIOC_APB->GPIODATA)+255)=DIO_port_level;
		}else if(DIO_port == PORTD)
		{
			*(&(MGPIOD_APB->GPIODATA)+255)=DIO_port_level;
		}else if(DIO_port == PORTE)
		{
			*(&(MGPIOE_APB->GPIODATA)+255)=DIO_port_level;
		}else if(DIO_port == PORTF)
		{
			*(&(MGPIOF_APB->GPIODATA)+255)=DIO_port_level;
		}
	}
}
void DIO_toggle_Pin (u8 DIO_port ,u8 DIO_pin)
{
	if((DIO_port <=5)&&(DIO_port >=0))
	{
		if((DIO_port <=5)&&(DIO_port >=0))
		{

			switch(DIO_port)
			{
			case PORTA : *(&(MGPIOA_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			case PORTB : *(&(MGPIOB_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			case PORTC : *(&(MGPIOC_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			case PORTD : *(&(MGPIOD_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			case PORTE : *(&(MGPIOE_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			case PORTF : *(&(MGPIOF_APB->GPIODATA)+(1<<DIO_pin)) ^=255; break ;
			}
		}
	}
}
void DIO_init_port(struct PIN_CONFIG * DIO_pin_config)
{
		MGPIOHBCTL = 0 ;

		if((DIO_pin_config->PORT_TYPE <= PORTF)&&(DIO_pin_config->PORT_TYPE >=PORTA))
		{
			switch(DIO_pin_config->PORT_TYPE)
			{
			case 0 :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOA_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOA_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOA_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOA_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOA_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOA_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/
					SET(MGPIOA_APB->GPIOIM , DIO_pin_config->PIN_TYPE);


					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOA_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOA_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOA_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOA_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOA_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOA_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOA_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOA_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOA_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOA_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOA_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOA_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}


					/*ENABLE INT MASK*/
					SET(MGPIOA_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOA_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOA_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOA_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOA_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOA_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOA_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOA_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOA_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;
			case 1 :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOB_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOB_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOB_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOB_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOB_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOB_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/
					CLR(MGPIOB_APB->GPIOIM , DIO_pin_config->PIN_TYPE);


					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOB_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOB_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOB_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOB_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOB_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOB_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOB_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOB_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOB_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOB_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOB_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOB_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}

					/*ENABLE INT MASK*/
					SET(MGPIOB_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOB_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOB_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOB_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOB_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOB_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOB_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOB_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOB_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;

			case 2 :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOC_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOC_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOC_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOC_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOC_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOC_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/
					CLR(MGPIOC_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
					/*CONFIGURE SENSE LEVEL*/

					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOC_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOC_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOC_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOC_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOC_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOC_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOC_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOC_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOC_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOC_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOC_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOC_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}


					/*ENABLE INT MASK*/
					SET(MGPIOC_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOC_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOC_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOC_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOC_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOC_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOC_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOC_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOC_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;

			case 3 :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOD_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOD_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOD_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOD_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOD_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOD_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/
					CLR(MGPIOD_APB->GPIOIM , DIO_pin_config->PIN_TYPE);

					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOD_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOD_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOD_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOD_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOD_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOD_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOD_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOD_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOD_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOD_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOD_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOD_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}


					/*ENABLE INT MASK*/
					SET(MGPIOD_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOD_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOD_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOD_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOD_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOD_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOD_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOD_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOD_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;

			case 4 :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOE_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOE_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOE_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOE_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOE_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOE_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/

					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOE_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOE_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOE_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOE_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOE_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOE_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOE_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOE_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOE_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOE_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOE_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOE_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}


					/*ENABLE INT MASK*/
					SET(MGPIOE_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOE_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOE_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOE_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOE_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOE_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOE_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOE_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOE_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;

			case PORTF :
				/*configure PIN direction */
				if(DIO_pin_config->PIN_DIRECTION == OUTPUT)
				{
					SET(MGPIOF_APB->GPIODIR , DIO_pin_config->PIN_TYPE);
					DIO_Write_Pin (DIO_pin_config->PORT_TYPE,DIO_pin_config->PIN_TYPE,DIO_pin_config->PIN_LEVEL);
				}
				else if(DIO_pin_config->PIN_DIRECTION == INPUT)
				{CLR(MGPIOF_APB->GPIODIR , DIO_pin_config->PIN_TYPE);}

				/*configure PIN MODE */
				if(DIO_pin_config->PIN_MODE == DIO)
				{
					CLR(MGPIOF_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					SET(MGPIOF_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
				}else if(DIO_pin_config->PIN_MODE == EXT_INT)
				{
					CLR(MGPIOF_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);
					/*ENABLE DIGITAL CIRCUIT*/
					SET(MGPIOF_APB->GPIODEN , DIO_pin_config->PIN_TYPE);
					/*DISABLE INT MASK*/
					CLR(MGPIOF_APB->GPIOIM , DIO_pin_config->PIN_TYPE);

					/*CONFIGURE SENSE LEVEL*/
					if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == FALLING)
					{
						CLR(MGPIOF_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOF_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == RISING)
					{
						CLR(MGPIOF_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOF_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
						SET(MGPIOF_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == BOTH_EDGES)
					{
						CLR(MGPIOF_APB->GPIOIS , DIO_pin_config->PIN_TYPE) ;
						SET(MGPIOF_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOF_APB->GPIOICR , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == LOW_LEVEL)
					{
						SET(MGPIOF_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}else if(DIO_pin_config->PIN_EXT_INT_SENSE_LEVEL == HIGH_LEVEL)
					{
						SET(MGPIOF_APB->GPIOIS , DIO_pin_config->PIN_TYPE);
						CLR(MGPIOF_APB->GPIOIBE , DIO_pin_config->PIN_TYPE);
						SET(MGPIOF_APB->GPIOIEV , DIO_pin_config->PIN_TYPE);
					}


					/*ENABLE INT MASK*/
					SET(MGPIOF_APB->GPIOIM , DIO_pin_config->PIN_TYPE);
				}
				else if(DIO_pin_config->PIN_MODE == AF_ADC)
				{SET(MGPIOF_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_MODE == AF_DMA)
				{SET(MGPIOF_APB->GPIOAFSEL , DIO_pin_config->PIN_TYPE);}

				/*configure internal attach*/
				if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_UP)
				{SET(MGPIOF_APB->GPIOPUR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == PULL_DOWN)
				{SET(MGPIOF_APB->GPIOPDR , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_INTERNAL_ATTACH == OPEN_DRAIN)
				{SET(MGPIOF_APB->GPIOODR , DIO_pin_config->PIN_TYPE);}

				/*configure output current */
				if(DIO_pin_config->PIN_OUTPUT_CURRENT == _2MA)
				{SET(MGPIOF_APB->GPIODR2R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _4MA)
				{SET(MGPIOF_APB->GPIODR4R , DIO_pin_config->PIN_TYPE);}
				else if(DIO_pin_config->PIN_OUTPUT_CURRENT == _8MA)
				{SET(MGPIOF_APB->GPIODR8R , DIO_pin_config->PIN_TYPE);}

				break ;

			}
		}

	}


#endif
