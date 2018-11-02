#include "sys.h"
#include "machine.h"


void machine_Init()
{
		RCC->APB2ENR|=1<<3;    //使能PORTB时钟	   	 
	  	 
		GPIOB->CRL&=0XFFFFFFF0;
		GPIOB->CRL|=0X00000003;    ///PB0推挽输出
		GPIOB->ODR =1;
	
		GPIOB->CRL&=0XFFFFFF0F;
		GPIOB->CRL|=0X00000030;    ///PB1推挽输出
		GPIOB->ODR =1<<1;
	
		GPIOB->CRL&=0XFFFFF0FF;
		GPIOB->CRL|=0X00000300;    ///PB2推挽输出
		GPIOB->ODR =1<<2;
	
		GPIOB->CRH&=0XFFFFFFF0;
		GPIOB->CRH|=0X00000003;    ///PB3推挽输出
		GPIOB->ODR =1<<8;
	
	
	
}









