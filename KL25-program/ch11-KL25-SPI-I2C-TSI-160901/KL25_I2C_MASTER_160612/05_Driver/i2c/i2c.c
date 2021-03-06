//=====================================================================
//文件名称：i2c.c
//功能概要：i2c底层驱动构件源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2013-05-4   V2.1
//        2015-01-21   V3.0
//=====================================================================
#include  "i2c.h"

static const uint_8 data[]={300,0x14,150,0x54,100,0x1f,75,0x25,50,0x5f};
static void send_signal(uint_8 Signal,uint_8 I2C_No);
static uint_8 wait(uint_8 x,uint_8 I2C_No);
static I2C_MemMapPtr i2c_get_base_address(uint_8 I2C_No);

//=====================================================================
//函数名称：send_signal
//功能概要：根据需要产生开始或停止信号
//参数说明： I2C_No:模块号，其取值为0，1
//       Signal: 'S'(Start),产生开始信号      'O'(Over),  产生停止信号
//函数返回：无
//=====================================================================
void send_signal(uint_8 Signal,uint_8 I2C_No)
{
    //获取i2c模块基址
    I2C_MemMapPtr num = i2c_get_base_address(I2C_No);
    if(num==I2C0)
    {
        if (Signal  == 'S')
        {
              //i2c0_c主机模式选择位MST由0变为1,可以产生开始信号
              BSET(I2C_C1_MST_SHIFT,I2C0_C1);
         }
         else if (Signal == 'O')
        {
              //主机模式选择位MST由1变为0,可以产生停止信号
        	 BCLR(I2C_C1_MST_SHIFT,I2C0_C1);
        }
    }
    else if(num==I2C1)
    {
         if (Signal == 'S')
         {
              //i2c0_c主机模式选择位MST由0变为1,可以产生开始信号
        	 BSET(I2C_C1_MST_SHIFT,I2C1_C1);
          }
          else if (Signal == 'O')
         {
              //主机模式选择位MST由1变为0,可以产生停止信号
        	  BCLR(I2C_C1_MST_SHIFT,I2C1_C1);
          }
    }
}
//=====================================================================
//函数名称： wait
//功能概要： 在时限内,循环检测接收应答标志位,或传送完成标志位,判断MCU
//          是否接收到应答信号或一个字节是否已在总线上传送完毕
//参数说明： I2C_No:模块号  ，其取值为0，1
//          x:x = 'A'(Ack),等待应答;x = 'T'(Transmission),等待一个字节数据传输完成
//函数返回：  0:收到应答信号或一个字节传送完毕;
//        1:未收到应答信号或一个 字节没传送完
//=====================================================================
uint_8 wait(uint_8 x,uint_8 I2C_No)
{
    uint_16 ErrTime, i;
    //获取i2c模块基地址
    I2C_MemMapPtr num = i2c_get_base_address(I2C_No);
    ErrTime = 255*10;            //定义查询超时时限
    for (i = 0;i < ErrTime;i++)
    {
         if (x == 'A')           //等待应答信号
         {
              if(( I2C_S_REG(num)  & I2C_S_RXAK_MASK)==0)
                   return 0;      //传送完一个字节后,收到了从机的应答信号
          }
         else if (x == 'T')      //等待传送完成一个字节信号
         {
             if ((I2C_S_REG(num) & I2C_S_IICIF_MASK) != 0)
             {
                  (I2C_S_REG(num) |=(0 | I2C_S_IICIF_MASK));  //清IICIF标志位
                       return 0;       //成功发送完一个字节
              }
          }
     }
    if (i >= ErrTime)
         return 1;               //超时,没有收到应答信号或发送完一个字节
}

