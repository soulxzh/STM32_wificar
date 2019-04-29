#include "motor.h"
#include "interface.h"
#include "stm32f10x.h"
#include "delay.h"

//RIO LIO高电平         电机顺时针转动 右轮后退 左轮前进  整体左转
//RIO高电平 LIO低电平 右轮顺时针  左轮逆时针 右前 左前  整体前进
//RIO低电平 LIO高电平 右轮逆时针  左轮顺时针 右后左后   整体向后
//RIO LIO低电平         电机逆时针转动                    整体右转



void CarGo()
{
	//GPIO_SetBits(GPIOA,GPIO_Pin_2);
	TIM_SetCompare1(TIM3,49);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_3);
	TIM_SetCompare2(TIM3,49);
	RIO=0; //右轮前进
	LIO=1; //左轮前进
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

void CarStop()//需要U型BACK
{
                            //使能高电平有效
	RIO=1;
	LIO=0;
	TIM_SetCompare1(TIM3,3599);//数值和占空比成反比;
	TIM_SetCompare2(TIM3,3599);
	delay_ms(500);
}

void MotorInit()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
	
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
