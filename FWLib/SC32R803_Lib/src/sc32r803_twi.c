/*
 ******************************************************************************
 * @file    sc32r803_twi.c
 * @author  SOC AE Team
 * @version V0.1
 * @date    29-09-2024
 * @brief TWI function module
 *
 *******************************************************************************
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
#include "sc32r803_twi.h"

/** @defgroup TWI_Group1 Configuration of the TWI computation unit functions
 *  @brief   Configuration of the TWI computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### TWI configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitialize the TWIx peripheral registers to their default reset values.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @retval None
 */
void TWI_DeInit ( TWI_SPIx_TypeDef* TWIx )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    if ( TWIx == TWI0 )
    {
        /* Enable TWI0 reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI0, ENABLE );
        /* Disable TWI0 reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI0, DISABLE );
    }
    else if ( TWIx == TWI1 )
    {
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI1, ENABLE );
        /* Disable TWI0 reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI1, DISABLE );
			
    }
    else if ( TWIx == TWI2 )
    {
        /* Enable TWI0 reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI2, ENABLE );
        /* Disable TWI0 reset state */
        RCC_APB0PeriphResetCmd ( RCC_APB0Periph_QTWI2, DISABLE );
			
    }
    else if ( TWIx == TWI3 )
    {
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI3, ENABLE );
        /* Disable TWI0 reset state */
        RCC_APB1PeriphResetCmd ( RCC_APB1Periph_QTWI3, DISABLE );
			
    }
}

/**
  * @brief  Fills each TWI_InitStruct member with its default value.
  * @param  TWI_InitStruct[out]: Pointer to structure TWI_InitTypeDef, to be initialized.
  * @retval None
  */
void TWI_StructInit ( TWI_InitTypeDef* TWI_InitStruct )
{
    /* Set the default configuration */
    TWI_InitStruct->TWI_Ack = TWI_Ack_Enable;
    TWI_InitStruct->TWI_Prescaler = 0x00;
    TWI_InitStruct->TWI_Stretch = 0;

    TWI_InitStruct->TWI_GeneralCall = TWI_GeneralCall_Disable;
    TWI_InitStruct->TWI_SlaveAdress = 0x00;
}

/**
 * @brief  Initializes the peripheral TWIx register with the parameters specified in TWI_InitStruct
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_InitStruct[out]: Pointer to structure TWI_InitTypeDef, to be initialized.
 * @retval None
 */
void TWI_Init ( TWI_SPIx_TypeDef* TWIx, TWI_InitTypeDef* TWI_InitStruct )
{

  uint32_t tmpreg;
  /* Check the parameters */
  assert_param(IS_TWI_ALL_PERIPH(TWIx));
  assert_param(IS_TWI_ACK(TWI_InitStruct->TWI_Ack));
  assert_param(IS_TWI_PRESCALER(TWI_InitStruct->TWI_Prescaler));
  assert_param(IS_TWI_STRETCH(TWI_InitStruct->TWI_Stretch));
  assert_param(IS_TWI_GENERALCALL(TWI_InitStruct->TWI_GeneralCall));
	/*---------------------------- TWIx TWI_CON Configuration ------------------------*/

	/* Get the TWIx TWI_CON value */
  tmpreg = TWIx->TWI_SPIx_CON;
  /* Clear AA, TWCK, STRETCH bits */
  tmpreg &= (uint32_t) ~(TWI_QSPIx_CON_AA | TWI_QSPIx_CON_SPOS | TWI_QSPIx_CON_STRETCH |TWI_QSPIx_CON_QTWCK);
  /* Configure TWIx: Ack, Clock division and Slave Clock Stretch */
  /* Set AA bits to TWI_Ack value */
  /* Set TWCK bits according to TWI_DataSize value */
  /* Set STRETCH bit according to TWI_Stretch value */


	tmpreg &=~TWI_QSPIx_CON_MODE;
  tmpreg |= (uint32_t)(TWI_InitStruct->TWI_Ack | TWI_InitStruct->TWI_Prescaler |TWI_InitStruct->TWI_Stretch);
  /* Write to TWIx TWI_CON */
  TWIx->TWI_SPIx_CON = tmpreg;
  /*---------------------------- TWIx TWI_ADD Configuration ------------------------*/
  /* Get the TWIx TWI_ADD value */
  tmpreg = TWIx->TWI_SPIx_ADD;
  /* Clear GC, TWCK, STRETCH bits */
  tmpreg &= (uint32_t) ~(TWI_QSPIx_ADD_GC | TWI_QSPIx_ADD_QTWADD);
  /* Configure TWIx: General Call and Slave Slave Address */
  /* Set AA bits to TWI_GC value */
  /* Set TWA according to TWI_SlaveAdress value */
  tmpreg |= (uint32_t)(TWI_InitStruct->TWI_GeneralCall |  ( ( TWI_InitStruct->TWI_SlaveAdress << 1 ) & 0xFE ) );

  /* Write to TWIx TWI_ADD */
  TWIx->TWI_SPIx_ADD = tmpreg;

}