//=====================================================================
//函数名称：i2c_init                                                        
//功能概要：初始化IICX模块。                                     
//参数说明：I2C_No:模块号,其取值为0,1
//       Mode 模式  1：主机     0：从机
//       address 本模块初始化地址    范围(1~255)
//       BaudRate为波特率，其单位为Kb/s，其取值为50,75,100,150,300
//函数返回：无                                                                  
//=====================================================================
void i2c_init(uint_8 I2C_No,uint_8 Mode,uint_8 address,uint_8 BaudRate)
{
    //获取I2C模块的基址
	uint_8 index;
    I2C_MemMapPtr num = i2c_get_base_address(I2C_No);
    if(I2C_No<0||I2C_No>1)//如果模块号错误则强制其为0
    {
    	I2C_No=0;
    }
    if(num==I2C0)
    {
        //I2C0 Clock Gate Control --enable
    	BSET(SIM_SCGC4_I2C0_SHIFT,SIM_SCGC4);
        I2C0_C1=0X00;
        BSET(I2C_S_IICIF_SHIFT,I2C0_S);

        //IIC_0：1=PTE24~25脚，2=PTB0~1脚，3=PTB2~3脚，4=PTC8~9脚
		//引脚复用为IIC0功能
        #if (IIC_0_GROUP == 1)
		PORTE_PCR24 = PORT_PCR_MUX(0x5);      //使能IIC0_SCL
		PORTE_PCR25 = PORT_PCR_MUX(0x5);      //使能IIC0_SDA
        #endif

		#if (IIC_0_GROUP == 2)
		PORTB_PCR0 = PORT_PCR_MUX(0x2);      //使能IIC0_SCL
		PORTB_PCR1 = PORT_PCR_MUX(0x2);      //使能IIC0_SDA
		#endif

		#if (IIC_0_GROUP == 3)
		PORTB_PCR2 = PORT_PCR_MUX(0x2);      //使能IIC0_SCL
		PORTB_PCR3 = PORT_PCR_MUX(0x2);      //使能IIC0_SDA
		#endif

		#if (IIC_0_GROUP == 4)
		PORTC_PCR8 = PORT_PCR_MUX(0x2);      //使能IIC0_SCL
		PORTC_PCR9 = PORT_PCR_MUX(0x2);      //使能IIC0_SDA
		#endif

        //设置 MULT 和 ICR,kL25的MCU总线频率为24M，在总线上分频得75K波特率  
        I2C0_A1=address;                    //本机作为从机时的默认地址
        for(index=0;index<10;index+=2)
        {
        	if(data[index]==BaudRate)
        	{
        		index++;
        		I2C0_F=data[index];        //将定义的参数赋给I2C1_F
        		break;
        	}
        }

        if(1 == Mode)   //主机模式
        {
            BSET(I2C_C1_IICEN_SHIFT,I2C0_C1);//开i2c0模块使能
            BSET(I2C_C1_TXAK_SHIFT,I2C0_C1); //置位i2c0 TXAK
        }
        else            //从机模式
        {
            BSET(I2C_C1_IICEN_SHIFT,I2C0_C1);//使能I2C模块
            BSET(I2C_C1_IICIE_SHIFT,I2C0_C1);//来I2C中断
            BSET(I2C_C1_MST_SHIFT,I2C0_C1);//设置成主机模式
            BCLR(I2C_C1_TX_SHIFT,I2C0_C1);//TX = 0,MCU设置为接收模式
//            i=I2C0_D;                        //读出IIC1D,准备接收数据
            BCLR(I2C_C1_MST_SHIFT,I2C0_C1);//MST位由1变成0，设置为从机模式
        }

    }
    else
    {
        //I2C1 Clock Gate Control --enable
    	BSET(SIM_SCGC4_I2C1_SHIFT,SIM_SCGC4);
        //SIM_SCGC4 |=SIM_SCGC4_I2C1_MASK;
        I2C1_C1=0X00;
        BSET(I2C_S_IICIF_SHIFT,I2C1_S);

        //IIC_1: 1=PTE1~0脚，2=PTA3~4脚, 3=PTC1~2脚, 4=PTC10~11脚
        //SD-FSL-KL25-EVB板上使用PTC1~2脚
		#if (IIC_1_GROUP == 1)
		PORTE_PCR1 = PORT_PCR_MUX(0x6);      //使能IIC1_SCL
		PORTE_PCR0 = PORT_PCR_MUX(0x6);      //使能IIC1_SDA
		#endif

		#if (IIC_1_GROUP == 2)
		PORTA_PCR3 = PORT_PCR_MUX(0x2);      //使能IIC1_SCL
		PORTA_PCR4 = PORT_PCR_MUX(0x2);      //使能IIC1_SDA
		#endif

		#if (IIC_1_GROUP == 3)
		PORTC_PCR1 = PORT_PCR_MUX(0x2);      //使能IIC1_SCL
		PORTC_PCR2 = PORT_PCR_MUX(0x2);      //使能IIC1_SDA
		#endif

		#if (IIC_1_GROUP == 4)
		PORTC_PCR10 = PORT_PCR_MUX(0x2);      //使能IIC1_SCL
		PORTC_PCR11 = PORT_PCR_MUX(0x2);      //使能IIC1_SDA
		#endif

        I2C1_A1=address;                    //本机作为从机时的默认地址
        for(index=0;index<10;index+=2)
        {
            if(data[index]==BaudRate)
            {
               index++;
               I2C1_F=data[index];        //将定义的参数赋给I2C1_F
               break;
            }
        }

        if(1 == Mode)   //主机模式
        {
            BSET(I2C_C1_IICEN_SHIFT,I2C1_C1);//开i2c0模块使能
            BSET(I2C_C1_TXAK_SHIFT,I2C1_C1); //置位i2c0 TXAK
        }
        else            //从机模式
        {
            BSET(I2C_C1_IICEN_SHIFT,I2C1_C1);//使能I2C模块
            BSET(I2C_C1_IICIE_SHIFT,I2C1_C1);//来I2C中断
            BSET(I2C_C1_MST_SHIFT,I2C1_C1);//设置成主机模式
            BCLR(I2C_C1_TX_SHIFT,I2C1_C1);//TX = 0,MCU设置为接收模式
//            i=I2C0_D;                        //读出IIC1D,准备接收数据
            BCLR(I2C_C1_MST_SHIFT,I2C1_C1);//MST位由1变成0，设置为从机模式
        }
    }
}

