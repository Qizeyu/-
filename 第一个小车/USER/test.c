#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
#include "led.h"
#include "sys.h"
#include "key.h"
#include "red_type.h"
#include "machine.h"
#include "PWM.h"


void go();     
void left();
void right();
void mini_left();
void mini_right();
void stop();
void back();

int main(void)
{		
   u16 led0pwmval=415; 

  int i=0;
	
  u16 led1pwmval=490; 	
	u8 dir=1;	
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);	  		//延时初始化
	//KEY_Init();						//按键输入
	                                                                                                                         LED_Init();
	red_Init();
	
	TIM8_PWM_Init(899,0);//不分频。PWM频率=72000/(899+1)=80Khz 
	machine_Init();
		
	LED0 = 0;
	LED1 = 0;
	
		LED0_PWM_VAL=led0pwmval;	
		LED1_PWM_VAL=led1pwmval;
		
	go();
	while(1)
	{
		if(SENSPR0==0&&SENSPR1==0&&SENSPR2==0)
		{
			go();
		}
		else if(SENSPR0==0&&SENSPR1==0&&SENSPR2==1)
		{
			mini_right();
			
			
			LED0_PWM_VAL=led0pwmval;	
			LED1_PWM_VAL=led1pwmval;
		}
		else if(SENSPR0==0&&SENSPR1==1&&SENSPR2==0)
		{
			go();
		}
		else if(SENSPR0==0&&SENSPR1==1&&SENSPR2==1)
		{
			
		
			right();
			
			
			
			LED0_PWM_VAL=led0pwmval;	
			LED1_PWM_VAL=led1pwmval;
			
			
		}
		else if(SENSPR0==1&&SENSPR1==0&&SENSPR2==0)
		{
			mini_left();
			
		
			LED0_PWM_VAL=led0pwmval;	
			LED1_PWM_VAL=led1pwmval;
			
		}
		else if(SENSPR0==1&&SENSPR1==1&&SENSPR2==0)
		{
			
			left();
			
			
			
			LED0_PWM_VAL=led0pwmval;	
			LED1_PWM_VAL=led1pwmval;
			
	
		}
		else if(SENSPR0==1&&SENSPR1==1&&SENSPR2==1)
		{
			stop();
		}
		else
			go();
		
		
		delay_ms (100);
	}
	

	
} 
	void left()
{
		left1=0;
		right1=1;
	
		left2=1;
		right2=0;
	
	
	LED0_PWM_VAL=	300;
	LED1_PWM_VAL= 375;
	
	delay_ms(500);
	
	
}
void right()
{
	left1=1;
  right1=0;
	
	
	left2=0;
	right2=1;
	
	LED0_PWM_VAL=200;	
	LED1_PWM_VAL=160;
	
	
	delay_ms(350);

	
}
void go()
{
		left1 =1;
		right1 = 0;
		
		left2 =1;
		right2 = 0;

}


void mini_left()
{
	
	LED0_PWM_VAL=850;	
	LED1_PWM_VAL=830;
	
	
	left1=0;
	right1=1;
	
	left2=1;
	right2=0;
	
	delay_ms(10);
	
}
void mini_right()
{
	
	LED0_PWM_VAL=850;	
	LED1_PWM_VAL=870;
	left1=1;
	right1=0;
	
	left2=0;
	right2=1;
	
	delay_ms(15);
		
}
void stop()
{
	left1=0;
	right1=0;
	left2=0;
	right2=0;
	
}
void back()
{
	left1=0;
	right1=1;
	
	left2=0;
	right2=1;
	
	delay_ms(1000);
}








