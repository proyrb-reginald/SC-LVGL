/**
 ******************************************************************************
 * @file    sc32r803_twi.h
 * @author  SOC AE Team
 * @version V0.1
 * @date     29-09-2024
 * @brief   Header file of TWI module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32r803_TWI_H
#define __sc32r803_TWI_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sc32r803.h"
#include "sc32.h"
#include "sc32r803_rcc.h"

/** @addtogroup sc32r803_StdPeriph_Driver
 * @{
 */

/** @addtogroup TWI
 * @{
 */

/** @defgroup TWI_Enumerations TWI Enumerations
 * @{
 */

/** @brief TWI_Ack TWI Ack State
 * @{
 */
typedef enum
{
    TWI_Ack_Disable = ( uint16_t ) ( 0X00U << TWI_QSPIx_CON_AA_Pos ), /*!< TWI Ack:Disable    */
    TWI_Ack_Enable  = ( uint16_t ) ( 0X01U << TWI_QSPIx_CON_AA_Pos ), /*!< TWI Ack:Enable   */
} TWI_Ack_TypeDef;

#define IS_TWI_ACK(STATE)	(((STATE) == TWI_Ack_Disable) ||  \
												  ((STATE) == TWI_Ack_Enable))
/**
 * @}
 */

/** @brief TWI_Prescaler TWI Prescaler
 * @{
 */

/** @defgroup TWI_Prescaler TWI Prescaler
 * @{
 */
typedef enum
{
	TWI_Prescaler_1 =  (uint16_t)(0x00U << TWI_QSPIx_CON_QTWCK_Pos),    /*!< Clock division: Fsource/1    */
  TWI_Prescaler_2 =  (uint16_t)(0x01U << TWI_QSPIx_CON_QTWCK_Pos),    /*!< Clock division: Fsource/2    */
  TWI_Prescaler_4 =  (uint16_t)(0x02U << TWI_QSPIx_CON_QTWCK_Pos),    /*!< Clock division: Fsource/4    */
  TWI_Prescaler_8 =  (uint16_t)(0x03U << TWI_QSPIx_CON_QTWCK_Pos),    /*!< Clock division: Fsource/8    */
  TWI_Prescaler_16 = (uint16_t)(0x04U << TWI_QSPIx_CON_QTWCK_Pos),   /*!< Clock division: Fsource/16    */
  TWI_Prescaler_32 = (uint16_t)(0x05U << TWI_QSPIx_CON_QTWCK_Pos),   /*!< Clock division: Fsource/32    */
  TWI_Prescaler_64 = (uint16_t)(0x06U << TWI_QSPIx_CON_QTWCK_Pos),   /*!< Clock division: Fsource/64    */
  TWI_Prescaler_128 = (uint16_t)(0x07U << TWI_QSPIx_CON_QTWCK_Pos),  /*!< Clock division: Fsource/128    */
  TWI_Prescaler_256 = (uint16_t)(0x08U << TWI_QSPIx_CON_QTWCK_Pos),  /*!< Clock division: Fsource/256    */
  TWI_Prescaler_512 = (uint16_t)(0x09U << TWI_QSPIx_CON_QTWCK_Pos),  /*!< Clock division: Fsource/512    */
  TWI_Prescaler_1024 = (uint16_t)(0x0AU << TWI_QSPIx_CON_QTWCK_Pos), /*!< Clock division: Fsource/1024    */
  TWI_Prescaler_2048 = (uint16_t)(0x0BU << TWI_QSPIx_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
  TWI_Prescaler_4096 = (uint16_t)(0x0CU << TWI_QSPIx_CON_QTWCK_Pos), /*!< Clock division: Fsource/2048   */
} TWI_Prescaler_TypeDef;

#define IS_TWI_PRESCALER(PRESCALER) (((PRESCALER) == TWI_Prescaler_1) || \
                                     ((PRESCALER) == TWI_Prescaler_2) || \
                                     ((PRESCALER) == TWI_Prescaler_4) || \
                                     ((PRESCALER) == TWI_Prescaler_8) || \
                                     ((PRESCALER) == TWI_Prescaler_16) || \
                                     ((PRESCALER) == TWI_Prescaler_32) || \
                                     ((PRESCALER) == TWI_Prescaler_64) || \
                                     ((PRESCALER) == TWI_Prescaler_128) || \
                                     ((PRESCALER) == TWI_Prescaler_256) || \
                                     ((PRESCALER) == TWI_Prescaler_512) || \
                                     ((PRESCALER) == TWI_Prescaler_1024)|| \
                                     ((PRESCALER) == TWI_Prescaler_2048) || \
                                     ((PRESCALER) == TWI_Prescaler_4096))

/**
 * @}
 */

/** @brief TWI_Stretch TWI Stretch State
 * @{
 */
typedef enum
{
    TWI_Stretch_Disable	= 0X00U << TWI_QSPIx_CON_STRETCH_Pos,  /*!< TWI Slave Clock Stretch:Disable    */
    TWI_Stretch_Enable	= 0X01U << TWI_QSPIx_CON_STRETCH_Pos, /*!< TWI Slave Clock Stretch:Enable   */
} TWI_Stretch_TypeDef;

