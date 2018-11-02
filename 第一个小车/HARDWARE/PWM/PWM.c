#include "PWM.h"
#include "led.h"

//��ʱ��3�жϷ������	 
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//����ж�
	{
		LED1=!LED1;			    				   				     	    	
	}				   
	TIM3->SR&=~(1<<0);//����жϱ�־λ 	    
}
//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3ʱ��ʹ��    
 	TIM3->ARR=arr;  	//�趨�������Զ���װֵ 
	TIM3->PSC=psc;  	//Ԥ��Ƶ������
	TIM3->DIER|=1<<0;   //��������ж�				
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3
  	MY_NVIC_Init(1,3,TIM3_IRQn,2);//��ռ1�������ȼ�3����2									 
}
//TIM8_CH1 PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM8_PWM_Init(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB2ENR|=1<<13; 	//TIM8ʱ��ʹ��    
	
	RCC->APB2ENR|=1<<4;  //GPIOCʹ��
	
	GPIOC->CRL&=0XF0FFFFFF;	//PC6���֮ǰ������
	GPIOC->CRL|=0X0B000000;	//���ù������ 
	
	GPIOC->CRL&=0X0FFFFFFF;	//PC7���֮ǰ������
	GPIOC->CRL|=0XB0000000;	//���ù������ 
	
	
	TIM8->ARR=arr;			//�趨�������Զ���װֵ 
	TIM8->PSC=psc;			//Ԥ��Ƶ������
  
	TIM8->CCMR1|=7<<4;  	//CH1 PWM2ģʽ		 
	TIM8->CCMR1|=1<<3; 		//CH1Ԥװ��ʹ��	 
 	TIM8->CCER|=1<<0;   	//OC1 ���ʹ��	     
	
	TIM8->CCMR1|=7<<12;  	//CH2 PWM2ģʽ		 
	TIM8->CCMR1|=1<<11; 		//CH2Ԥװ��ʹ��	 
 	TIM8->CCER|=1<<4;   	//OC2 ���ʹ��	
	
	TIM8->BDTR|=1<<15;   	//MOE�����ʹ��	   

	TIM8->CR1=0x0080;   	//ARPEʹ�� 
	TIM8->CR2=0x0080;   	//ARPEʹ�� 
	
	TIM8->CR1|=0x01;    	//ʹ�ܶ�ʱ��8 				
  //TIM8->CR2|=0X02;
	
}  














