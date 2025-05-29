/*
 ******************************************************************************
 * @file    sc32r803_qspi.c
 * @author  SOC AE Team
 * @version V0.1
 * @date     29-09-2024
 * @brief QSPI function module
 *
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
/* Includes ------------------------------------------------------------------*/
#include "sc32r803_qspi.h"
/** @defgroup QSPI_Exported_Functions_Group1 Configuration of the QSPI computation unit functions
 *  @brief   Configuration of the QSPI computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### QSPI configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the QSPI peripheral registers to their default reset values.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @retval None
 */
void QSPI_DeInit(TWI_QSPIx_TypeDef* QSPIx)
{
    assert_param ( IS_QSPIx_ALL_PERIPH ( QSPIx ) );

    if ( QSPIx == QSPI0 )
    {
			/* Enable QSPI reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI0, ENABLE );
			/* DISABLE QSPI reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI0, DISABLE );
    }
    else if ( QSPIx == QSPI1 )
    {
			/* Enable QSPI reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI1, ENABLE );
			/* DISABLE QSPI reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI1, DISABLE );
    }	
}
/**
  * @brief  Fills each QSPI_InitTypeDef member with its default value.
  * @param  QSPI_InitStruct[out]:Pointer to structure QSPI_InitTypeDef, to be initialized.
  * @retval None
  */
void QSPI_StructInit(QSPI_InitTypeDef* QSPI_InitStruct)
{
			/* Set the default configuration */
			QSPI_InitStruct->QSPI_CLKONLY = QSPI_CLKONLY_OFF;
			QSPI_InitStruct->QSPI_CPMode = QSPI_CPMode_Low;
			QSPI_InitStruct->QSPI_DWidth = QSPI_DWidth_8bit;
			QSPI_InitStruct->QSPI_Mode =  QSPI_Mode_SPI;
			QSPI_InitStruct->QSPI_Prescaler = QSPI_Prescaler_1;
			QSPI_InitStruct->QSPI_RW = QSPI_RW_Write;
			QSPI_InitStruct->QSPI_SShift = QSPI_SShift_OFF;
			QSPI_InitStruct->QSP_LMode = QSPI_LMode_0Line;
	
}
/**
 * @brief  Enables or disables the specified OP peripheral.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_InitStruct[out]:Pointer to structure QSPI_InitTypeDef, to be initialized.
 * @retval None
 */
void QSPI_Init(TWI_QSPIx_TypeDef* QSPIx,QSPI_InitTypeDef* QSPI_InitStruct)
{
	uint32_t tmpreg;
	assert_param (IS_QSPI_SShift(SShift));
	assert_param (IS_QSPI_PRESCALER(PRESCALER));
	assert_param (IS_QSPI_DWidth(DWidth));
  assert_param (IS_QSPI_LMode(LMode) );
	assert_param (IS_QSPI_Mode(Mode));
	assert_param (IS_QSPI_CPMode(CPMode));
	 /*---------------------------- TWI_QSPIx_CON Configuration ------------------------*/
	 /* Get the TWI_QSPIx_CON value */
	tmpreg = QSPIx->TWI_QSPIx_CON;
	 /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , STRDIR , STRTEN  , QTWEN And so on SPR bits */
	tmpreg &= ~(TWI_QSPIx_CON_SSHIFT|TWI_QSPIx_CON_QTWCK|TWI_QSPIx_CON_DWIDTH|TWI_QSPIx_CON_LMODE|\
	            TWI_QSPIx_CON_MODE|TWI_QSPIx_CON_STRDIR|TWI_QSPIx_CON_STRTEN|TWI_QSPIx_CON_STRREN|\
	            TWI_QSPIx_CON_RW|TWI_QSPIx_CON_CPOL|TWI_QSPIx_CON_CPHA|TWI_QSPIx_CON_DORD|TWI_QSPIx_CON_CLKONLY|\
	            TWI_QSPIx_CON_SMSTR|TWI_QSPIx_CON_SPOS|TWI_QSPIx_CON_QTWEN);
	  /* Configure QSPI: SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , STRDIR , STRTEN  , QTWEN And so on SPR bits */
	tmpreg |= (QSPI_InitStruct->QSPI_CLKONLY|QSPI_InitStruct->QSPI_CPMode|QSPI_InitStruct->QSPI_DWidth|\
	           QSPI_InitStruct->QSPI_Mode|QSPI_InitStruct->QSPI_Prescaler|QSPI_InitStruct->QSPI_RW|\
	           QSPI_InitStruct->QSPI_SShift|QSPI_InitStruct->QSP_LMode);
	tmpreg |=TWI_QSPIx_CON_SMSTR;
	 /* Write to TWI_QSPIx_CON */
	QSPIx->TWI_QSPIx_CON = tmpreg;
	
}
/**
 * @brief  Enables or disables the specified QSPI peripheral.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  NewState[in]: new state of the QSPI peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void QSPI_Cmd(TWI_QSPIx_TypeDef* QSPIx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
		if (NewState != DISABLE)
		{
			/* Enable the selected QSPI interrupt */
			QSPIx->TWI_QSPIx_CON |= TWI_QSPIx_CON_QTWEN;
		}
		else
		{
			/* Disable the selected QSPI interrupt */
			QSPIx->TWI_QSPIx_CON  &= ~TWI_QSPIx_CON_QTWEN;
		}
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  DWIDTH[in]: QSPI Work Mode.
 *                  - QSPI_DWidth_8bit:Transmitted data width:8 bit
 *                  - QSPI_DWidth_16bit:Transmitted data width:16 bit
 *                  - QSPI_DWidth_24bit:Transmitted data width:24 bit
 *                  - QSPI_DWidth_32bit:Transmitted data width:32 bit

 * @retval None
 */
void QSPI_SetDataLength(TWI_QSPIx_TypeDef *QSPIx,QSPI_DWidth_TypeDef QSPI_DWidth)
{
	assert_param (IS_QSPI_DWidth(DWidth));
	
	 uint32_t tmpreg;
	/* Get the TWI_QSPIx_CON value */
	tmpreg = QSPIx->TWI_QSPIx_CON;
	 /* Clear DWIDTH SPR bits */
	tmpreg &= ~(TWI_QSPIx_CON_DWIDTH);
	/* Configure QSPI: LMODE, DWIDTH */
	tmpreg |=   QSPI_DWidth;
	 /* Write to TWI_QSPIx_CON */
	QSPIx->TWI_QSPIx_CON = tmpreg;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  LMODE[in]: QSPI Transmitted line.
 *                  - QSP_LMode_0Line:Transmitted line :0 line
 *                  - QSP_LMode_1Line:Transmitted line :1 line
 *                  - QSP_LMode_2Line:Transmitted line :2 line
 *                  - QSP_LMode_4Line:Transmitted line :4 line
 * @retval None
 */
void QSPI_LModeSelect(TWI_QSPIx_TypeDef *QSPIx,QSPI_LMode_TypeDef QSPI_LMode)
{
		assert_param (IS_QSPI_DWidth(DWidth));
	
	 uint32_t tmpreg;
	/* Get the TWI_QSPIx_CON value */
	tmpreg = QSPIx->TWI_QSPIx_CON;
	 /* Clear LMODE SPR bits */
	tmpreg &= ~(TWI_QSPIx_CON_LMODE);
	/* Configure QSPI: LMODE*/
	tmpreg |=   QSPI_LMode;
	 /* Write to TWI_QSPIx_CON */
	QSPIx->TWI_QSPIx_CON = tmpreg;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  LMODE[in]: Work mode.
 *               - QSPI_Mode_SPI:Work mode:SPI 
 *               - QSPI_Mode_QSPI:Work mode:QSPI
 *               - QSPI_Mode_QSPISTRT:Work mode:QSPISTRT
 *               - QSPI_Mode_QSPISTRR:Work mode:QSPISTRR 
 * @retval None
 */
void QSPI_ModeSelect(TWI_QSPIx_TypeDef *QSPIx,QSPI_Mode_TypeDef QSPI_Mode)
{
		assert_param (IS_QSPI_DWidth(DWidth));
	
	 uint32_t tmpreg;
	/* Get the TWI_QSPIx_CON value */
	tmpreg = QSPIx->TWI_QSPIx_CON;
	 /* Clear MODE SPR bits */
	tmpreg &= ~(TWI_QSPIx_CON_MODE);
	/* Configure QSPI: LMODE*/
	tmpreg |=   QSPI_Mode;
	 /* Write to TWI_QSPIx_CON */
	QSPIx->TWI_QSPIx_CON = tmpreg;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  LMODE[in]: QSPI Transmitted line.
 *                  - QSPI_LMode_0Line:Transmitted line :0 line
 *                  - QSPI_LMode_1Line:Transmitted line :1 line
 *                  - QSPI_LMode_2Line:Transmitted line :2 line
 *                  - QSPI_LMode_4Line:Transmitted line :4 line
 * @param  DWIDTH[in]: QSPI Work Mode.
 *                  - QSPI_DWidth_8bit:Transmitted data width:8 bit
 *                  - QSPI_DWidth_16bit:Transmitted data width:16 bit
 *                  - QSPI_DWidth_24bit:Transmitted data width:24 bit
 *                  - QSPI_DWidth_32bit:Transmitted data width:32 bit
 * @param  CLKONLY[in]: Enable or disable QSPI CLKONLY.
 *                  - QSPI_CLKONLY_OFF：Only send the clock OFF
 *                  - QSPI_CLKONLY_ON：Only send the clock ON
 * @retval None
 */
void QSPIx_Write_ComSet( TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE, uint32_t DWIDTH,uint32_t CLKONLY)
{
  uint32_t tmpreg;
	assert_param (IS_QSPI_SShift(SShift));
	assert_param (IS_QSPI_PRESCALER(PRESCALER));
	assert_param (IS_QSPI_DWidth(DWidth));
  assert_param (IS_QSPI_LMode(LMode) );
	assert_param (IS_QSPI_Mode(Mode));
	assert_param (IS_QSPI_CPMode(CPMode));
	/* Get the TWI_QSPIx_CON value */
	tmpreg = QSPIx->TWI_QSPIx_CON;
	 /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , RW SPR bits */
	tmpreg &= ~(TWI_QSPIx_CON_DWIDTH|TWI_QSPIx_CON_LMODE|TWI_QSPIx_CON_RW);
	/* Configure QSPI: LMODE, DWIDTH */
	tmpreg |=   LMODE|DWIDTH;
	 /* Write to TWI_QSPIx_CON */
	QSPIx->TWI_QSPIx_CON = tmpreg;
	/* Configure QSPI: QSPI_CLKONLY */
	if(CLKONLY == QSPI_CLKONLY_ON)                     // 判断只发时钟是否禁止
	{
		QSPIx->TWI_QSPIx_CON  |= QSPI_CLKONLY_ON;
	}
	else
	{
		QSPIx->TWI_QSPIx_CON &= ~QSPI_CLKONLY_ON;
	}
}

/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
void QSPI_SendData8(TWI_QSPIx_TypeDef *QSPIx,uint8_t Data)
{
	 QSPIx->TWI_QSPIx_DATA = (uint8_t) Data;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
void QSPI_SendData16(TWI_QSPIx_TypeDef *QSPIx,uint16_t Data)
{
	 QSPIx->TWI_QSPIx_DATA = (uint16_t) Data;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
void QSPI_SendData32(TWI_QSPIx_TypeDef *QSPIx,uint32_t Data)
{
	 QSPIx->TWI_QSPIx_DATA = (uint32_t) Data;
}
/**
 * @brief  Transmits multiple data through the SPIx peripheral FIFO.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: the datas to transmit.
 * @param  length[in]: the data length to tramsmit.
 * @retval None
 */
void QSPI_SendDataFIFO (TWI_QSPIx_TypeDef *QSPIx, uint32_t* Data, uint16_t length )
{

    uint8_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit 16Bit Data */
		if ( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)>=QSPI_DWidth_24bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA = ( uint32_t ) Data[tmpNum];
				}
		}
		/* Transmit 16 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_16bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA  = ( uint32_t ) ( * ( ( uint16_t* ) Data + tmpNum ) );
				}
		}
				/* Transmit 8 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_8bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA  = ( uint32_t ) ( * ( ( uint8_t* ) Data + tmpNum ) );
				}
		}

}
/**
 * @brief  Transmits multiple data through the QSPIx peripheral .
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI can be select the QSPI1 peripheral.
 * @param  buf[in]: the datas to transmit.
 * @param  len[in]: the data length to tramsmit.
 * @retval None
 */
void QSPI_SendMultipleData(TWI_QSPIx_TypeDef *QSPIx, uint32_t *buf, uint32_t length)
{
    uint8_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit 16Bit Data */
		if ( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)>=QSPI_DWidth_24bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA = ( uint32_t ) buf[tmpNum];
					  while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)==0); //等待BUSY清零
				}
		}
		/* Transmit 16 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_16bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA  = ( uint32_t ) ( * ( ( uint16_t* ) buf + tmpNum ) );
					while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)); //等待BUSY清零
				}
		}
				/* Transmit 8 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_8bit)
		{
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
						QSPIx->TWI_QSPIx_DATA  = ( uint32_t ) ( * ( ( uint8_t* ) buf + tmpNum ) );
					 while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)); //等待BUSY清零
				}
		}	
		// QSPIx->TWI_QSPIx_DL = length;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  LMODE[in]: QSPI Transmitted line.
 *                  - QSP_LMode_0Line:Transmitted line :0 line
 *                  - QSP_LMode_1Line:Transmitted line :1 line
 *                  - QSP_LMode_2Line:Transmitted line :2 line
 *                  - QSP_LMode_4Line:Transmitted line :4 line
 * @param  DWIDTH[in]: QSPI Work Mode.
 *                  - QSPI_Mode_SPI:Work mode:SPI 
 *                  -QSPI_Mode_QSPI:Work mode:QSPI
 *                  -QSPI_Mode_QSPISTRT:Work mode:QSPISTRT 
 *                  -QSPI_Mode_QSPISTRR:Work mode:QSPISTRR 
 * @param  CLKONLY[in]: Enable or disable QSPI CLKONLY.
 *                  - QSPI_CLKONLY_OFF：Only send the clock OFF
 *                  - QSPI_CLKONLY_ON：Only send the clock ON
 * @retval None
 */
void QSPIx_Read_ComSet(TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE, uint32_t DWIDTH, uint32_t length)//,uint32_t CLKONLY
{
			uint32_t tmpreg;
			assert_param (IS_QSPI_SShift(SShift));
			assert_param (IS_QSPI_PRESCALER(PRESCALER));
			assert_param (IS_QSPI_DWidth(DWidth));
			assert_param (IS_QSPI_LMode(LMode) );
			assert_param (IS_QSPI_Mode(Mode));
			assert_param (IS_QSPI_CPMode(CPMode));
			/* Get the TWI_QSPIx_CON value */
			tmpreg = QSPIx->TWI_QSPIx_CON;
			 /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , RW SPR bits */
			tmpreg &= ~(TWI_QSPIx_CON_DWIDTH|TWI_QSPIx_CON_LMODE|TWI_QSPIx_CON_RW);
			/* Configure QSPI: LMODE, DWIDTH */
			tmpreg |=   LMODE|DWIDTH;
			 /* Write to TWI_QSPIx_CON */
    	
	
			QSPIx->TWI_QSPIx_CON = tmpreg;
			/* Configure QSPI: QSPI_CLKONLY */
//			if(CLKONLY == QSPI_CLKONLY_ON)                     
//			{
//				QSPIx->TWI_QSPIx_CON  |= QSPI_CLKONLY_ON;
//			}
//			else
//			{
//				QSPIx->TWI_QSPIx_CON &= ~QSPI_CLKONLY_ON;
//			}
		   QSPIx->TWI_QSPIx_CON |= TWI_QSPIx_CON_RW;
			 /* Clear WI_QSPIx_DL */
			QSPIx->TWI_QSPIx_DL = 0x00;
			
			QSPIx->TWI_QSPIx_DL = length;

			

	
}

void QSPIx_CLKONLYSet(TWI_QSPIx_TypeDef *QSPIx, uint32_t CLKONLY)
{
			if(CLKONLY == QSPI_CLKONLY_ON)                     
			{
				QSPIx->TWI_QSPIx_CON  |= QSPI_CLKONLY_ON;
			}
			else
			{
				QSPIx->TWI_QSPIx_CON &= ~QSPI_CLKONLY_ON;
			}	
}

/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
uint8_t QSPI_ReceiveData8(TWI_QSPIx_TypeDef *QSPIx)
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );

    return ( uint8_t ) QSPIx->TWI_QSPIx_DATA;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
uint16_t QSPI_ReceiveData16(TWI_QSPIx_TypeDef *QSPIx)
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );

    return ( uint16_t ) QSPIx->TWI_QSPIx_DATA;
}
/**
 * @brief  Configure QSPI write conditions.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: QSPI Transmitted Data.
 * @retval None
 */
