/********************************************************************************
 * @file    QSPI_ReadID.c
 * @author  SOC AE Team
 * @version V0.1
 * @date    27-09-2024
 * @brief   QSPI读取外部Flash的ID（ID：EF17）。
 *
 *******************************************************************************/
#include "sc32_conf.h"
#include "Function_Init.h"
#define FIFO_Mode 0
uint8_t i = 0;
uint32_t STR_MODE_DL1 = 261120;//480*272*2像素
uint8_t RFlag = 0;
uint8_t TFlag = 0;
volatile	uint32_t  BUFF = 0;
uint32_t LCDData[32]={0}; 
uint32_t  LCDDataend[8] ={0};	 
void QSPI_FiFO_Mode_TFT(void)
{

	RCC_APB0Cmd(ENABLE);
	RCC_APB1Cmd(ENABLE);
	RCC_APB0PeriphClockCmd(RCC_APB0Periph_QTWI0, ENABLE);//开启QSPI0时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_QTWI1, ENABLE);//开启QSPI1时钟	
	QSPI_InitTypeDef QSPI_InitStruct;
	QSPI_StructInit(&QSPI_InitStruct);
	QSPI_InitStruct.QSPI_CLKONLY = QSPI_CLKONLY_OFF;//只发时钟关闭
	QSPI_InitStruct.QSPI_CPMode = QSPI_CPMode_Low;//空闲时低电平和第一沿采样
	QSPI_InitStruct.QSPI_Prescaler = QSPI_Prescaler_1;//时钟分频16
	QSPI_InitStruct.QSPI_Mode = QSPI_Mode_QSPI;//QSPI半双工模式
	QSPI_InitStruct.QSPI_SShift = QSPI_SShift_HalfClock;//时钟偏移
	QSPI_Init(QSPI0,&QSPI_InitStruct);
	QSPI_Cmd(QSPI0, ENABLE);
	QSPI_Init(QSPI1,&QSPI_InitStruct);
	QSPI_Cmd(QSPI1, ENABLE);
  /* 使能QSPI0中断*/
	NVIC_EnableIRQ(TWIx_QSPIx_0_2_IRQn);
	NVIC_EnableIRQ(TWIx_QSPIx_1_3_IRQn);
  QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|TWI_QSPIx_IDE_DLUFIE, ENABLE);//
	  //初始化GPIO为输出模式	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =GPIO_Mode_OUT_PP ;
	GPIO_InitStruct.GPIO_Pin =GPIO_PIN_All; 
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	GPIOA->PIN = 0XFFFF;//上拉电阻打开     Q1
  PD_BIT(0) = 1;
	PA_BIT(0) = 0;
	PA_BIT(1) = 1;
	PA_BIT(2) = 1;
	PD_BIT(10) = 1; //                    Q2
	//初始化LCD
	Init_LCD(QSPI1);
 
	//TEST//
  PC_BIT(0) = 1;	
	while(1)
	{
		for(i=0;i<32;i++)       
		{			
			 
				QSPI_Init(QSPI0,&QSPI_InitStruct);
				QSPI_Cmd(QSPI0, ENABLE);
				QSPI_Init(QSPI1,&QSPI_InitStruct);
				QSPI_Cmd(QSPI1, ENABLE);
				DispPic_str(QSPI1);		

	       QSPIx_Write_ComSet(QSPI1,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);
		
			
			
			
			
			

				if((W25Q16_QSPIReadID(QSPI0)) ==0xEF17) //再次以QSPI方式问询Flash ID是否成功
				{
						W25QXX_FastRead(QSPI0,0xEB,i*STR_MODE_DL1);
            QSPIx_Read_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_32bit,0);	//,QSPI_CLKONLY_ON
//			 
#if (FIFO_Mode==0)	
           QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|QSPI_IT_RX, ENABLE);
#endif						
			



	
#if (FIFO_Mode==0)	
 PC_BIT(0) = 1;	       	
					  for(uint16_t cnt=0;cnt<0xff00/8;cnt++)
					{ 
						QSPI_Receivelen(QSPI0, 8);	        
						QSPIx_CLKONLYSet(QSPI0, QSPI_CLKONLY_ON);				
						while(DL_OK==0);				
					  DL_OK =  0;   		
		       
	          QSPI_SendDataFIFO (QSPI1, LCDData, 8 ); // 13     6	
 PC_OT(0) ;  			     
					}		

#endif

#if (FIFO_Mode==1)
					
			QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|TWI_QSPIx_IDE_DLUFIE, DISABLE);
 PC_BIT(0) = 1;	
			for(uint16_t cnt=0;cnt<0xff00/8;cnt++)
			 {				         
			QSPIx_CLKONLYSet(QSPI0, QSPI_CLKONLY_ON);				
		
			QSPI_Receivelen(QSPI0, 8);			
										
			while(!(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF)));	

			
			QSPI_ReceiveDataFIFO (QSPI0, LCDData, 8 );	

			QSPI_SendDataFIFO (QSPI1, LCDData, 8 ); 	
			QSPI0->TWI_QSPIx_STS = TWI_QSPIx_STS_DLUFIF;
 PC_OT(0) ;
			}	
					
#endif

		






				  	QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|TWI_QSPIx_IDE_DLUFIE, ENABLE);
					 QSPI_ITConfig(QSPI0, QSPI_IT_RXH, DISABLE);QSPI_ITConfig(QSPI0, QSPI_IT_RX, DISABLE);
					QSPI_ITConfig(QSPI1,  QSPI_IT_TXH, DISABLE);

			
			 	}
 
				//CS 拉高
				QSPI_SET_CS_High(QSPI0);
				FLASH_OK = 1;
				while(!FLASH_OK); 
	
				PB_BIT(2) = 1;
			
			Delayms(500);
		}
		
		Delayms(5000);
	}

		  
}

void QSPIx_0_2_FiFO_TFTDriver(void)
{
	
	 

	if(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF))
	 {
		
		 //DLUFIF_IO;
		 DL_OK = 1;
  QSPI_ReceiveDataFIFO (QSPI0, LCDData, 8 );//18     6				 
  //   QSPI_ReceiveDataFIFO (QSPI0, LCDData+8, 8 );	
     QSPI0->TWI_QSPIx_STS = TWI_QSPIx_STS_RXHIF;    
		 QSPI0->TWI_QSPIx_STS = TWI_QSPIx_STS_DLUFIF|TWI_QSPIx_STS_RXHIF;
	
	 }

}
void QSPIx_1_3_FiFO_TFTDriver(void)
{
	 	if(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_TXHIF))
	 {
		  

		  QSPI1->TWI_QSPIx_STS = TWI_QSPIx_STS_TXHIF; 
		 
		 

	 }	
	
		 	if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_TXEIF))
	 {
		 QSPI1->TWI_QSPIx_STS = 0x00000004;

		 TFlag = 1;
	 }	
}
