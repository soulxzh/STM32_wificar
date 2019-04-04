#ifndef __INTERFACE_H_
#define __INTERFACE_H_

#include "stm32f10x.h"

#define SYSTEM_SUPPORT_OS		0		//����ϵͳ�ļ����Ƿ�֧��UCOS
																	    
	 
//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
//IO�ڲ����궨��
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //��� 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //���� 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //��� 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //���� 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //��� 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //���� 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //��� 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //���� 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //��� 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //��� 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //��� 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����

//user LED PF8
#define LED1_PIN         GPIO_Pin_8
#define LED1_GPIO        GPIOF
#define LED1_RESET       GPIO_SetBits(LED1_GPIO , LED1_PIN)
#define LED1_SET         GPIO_ResetBits(LED1_GPIO , LED1_PIN)

//user LED PF9
#define LED2_PIN         GPIO_Pin_9
#define LED2_GPIO        GPIOF
#define LED2_RESET       GPIO_SetBits(LED2_GPIO , LED2_PIN)
#define LED2_SET         GPIO_ResetBits(LED2_GPIO , LED2_PIN)


//����ң�� ���������������,�ⲿ�ж� PD10
#define IRIN_PIN         GPIO_Pin_10
#define IRIN_GPIO        GPIOD
#define IRIN_PORTSOURCE  GPIO_PortSourceGPIOD
#define IRIN_PINSOURCE   GPIO_PinSource10
#define IRIN_EXITLINE    EXTI_Line10
#define IRIN_IRQCH       EXTI15_10_IRQn
#define IRIN             GPIO_ReadInputDataBit(IRIN_GPIO, IRIN_PIN)


//���������� �ⲿ�жϷ��� PB14
#define Echo_PIN         GPIO_Pin_14
#define Echo_GPIO        GPIOB
#define Echo_PORTSOURCE  GPIO_PortSourceGPIOB
#define Echo_PINSOURCE   GPIO_PinSource14
#define Echo_EXITLINE    EXTI_Line14
#define Echo_IRQCH       EXTI15_10_IRQn
#define Echo             GPIO_ReadInputDataBit(Echo_GPIO, Echo_PIN)
//����IO PD8
#define Trig_PIN         GPIO_Pin_8
#define Trig_GPIO        GPIOD
#define Trig_RESET       GPIO_SetBits(Trig_GPIO , Trig_PIN)
#define Trig_SET         GPIO_ResetBits(Trig_GPIO , Trig_PIN)//5ת3.3����һ�η��� modfied by LC 2015.09.20 10:18


//�������IO PD12
#define Servo_PIN         GPIO_Pin_12
#define Servo_GPIO        GPIOD
#define Servo_SET         GPIO_SetBits(Servo_GPIO , Servo_PIN)
#define Servo_RESET       GPIO_ResetBits(Servo_GPIO , Servo_PIN)

//LCD1602 IO
//LCDRS PC13   
#define LCDRS_PIN         GPIO_Pin_13
#define LCDRS_GPIO        GPIOC
#define LCDRS_SET         GPIO_SetBits(LCDRS_GPIO , LCDRS_PIN)
#define LCDRS_RESET       GPIO_ResetBits(LCDRS_GPIO , LCDRS_PIN)

//LCDWR PC14   
#define LCDWR_PIN         GPIO_Pin_14
#define LCDWR_GPIO        GPIOC
#define LCDWR_SET         GPIO_SetBits(LCDWR_GPIO , LCDWR_PIN)
#define LCDWR_RESET       GPIO_ResetBits(LCDWR_GPIO , LCDWR_PIN)

//LCDEN PC15  
#define LCDEN_PIN         GPIO_Pin_15
#define LCDEN_GPIO        GPIOC
#define LCDEN_SET         GPIO_SetBits(LCDEN_GPIO , LCDEN_PIN)
#define LCDEN_RESET       GPIO_ResetBits(LCDEN_GPIO , LCDEN_PIN)

//LCDPORT PF0-PF7
#define LCD_PORT        0x00ff
#define LCD_GPIO        GPIOF
#define LCDWRITE_DATA(data)   LCD_GPIO->BSRR = 0x00ff0000;LCD_GPIO->BSRR = (data)     

//�������IO���� 
/* 
FRONT_LEFT_F_PIN	PG13	��ǰǰ��IO
FRONT_LEFT_B_PIN	PG11	��ǰ����IO

FRONT_RIGHT_F_PIN	PC11	��ǰǰ��IO
FRONT_RIGHT_B_PIN	PD0	    ��ǰ����IO

BEHIND_LEFT_F_PIN	PD6	    ���ǰ��IO
BEHIND_LEFT_B_PIN	PG9	    ������IO

BEHIND_RIGHT_F_PIN	PD4	    �Һ�ǰ��IO
BEHIND_RIGHT_B_PIN	PD2	    �Һ����IO
 */