uint32_t QSPI_ReceiveData32(TWI_QSPIx_TypeDef *QSPIx)
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
	
    return ( uint32_t ) QSPIx->TWI_QSPIx_DATA;
}


/**/
void QSPI_Receivelen(TWI_QSPIx_TypeDef *QSPIx,uint32_t datalen)
{
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
  	QSPIx->TWI_QSPIx_DL = datalen;
    
}
/**
 * @brief  Transmits multiple data through the QSPIx peripheral .
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI can be select the QSPI1 peripheral.
 * @param  buf[in]: the datas to transmit.
 * @param  length[in]: the data length to tramsmit.
 * @retval None
 */
void QSPIx_ReceiveMultipleData(TWI_QSPIx_TypeDef *QSPIx,uint8_t *buf, uint32_t length)
{
    uint8_t tmpNum;

    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    /* Transmit 16Bit Data */
		if ( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)>=QSPI_DWidth_24bit)
		{ 
			
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
				 QSPIx->TWI_QSPIx_DL = 1;
				 QSPIx->TWI_QSPIx_CON |=	TWI_QSPIx_CON_CLKONLY;
				 while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)==0); //等待BUSY清零
					buf[tmpNum]	= QSPIx->TWI_QSPIx_DATA  ;
					
				}
		}
		/* Transmit 16 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_16bit)
		{ 
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
					QSPIx->TWI_QSPIx_DL = 1;
          QSPIx->TWI_QSPIx_CON |=	TWI_QSPIx_CON_CLKONLY;
					while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)); //等待BUSY清零
				 ( * ( ( uint16_t* ) buf + tmpNum ) )=QSPIx->TWI_QSPIx_DATA ;
					
				}
		}
				/* Transmit 8 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_8bit)
		{  
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
					QSPIx->TWI_QSPIx_DL = 1;	
          QSPIx->TWI_QSPIx_CON |=	TWI_QSPIx_CON_CLKONLY;
				while(QSPI_GetFlagStatus(QSPI0,QSPI_Flag_BUSY)); //等待BUSY清零
				 ( * ( ( uint8_t* ) buf + tmpNum ) ) = QSPIx->TWI_QSPIx_DATA  ;
					
				}
		}	

}
/**
 * @brief  QSPIx receives data through FIFO.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  Data[in]: the datas to receive.
 * @param  length[in]: the data length to receive.
 * @retval The received data.
 */