/**
 * @brief  Enables or disables the specified TWI peripheral.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  NewState[in]:new state of the TWIx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TWI_Cmd ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the TWI Function */
        TWIx->TWI_SPIx_CON |= TWI_SPIx_CON_QTWEN;
    }
    else
    {
        /* Disable the TWI Function */
        TWIx->TWI_SPIx_CON &= ( uint16_t ) ~TWI_SPIx_CON_QTWEN;
    }
}

/**
  * @brief  Enables or disables the specified TWI acknowledge feature.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  NewState[in]: new state of the TWI Acknowledgement.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None.
  */
void TWI_AcknowledgeConfig ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the acknowledgement */
        TWIx->TWI_SPIx_CON |= TWI_SPIx_CON_AA;
    }
    else
    {
        /* Disable the acknowledgement */
       TWIx->TWI_SPIx_CON &= ( uint16_t ) ~TWI_SPIx_CON_AA;
    }
}

/**
  * @brief  Enables or disables the specified TWI general call feature.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  NewState[in]: new state of the TWI General call.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void TWI_GeneralCallCmd ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable general call */
        TWIx->TWI_SPIx_ADD|= TWI_QSPIx_ADD_GC;
    }
    else
    {
        /* Disable general call */
        TWIx->TWI_SPIx_ADD &= ( uint16_t ) ~TWI_QSPIx_ADD_GC;
    }
}

/**
  * @brief  Enables or disables the specified TWI Clock stretching.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  NewState[in]: new state of the TWIx Clock stretching.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None
  */
void TWI_StretchClockConfig ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState == DISABLE )
    {
        /* Enable the selected TWI Clock stretching */
        TWIx->TWI_SPIx_CON|= TWI_QSPIx_CON_STRETCH;
    }
    else
    {
        /* Disable the selected TWI Clock stretching */
        TWIx->TWI_SPIx_CON &= ( uint16_t ) ~ ( ( uint16_t ) TWI_QSPIx_CON_STRETCH );
    }
}

/**
  * @brief  Example Set the number of Nbytes.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  Nbytes[in]: Number of bytes to be sent or received.
  *          This parameter can be less than 256.
  * @retval None
  */
void TWI_SetNbytes ( TWI_SPIx_TypeDef* TWIx, uint8_t Nbytes )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );

    TWIx->TWI_SPIx_STS = ( uint32_t ) ( Nbytes << TWI_QSPIx_STS_NBYTES_Pos );
}

/**
  * @brief  Obtain the number of remaining Nbytes.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @retval Number of bytes to be sent or received.
  */
uint8_t TWI_GetNbytes ( TWI_SPIx_TypeDef* TWIx )
{
    uint8_t tmpnum;

    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );

    tmpnum = ( uint8_t ) ( TWIx->TWI_SPIx_STS  >> TWI_QSPIx_STS_NBYTES_Pos );

    return tmpnum;
}

/** @defgroup TWI_Group2 Data transfers functions
 *  @brief   Data transfers functions
 *
@verbatim
 ===============================================================================
                      ##### Data transfers functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
  * @brief  Generates TWIx communication START condition.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  NewState[in]:new state of the TWI START condition generation.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None.
  */
