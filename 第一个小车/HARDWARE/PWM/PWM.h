#ifndef __PWM_H
#define __PWM_H
#include "sys.h"

//ͨ���ı�TIM1->CCR1��ֵ���ı�ռ�ձȣ��Ӷ�����LED0������
#define LED0_PWM_VAL TIM8->CCR1     
#define LED1_PWM_VAL TIM8->CCR2 
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM8_PWM_Init(u16 arr,u16 psc);
#endif