void QSPI_ReceiveDataFIFO (TWI_QSPIx_TypeDef *QSPIx, uint32_t* Data, uint16_t length )
{

    uint8_t tmpNum;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
	 // QSPIx->TWI_QSPIx_DL = length;
    /* Transmit 16Bit Data */
		if ( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)>=QSPI_DWidth_24bit)
		{
			
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
					   Data[tmpNum]	 = QSPIx->TWI_QSPIx_DATA;
				}
		}
		/* Transmit 16 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_16bit)
		{
			
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
					 ( * ( ( uint16_t* ) Data + tmpNum )  = QSPIx->TWI_QSPIx_DATA );
				}
		}
				/* Transmit 8 Bit Data */
		else if( ( QSPIx->TWI_QSPIx_CON & TWI_QSPIx_CON_DWIDTH)==QSPI_DWidth_8bit)
		{
			
				for ( tmpNum = 0; tmpNum < length; tmpNum++ )
				{
				 ( * ( ( uint8_t* ) Data + tmpNum ) =QSPIx->TWI_QSPIx_DATA  );
				}
		}
    

}
/** @defgroup QSPI_Group Interrupts, DMA and flags management functions
 *  @brief   Interrupts, DMA and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the specified SPI interrupts.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_IT[in]:specifies the QSPI interrupts sources to be enabled or disabled.
 *               - QSPI_IT_INTEN:SPI total interruption
 *               - QSPI_IT_RXNE:SPI RX buffer not empty Interrupt
 *               - QSPI_IT_TB:SPI TX buffer is empty Interrupt
 *               - QSPI_IT_RX:Receiving FIFO overflow Interrupt
 *               - QSPI_IT_RXH:Receive FIFO over half Interrupt
 *               - QSPI_IT_TXH:Transmit FIFO under half Interrupt
 *               - QSPI_IT_TBIE：SPI Interrupt: Transmit TBIE under half Interrupt 
 * @param  NewState[in]: new state of the SPI interrupts.
 *               - DISABLE:Function disable
 *               - ENABLE:Function enable
 * @retval None
 */
