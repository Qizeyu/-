#include "sys.h"
#include "red_type.h"


void red_Init()
{
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	 
	  	 
		GPIOA->CRL&=0XFF0FFFFF; 
		GPIOA->CRL|=0X00400000;//PB5 浮空输入   	 
   
		GPIOA->CRL&=0XF0FFFFFF; 
		GPIOA->CRL|=0X04000000;//PB6 浮空输入   	
	
		GPIOA->CRL&=0X0FFFFFFF; 
		GPIOA->CRL|=0X40000000;//PB7 浮空输入   


}



