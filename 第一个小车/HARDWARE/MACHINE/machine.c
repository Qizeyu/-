#include "sys.h"
#include "machine.h"


void machine_Init()
{
		RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	   	 
	  	 
		GPIOB->CRL&=0XFFFFFFF0;
		GPIOB->CRL|=0X00000003;    ///PB0�������
		GPIOB->ODR =1;
	
		GPIOB->CRL&=0XFFFFFF0F;
		GPIOB->CRL|=0X00000030;    ///PB1�������
		GPIOB->ODR =1<<1;
	
		GPIOB->CRL&=0XFFFFF0FF;
		GPIOB->CRL|=0X00000300;    ///PB2�������
		GPIOB->ODR =1<<2;
	
		GPIOB->CRH&=0XFFFFFFF0;
		GPIOB->CRH|=0X00000003;    ///PB3�������
		GPIOB->ODR =1<<8;
	
	
	
}









