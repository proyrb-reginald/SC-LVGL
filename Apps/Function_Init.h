/********************************************************************************
 * @file    Function_Init_.h
 * @author  SOC AE Team
 * @version V0.1
 * @date    27-09-2023
 * @brief	
 *
 *******************************************************************************/
#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "sc32_conf.h"
#include "stdio.h"

#define LCD_Reset_set()  	PC_BIT(14)=1   //LCD_RESET引脚拉高
#define LCD_Reset_clr() 	PC_BIT(14)=0 //LCD_RESET引脚拉低
#define PIC_COL                 480
#define PIC_ROW                 272

extern	uint8_t i;
extern  uint32_t STR_MODE_DL1;//480*272*2像素

extern uint8_t DL_OK ;
extern uint8_t FLASH_OK;

extern uint32_t TK_exKeyValueFlag;

uint16_t W25Q16_QSPIReadID(TWI_QSPIx_TypeDef *qspi);
void Delayms(uint16_t num);
void Delay(uint32_t count);
void QSPI_SET_CS_High(TWI_QSPIx_TypeDef *qspi);
void QSPI_SET_CS_Low(TWI_QSPIx_TypeDef *qspi);
void write_senddata(TWI_QSPIx_TypeDef *qspi,uint8_t cmddata, uint8_t* data, uint32_t len);
void Init_LCD(TWI_QSPIx_TypeDef *qspi);
void write_sendcmd(TWI_QSPIx_TypeDef *qspi,uint8_t cmddata);
void LCDBlockWrite(TWI_QSPIx_TypeDef *qspi,unsigned int Xstart, unsigned int Xend, unsigned int Ystart, unsigned int Yend);
void W25QXX_FastRead( TWI_QSPIx_TypeDef *qspi,uint8_t	 Readcmd,uint32_t ReadAddr);
void DispPic_str(TWI_QSPIx_TypeDef *qspi);
void Lcd_Refrsh_DMA(TWI_QSPIx_TypeDef *qspi,uint16_t sx, uint16_t ex, uint16_t sy, uint16_t ey, uint16_t *color_p);
void QSPI_Half_Duplex_Data_Transceiving(void);
void QSPI_Striaight_Mode_TFT(void);
void QSPIx_0_2_ReadID(void);
void QSPIx_0_2_TFTDriver(void);
void QSPIx_1_3_TFTDriver(void);
void QSPI_FiFO_Mode_TFT(void);
void QSPIx_0_2_FiFO_TFTDriver(void);
void QSPIx_1_3_FiFO_TFTDriver(void);
void QSPI_DMA_Mode_TFT(void);
void QSPIx_0_2_DMA_TFTDriver(void);
void Sys_Scan(void);
#endif