void QSPI_ITConfig(TWI_QSPIx_TypeDef* QSPIx,uint32_t QSPI_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param ( IS_QSPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_QSPI_IT ( SPI_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        QSPIx->TWI_QSPIx_IDE |= QSPI_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        QSPIx->TWI_QSPIx_IDE &= ( uint16_t ) ~QSPI_IT;
    }
	
}
/**
 * @brief  Checks whether the specified SPI flag is set or not.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_FLAG[in]: specifies the flag to check.
 *         - QSPI_Flag_SPIF:SPI transmit and receive flag
 *         - QSPI_Flag_RINEIF:SPI RX buffer not empty flag
 *         - QSPI_Flag_TXEIF:TX buffer is empty flag
 *         - QSPI_Flag_RXFIF:Receiving FIFO overflow flag
 *         - QSPI_Flag_RXHIF:Receive FIFO over half flag
 *         - QSPI_Flag_TXHIF:Transmit FIFO under half flag
 *         - QSPI_Flag_WCOL:Write conflict flag
 *         - QSPI_FLAG_QTWIF = (uint8_t)SPI1_TWI1_STS_QTWIF  
 * @retval The new state of INT_Flag (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus QSPI_GetFlagStatus ( TWI_QSPIx_TypeDef* QSPIx, QSPI_FLAG_TypeDef QSPI_FLAG )
{

    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_SPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_SPI_FLAG ( SPI_FLAG ) );

    if ( ( QSPIx->TWI_QSPIx_STS & QSPI_FLAG ) != ( uint16_t ) RESET )
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;

}
/**
 * @brief  Clears the SPIx's pending flags.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_FLAG[in]:specifies the flag bit to clear.
 *         - QSPI_Flag_SPIF:SPI transmit and receive flag
 *         - QSPI_Flag_RINEIF:SPI RX buffer not empty flag
 *         - QSPI_Flag_TXEIF:TX buffer is empty flag
 *         - QSPI_Flag_RXFIF:Receiving FIFO overflow flag
 *         - QSPI_Flag_RXHIF:Receive FIFO over half flag
 *         - QSPI_Flag_TXHIF:Transmit FIFO under half flag
 *         - QSPI_Flag_WCOL:Write conflict flag
 * @retval None
 */

void QSPI_ClearFlag (TWI_QSPIx_TypeDef* QSPIx, uint32_t QSPI_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_QSPI_ALL_PERIPH ( QSPI_FLAG ) );
    /* Clear the flags */
    QSPIx->TWI_QSPIx_STS = ( uint16_t ) QSPI_FLAG;

}
/**
 * @brief  Enables or disables the SPI's DMA interface.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_DMAReq[in]: specifies the DMA request.
 *           - QSPI_DMAReq_RX:SPI DMA Request Receive
 *           - QSPI_DMAReq_TX:SPI DMA Request Transmit
 * @param  NewState[in]:new state of the DMA Request sources.
 *           - DISABLE:Function disable
 *           - ENABLE:Function enable
 * @retval None
 */

void QSPI_DMACmd ( TWI_QSPIx_TypeDef* QSPIx, uint16_t QSPI_DMAReq, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_QSPI_ALL_PERIPH ( SPIx ) );
    assert_param ( IS_QSPI_DMAREQ ( QSPI_DMAReq ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the selected SPI DMA requests */
        QSPIx->TWI_QSPIx_IDE |= QSPI_DMAReq;
    }
    else
    {
        /* Disable the selected SPI DMA requests */
         QSPIx->TWI_QSPIx_IDE &= ( uint16_t ) ~QSPI_DMAReq;
    }
}


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF FILE****/
