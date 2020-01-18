#============================================================================
#�ļ����ƣ�light.inc
#���ܸ�Ҫ��С��������������ࣩͷ�ļ�
#��Ȩ���У����ݴ�ѧNXPǶ��ʽ����(sumcu.suda.edu.cn)
#�汾���£�2016-04-20  V1.6
#============================================================================
#ifndef LIGHT_INC
#define LIGHT_INC

.include "gpio.inc"

#ָʾ�ƶ˿ڼ����Ŷ���
.equ LIGHT_RED,(PTB_NUM|19)    @��ɫRUN��ʹ�õĶ˿�/����
.equ LIGHT_BLUE,(PTB_NUM|9)    @��ɫRUN��ʹ�õĶ˿�/����
.equ LIGHT_GREEN,(PTB_NUM|18)  @��ɫRUN��ʹ�õĶ˿�/����

#��״̬�궨�壨�������ư���Ӧ��������ƽ��Ӳ���ӷ�������
.equ LIGHT_ON,0     @����
.equ LIGHT_OFF,1    @�ư�

#============================================================================
# �������ƣ�  light_init
# �������أ� ��
# ����˵����r0:(�˿ں�)|(���ź�),��:(PTB_NUM|(5u))��ʾB��5��,ͷ�ļ����к궨��
#          r3:�趨С��״̬����light.inc�к궨�塣
# ���ܸ�Ҫ��  ָʾ��������ʼ��
#============================================================================
 .global light_init

#============================================================================
# �������ƣ�    light_control
# �������أ�     ��                
# ����˵����   r0��(�˿ں�)|(���ź�),��:(PTB_NUM|(5u))��ʾB��5��,ͷ�ļ����к궨��
#            r3���趨С��״̬����light.inc�к궨�塣
# ���ܸ�Ҫ������ָʾ��������
#============================================================================
 .global light_control

#============================================================================
# �������ƣ�    light_change
# �������أ�     ��                
# ����˵����    r0:(�˿ں�)|(���ź�),��:(PTB_NUM|(5u))��ʾB��5��,ͷ�ļ����к궨��
# ���ܸ�Ҫ���л�ָʾ��������
#============================================================================
 .global light_change 


#endif