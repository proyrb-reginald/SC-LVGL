/*****************************************************************************
 Copyright (c)   
  FileName	   : SC_Init.c
  Function	   : Contains the MCU initialization function and its C file
  Instructions   : 
 ******************************************************************************
 * @attention
 *
 *1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only 
 *intended for use with SinOne products. No other uses are authorized. This 
 *software is owned by SinOne Microelectronics Co.,Ltd. and is protected under 
 *all applicable laws, including copyright laws. 
 *2.The software which is for guidance only aims at providing customers with 
 *coding information regarding their products in order for them to save time. 
 *As a result, SinOne shall not be held liable for any direct, indirect or 
 *consequential damages with respect to any claims arising from the content of 
 *such software and/or the use made by customers of the coding information 
 *contained herein in connection with their products.
 *
 *  COPYRIGHT 2024 SinOne Microelectronics
 */

#include "SC_Init.h"	// MCU initialization header file, including all firmware library header files
#include "SC_itExtern.h"


/**************************************Generated by EasyCodeCube*************************************/
//Forbid editing areas between the labels !!!
/*************************************.Generated by EasyCodeCube.************************************/

/*****************************************************
*Function Name: SC_Init
*Function: MCU init
*Input param: void
*Output param: void
*****************************************************/
void SC_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  SC_RCC_Init();
	SC_GPIO_Init();
	SC_DMA0_Init();
	SC_UART0_Init();
	SC_TIM0_Init();
	
  /*<Generated by EasyCodeCube end>*/
}
/*****************************************************
*Function Name: SC_RCC_Init
*Function: RCC init
*Input param: void
*Output param: void
*****************************************************/
void SC_RCC_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
    RCC->RCC_CFG0 |= (0X1 << RCC_CFG0_WAIT_Pos); //WAIT = 01~11
    RCC->RCC_CFG0  |= 0x00004000;
    RCC->RCC_CFG0  |= 0x00000200;
    RCCAHB->AHB_CFG &= ~((uint32_t)AHB_CFG_CLKDIV);
    RCCAHB->AHB_CFG |= ((uint32_t)0x00000000);    //HLCK 1分频
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0  |= 0x00000080;
    RCC_APB0Cmd(ENABLE);
    RCC_APB1Cmd(ENABLE);
		RCC_APB0PeriphClockCmd(RCC_APB0Periph_UART1, ENABLE);//开启UART1时钟
		RCC_APB0PeriphClockCmd(RCC_APB0Periph_QTWI0, ENABLE);//开启UART1时钟
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_QTWI1, ENABLE);//开启UART1时钟
  /*<Generated by EasyCodeCube end>*/	
}
/*****************************************************
*Function Name: SC_SYSTICK_Init
*Function: system timer init
*Input param: void
*Output param: void
*****************************************************/
void SC_SYSTICK_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}
/*****************************************************
*Function Name: SC_OPTION_Init
*Function: custom OPTION init
*Input param: void
*Output param: void
*****************************************************/
void SC_OPTION_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}
/*****************************************************
*Function Name: SC_NVIC_Init
*Function: nvic init
*Input param: void
*Output param: void
*****************************************************/
void SC_NVIC_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_GPIO_Init
*Function: GPIO init
*Input param: void
*Output param: void
*****************************************************/
void SC_GPIO_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
//	/*GPIOInit_PA00 Struct*/GPIO_InitTypeDef GPIOInit_PIN_Struct;
//	GPIOInit_PIN_Struct.GPIO_Pin = GPIO_PIN_All;
//	GPIOInit_PIN_Struct.GPIO_Mode = GPIO_Mode_OUT_PP;
//	GPIOInit_PIN_Struct.GPIO_DriveLevel = 0;
//	GPIO_Init(GPIOA,&GPIOInit_PIN_Struct);/*端口初始化*/
//	GPIO_Init(GPIOB,&GPIOInit_PIN_Struct);/*端口初始化*/
//	GPIO_Init(GPIOC,&GPIOInit_PIN_Struct);/*端口初始化*/
//	GPIO_Init(GPIOD,&GPIOInit_PIN_Struct);/*端口初始化*/
	GPIOA->PXCON = 0XFFFF;
	GPIOB->PXCON = 0XFFFF;
	GPIOC->PXCON = 0XFFFF;	
	GPIOD->PXCON = 0XFFFF;
	GPIOA->PIN = 0XFFFF;
	GPIOB->PIN = 0XFFFF;
	GPIOC->PIN = 0XFFFF;
	GPIOD->PIN = 0XFFFF;
	GPIOB->PXPH = 0xFFFF;

	PD_BIT(0) = 1;
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_UART0_Init
*Function: UART0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
	/*GPIOInit_PC02 Struct*/GPIO_InitTypeDef GPIOInit_PB11_Struct;
	GPIOInit_PB11_Struct.GPIO_Pin = GPIO_Pin_11;
	GPIOInit_PB11_Struct.GPIO_Mode = GPIO_Mode_IN_PU;
	GPIO_Init(GPIOB,&GPIOInit_PB11_Struct);/*TX0?????*/
	/*GPIOInit_PC03 Struct*/GPIO_InitTypeDef GPIOInit_PB12_Struct;
	GPIOInit_PB12_Struct.GPIO_Pin = GPIO_Pin_12;
	GPIOInit_PB12_Struct.GPIO_Mode = GPIO_Mode_IN_PU;
	GPIO_Init(GPIOB,&GPIOInit_PB12_Struct);/*RX0?????*/
	RCC_APB0PeriphClockCmd(RCC_APB0Periph_UART0, ENABLE);
	/*Init Struct*/UART_InitTypeDef UART_InitStruct;
	UART_InitStruct.UART_ClockFrequency = 32000000;
	UART_InitStruct.UART_BaudRate = 115200;
	UART_InitStruct.UART_Mode = UART_Mode_10B;
	UART_Init(UART0, &UART_InitStruct);
	/*INT_EN*/UART_ITConfig(UART0,UART_IT_EN,DISABLE);
	/*DMA_TX*/UART_DMACmd(UART0,UART_DMAReq_TX,DISABLE);
	/*DMA_RX*/UART_DMACmd(UART0,UART_DMAReq_RX,DISABLE);
	/*Init Struct*/UART_PinRemapConfig(UART0,UART_PinRemap_Default);
	UART_TXCmd(UART0,ENABLE);
	UART_RXCmd(UART0,ENABLE);
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_UART1_Init
*Function: UART1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_UART2_Init
*Function: UART2 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART2_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_UART3_Init
*Function: UART3 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART3_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_UART4_Init
*Function: UART4 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART4_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_UART5_Init
*Function: UART5 init
*Input param: void
*Output param: void
*****************************************************/
void SC_UART5_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_TIM0_Init
*Function: Timer0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
	RCC_APB0PeriphClockCmd(RCC_APB0Periph_TIM0,ENABLE);
	/*Init Struct*/TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_WorkMode = TIM_WorkMode_Timer;
	TIM_TimeBaseInitStruct.TIM_Prescaler = TIM_PRESCALER_1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Preload = 33536;
	TIM_TimeBaseInitStruct.TIM_EXENX = TIM_EXENX_Disable;
	TIM_TIMBaseInit(TIM0, &TIM_TimeBaseInitStruct);
	/*Init Struct*/TIM_IC_InitTypeDef TIM_IC_InitStruct;
	TIM_IC_InitStruct.TIM_RICPIN = TIM_RICPin_Disable;
	TIM_IC_InitStruct.TIM_FICPIN = TIM_FICPin_Disable;
	TIM_ICInit(TIM0, &TIM_IC_InitStruct);
	TIM_ICCmd(TIM0, DISABLE);
	/*INTEN*/TIM_ITConfig(TIM0,TIM_IT_INTEN, ENABLE);
	/*TI*/TIM_ITConfig(TIM0,TIM_IT_TI,ENABLE);
	/*Init Struct*/NVIC_SetPriority(TIMER0_IRQn,3);/*TIMER0*/
	NVIC_EnableIRQ(TIMER0_IRQn);
	TIM_Cmd(TIM0,ENABLE);
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_TIM1_Init
*Function: Timer1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_TIM2_Init
*Function: Timer2 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM2_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_TIM3_Init
*Function: Timer3 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM3_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_TIM4_Init
*Function: Timer4 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM4_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_TIM5_Init
*Function: Timer5 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM5_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_TIM6_Init
*Function: Timer6 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM6_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_TIM7_Init
*Function: Timer7 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TIM7_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_PWM0_Init
*Function: PWM0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_PWM0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_LEDPWM_Init
*Function: LEDPWM init
*Input param: void
*Output param: void
*****************************************************/
void SC_LEDPWM_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_INT_Init
*Function: INT init
*Input param: void
*Output param: void
*****************************************************/
void SC_INT_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_ADC_Init
*Function: ADC init
*Input param: void
*Output param: void
*****************************************************/
void SC_ADC_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_OP_Init
*Function: PGA init
*Input param: void
*Output param: void
*****************************************************/
void SC_OP_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_IAP_Init
*Function: IAP init
*Input param: void
*Output param: void
*****************************************************/
void SC_IAP_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_SPI0_Init
*Function: SPI0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_SPI0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_SPI1_Init
*Function: SPI1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_SPI1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_SPI2_Init
*Function: SPI2 init
*Input param: void
*Output param: void
*****************************************************/
void SC_SPI2_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_SPI3_Init
*Function: SPI3 init
*Input param: void
*Output param: void
*****************************************************/
void SC_SPI3_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_TWI0_Init
*Function: TWI0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TWI0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_TWI1_Init
*Function: TWI1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TWI1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_TWI2_Init
*Function: TWI2 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TWI2_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_TWI3_Init
*Function: TWI3 init
*Input param: void
*Output param: void
*****************************************************/
void SC_TWI3_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}
/*****************************************************
*Function Name: SC_BTM_Init
*Function: BTM init
*Input param: void
*Output param: void
*****************************************************/
void SC_BTM_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_CRC_Init
*Function: CRC init
*Input param: void
*Output param: void
*****************************************************/
void SC_CRC_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_DMA0_Init
*Function: DMA0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_DMA0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA,ENABLE);
	/*Init Struct*/DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_Priority = DMA_Priority_LOW;
	DMA_InitStruct.DMA_TargetMode = DMA_TargetMode_FIXED;
	DMA_InitStruct.DMA_SourceMode = DMA_SourceMode_INC;
	DMA_InitStruct.DMA_SrcAddress = 0x0000;
	DMA_InitStruct.DMA_DstAddress = (uint32_t)&QSPI1->TWI_QSPIx_DATA;
	DMA_InitStruct.DMA_DataSize = DMA_DataSize_HakfWord;
	DMA_InitStruct.DMA_Burst = DMA_Burst_Disable;
	DMA_InitStruct.DMA_Request = DMA_Request_TWI_QSPI1_TX;
	DMA_InitStruct.DMA_BufferSize = 0x0000;
	DMA_InitStruct.DMA_CircularMode = DMA_CircularMode_Disable;
	DMA_Init(DMA0, &DMA_InitStruct);
	/*INTEN*/DMA_ITConfig(DMA0,DMA_IT_INTEN, DISABLE);
	DMA_DMACmd(DMA0,DMA_DMAReq_CHRQ,DISABLE);
	DMA_Cmd(DMA0,DISABLE);
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_DMA1_Init
*Function: DMA1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_DMA1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_DMA2_Init
*Function: DMA2 init
*Input param: void
*Output param: void
*****************************************************/
void SC_DMA2_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_DMA3_Init
*Function: DMA3 init
*Input param: void
*Output param: void
*****************************************************/
void SC_DMA3_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_WDT_Init
*Function: WDT init
*Input param: void
*Output param: void
*****************************************************/
void SC_WDT_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}

