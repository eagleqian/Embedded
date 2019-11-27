//======================================================================
//文件名称：light.h
//功能概要：小灯构件头文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2013-02-02   V2.0
//======================================================================

#ifndef _LIGHT_H     //防止重复定义（_LIGHT_H  开头)
#define _LIGHT_H

//头文件包含
#include "common.h"    //包含公共要素头文件
#include "gpio.h"      //用到gpio构件

//指示灯端口及引脚定义
#define RUN_LIGHT_RED       (PORT_B|19)   //红色RUN灯使用的端口/引脚
#define RUN_LIGHT_BLUE      (PORT_B|9)    //蓝色RUN灯使用的端口/引脚
#define RUN_LIGHT_GREEN     (PORT_B|18)   //绿色RUN灯使用的端口/引脚

//灯状态宏定义（灯亮、灯暗对应的物理电平由硬件接法决定）
#define LIGHT_ON        0    //灯亮
#define LIGHT_OFF       1    //灯暗

//=================接口函数声明===============================================
//======================================================================
//函数名称：light_init
//函数参数：port_pin：(端口号)|(引脚号)（如：(PORTB)|(5) 表示为B口5号脚）
//       state：设定小灯状态。由宏定义。
//函数返回：无
//功能概要：指示灯驱动初始化。
//======================================================================
void light_init(uint_16 port_pin, uint_8 state);

//======================================================================
//函数名称：light_control
//函数参数：port_pin：(端口号)|(引脚号)（如：(PORTB)|(5) 表示为B口5号脚）
//       state：设定小灯状态。由宏定义。
//函数返回：无
//功能概要：控制指示灯亮暗。
//======================================================================
void light_control(uint_16 port_pin, uint_8 state);

//======================================================================
//函数名称：light_change
//函数参数：port_pin：(端口号)|(引脚号)（如：(PORTB)|(5) 表示为B口5号脚）
//函数返回：无
//功能概要：切换指示灯亮暗。
//======================================================================
void light_change(uint_16 port_pin);

#endif    //防止重复定义（_LIGHT_H  结尾)


//=====================================================================
//声明：
//（1）我们开发的源代码，在本中心提供的硬件系统测试通过，真诚奉献给社会，不足之处，
//     欢迎指正。
//（2）对于使用非本中心硬件系统的用户，移植代码时，请仔细根据自己的硬件匹配。
//
//苏州大学飞思卡尔嵌入式中心（苏州华祥信息科技有限公司）
//技术咨询：0512-65214835  http://sumcu.suda.edu.cn
//业务咨询：0512-87661670,18915522016  http://www.hxtek.com.cn