void TWI_GenerateSTART ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Generate a START condition */
        TWIx->TWI_SPIx_CON |= TWI_SPIx_CON_START;
    }
    else
    {
        /* Disable the START condition generation */
       TWIx->TWI_SPIx_CON &= ( uint16_t ) ~TWI_SPIx_CON_START;
    }
}

/**
  * @brief  Generates TWIx communication STOP condition.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  NewState[in]:new state of the TWI STOP condition generation.
  *                  - DISABLE:Function disable
  *                  - ENABLE:Function enable
  * @retval None.
  */
void TWI_GenerateSTOP ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Generate a STOP condition */
        TWIx->TWI_SPIx_CON |= TWI_SPIx_CON_STOP;
    }
    else
    {
        /* Disable the STOP condition generation */
        TWIx->TWI_SPIx_CON &= ( uint16_t ) ~TWI_SPIx_CON_STOP;
    }
}

/**
  * @brief  Sends an address word to the specified slave TWI device.
	* @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
  * @param  Address[in]: specifies the slave address which will be transmitted
  * @param  TWI_Command[in]:specifies whether the TWI device will be a Transmitter or a Receiver.
  *                  - TWI_Command_Write:TWI Command:Write
  *                  - TWI_Command_Read:TWI Command:Read
  * @retval None.
  */
void TWI_Send7bitAddress ( TWI_SPIx_TypeDef* TWIx, uint8_t Address, TWI_Command_TypeDef TWI_Command )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_TWI_COMMAND ( TWI_Command ) );
    Address = ( Address << 1 );
    /* Test on the direction to set/reset the read/write bit */
    if ( TWI_Command != TWI_Command_Write )
    {
        /* Set the address bit0 for read */
        Address |= TWI_Command_Read;
    }
    else
    {
        /* Reset the address bit0 for write */
        Address &= ( uint8_t ) ~ ( ( uint8_t ) TWI_Command_Read );
    }

    /* Send the address */
    TWIx->TWI_SPIx_DATA = Address;
}

/**
 * @}
 */


/**
 * @brief  Send a data through the peripheral TWIx.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  Data[in]: the data to transmit.
 * @retval None
 */
void TWI_SendData ( TWI_SPIx_TypeDef* TWIx, uint8_t Data )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    /* Transmit Data */
    TWIx->TWI_SPIx_DATA = Data;
}

/**
 * @brief  Returns the most recent data received via TWIx.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @retval the most recent data received via TWIx.
 */
uint16_t TWI_ReceiveData ( TWI_SPIx_TypeDef* TWIx )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    /* Receive Data */
    return ( uint16_t ) TWIx->TWI_SPIx_DATA;
}

/**
 * @}
 */

/**
 * @brief  Configures the TIMx Pin Remap
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_Remap[in]:specifies the TIM input remapping source.
 *                  - TWI_PinRemap_Default:TIM Pin Remap  Disable
 *                  - TWI_PinRemap_A:TIM Pin Remap: Remap mode A
 *                  - TWI_PinRemap_B:TIM Pin Remap: Remap mode B
 *                  - TWI_PinRemap_C:TIM Pin Remap: Remap mode C
 * @retval None
 */
void TWI_PinRemapConfig ( TWI_SPIx_TypeDef* TWIx, TWI_PinRemap_TypeDef TWI_Remap )
{

  uint32_t tmpreg ;
  /* Check the parameters */
  assert_param(IS_TWI_ALL_PERIPH(TWIx));
  
	

  tmpreg = TWIx->TWI_SPIx_CON;

  tmpreg &= (uint32_t)(~TWI_SPIx_CON_SPOS);

  tmpreg |= TWI_Remap;

  TWIx->TWI_SPIx_CON = tmpreg;
	
}

/**
 * @}
 */
/* End of TWI_Group3.	*/

/** @defgroup TWI_Group4 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
 *
@verbatim
 ===============================================================================
            ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the specified TWI interrupts.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_IT[in]:specifies the TWI interrupts sources to be enabled or disabled.
 *                  - TWI_IT_INT: TWI Interrupt
 * @param  NewState[in]: new state of the TWI interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 *
 * @retval None
 */