/*****************************************************
*Function Name: SC_LCD_Init
*Function: LCD init
*Input param: void
*Output param: void
*****************************************************/
void SC_LCD_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_LED_Init
*Function: LED init
*Input param: void
*Output param: void
*****************************************************/
void SC_LED_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/
}

/*****************************************************
*Function Name: SC_ACMP_Init
*Function: ACMP init
*Input param: void
*Output param: void
*****************************************************/
void SC_ACMP_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}
/*****************************************************
*Function Name: SC_CAN_Init
*Function: CANinit
*Input param: void
*Output param: void
*****************************************************/
void SC_CAN_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/	
}
/*****************************************************
*Function Name: SC_QSPI0_Init
*Function: QSPI0 init
*Input param: void
*Output param: void
*****************************************************/
void SC_QSPI0_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
  /*<Generated by EasyCodeCube end>*/		
}

/*****************************************************
*Function Name: SC_QSPI1_Init
*Function: QSPI1 init
*Input param: void
*Output param: void
*****************************************************/
void SC_QSPI1_Init(void)
{
  /*<Generated by EasyCodeCube begin>*/
  //Forbid editing areas between the labels !!!
	QSPI_InitTypeDef QSPI_InitStruct;
	QSPI_StructInit(&QSPI_InitStruct);
	QSPI_InitStruct.QSPI_CLKONLY = QSPI_CLKONLY_OFF;//只发时钟关闭
	QSPI_InitStruct.QSPI_CPMode = QSPI_CPMode_Low;//空闲时低电平和第一沿采样
	QSPI_InitStruct.QSPI_Prescaler = QSPI_Prescaler_1;//时钟分频16
	QSPI_InitStruct.QSPI_Mode = QSPI_Mode_QSPI;//QSPI半双工模式
	QSPI_InitStruct.QSPI_SShift = QSPI_SShift_HalfClock;//时钟偏移
	QSPI_Init(QSPI1,&QSPI_InitStruct);
	NVIC_EnableIRQ(TWIx_QSPIx_1_3_IRQn);
	QSPI_Cmd(QSPI1, ENABLE);
  /*<Generated by EasyCodeCube end>*/		
}






