#define FRONT_LEFT_F_PIN         GPIO_Pin_13
#define FRONT_LEFT_F_GPIO        GPIOG
#define FRONT_LEFT_F_SET         GPIO_SetBits(FRONT_LEFT_F_GPIO , FRONT_LEFT_F_PIN)
#define FRONT_LEFT_F_RESET       GPIO_ResetBits(FRONT_LEFT_F_GPIO , FRONT_LEFT_F_PIN)

#define FRONT_LEFT_B_PIN         GPIO_Pin_11
#define FRONT_LEFT_B_GPIO        GPIOG
#define FRONT_LEFT_B_SET         GPIO_SetBits(FRONT_LEFT_B_GPIO , FRONT_LEFT_B_PIN)
#define FRONT_LEFT_B_RESET       GPIO_ResetBits(FRONT_LEFT_B_GPIO , FRONT_LEFT_B_PIN)

#define FRONT_RIGHT_F_PIN         GPIO_Pin_11
#define FRONT_RIGHT_F_GPIO        GPIOC
#define FRONT_RIGHT_F_SET         GPIO_SetBits(FRONT_RIGHT_F_GPIO , FRONT_RIGHT_F_PIN)
#define FRONT_RIGHT_F_RESET       GPIO_ResetBits(FRONT_RIGHT_F_GPIO , FRONT_RIGHT_F_PIN)

#define FRONT_RIGHT_B_PIN         GPIO_Pin_0
#define FRONT_RIGHT_B_GPIO        GPIOD
#define FRONT_RIGHT_B_SET         GPIO_SetBits(FRONT_RIGHT_B_GPIO , FRONT_RIGHT_B_PIN)
#define FRONT_RIGHT_B_RESET       GPIO_ResetBits(FRONT_RIGHT_B_GPIO , FRONT_RIGHT_B_PIN)

#define BEHIND_LEFT_F_PIN         GPIO_Pin_6
#define BEHIND_LEFT_F_GPIO        GPIOD
#define BEHIND_LEFT_F_SET         GPIO_SetBits(BEHIND_LEFT_F_GPIO , BEHIND_LEFT_F_PIN)
#define BEHIND_LEFT_F_RESET       GPIO_ResetBits(BEHIND_LEFT_F_GPIO , BEHIND_LEFT_F_PIN)

#define BEHIND_LEFT_B_PIN         GPIO_Pin_9
#define BEHIND_LEFT_B_GPIO        GPIOG
#define BEHIND_LEFT_B_SET         GPIO_SetBits(BEHIND_LEFT_B_GPIO , BEHIND_LEFT_B_PIN)
#define BEHIND_LEFT_B_RESET       GPIO_ResetBits(BEHIND_LEFT_B_GPIO , BEHIND_LEFT_B_PIN)

#define BEHIND_RIGHT_F_PIN         GPIO_Pin_4
#define BEHIND_RIGHT_F_GPIO        GPIOD
#define BEHIND_RIGHT_F_SET         GPIO_SetBits(BEHIND_RIGHT_F_GPIO , BEHIND_RIGHT_F_PIN)
#define BEHIND_RIGHT_F_RESET       GPIO_ResetBits(BEHIND_RIGHT_F_GPIO , BEHIND_RIGHT_F_PIN)

#define BEHIND_RIGHT_B_PIN         GPIO_Pin_2
#define BEHIND_RIGHT_B_GPIO        GPIOD
#define BEHIND_RIGHT_B_SET         GPIO_SetBits(BEHIND_RIGHT_B_GPIO , BEHIND_RIGHT_B_PIN)
#define BEHIND_RIGHT_B_RESET       GPIO_ResetBits(BEHIND_RIGHT_B_GPIO , BEHIND_RIGHT_B_PIN)

//ѭ�����Թ�
/* 
��ѭ��	SEARCH_M_PIN	PG8
��ѭ��	SEARCH_R_PIN	PG6
��ѭ��	SEARCH_L_PIN	PG4
 */
#define SEARCH_M_PIN         GPIO_Pin_8
#define SEARCH_M_GPIO        GPIOG
#define SEARCH_M_IO          GPIO_ReadInputDataBit(SEARCH_M_GPIO, SEARCH_M_PIN)

