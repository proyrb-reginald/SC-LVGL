/********************************************************************************
 * @file    QSPI_Half_Duplex_Data_Transceiving.c
 * @author  SOC AE Team
 * @version V0.1
 * @date    28-10-2024
 * @brief   QSPI普通数据收发(轮询方式/中断方式)。
 *
 *******************************************************************************/
#include "sc32_conf.h"
#include "Function_Init.h"
#define Mode 1

volatile uint8_t  QSPI_Flag=0;

void QSPI_Half_Duplex_Data_Transceiving()
{
		uint16_t READID = 0;
		GPIO_InitTypeDef GPIO_InitStruct; //定义GPIO初始化结构体变量
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT_PP;
		GPIO_Init(GPIOB, &GPIO_InitStruct);
		PB_BIT(13)=1;
//test
//GPIO_InitStruct.GPIO_Mode =GPIO_Mode_OUT_PP ;
//	GPIO_InitStruct.GPIO_Pin =GPIO_PIN_All; 
//	GPIO_Init(GPIOA,&GPIO_InitStruct);
//	GPIO_Init(GPIOB,&GPIO_InitStruct);
//	GPIO_Init(GPIOC,&GPIO_InitStruct);
//	GPIO_Init(GPIOD,&GPIO_InitStruct);
//	PC_BIT(0)=1;
//test	
	
		/*开启QSPI0时钟*/
		RCC_APB0Cmd( ENABLE );		
		RCC_APB0PeriphClockCmd(RCC_APB0Periph_QTWI0,ENABLE); 
		
		QSPI_InitTypeDef QSPI_InitStruct;
		QSPI_StructInit(&QSPI_InitStruct);
		QSPI_InitStruct.QSPI_CLKONLY = QSPI_CLKONLY_OFF;//只发时钟关闭
		QSPI_InitStruct.QSPI_CPMode = QSPI_CPMode_Low;//空闲时低电平和第一沿采样
		QSPI_InitStruct.QSPI_Prescaler = QSPI_Prescaler_1;//时钟分频16
		QSPI_InitStruct.QSPI_Mode = QSPI_Mode_QSPI;//QSPI模式
		QSPI_InitStruct.QSPI_SShift = QSPI_SShift_HalfClock;//时钟偏移
		QSPI_Init(QSPI0,&QSPI_InitStruct);
		QSPI_Cmd(QSPI0, ENABLE);
#if (MoDde==1)	
		/* 使能QSPI0中断 */
	  QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|QSPI_IT_QTWIE, ENABLE);
	  NVIC_EnableIRQ(TWIx_QSPIx_0_2_IRQn);
#endif
		while(1)
		{	
		QSPIx_Write_ComSet(QSPI0,QSPI_LMode_1Line,QSPI_DWidth_8bit,QSPI_CLKONLY_OFF);
		//CS 拉低
		PB_BIT(13) = 0;
#if (Mode==0)
		// 设置发送命令  0X94 Read Manufacturer/Device ID
		QSPI_SendData16(QSPI0,0x94);
		while(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //等待BUSY清零
	
//test
//QSPIx_Write_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);
//PC_BIT(0)=0;	
//QSPI_SendData32(QSPI0,0xffffffff);			
//while(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //等待BUSY清零	
//PC_BIT(0)=1;
//QSPI_SendData32(QSPI0,0xffffffff);	
//while(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //等待BUSY清零				
//PC_BIT(0)=0;	
			
		// 设置 24bit 地址大小发送
		QSPIx_Write_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
//PC_BIT(0)=1;		
		QSPI_SendData32(QSPI0,0x000000);	
		while(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //等待BUSY清零		

		// 设置 3个Dummy
		QSPIx_Write_ComSet(QSPI0,QSPI_LMode_0Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
		QSPI_SendData32(QSPI0,0x000000);	  
			
		QSPIx_Read_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_16bit,1);//,QSPI_CLKONLY_ON
		 QSPIx_CLKONLYSet(QSPI0, QSPI_CLKONLY_ON);
//		QSPI_Receivelen(QSPI0,1);
		while(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //等待BUSY清零
		READID = QSPI0->TWI_QSPIx_DATA;
			

#elif (Mode==1)
		// 设置发送命令  0X94 Read Manufacturer/Device ID
		QSPI_SendData16(QSPI0,0x94);
		while(QSPI_Flag==0); //等待发送结束清零
    QSPI_Flag = 0;
//test	
// 设置 24bit 地址大小发送
//QSPIx_Write_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);
//PC_BIT(0)=0;
//QSPI_SendData32(QSPI0,0xffffffff);	
//while(QSPI_Flag==0); //等待发送结束清零
//PC_BIT(0)=1;
//QSPI_Flag = 0;
//QSPI_SendData32(QSPI0,0xffffffff);	
//while(QSPI_Flag==0); //等待发送结束清零
//PC_BIT(0)=0;
//QSPI_Flag = 0;	


		// 设置 24bit 地址大小发送
		QSPIx_Write_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
//PC_BIT(0)=1;
		QSPI_SendData32(QSPI0,0x000000);	
		while(QSPI_Flag==0); //等待发送结束清零
    QSPI_Flag = 0;	
  

		// 设置 3个Dummy
		QSPIx_Write_ComSet(QSPI0,QSPI_LMode_0Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
		QSPI_SendData32(QSPI0,0x000000);	  
		while(QSPI_Flag==0); //等待发送结束清零
    QSPI_Flag = 0;
		
		QSPIx_Read_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_16bit,1);//,QSPI_CLKONLY_ON
    QSPIx_CLKONLYSet(QSPI0, QSPI_CLKONLY_ON);
	//	QSPI_Receivelen(QSPI0,1);
		while(QSPI_Flag==0); //等待发送结束清零
    QSPI_Flag = 0;
		READID = QSPI_ReceiveData16(QSPI0);	
#endif
    //CS 拉低
		PB_BIT(13) = 1;
		if(READID == 0xEF17)
		{
			printf("读取ID成功");
		}
	 }	  
}

void QSPIx_0_2_ReadID()
{
  if(QSPI_GetFlagStatus(QSPI0,QSPI_FLAG_QTWIF))
	{
		QSPI_ClearFlag(QSPI0,QSPI_FLAG_QTWIF);
		QSPI_Flag = 1;
		
	}
}

