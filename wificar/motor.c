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
	TIM_SetCompare1(TIM3,49);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	TIM_SetCompare2(TIM3,49);
	RIO=0; //����ǰ��
	LIO=1; //����ǰ��
}

void CarLeft()
{
	TIM_SetCompare1(TIM3,49);
	TIM_SetCompare2(TIM3,1799);
	RIO=0;
	LIO=0;
}

void CarRight()
{
	TIM_SetCompare1(TIM3,1799);
	TIM_SetCompare2(TIM3,49);
	RIO=1;	
	LIO=1;
}

void CarBack()
{
	TIM_SetCompare1(TIM3,49);
  TIM_SetCompare2(TIM3,49);
	RIO=1;
	LIO=0;
}

void CarStop()//��ҪU��BACK
{
                            //ʹ�ܸߵ�ƽ��Ч
	RIO=1;
	LIO=0;
	TIM_SetCompare1(TIM3,3599);//��ֵ��ռ�ձȳɷ���;
	TIM_SetCompare2(TIM3,3599);
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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 		
	TIM_SetCompare1(TIM3,3599);	
	TIM_SetCompare2(TIM3,3599);
}
