/********************************* �����к�̫�������޹�˾ *******************************
* ʵ �� �� ��С������ң��ʵ��
* ʵ��˵�� ��ʹ���ֻ���������ģ���ͨ���ֻ�����ָ��������С��
* ʵ��ƽ̨ ����̫ARM��Ƭ��������
* ���ӷ�ʽ ����ο�interface.h�ļ�
* ע    �� ��ָ������������ͲŻ�ʹС����������ֹͣ����ָ���С����ֹͣ
* ��    �� ����̫���Ӳ�Ʒ�з���    QQ ��1909197536
* ��    �� ��http://shop120013844.taobao.com/
****************************************************************************************/

#include "stm32f10x.h"
#include "interface.h"
#include "LCD1602.h"
#include "IRCtrol.h"
#include "motor.h"
#include "uart.h"
#include "ESP8266.h"
#include "serialportAPI.h"
#include "delay.h"
#include <stdlib.h>
#include <stdio.h>

//ȫ�ֱ�������
unsigned int speed_count=0;//ռ�ձȼ����� 50��һ����
char front_left_speed_duty=SPEED_DUTY;
char front_right_speed_duty=SPEED_DUTY;
char behind_left_speed_duty=SPEED_DUTY;
char behind_right_speed_duty=SPEED_DUTY;

unsigned char tick_5ms = 0;//5ms����������Ϊ�������Ļ�������
unsigned char tick_1ms = 0;//1ms����������Ϊ����Ļ���������
unsigned char tick_200ms = 0;//ˢ����ʾ
unsigned int tick_3s = 0;//��3s���߼��

char ctrl_comm = COMM_STOP;//����ָ��
unsigned char continue_time=0;
unsigned char wifi_rec_flag=0;//�������Ʊ�־λ

#define HOST_NAME   "192.168.1.106" //����IP
#define HOST_PORT   2400  //�����˿�

#define SSID "TP-LINK_83D4"  //·������
#define PSD  "60604_25" //����

#define RECVBUF_SIZE 16
unsigned char buffer[RECVBUF_SIZE] = {0};

int main(void)
{
	USART1Conf(9600);
	DBG("System Start");
	delay_init();
	GPIOCLKInit();
	UserLEDInit();
	LCD1602Init();
	TIM3_PWM_Init(900,0);
	MotorInit();
	ServoInit();
  //USART3Conf(9600);

	UartBegin(115200,&USART3Conf,&PutChar);//ÿ�������겨���ʺ���Ҫ��һ����ʱ
	delay_ms(10000);
	LED1_RESET;
	//WiFi��ʼ��������ָ����·����������
	while(WifiInit(SSID,PSD,HOST_NAME,HOST_PORT) == 0);
	LED2_RESET;

	while(1)
	{					
		if(SerialAvailable() > 5)//���յ�����5���ַ�
		{
			int len;
			len = recv(buffer, RECVBUF_SIZE, 100);
			if (len > 0)
			{
					char inChar;
					inChar = buffer[0];
	//			  send(buffer, len);
					if (ctrl_comm != inChar || continue_time == 1)
					{
						wifi_rec_flag = 1;
						ctrl_comm = inChar;
					}
					continue_time = 60;//���³���ʱ��
				  tick_3s = 0;//����������
			} 
		}
		
	  //if(tick_5ms >= 5)
		//{
		//	tick_5ms = 0;
		//	tick_200ms++;
		//	if(tick_200ms >= 40)
		//	{
		//		tick_200ms = 0;
		//		tick_3s++;
		//		LEDToggle(LED1_PIN);
		//		if(tick_3s >= 15)//15*200=3000
		//		{
		//			tick_3s = 0;
					//��ʱ��������Ƿ����������������,wifi��λ��������
		//			if(getSystemStatus() != STATUS_GETLINK)
		//      {
		//				DBG("TCP unlink");
		//				while(!WifiInit(SSID,PSD,HOST_NAME,HOST_PORT));
		//      }	
		//	
		//    }
		
			//continue_time--;//200ms �޽���ָ���ͣ��
			//if(continue_time == 0)
			//{
			//	continue_time = 1;
			//	CarStop();
			//}
			//do something
			if(wifi_rec_flag == 1)//���յ��ź�
			{
				wifi_rec_flag = 0;
				switch(ctrl_comm)
				{
					case COMM_UP:    CarGo();break;
					case COMM_DOWN:  CarBack();break;
					case COMM_LEFT:  CarLeft();break;
					case COMM_RIGHT: CarRight();break;
					case COMM_STOP:  CarStop();break;
					default : break;
				}
				DBG("recv COMM");
			}
	}
		
 }
//}