#define IS_TWI_STRETCH(STRETCH)	(((STRETCH) == TWI_Stretch_Enable) ||  \
																((STRETCH) == TWI_Stretch_Disable))
/**
 * @}
 */

/** @brief TWI_GeneralCall TWI First Bit
 * @{
 */
typedef enum
{
    TWI_GeneralCall_Disable = 0X00U << TWI_QSPIx_ADD_GC_Pos,  /*!< TWI General Call State:Disable    */
    TWI_GeneralCall_Enable = 0X01U << TWI_QSPIx_ADD_GC_Pos, /*!< TWI General Call State:Enable    */
} TWI_GeneralCall_TypeDef;

#define IS_TWI_GENERALCALL(GENERALCALL)	(((GENERALCALL) == TWI_GeneralCall_Disable) ||  \
																				((GENERALCALL) == TWI_GeneralCall_Enable))
/**
 * @}
 */

/** @brief TWI_Command TWI Command
 * @{
 */
typedef enum
{
    TWI_Command_Write = ( uint8_t ) 0X00U, /*!< TWI Command:Write    */
    TWI_Command_Read  = ( uint8_t ) 0X01U, /*!< TWI Command:Read    */
} TWI_Command_TypeDef;

#define IS_TWI_COMMAND(COMMAND)	(((COMMAND) == TWI_Command_Write) ||  \
														    	((COMMAND) == TWI_Command_Read))
/**
 * @}
 */


/** @brief TWI_PinRemap TIM Pin Remap
 * @{
 */

typedef enum
{
    TWI_PinRemap_Default = ( uint32_t ) ( 0x00 << TWI_QSPIx_CON_SPOS_Pos ), /*!< TIM Pin Remap: Disable */
    TWI_PinRemap_A       = ( uint32_t ) ( 0x01 << TWI_QSPIx_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode A */
    TWI_PinRemap_B       = ( uint32_t ) ( 0x02 << TWI_QSPIx_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode B */
    TWI_PinRemap_C       = ( uint32_t ) ( 0x03 << TWI_QSPIx_CON_SPOS_Pos ), /*!< TIM Pin Remap: Remap mode C */
 } TWI_PinRemap_TypeDef;


#define IS_TWI_LIST2_PINREMAP(REMAP) (((REMAP) == TWI_PinRemap_Default) ||  \
																      ((REMAP) == TWI_PinRemap_A) ||  \
																      ((REMAP) == TWI_PinRemap_B) ||  \
																      ((REMAP) == TWI_PinRemap_C))


/**
 * @}
 */

/** @brief TWI_StateMachine TWI StateMachine
 * @{
 */
typedef enum
{
    TWI_Slave_Idle = 0x00 << TWI_QSPIx_STS_STATE_Pos,
    TWI_Slave_ReceivedaAddress = 0x01 << TWI_QSPIx_STS_STATE_Pos,
    TWI_Slave_ReceivedaData = 0x02 << TWI_QSPIx_STS_STATE_Pos,
    TWI_Slave_SendData = 0x03 << TWI_QSPIx_STS_STATE_Pos,

    TWI_Master_Idle = 0x00 <<TWI_QSPIx_STS_STATE_Pos,
    TWI_Master_SendAddress = 0x01 << TWI_QSPIx_STS_STATE_Pos,
    TWI_Master_SendData = 0x02 << TWI_QSPIx_STS_STATE_Pos,
    TWI_Master_ReceivedaData = 0x03 <<TWI_QSPIx_STS_STATE_Pos,
} TWI_StateMachine_TypeDef;

#define IS_TWI_STATEMACHINE(STATE)	(((STATE) == TWI_Slave_Idle) ||  \
															((STATE) == TWI_Slave_ReceivedaAddress) ||  \
                              ((STATE) == TWI_Slave_ReceivedaData) ||  \
                              ((STATE) == TWI_Slave_SendData) ||  \
                              ((STATE) == TWI_Slave_ReceivedaUACK) ||  \
                              ((STATE) == TWI_Master_Idle) ||  \
                              ((STATE) == TWI_Master_SendAddress) ||  \
                              ((STATE) == TWI_Master_SendData) ||  \
                              ((STATE) == TWI_Master_ReceivedaData))
/**
 * @}
 */

/** @brief TWI_IT TWI Interrupt
 * @{
 */
typedef enum
{
    TWI_IT_INT = ( uint32_t ) TWI_QSPIx_IDE_INTEN,	/*!< TWI Interrupt: TWI Interrupt */
	  TWI_IT_QTWIE = (uint32_t) TWI_SPIx_IDE_QTWIE,	/*!< TWI Interrupt: TWI total interruption */	
} TWI_IT_TypeDef;

#define IS_TWI_IT(IT) ((IT) == TWI_IT_INT)
/**
 * @}
 */

/** @brief TWI_DMAReq TWI DMA Request
 * @{
 */