void TWI_ITConfig ( TWI_SPIx_TypeDef* TWIx, uint16_t TWI_IT, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_TWI_IT ( TWI_IT ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the Interrupt sources */
        TWIx->TWI_SPIx_IDE |= TWI_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        TWIx->TWI_SPIx_IDE &= ( uint16_t ) ~TWI_IT;
    }
}

/**
 * @brief  Checks whether the specified TWI flag is set or not.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_FLAG[in]: specifies the flag to check.
 *                  - TWI_FLAG_TXRXnE:Transmit/receive completion flag
 *                  - TWI_FLAG_GCA:Generic Call flags
 *                  - TWI_FLAG_MSTR:Flag to identify master or slave
 *                  - TWI_FLAG_QTWIF:Flag about QTWIF
 * @retval The new state of TWI_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus TWI_GetFlagStatus ( TWI_SPIx_TypeDef* TWIx, TWI_FLAG_TypeDef TWI_FLAG )
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_TWI_FLAG ( TWI_FLAG ) );
    if ( ( TWIx->TWI_SPIx_STS & TWI_FLAG ) != ( uint16_t ) RESET )
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
 * @brief  Clears the TWIx's pending flags.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_FLAG[in]: specifies the flag bit to clear.
 *                  - TWI_FLAG_TWIF:Interrupt flag 
 *                  - TWI_FLAG_TXRXnE:Transmit/receive completion flag 
 *                  - TWI_FLAG_GCA:Generic Call flags  
 *                  - TWI_FLAG_QTWIF:TWI FLAG QTWIF
 * @retval None
 */
void TWI_ClearFlag ( TWI_SPIx_TypeDef* TWIx, TWI_FLAG_TypeDef TWI_FLAG )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    /* Clear the flags */
    TWIx->TWI_SPIx_STS |= ( uint16_t ) TWI_FLAG;
}

/**
 * @brief  Get whether the specified TWI State Machine.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @retval The new state  Machine of TWIx.
 *                  - TWI_Slave_Idle
 *                  - TWI_Slave_ReceivedaAddress
 *                  - TWI_Slave_ReceivedaData
 *                  - TWI_Slave_SendData
 *                  - TWI_Master_Idle
 *                  - TWI_Master_SendAddress
 *                  - TWI_Master_SendData
 *                  - TWI_Master_ReceivedaData
 */
TWI_StateMachine_TypeDef TWI_GetStateMachine ( TWI_SPIx_TypeDef* TWIx )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );

    return ( TWI_StateMachine_TypeDef ) ( TWIx->TWI_SPIx_STS & TWI_SPIx_STS_STATE );
}

/**
 * @brief  Enables or disables the TWI's DMA interface.
 * @param  TWIx[out]:where x can be 0 or 1 to select the TWIx peripheral.
 *                  - TWI0:Timer peripheral select TWI0
 *                  - TWI1:Timer peripheral select TWI1
 *                  - TWI2:Timer peripheral select TWI2
 *                  - TWI3:Timer peripheral select TWI3
 * @param  TWI_DMAReq[in]:specifies the DMA request.
 *                - TWI_DMAReq_RX:TWI DMA Request  Receive
 *                - TWI_DMAReq_TX :TWI DMA Request: Transmit
 * @param  NewState[in]:new state of the DMA Request sources.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TWI_DMACmd ( TWI_SPIx_TypeDef* TWIx, TWI_DMAReq_TypeDef TWI_DMAReq, FunctionalState NewState )
{
    /* Check the parameters */
    assert_param ( IS_TWI_ALL_PERIPH ( TWIx ) );
    assert_param ( IS_TWI_DMAREQ ( TWI_DMAReq ) );
    assert_param ( IS_FUNCTIONAL_STATE ( NewState ) );
    if ( NewState != DISABLE )
    {
        /* Enable the selected TWI DMA requests */
        TWIx->TWI_SPIx_IDE |= TWI_DMAReq;
    }
    else
    {
        /* Disable the selected TWI DMA requests */
        TWIx->TWI_SPIx_IDE &= ( uint16_t ) ~TWI_DMAReq;
    }
}

/**
 * @}
 */
/* End of TWI_Group4.	*/

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
