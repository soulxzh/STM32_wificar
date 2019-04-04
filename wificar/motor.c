#include "motor.h"
#include "interface.h"
#include "stm32f10x.h"
#include "delay.h"

//RIO LIO�ߵ�ƽ         ���˳ʱ��ת�� ���ֺ��� ����ǰ��  ������ת
//RIO�ߵ�ƽ LIO�͵�ƽ ������˳ʱ��  ������ʱ�� ��ǰ ��ǰ  ����ǰ��
//RIO�͵�ƽ LIO�ߵ�ƽ ��������ʱ��  ����˳ʱ�� �Һ����   �������
//RIO LIO�͵�ƽ         �����ʱ��ת��                    ������ת



void CarGo()
{
	//GPIO_SetBits(GPIOA,GPIO_Pin_2);
	TIM_SetCompare1(TIM3,400);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	TIM_SetCompare2(TIM3,400);
	RIO=1; //����ǰ��
	LIO=0; //����ǰ��
}

void CarLeft()
{
	TIM_SetCompare2(TIM3,200);
	TIM_SetCompare1(TIM3,400);
	RIO=1;
	LIO=1;
}

void CarRight()
{
	TIM_SetCompare2(TIM3,400);
	TIM_SetCompare1(TIM3,200);
	RIO=0;	
	LIO=0;
}

void CarBack()
{
	TIM_SetCompare1(TIM3,400);
  TIM_SetCompare2(TIM3,400);
	RIO=0;
	LIO=1;
}

void CarStop()//��ҪU��BACK
{
                            //ʹ�ܸߵ�ƽ��Ч
	TIM_SetCompare1(TIM3,899);//��ֵ��ռ�ձȳɷ���;
	TIM_SetCompare2(TIM3,899);
	RIO=1;
	LIO=0;
	delay_ms(500);
}

void MotorInit()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);						

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 		
	TIM_SetCompare1(TIM3,899);	
  TIM_SetCompare2(TIM3,899);
}
