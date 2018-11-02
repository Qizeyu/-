#include "PWM.h"
#include "led.h"

//定时器3中断服务程序	 
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//溢出中断
	{
		LED1=!LED1;			    				   				     	    	
	}				   
	TIM3->SR&=~(1<<0);//清除中断标志位 	    
}
//通用定时器中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3时钟使能    
 	TIM3->ARR=arr;  	//设定计数器自动重装值 
	TIM3->PSC=psc;  	//预分频器设置
	TIM3->DIER|=1<<0;   //允许更新中断				
	TIM3->CR1|=0x01;    //使能定时器3
  	MY_NVIC_Init(1,3,TIM3_IRQn,2);//抢占1，子优先级3，组2									 
}
//TIM8_CH1 PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM8_PWM_Init(u16 arr,u16 psc)
{		 					 
	//此部分需手动修改IO口设置
	RCC->APB2ENR|=1<<13; 	//TIM8时钟使能    
	
	RCC->APB2ENR|=1<<4;  //GPIOC使能
	
	GPIOC->CRL&=0XF0FFFFFF;	//PC6清除之前的设置
	GPIOC->CRL|=0X0B000000;	//复用功能输出 
	
	GPIOC->CRL&=0X0FFFFFFF;	//PC7清除之前的设置
	GPIOC->CRL|=0XB0000000;	//复用功能输出 
	
	
	TIM8->ARR=arr;			//设定计数器自动重装值 
	TIM8->PSC=psc;			//预分频器设置
  
	TIM8->CCMR1|=7<<4;  	//CH1 PWM2模式		 
	TIM8->CCMR1|=1<<3; 		//CH1预装载使能	 
 	TIM8->CCER|=1<<0;   	//OC1 输出使能	     
	
	TIM8->CCMR1|=7<<12;  	//CH2 PWM2模式		 
	TIM8->CCMR1|=1<<11; 		//CH2预装载使能	 
 	TIM8->CCER|=1<<4;   	//OC2 输出使能	
	
	TIM8->BDTR|=1<<15;   	//MOE主输出使能	   

	TIM8->CR1=0x0080;   	//ARPE使能 
	TIM8->CR2=0x0080;   	//ARPE使能 
	
	TIM8->CR1|=0x01;    	//使能定时器8 				
  //TIM8->CR2|=0X02;
	
}  