//=====================================================================
//函数名称：i2c_read1                                                        
//功能概要：从从机读1个字节数据                                            
//参数说明：  I2C_No:模块号，其取值为0，1
//       DeviceAddr:设备地址    范围(1~255)
//       DataLocation:数据在从机接收数组中的位置    范围(0~255)
//       Data:带回收到的一个字节数据  
//函数返回：为0,成功读一个字节;为1,读一个字节失败  
//函数说明: 内部调用 send_signal,wait  
//============================================================================
uint_8 i2c_read1(uint_8 I2C_No,uint_8 DeviceAddr, uint_8 DataLocation, uint_8 *Data)
{      
         //获取i2c模块基址
     I2C_MemMapPtr num = i2c_get_base_address(I2C_No);            
     BSET(I2C_C1_TX_SHIFT,I2C_C1_REG(num)); //TX = 1,MCU设置为发送模式
     send_signal('S',I2C_No);               //发送开始信号 
     I2C_D_REG(num)  = DeviceAddr & 0xfe;   //发送设备地址,并通知从机接收数据
     if (wait('T',I2C_No))               //等待一个字节数据传送完成  
     {      
          return 1;                          //没有传送成功,读一个字节失败   
     }
     if (wait('A',I2C_No))               //等待从机应答信号 
     {
          return 1;                          //没有等到应答信号,读一个字节失败 
     }
     I2C_D_REG(num)  = DataLocation;          //发送数据在从机接收数组中的位置
     if (wait('T',I2C_No))               //等待一个字节数据传送完成 
     {	 
          return 1;                          //没有传送成功,读一个字节失败
     }
     if (wait('A',I2C_No))               //等待从机应答信号   
     {  
          return 1;                          //没有等到应答信号,读一个字节失败  
     }
     // 当MCU在主机模 式下，向该位写1将产生一个重新开始信号  
     BSET(I2C_C1_RSTA_SHIFT,I2C_C1_REG(num));
     I2C_D_REG(num) = DeviceAddr | 0x01;    //通知从机改为发送数据    
     if (wait('T',I2C_No))               //等待一个字节数据传送完成  
     { 
          return 1;                          //没有传送成功,读一个字节失败 
     }
     if (wait('A',I2C_No))               //等待从机应答信号  
     {
          return 1;                         //没有等到应答信号,读一个字节失败
     }
     BCLR(I2C_C1_TX_SHIFT,I2C_C1_REG(num));      //TX = 0,MCU设置为接收模式 (170216改） 

  
     *Data = I2C_D_REG(num);            //读出IIC1D,准备接收数据   
     if (wait('T',I2C_No))           //等待一个字节数据传送完成  
     {  	 
          return 1;                      //没有传送成功,读一个字节失败  
     }
     send_signal('O',I2C_No);           //发送停止信号    
     *Data = I2C_D_REG(num);            //读出接收到的一个数据    	
           return 0;                          //正确接收到一个字节数据	
}

//============================================================================
//函数名称：i2c_write1                                                        
//功能概要：向从机写1个字节数据                                           
//参数说明：  I2C_No:模块号       ，其取值为0，1
//       DeviceAddr:设备地址    范围(1~255)
//       DataLocation:数据在从机接收数组中的位置    范围(0~255)
//       Data:要发给从机的1个字节数据  
//函数返回：为0,成功写一个字节;为1,写一个字节失败 
//函数说明: 内部调用 send_signal,wait  
//============================================================================

