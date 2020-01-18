//============================================================================
//�ļ����ƣ�includes.h
//���ܸ�Ҫ��Ӧ�ù�����ͷ�ļ�
//��Ȩ���У����ݴ�ѧ��˼����Ƕ��ʽ����(sumcu.suda.edu.cn)
//�汾���£�2012-11-12  V2.0
//============================================================================

#ifndef _INCLUDES_H
#define _INCLUDES_H

#include "common.h"
#include "printf.h"
#include "gpio.h"
#include "light.h"
#include "uart.h"
#include "rtc.h"

//����ȫ�ֱ���
//����С����˸Ƶ��
#define RUN_COUNTER_MAX   1500000ul 

uint_8 g_time[3];             //��¼ʱ���ȫ������
uint32_t AlarmTimes;          //������ʱ����ʱ���
uint32_t SecondTimes;         //��ʱ�������������ʼֵ

//����ʹ�õĵ��Ժ�
#define UART_TEST UART_1
#define TEST_UART_BAUDRATE   9600UL


#endif