#define SEARCH_R_PIN         GPIO_Pin_6
#define SEARCH_R_GPIO        GPIOG
#define SEARCH_R_IO          GPIO_ReadInputDataBit(SEARCH_R_GPIO, SEARCH_R_PIN)

#define SEARCH_L_PIN         GPIO_Pin_4
#define SEARCH_L_GPIO        GPIOG
#define SEARCH_L_IO          GPIO_ReadInputDataBit(SEARCH_L_GPIO, SEARCH_L_PIN)
#define BLACK_AREA 1
#define WHITE_AREA 0

//�������
/* 
�ұ���	VOID_R_PIN	PC7
�����	VOID_L_PIN	PG2
 */
#define VOID_R_PIN         GPIO_Pin_7
#define VOID_R_GPIO        GPIOC
#define VOID_R_IO          GPIO_ReadInputDataBit(VOID_R_GPIO, VOID_R_PIN)

#define VOID_L_PIN         GPIO_Pin_2
#define VOID_L_GPIO        GPIOG
#define VOID_L_IO          GPIO_ReadInputDataBit(VOID_L_GPIO, VOID_L_PIN)
#define BARRIER_Y 0 //���ϰ���
#define BARRIER_N 1  //���ϰ���

//����
/* 
�ٶ�������	FRONT_RIGHT_S_PIN	PA11
�ٶ�������	FRONT_LEFT_S_PIN	PA12
 */
#define FRONT_RIGHT_S_PIN         GPIO_Pin_11
#define FRONT_RIGHT_S_GPIO        GPIOA
#define FRONT_RIGHT_S_IO          GPIO_ReadInputDataBit(FRONT_RIGHT_S_GPIO, FRONT_RIGHT_S_PIN)

#define FRONT_LEFT_S_PIN         GPIO_Pin_12
#define FRONT_LEFT_S_GPIO        GPIOA
#define FRONT_LEFT_S_IO          GPIO_ReadInputDataBit(FRONT_LEFT_S_GPIO, FRONT_LEFT_S_PIN)

//��ǰ
#define FRONT_LEFT_GO    FRONT_LEFT_F_SET; FRONT_LEFT_B_RESET//ǰ��
#define FRONT_LEFT_BACK  FRONT_LEFT_F_RESET; FRONT_LEFT_B_SET//����
#define FRONT_LEFT_STOP  FRONT_LEFT_F_RESET; FRONT_LEFT_B_RESET//ֹͣ

//��ǰ
#define FRONT_RIGHT_GO     FRONT_RIGHT_F_SET;  FRONT_RIGHT_B_RESET
#define FRONT_RIGHT_BACK   FRONT_RIGHT_F_RESET;FRONT_RIGHT_B_SET
#define FRONT_RIGHT_STOP   FRONT_RIGHT_F_RESET;FRONT_RIGHT_B_RESET

//���
#define BEHIND_LEFT_GO     BEHIND_LEFT_F_SET;BEHIND_LEFT_B_RESET
#define BEHIND_LEFT_BACK   BEHIND_LEFT_F_RESET;BEHIND_LEFT_B_SET
#define BEHIND_LEFT_STOP   BEHIND_LEFT_F_RESET;BEHIND_LEFT_B_RESET

//�Һ�
#define BEHIND_RIGHT_GO    BEHIND_RIGHT_F_SET;BEHIND_RIGHT_B_RESET
#define BEHIND_RIGHT_BACK  BEHIND_RIGHT_F_RESET;BEHIND_RIGHT_B_SET
#define BEHIND_RIGHT_STOP  BEHIND_RIGHT_F_RESET;BEHIND_RIGHT_B_RESET

#define SPEED_DUTY 40//Ĭ��ռ�ձ� ��1ms��С�ֱ��� ����50ms����

//ָ���
#define COMM_STOP  'I'//ֹͣ
#define COMM_UP    'A'//ǰ��
#define COMM_DOWN  'B'//����
#define COMM_LEFT  'C'//��ת
#define COMM_RIGHT 'D'//��ת

extern unsigned char tick_5ms;//5ms����������Ϊ�������Ļ�������
extern unsigned char tick_1ms;//1ms����������Ϊ����Ļ���������
extern unsigned int speed_count;//ռ�ձȼ����� 50��һ����
extern unsigned char bt_rec_flag;//�������Ʊ�־λ

void LEDToggle(uint16_t Led);

void IRIN_Configuration(void);
void TIM2_Init(void);
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void RedRayInit(void);
void ServoInit(void);
void GPIOCLKInit(void);
void UserLEDInit(void);

#endif