uint_8 i2c_write1(uint_8 I2C_No,uint_8 DeviceAddr, uint_8 DataLocation, uint_8 Data)
{
	 //获取i2c模块基址
     I2C_MemMapPtr num = i2c_get_base_address(I2C_No);	
     BSET(I2C_C1_TX_SHIFT,I2C_C1_REG(num)); //TX = 1,MCU设置为发送模式
     send_signal('S',I2C_No);          //发送开始信号
     I2C_D_REG(num) = DeviceAddr & 0xfe;  //发送设备地址,并通知从机接收数据
     if (wait('T',I2C_No))             //等待一个字节数据传送完成
          return 1;                        //没有传送成功,写一个字节失败
     if (wait('A',I2C_No))             //等待从机应答信号
          return 1;                        //没有等到应答信号,写一个字节失败   
     I2C_D_REG(num) = DataLocation;         //发送数据在从机接收数组中的位置
     if (wait('T',I2C_No))             //等待一个字节数据传送完成
          return 1;                        //没有传送成功,写一个字节失败
     if (wait('A',I2C_No))             //等待从机应答信号
          return 1;                        //没有等到应答信号,写一个字节失败   
     I2C_D_REG(num) = Data;               //写数据
     if (wait('T',I2C_No))             //等待一个字节数据传送完成
          return 1;                        //没有传送成功,写一个字节失败
     if (wait('A',I2C_No))             //等待从机应答信号
          return 1;                        //没有等到应答信号,写一个字节失败   
     send_signal('O',I2C_No);          //发送停止信号
          return 0;
}
//============================================================================
//函数名称： i2c_readn                                                        
//功能概要： 从从机读N个字节数据                                             
//参数说明：  I2C_No:模块号       ，其取值为0，1
//       DeviceAddr:设备地址    范围(1~255)
//       DataLocation:数据在从机接收数组中的位置    范围(0~255)
//       Data:读出数据的缓冲区
//       N:从从机读的字节个数 
//函数返回： 为0,成功读N个字节;为1,读N个字节失败  
//函数说明: 内部调用i2c_read1  
//============================================================================
uint_8 i2c_readn(uint_8 I2C_No,uint_8 DeviceAddr, uint_8 DataLocation, uint_8 Data[], uint_8 N)
{
    uint_16 i, j;
    for (i = 0;i < N;i++)
    {
        for(j = 0;j <15*40 ;j++); //最小延时(发送的每个字节之间要有时间间隔)
        if (i2c_read1(I2C_No,DeviceAddr, DataLocation + i, &Data[i]))
             return 1;             //其中一个字节没有接收到,返回失败标志:1
    }
    if (i >= N)
        return 0;                 //成功接收N个数据,返回成功标志:0
}


//============================================================================
//函数名称： i2c_writen                                                        
//功能概要： 向从机写N个字节数据                                              
//参数说明：  I2C_No:模块号       ，其取值为0，1
//       DeviceAddr:设备地址    范围(1~255)
//       DataLocation:数据在从机接收数组中的位置    范围(0~255)
//       Data:要写入的数据 的首地址
//       N:从从机读的字节个数 
//函数返回： 为0,成功写N个字节;为1,写N个字节失败
//函数说明: 内部调用i2c_write1   
//============================================================================
uint_8 i2c_writen(uint_8 I2C_No,uint_8 DeviceAddr, uint_8 DataLocation,uint_8 Data[], uint_8 N)
{
    uint_16 i, j;
    for (i = 0;i < N;i++)
    {
        for(j = 0;j < 15*40;j++); //最小延时(发送的每个字节之间要有时间间隔)
        if (i2c_write1(I2C_No,DeviceAddr, DataLocation + i, Data[i]))
            return 1;            //其中一个字节没有发送出去,返回失败标志:1
    }
    if (i >= N)
        return 0;                //成功发送N个数据,返回成功标志:0
}
//==============================================================================
//函数名称：i2c_re_enable_int.
//功能说明：打开i2c的IRQ中断。
//函数参数：i2cNO:i2c模块号      ，其取值为0，1
//函数返回：无。
//==============================================================================
void i2c_enable_re_int(uint_8 I2C_No)
{
	 enable_irq (I2C_No+8);
}

//==============================================================================
//函数名称：i2c_re_disable_int.
//功能说明：关闭i2c的IRQ中断。
//函数参数：i2cNO:i2c模块号      ，其取值为0,1
//函数返回：无。
//==============================================================================
void i2c_disable_re_int(uint_8 I2C_No)
{
	 disable_irq (I2C_No+8);
}

//============================================================================
//函数名称：i2c_get_base_address                                                        
//功能概要：获取i2c模块的基址                                                
//参数说明：i2cNO:i2c模块号      ，其取值为0，1
//函数返回：i2c模块的基址值                                                                  
//============================================================================
I2C_MemMapPtr i2c_get_base_address(uint_8 I2C_No)
{
        switch(I2C_No)
        {
            case 0:
                    return I2C0_BASE_PTR;
                      break;
            case 1:
                    return I2C1_BASE_PTR;
                       break;
	}
}