typedef enum
{
    TWI_DMAReq_RX = ( uint32_t ) TWI_QSPIx_IDE_RXDMAEN, /*!< TWI DMA Request: Receive */
    TWI_DMAReq_TX = ( uint32_t ) TWI_QSPIx_IDE_TXDMAEN, /*!< TWI DMA Request: Transmit */
} TWI_DMAReq_TypeDef;

#define IS_TWI_DMAREQ(DMAREQ) (((DMAREQ) == TWI_DMAReq_RX) || \
                               ((DMAREQ) == TWI_DMAReq_TX))
/**
 * @}
 */

/** @brief TWI_FLAG TWI Flag
 * @{
 */

/** @defgroup TWI_FLAG TWI Flag
 * @{
 */
typedef enum
{
  TWI_FLAG_TXRXnE = (uint16_t)TWI_QSPIx_STS_TXERXE, /*!< TWI Flag: Transmit/receive completion flag */
  TWI_FLAG_GCA = (uint16_t)TWI_QSPIx_STS_GCA, /*!< TWI Flag: Generic Call flags */
  TWI_FLAG_QTWIF = (uint8_t)TWI_SPIx_STS_QTWIF, /*!< TWI1 Flag: Interrupt flag */
 
} TWI_FLAG_TypeDef;

#define IS_TWI_FLAG(FLAG) (((FLAG) == TWI_FLAG_TXRXnE) || \
                           ((FLAG) == TWI_FLAG_GCA)||\
													  ((FLAG) == TWI_FLAG_QTWIF) )

/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @brief TWI_Constants TWI Constants
  * @{
  */

#define IS_TWI_ALL_PERIPH(PERIPH) (((PERIPH) == TWI0) || \
                                   ((PERIPH) == TWI1) || \
                                    ((PERIPH) == TWI2) || \
																		((PERIPH) == TWI3))
/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup TWI_Struct TWI Struct
 * @{
 */

/** @brief TWI Time base Configuration Structure definition
 * @{
 */
typedef struct
{
    uint16_t TWI_Ack; /*!< This member configures TWI Ack.
                                              This parameter can be a value of @ref TWI_Ack_TypeDef. */

    uint16_t TWI_Prescaler; /*!< This member configures TWI Prescaler.
                                              This parameter can be a value of @ref TWI_Prescaler_TypeDef. */

    uint16_t TWI_Stretch; /*!< This member configures TWI Stretch.
                                              This parameter can be a value of @ref TWI_Stretch_TypeDef. */

    uint16_t TWI_GeneralCall; /*!< This member configures TWI General Call.
                                              This parameter can be a value of @ref TWI_GeneralCall_TypeDef. */

    uint32_t TWI_SlaveAdress; /*!< This member configures TWI SlaveAdress.
                                              This parameter can be a value of 1 to 127. */

} TWI_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of Struct -----------------------------------------------------*/

/** @addtogroup TWI_Functions TWI Functions
 * @{
 */

/* TWI Base functions ********************************************************/
void TWI_DeInit ( TWI_SPIx_TypeDef* TWIx );
void TWI_Init ( TWI_SPIx_TypeDef* TWIx, TWI_InitTypeDef* TWI_InitStruct );
void TWI_StructInit ( TWI_InitTypeDef* TWI_InitStruct );
void TWI_Cmd ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_AcknowledgeConfig ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_GeneralCallCmd ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_StretchClockConfig ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_SetNbytes ( TWI_SPIx_TypeDef* TWIx, uint8_t Nbytes );
uint8_t TWI_GetNbytes ( TWI_SPIx_TypeDef* TWIx );
/* Data transfers functions ********************************************************/
void TWI_GenerateSTART ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_GenerateSTOP ( TWI_SPIx_TypeDef* TWIx, FunctionalState NewState );
void TWI_Send7bitAddress ( TWI_SPIx_TypeDef* TWIx, uint8_t Address, TWI_Command_TypeDef TWI_Command );
void TWI_SendData ( TWI_SPIx_TypeDef* TWIx, uint8_t Data );
uint16_t TWI_ReceiveData ( TWI_SPIx_TypeDef* TWIx );

/* Pin remap management functions  **********************************************/
void TWI_PinRemapConfig ( TWI_SPIx_TypeDef* TWIx, TWI_PinRemap_TypeDef TWI_Remap );

/* Interrupts, DMA and flags management functions  **********************************************/
void TWI_ITConfig ( TWI_SPIx_TypeDef* TWIx, uint16_t TWI_IT, FunctionalState NewState );
FlagStatus TWI_GetFlagStatus ( TWI_SPIx_TypeDef* TWIx, TWI_FLAG_TypeDef TWI_FLAG );
TWI_StateMachine_TypeDef TWI_GetStateMachine ( TWI_SPIx_TypeDef* TWIx );
void TWI_ClearFlag ( TWI_SPIx_TypeDef* TWIx, TWI_FLAG_TypeDef TWI_FLAG );
void TWI_DMACmd ( TWI_SPIx_TypeDef* TWIx, TWI_DMAReq_TypeDef TWI_DMAReq, FunctionalState NewState );

/**
 * @}
 */
/* End of functions --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
