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
uint32_t STR_MODE_DL1 = 261120;//480*272*2����
void Striaight_Mode_Test(TWI_QSPIx_TypeDef *qspi_flash,TWI_QSPIx_TypeDef *qspi_lcd, uint32_t addr);


void QSPI_Striaight_Mode_TFT(void)
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
	  //��ʼ��GPIOΪ���ģʽ	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =GPIO_Mode_OUT_PP ;
	GPIO_InitStruct.GPIO_Pin =GPIO_PIN_All; 
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	GPIOA->PIN = 0XFFFF;//���������     Q1
	PD_BIT(0) = 1;
	PA_BIT(0) = 0;
	PA_BIT(1) = 1;
	PA_BIT(2) = 1;
	PD_BIT(10) = 1; //                    Q2
	//��ʼ��LCD
	Init_LCD(QSPI1);
		
	Striaight_Mode_Test(QSPI0, QSPI1, 0);	
	Delayms(500);
		  
}

void Striaight_Mode_Test(TWI_QSPIx_TypeDef *qspi_flash,TWI_QSPIx_TypeDef *qspi_lcd, uint32_t addr)
{
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
	DispPic_str(QSPI1);		
	//����Ϊֱͨ��ģʽ
	QSPI_ModeSelect(QSPI1,QSPI_Mode_QSPISTRR);
	QSPIx_Write_ComSet(QSPI1,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);
				 
		W25QXX_FastRead(QSPI0,0x6B,addr*STR_MODE_DL1);
		QSPI_ModeSelect(QSPI0,QSPI_Mode_QSPISTRT);
		QSPIx_Read_ComSet(QSPI0,QSPI_LMode_4Line,QSPI_DWidth_32bit,STR_MODE_DL1*1 / 4);	//,QSPI_CLKONLY_ON

		QSPIx_CLKONLYSet(QSPI0, QSPI_CLKONLY_ON);
		while(!DL_OK);

		DL_OK = 0;
		//CS ����
		QSPI_SET_CS_High(QSPI0);
		FLASH_OK = 1;
	
	while(!FLASH_OK); 
	PB_BIT(2) = 1;
	
}
/*==========================================================
                       QSPI0/1�жϷ�����
===========================================================*/
void QSPIx_0_2_TFTDriver()
{
	
	if(READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF))
	 {
		 QSPI0->TWI_QSPIx_STS = 0x00000040;
		 //DLUFIF_IO;
		 DL_OK = 1;
	 }	
}



