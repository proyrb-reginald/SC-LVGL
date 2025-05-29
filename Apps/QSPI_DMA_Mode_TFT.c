/********************************************************************************
 * @file    QSPI_ReadID.c
 * @author  SOC AE Team
 * @version V0.1
 * @date    27-09-2024
 * @brief   QSPI��ȡ�ⲿFlash��ID��ID��EF17����
 *
 *******************************************************************************/
#include "sc32_conf.h"
#include "Function_Init.h"

void QSPI_DMA_Mode_TFT(void)
{

	RCC_APB0Cmd(ENABLE);
	RCC_APB1Cmd(ENABLE);
	RCC_APB0PeriphClockCmd(RCC_APB0Periph_QTWI0, ENABLE);//����QSPI0ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_QTWI1, ENABLE);//����QSPI1ʱ��	
	QSPI_InitTypeDef QSPI_InitStruct;
	QSPI_StructInit(&QSPI_InitStruct);
	QSPI_InitStruct.QSPI_CLKONLY = QSPI_CLKONLY_OFF;//ֻ��ʱ�ӹر�
	QSPI_InitStruct.QSPI_CPMode = QSPI_CPMode_Low;//����ʱ�͵�ƽ�͵�һ�ز���
	QSPI_InitStruct.QSPI_Prescaler = QSPI_Prescaler_1;//ʱ�ӷ�Ƶ16
	QSPI_InitStruct.QSPI_Mode = QSPI_Mode_QSPI;//QSPI��˫��ģʽ
	QSPI_InitStruct.QSPI_SShift = QSPI_SShift_HalfClock;//ʱ��ƫ��
	QSPI_Init(QSPI0,&QSPI_InitStruct);
	QSPI_Cmd(QSPI0, ENABLE);
	QSPI_Init(QSPI1,&QSPI_InitStruct);
	QSPI_Cmd(QSPI1, ENABLE);
  /* ʹ��QSPI0�ж�*/
	NVIC_EnableIRQ(TWIx_QSPIx_0_2_IRQn);
	NVIC_EnableIRQ(TWIx_QSPIx_1_3_IRQn);
  QSPI_ITConfig(QSPI0, TWI_QSPIx_IDE_INTEN|TWI_QSPIx_IDE_DLUFIE, ENABLE);//
	
	RCCAHB->AHB_CFG |= 0X01; //����DMAģ��ʱ��
 
  /* ʹ��DMA��ʱ�� */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA, ENABLE);
  /* DMA�������� */
	DMA_InitTypeDef DMA_InitStruct; //����DMA��ʼ���ṹ�����
  DMA_StructInit(&DMA_InitStruct);
  DMA_InitStruct.DMA_Burst = DMA_Burst_Disable;	//Brustģʽ�ر�
  DMA_InitStruct.DMA_CircularMode = DMA_CircularMode_Disable;	//����ѭ��ģʽ
  DMA_InitStruct.DMA_DataSize = DMA_DataSize_Word;	//������Ϊ�ֽ�
  DMA_InitStruct.DMA_SourceMode = DMA_SourceMode_FIXED;	//Դ��ַ�̶�
  DMA_InitStruct.DMA_TargetMode = DMA_TargetMode_FIXED;	//Ŀ���ַ�̶�

  DMA_InitStruct.DMA_SrcAddress = (uint32_t)&QSPI0->TWI_QSPIx_DATA;	//���õ�һ�δ�����׵�ַ
  DMA_InitStruct.DMA_DstAddress = (uint32_t)&QSPI1->TWI_QSPIx_DATA;	//����Ŀ���ַ
  DMA_InitStruct.DMA_Request = DMA_Request_TWI_QSPI0_RX;	//
	 DMA_Init(DMA0, &DMA_InitStruct);


 

	  //��ʼ��GPIOΪ���ģʽ	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =GPIO_Mode_OUT_PP ;
	GPIO_InitStruct.GPIO_Pin =GPIO_PIN_All; 
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	GPIOA->PIN = 0XFFFF;//���������    
  PD_BIT(0) = 1;
	PA_BIT(0) = 0;
	PA_BIT(1) = 1;
	PA_BIT(2) = 1;
	PD_BIT(10) = 1; //                   
	//��ʼ��LCD
	Init_LCD(QSPI1);

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
				QSPI1->TWI_QSPIx_IDE &=~0x80;
	      QSPI1->TWI_QSPIx_IDE |=0x80;
	       QSPIx_Write_ComSet(QSPI1,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);

				if((W25Q16_QSPIReadID(QSPI0)) ==0xEF17) //�ٴ���QSPI��ʽ��ѯFlash ID�Ƿ�ɹ�
				{
					W25QXX_FastRead(QSPI0,0xEB,i*STR_MODE_DL1);
					DMA_SetCurrDataCounter(DMA0,STR_MODE_DL1*1 / 4); //����DMA������
					
					QSPI_DMACmd (QSPI0, QSPI_DMAReq_RX, DISABLE  );
					QSPI_DMACmd (QSPI0, QSPI_DMAReq_RX, ENABLE  );
					
					DMA_Cmd(DMA0, DISABLE);
					DMA_Cmd(DMA0, ENABLE);
					
					
					
					QSPI0->TWI_QSPIx_STS =0x02;
					DMA0->DMA_STS = 0x0F;
					QSPIx_Read_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_32bit,STR_MODE_DL1*1/4);//,QSPI_CLKONLY_ON
PC_BIT(0) = 0;
			    QSPIx_CLKONLYSet(QSPI0 , QSPI_CLKONLY_ON)	;	
					while(!(DMA0->DMA_STS & DMA_STS_TCIF)); //�ȴ�DMA�������
PC_BIT (0)=1;
					DMA0->DMA_STS |= DMA_STS_TCIF;//���־

						QSPI_SET_CS_High(QSPI0);
						FLASH_OK = 1;
				}
				while(!FLASH_OK); 
	
				PB_BIT(2) = 1;
			
			Delayms(500);
		}
		
		Delayms(5000);
	}
				
				



	

		  
}

///*==========================================================
//                       QSPI0/1�жϷ�����
//===========================================================*/
void QSPIx_0_2_DMA_TFTDriver()
{
	
	if(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF))
	 {
		 QSPI0->TWI_QSPIx_STS = 0x00000040;
		 //DLUFIF_IO;
		 DL_OK = 1;
	 }	
	 


}
