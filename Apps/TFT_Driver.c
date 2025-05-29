#include "sc32_conf.h"
#include "Function_Init.h"
#define LCD_Reset_set()  	PC_BIT(14)=1   //LCD_RESET��������
#define LCD_Reset_clr() 	PC_BIT(14)=0 //LCD_RESET��������
#define PIC_COL                 480
#define PIC_ROW                 272



uint8_t  INITLCD_flag = 0;

//uint8_t WriteData[30]= { 0xf1,0xe2,0x55,0xAA,0xb5 ,0xa6 ,0x98,0x77,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xff};
uint8_t DL_OK = 0;
uint8_t FLASH_OK = 0;
//LCD��ʼ������
uint8_t DATA0[]={0x00,0x00,0xff,0x00,0xa5};
uint8_t DATA1[]={0x00,0x00,0xe7,0x00,0x10};
uint8_t DATA2[]={0x00,0x00,0x35,0x00,0x00};
uint8_t DATA3[]={0x00,0x00,0x43,0x00,0x00};//RGB565��Ҫ43H[0]Ϊ0
uint8_t DATA4[]={0x00,0x00,0x3a,0x00,0x01};
uint8_t DATA5[]={0x00,0x00,0x40,0x00,0x01};
//uint8_t DATA6[]={0x00,0x00,0x41,0x00,0x01};
uint8_t DATA7[]={0x00,0x00,0x55,0x00,0x01};
uint8_t DATA8[]={0x00,0x00,0x44,0x00,0x15};//0X05 16bit; 0x02  8bit;0x07 24bit
uint8_t DATA9[]={0x00,0x00,0x45,0x00,0x15};
uint8_t DATA10[]={0x00,0x00,0x7d,0x00,0x03};
uint8_t DATA11[]={0x00,0x00,0xc1,0x00,0xbb};
uint8_t DATA12[]={0x00,0x00,0xc2,0x00,0x13};
uint8_t DATA13[]={0x00,0x00,0xc3,0x00,0X10};
uint8_t DATA14[]={0x00,0x00,0xc6,0x00,0x3e};
uint8_t DATA15[]={0x00,0x00,0xc7,0x00,0x25};
uint8_t DATA16[]={0x00,0x00,0xc8,0x00,0x11};
uint8_t DATA17[]={0x00,0x00,0x00,0x00,0x66};
uint8_t DATA18[]={0x00,0x00,0x00,0x00,0x49};
uint8_t DATA19[]={0x00,0x00,0x00,0x00,0x57};
uint8_t DATA20[]={0x00,0x00,0x00,0x00,0x08};
uint8_t DATA21[]={0x00,0x00,0x00,0x00,0x13};
uint8_t DATA22[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA23[]={0x00,0x00,0x00,0x00,0x33};
uint8_t DATA24[]={0x00,0x00,0x00,0x00,0x4b};
uint8_t DATA25[]={0x00,0x00,0x00,0x00,0x7c};
uint8_t DATA26[]={0x00,0x00,0x00,0x00,0x45};
uint8_t DATA27[]={0x00,0x00,0x00,0x00,0x77};
uint8_t DATA28[]={0x00,0x00,0x00,0x00,0x0a};
uint8_t DATA29[]={0x00,0x00,0x00,0x00,0x2a};
uint8_t DATA30[]={0x00,0x00,0x00,0x00,0x0a};
uint8_t DATA31[]={0x00,0x00,0x00,0x00,0x1a};
uint8_t DATA32[]={0x00,0x00,0x00,0x00,0x43};		
uint8_t DATA33[]={0x00,0x00,0x00,0x00,0x42};
uint8_t DATA34[]={0x00,0x00,0x00,0x00,0x3c};
uint8_t DATA35[]={0x00,0x00,0x00,0x00,0x64};
uint8_t DATA36[]={0x00,0x00,0x00,0x00,0x41};
//uint8_t DATA37[]={0x00,0x00,0x00,0x00,0x80,0x03,0x08,0x06,0x05,0x2B};	
uint8_t DATA37[]={0x00,0x00,0x00,0x00,0x3c};	
uint8_t DATA38[]={0x00,0x00,0x00,0x00,0x02};
uint8_t DATA39[]={0x00,0x00,0x00,0x00,0x3c};
uint8_t DATA40[]={0x00,0x00,0x00,0x00,0x1f};
uint8_t DATA41[]={0x00,0x00,0x00,0x00,0x80};
uint8_t DATA42[]={0x00,0x00,0x00,0x00,0x3f};
//uint8_t DATA42[]={0x00,0x00,0x00,0x00,0xFF,0xFF,0XFF,0XFF};
uint8_t DATA43[]={0x00,0x00,0x00,0x00,0x21};
uint8_t DATA44[]={0x00,0x00,0x00,0x00,0x07};
uint8_t DATA45[]={0x00,0x00,0x00,0x00,0xe0};
uint8_t DATA46[]={0x00,0x00,0x00,0x00,0x01};
uint8_t DATA47[]={0x00,0x00,0x00,0x00,0x14};
uint8_t DATA48[]={0x00,0x00,0x00,0x00,0x20};
uint8_t DATA49[]={0x00,0x00,0x00,0x00,0x52};
uint8_t DATA50[]={0x00,0x00,0x00,0x00,0x10};
uint8_t DATA51[]={0x00,0x00,0x00,0x00,0x42};
uint8_t DATA52[]={0x00,0x00,0x00,0x00,0x20};
uint8_t DATA53[]={0x00,0x00,0x00,0x00,0x52};
uint8_t DATA54[]={0x00,0x00,0x00,0x00,0x10};
uint8_t DATA55[]={0x00,0x00,0x00,0x00,0x42};
//uint8_t DATA56[]={0x00,0x00,0x00,0x00,0x20};
//uint8_t DATA57[]={0x00,0x00,0x00,0x00,0x52};
//uint8_t DATA58[]={0x00,0x00,0x00,0x00,0x10};
//uint8_t DATA59[]={0x00,0x00,0x00,0x00,0x42};
uint8_t DATA60[]={0x00,0x00,0x00,0x00,0x0a};
uint8_t DATA61[]={0x00,0x00,0x00,0x00,0x32};
//uint8_t DATA62[]={0x00,0x00,0x00,0x00,0x06};
//uint8_t DATA63[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA64[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA65[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA66[]={0x00,0x00,0x00,0x00,0x05};
uint8_t DATA67[]={0x00,0x00,0x00,0x00,0x03};
uint8_t DATA68[]={0x00,0x00,0x00,0x00,0x02};
uint8_t DATA69[]={0x00,0x00,0x00,0x00,0x2d};
uint8_t DATA70[]={0x00,0x00,0x00,0x00,0x02};
uint8_t DATA71[]={0x00,0x00,0x00,0x00,0x1A};
uint8_t DATA72[]={0x00,0x00,0x00,0x00,0x40};
uint8_t DATA73[]={0x00,0x00,0x00,0x00,0x3F};
uint8_t DATA74[]={0x00,0x00,0x00,0x00,0x38};
uint8_t DATA75[]={0x00,0x00,0x00,0x00,0x37};
uint8_t DATA76[]={0x00,0x00,0x00,0x00,0x37};
uint8_t DATA77[]={0x00,0x00,0x00,0x00,0x36};
uint8_t DATA78[]={0x00,0x00,0x00,0x00,0x28};
uint8_t DATA79[]={0x00,0x00,0x00,0x00,0x28};
uint8_t DATA80[]={0x00,0x00,0x00,0x00,0x09};
uint8_t DATA81[]={0x00,0x00,0x00,0x00,0x05};
uint8_t DATA82[]={0x00,0x00,0x00,0x00,0x0f};
uint8_t DATA83[]={0x00,0x00,0x00,0x00,0x0c};
uint8_t DATA84[]={0x00,0x00,0x00,0x00,0x18};
uint8_t DATA85[]={0x00,0x00,0x00,0x00,0x14};
uint8_t DATA86[]={0x00,0x00,0x00,0x00,0x12};
uint8_t DATA87[]={0x00,0x00,0x00,0x00,0x0E};
uint8_t DATA88[]={0x00,0x00,0x00,0x00,0x15};
uint8_t DATA89[]={0x00,0x00,0x00,0x00,0x15};
uint8_t DATA90[]={0x00,0x00,0x00,0x00,0x11};
uint8_t DATA91[]={0x00,0x00,0x00,0x00,0x15};
uint8_t DATA92[]={0x00,0x00,0x00,0x00,0x12};
uint8_t DATA93[]={0x00,0x00,0x00,0x00,0x11};
uint8_t DATA94[]={0x00,0x00,0x00,0x00,0x19};
uint8_t DATA95[]={0x00,0x00,0x00,0x00,0x0F};
uint8_t DATA96[]={0x00,0x00,0x00,0x00,0x04};
uint8_t DATA97[]={0x00,0x00,0x00,0x00,0x01};
uint8_t DATA98[]={0x00,0x00,0x00,0x00,0x11};
uint8_t DATA99[]={0x00,0x00,0x00,0x00,0x0D};
uint8_t DATA100[]={0x00,0x00,0x00,0x00,0x19};
uint8_t DATA101[]={0x00,0x00,0x00,0x00,0x12};
uint8_t DATA102[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA103[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA104[]={0x00,0x00,0x00,0x00,0x00};
uint8_t DATA105[]={0x00,0x00,0x00,0x00,0xc0};
void Delayms(uint16_t num)
{
	uint16_t i,j;
	for(i=0;i<num;i++)
	{
	  for(j=0;j<0x200;j++);
	}
}
void Delay(uint32_t count)
{
    uint32_t i;
	for(i=0;i<count;i++)
	;
}
//QSPI CS IO������
void QSPI_SET_CS_High(TWI_QSPIx_TypeDef *qspi)
{
	if(qspi == QSPI0)
	{
		PB_BIT(13) = 1;
	}
	else
	{
		PB_BIT(2) = 1;
	}

}
//QSPI CS IO������
void QSPI_SET_CS_Low(TWI_QSPIx_TypeDef *qspi)
{
	if(qspi == QSPI0)
	{
		PB_BIT(13) = 0;
	}
	else
	{
		PB_BIT(2) = 0;
	}
}

void write_senddata(TWI_QSPIx_TypeDef *qspi,uint8_t cmddata, uint8_t* data, uint32_t len)
{
  
  if(INITLCD_flag)
  {
    data[0] = 0x12;
  }
  else
  {
    data[0] = 0x02;
  }
  data[2] = cmddata;
	//CS ����
   QSPI_SET_CS_Low(qspi);

  // ���÷�������
  QSPIx_Write_ComSet(QSPI1, QSPI_LMode_1Line, QSPI_DWidth_8bit, QSPI_CLKONLY_OFF);
	QSPI_SendMultipleData(QSPI1,(uint32_t*)data,len);

  //CS ����
  QSPI_SET_CS_High(qspi);
		

}

void Init_LCD(TWI_QSPIx_TypeDef *qspi)
{
	LCD_Reset_set();    Delayms(10);  //LCD_RESET��λ��
  LCD_Reset_clr();	Delayms(10);
	LCD_Reset_set();	Delayms(60);
  //------end Reset Sequence-----//
	/*----��ʼ�Ĵ���ʹ�ܲ��� ------ */
	write_senddata(qspi,0xff,DATA0,sizeof(DATA0));
	write_senddata(qspi,0xE7,DATA1,sizeof(DATA1));	   //TE_output_en
	write_senddata(qspi,0x35,DATA2,sizeof(DATA2));	   //TE_ interface_en
	write_senddata(qspi,0x43,DATA3,sizeof(DATA3));	
	write_senddata(qspi,0x36,DATA105,sizeof(DATA105));
	write_senddata(qspi,0x3A,DATA4,sizeof(DATA4));	   
	write_senddata(qspi,0x40,DATA5,sizeof(DATA5));	     
	write_senddata(qspi,0x55,DATA7,sizeof(DATA7));	   
	write_senddata(qspi,0x44,DATA8,sizeof(DATA8));//VBP  
	write_senddata(qspi,0x45,DATA9,sizeof(DATA9));//VFP  
	write_senddata(qspi,0x7d,DATA10,sizeof(DATA10));//vdds_trim[2:0]								
	write_senddata(qspi,0xc1,DATA11,sizeof(DATA11));//avdd_clp_en avdd_clp[1:0] avcl_clp_en avcl_clp[1:0]
	write_senddata(qspi,0xc2,DATA12,sizeof(DATA12));//vgl_clp_en vgl_clp[2:0]		
	write_senddata(qspi,0xc3,DATA13,sizeof(DATA13));//vgl_clp_en vgl_clp[2:0]		
	write_senddata(qspi,0xc6,DATA14,sizeof(DATA14));//avdd_ratio_sel avcl_ratio_sel vgh_ratio_sel[1:0] vgl_ratio_sel[1:0]	
	write_senddata(qspi,0xc7,DATA15,sizeof(DATA15));//mv_clk_sel[1:0] avdd_clk_sel[1:0] avcl_clk_sel[1:0]	
	write_senddata(qspi,0xc8,DATA16,sizeof(DATA16));//	VGL_CLK_sel
	write_senddata(qspi,0x7a,DATA17,sizeof(DATA17));//	user_vgsp
	write_senddata(qspi,0x6f,DATA18,sizeof(DATA18));//	user_gvdd
	write_senddata(qspi,0x78,DATA19,sizeof(DATA19));//	user_gvcl	
	write_senddata(qspi,0x73,DATA20,sizeof(DATA20));	   
	write_senddata(qspi,0x74,DATA21,sizeof(DATA21));	   
	write_senddata(qspi,0xc9,DATA22,sizeof(DATA22));//
	write_senddata(qspi,0x67,DATA23,sizeof(DATA23));	  //gate_ed
	write_senddata(qspi,0x51,DATA24,sizeof(DATA24));//gate_st_o[7:0]
	write_senddata(qspi,0x52,DATA25,sizeof(DATA25));//gate_ed_o[7:0]
	write_senddata(qspi,0x53,DATA26,sizeof(DATA26));//gate_st_e[7:0]
	write_senddata(qspi,0x54,DATA27,sizeof(DATA27));//gate_ed_e[7:0]
	//sorce 
	write_senddata(qspi,0x46,DATA28,sizeof(DATA28));//fsm_hbp_o[5:0]
	write_senddata(qspi,0x47,DATA29,sizeof(DATA29));//fsm_hfp_o[5:0]
	write_senddata(qspi,0x48,DATA30,sizeof(DATA30));//fsm_hbp_e[5:0]
	write_senddata(qspi,0x49,DATA31,sizeof(DATA31));//fsm_hfp_e[5:0]
	write_senddata(qspi,0x56,DATA32,sizeof(DATA32));//src_ld_wd[1:0] src_ld_st[5:0]
	write_senddata(qspi,0x57,DATA33,sizeof(DATA33));//pn_cs_en src_cs_st[5:0]
	write_senddata(qspi,0x58,DATA34,sizeof(DATA34));//src_cs_p_wd[6:0]
	write_senddata(qspi,0x59,DATA35,sizeof(DATA35));//src_cs_n_wd[6:0]
	write_senddata(qspi,0x5a,DATA36,sizeof(DATA36));//src_pchg_st_o[6:0]
	write_senddata(qspi,0x5b,DATA37,sizeof(DATA37));//src_pchg_wd_o[6:0]
	write_senddata(qspi,0x5c,DATA38,sizeof(DATA38));//src_pchg_st_e[6:0]
	write_senddata(qspi,0x5d,DATA39,sizeof(DATA39));//src_pchg_wd_e[6:0]
	write_senddata(qspi,0x5e,DATA40,sizeof(DATA40));//src_pol_sw[7:0]
	write_senddata(qspi,0x60,DATA41,sizeof(DATA41));//src_op_st_o[7:0]
	write_senddata(qspi,0x61,DATA42,sizeof(DATA42));//src_op_st_e[7:0]
	write_senddata(qspi,0x62,DATA43,sizeof(DATA43));//src_op_ed_o[9:8] src_op_ed_e[9:8]
	write_senddata(qspi,0x63,DATA44,sizeof(DATA44));//src_op_ed_o[7:0]
	write_senddata(qspi,0x64,DATA45,sizeof(DATA45));//src_op_ed_e[7:0]
	write_senddata(qspi,0x65,DATA46,sizeof(DATA46));//chopper
	write_senddata(qspi,0x6E,DATA47,sizeof(DATA47));	   
	write_senddata(qspi,0xca,DATA48,sizeof(DATA48));//avdd_mux_st_o[7:0]
	write_senddata(qspi,0xcb,DATA49,sizeof(DATA49));//avdd_mux_ed_o[7:0]
	write_senddata(qspi,0xcc,DATA50,sizeof(DATA50));//avdd_mux_st_e[7:0]
	write_senddata(qspi,0xcD,DATA51,sizeof(DATA51));//avdd_mux_ed_e[7:0]
	write_senddata(qspi,0xD0,DATA52,sizeof(DATA52));//avcl_mux_st_o[7:0]
	write_senddata(qspi,0xD1,DATA53,sizeof(DATA53));//avcl_mux_ed_o[7:0]
	write_senddata(qspi,0xD2,DATA54,sizeof(DATA54));//avcl_mux_st_e[7:0]
	write_senddata(qspi,0xD3,DATA55,sizeof(DATA55));//avcl_mux_ed_e[7:0]
	write_senddata(qspi,0xD4,DATA60,sizeof(DATA60));//vgh_mux_st[7:0]
	write_senddata(qspi,0xD5,DATA61,sizeof(DATA61));//vgh_mux_ed[7:0]

	write_senddata(qspi,0x80,DATA64,sizeof(DATA64));	   //gam_vrp0	
	write_senddata(qspi,0xA0,DATA65,sizeof(DATA65));	   //gam_VRN0	
	write_senddata(qspi,0x81,DATA66,sizeof(DATA66));	   //gam_vrp1	
	write_senddata(qspi,0xA1,DATA67,sizeof(DATA67));	   //gam_VRN1	
	write_senddata(qspi,0x82,DATA68,sizeof(DATA68));	   //gam_vrp2	 
	write_senddata(qspi,0xA2,DATA70,sizeof(DATA70));	   //gam_VRN2	
	write_senddata(qspi,0x86,DATA69,sizeof(DATA69));	   //gam_prp0	 
	write_senddata(qspi,0xA6,DATA71,sizeof(DATA71));	   //gam_PRN0	 	
	write_senddata(qspi,0x87,DATA72,sizeof(DATA72));	   //gam_prp1	 
	write_senddata(qspi,0xA7,DATA73,sizeof(DATA73));	   //gam_PRN1	 	
	write_senddata(qspi,0x83,DATA74,sizeof(DATA74));	   //gam_vrp3	 
	write_senddata(qspi,0xA3,DATA75,sizeof(DATA75));	   //gam_VRN3		
	write_senddata(qspi,0x84,DATA76,sizeof(DATA76));	   //gam_vrp4	 
	write_senddata(qspi,0xA4,DATA77,sizeof(DATA77));	   //gam_VRN4		
	write_senddata(qspi,0x85,DATA78,sizeof(DATA78));	   //gam_vrp5	  
	write_senddata(qspi,0xA5,DATA79,sizeof(DATA79));	   //gam_VRN5		
	write_senddata(qspi,0x88,DATA80,sizeof(DATA80));	   //gam_pkp0	  
	write_senddata(qspi,0xA8,DATA81,sizeof(DATA81));	   //gam_PKN0		
	write_senddata(qspi,0x89,DATA82,sizeof(DATA82));	   //gam_pkp1	  
	write_senddata(qspi,0xA9,DATA83,sizeof(DATA83));	   //gam_PKN1		
	write_senddata(qspi,0x8a,DATA84,sizeof(DATA84));	   //gam_pkp2	  
	write_senddata(qspi,0xAa,DATA85,sizeof(DATA85));	   //gam_PKN2		
	write_senddata(qspi,0x8b,DATA86,sizeof(DATA86));	   //gam_PKP3	 
	write_senddata(qspi,0xAb,DATA87,sizeof(DATA87));	   //gam_PKN3		
	write_senddata(qspi,0x8c,DATA88,sizeof(DATA88));	   //gam_PKP4	
	write_senddata(qspi,0xAc,DATA89,sizeof(DATA89));	   //gam_PKN4	
	write_senddata(qspi,0x8d,DATA90,sizeof(DATA90));	   //gam_PKP5	
	write_senddata(qspi,0xAd,DATA91,sizeof(DATA91));	   //gam_PKN5	
	write_senddata(qspi,0x8e,DATA92,sizeof(DATA92));	   //gam_PKP6	
	write_senddata(qspi,0xAe,DATA93,sizeof(DATA93));	   //gam_PKN6	
	write_senddata(qspi,0x8f,DATA94,sizeof(DATA94));	   //gam_PKP7	
	write_senddata(qspi,0xAf,DATA95,sizeof(DATA95));	   //gam_PKN7	
	write_senddata(qspi,0x90,DATA96,sizeof(DATA96));	   //gam_PKP8	
	write_senddata(qspi,0xB0,DATA97,sizeof(DATA97));	   //gam_PKN8	
	write_senddata(qspi,0x91,DATA98,sizeof(DATA98));	   //gam_PKP9	
	write_senddata(qspi,0xB1,DATA99,sizeof(DATA99));	   //gam_PKN9	
	write_senddata(qspi,0x92,DATA100,sizeof(DATA100));	   //gam_PKP10	
	write_senddata(qspi,0xB2,DATA101,sizeof(DATA101));	   //gam_PKN10	
	write_senddata(qspi,0xff,DATA102,sizeof(DATA102));
	write_senddata(qspi,0x11,DATA103,sizeof(DATA103));
	Delay(120);
									
	write_senddata(qspi,0x29,DATA104,sizeof(DATA104));
	
	Delay(20);
}

void write_sendcmd(TWI_QSPIx_TypeDef *qspi,uint8_t cmddata)
{
  uint8_t i = 0;
  uint8_t senddata[4] = {0x00, 0x00, cmddata, 0x00};
  if(INITLCD_flag)
  {
    senddata[0] = 0x12;
  }
  else
  {
    senddata[0] = 0x02;
  }

	//CS ����
   QSPI_SET_CS_Low(qspi);
  // ���÷�������
  QSPIx_Write_ComSet(qspi, QSPI_LMode_1Line, QSPI_DWidth_8bit, QSPI_CLKONLY_OFF);
  for(i = 0; i < 4; i++)
  {
    QSPI_SendData8(qspi, senddata[i]);
    while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));
  }
  //CS ����
  QSPI_SET_CS_High(qspi);
}
void LCDBlockWrite(TWI_QSPIx_TypeDef *qspi,unsigned int Xstart, unsigned int Xend, unsigned int Ystart, unsigned int Yend)
{
  uint8_t Xdata[] = {0x00, 0x00, 0x00, 0x00, (Xstart >> 8), (Xstart & 0xff), (Xend >> 8), (Xend & 0xff)};
  uint8_t Ydata[] = {0x00, 0x00, 0x00, 0x00, (Ystart >> 8), (Ystart & 0xff), (Yend >> 8), (Yend & 0xff)};

  write_senddata(qspi,0x2a, Xdata, sizeof(Xdata));
  write_senddata(qspi,0x2b, Ydata, sizeof(Ydata));
  write_sendcmd(qspi,0x2C);

}



void DispPic_str(TWI_QSPIx_TypeDef *qspi)
{
	uint16_t cmd ;
	LCDBlockWrite(qspi,0,PIC_COL-1,0,PIC_ROW-1);
	INITLCD_flag=1;	
	write_sendcmd(qspi,0x2C);
	if(INITLCD_flag)         //Q4
	{
		cmd = 0x12;
	}
	else
	{
		cmd = 0x02;
	}
  //CS ����
  QSPI_SET_CS_Low(qspi); 
	// ���÷������� 
	QSPIx_Write_ComSet(qspi,QSPI_LMode_1Line,QSPI_DWidth_8bit,QSPI_CLKONLY_OFF);
	QSPI_SendData16(qspi,cmd);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	QSPIx_Write_ComSet(qspi,QSPI_LMode_4Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
	QSPI_SendData32(qspi,0x002C00);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����

}

void Lcd_Refrsh_DMA(TWI_QSPIx_TypeDef *qspi,uint16_t sx, uint16_t ex, uint16_t sy, uint16_t ey, uint16_t *color_p)
{
    ///<���������ݰ���һ�ε�DMA
//	  LCDBlockWrite(qspi,sx, ex, sy, ey);
//    DMA_Cmd(DMA0, DISABLE);	
//    DMA_SetCurrDataCounter(DMA0,(ex - sx + 1)*(ey - sy + 1));  //���ݴ�����
//		DMA0->DMA_SADR = ( uint32_t )color_p;

//    QSPI_SET_CS_Low(qspi);
//		INITLCD_flag = 1;
//	
//		qspi->TWI_QSPIx_CON=0x48810080;
//		qspi->TWI_QSPIx_DATA=0x12;
//		while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));

//		qspi->TWI_QSPIx_CON=0xE8810080;
//		qspi->TWI_QSPIx_DATA=0x003C00;
//		while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));
//	
//		qspi->TWI_QSPIx_IDE &=~0x80;
//		qspi->TWI_QSPIx_IDE |=0x80;
//		QSPIx_Write_ComSet(qspi,QSPI_LMode_4Line,QSPI_DWidth_16bit,QSPI_CLKONLY_OFF);
//    DMA_Cmd(DMA0, ENABLE);// ʹ��DMA
//	
//		QSPI1->TWI_QSPIx_STS |=0X3F;
//		DMA0->DMA_STS |= 0x06;
//		DMA0->DMA_STS = DMA_STS_SWREQ;
//		while(!(DMA0->DMA_STS & DMA_STS_TCIF)); //�ȴ�DMA�������
//		DMA0->DMA_STS |= DMA_STS_TCIF;//���־
//		
//		DMA0->DMA_STS |= 0x06;
//	  QSPI1->TWI_QSPIx_STS |=0X3F;
//		INITLCD_flag = 0;
//		
//    QSPI_SET_CS_High(qspi);


		int32_t x,y;
		int16_t height,width,cmd;
		width = ex - sx + 1;          
		height = ey - sy + 1;
		LCDBlockWrite(qspi,sx, ex, sy, ey);
		QSPI_SET_CS_Low(qspi);

		qspi->TWI_QSPIx_CON=0x48810080;
		qspi->TWI_QSPIx_DATA=0x12;
		while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));

		qspi->TWI_QSPIx_CON=0xE8810080;
		qspi->TWI_QSPIx_DATA=0x003C00;
		while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));
		for(y = sy; y <= ey; y++) {
				for(x = sx; x <= ex; x++) {
						INITLCD_flag = 1;
				
						qspi->TWI_QSPIx_CON=0xD8810080;
						qspi->TWI_QSPIx_DATA=*color_p;
						while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY));
						
						INITLCD_flag = 0;
						color_p++;
				}
		}
		QSPI_SET_CS_High(qspi);
}


void W25QXX_FastRead( TWI_QSPIx_TypeDef *qspi,uint8_t	 Readcmd,uint32_t ReadAddr)
{
	QSPIx_Write_ComSet(qspi,QSPI_LMode_1Line,QSPI_DWidth_8bit,QSPI_CLKONLY_OFF);
  //CS ����
  QSPI_SET_CS_Low(qspi);

	QSPI_SendData8(qspi,Readcmd);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	
	// ���÷��͵�ַ
	QSPIx_Write_ComSet(qspi,QSPI_LMode_4Line,QSPI_DWidth_32bit,QSPI_CLKONLY_OFF);////24�ĳ�32bit
	QSPI_SendData32(qspi,ReadAddr);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	// ���ÿ�����
	QSPIx_Write_ComSet(qspi,QSPI_LMode_0Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
	QSPI_SendData32(qspi,0XFF0000);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	
}
uint16_t W25Q16_QSPIReadID(TWI_QSPIx_TypeDef *qspi)
{
	uint8_t u8RxData[4] = {0}; 

	QSPIx_Write_ComSet(qspi,QSPI_LMode_1Line,QSPI_DWidth_8bit,QSPI_CLKONLY_OFF);
  //CS ����
  QSPI_SET_CS_Low(qspi); 
	
	// ���÷�������  0X94 Read Manufacturer/Device ID
	QSPI_SendData8(qspi,0x94);
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	// ���� 24bit ��ַ��С����
	QSPIx_Write_ComSet(qspi,QSPI_LMode_4Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
	QSPI_SendData32(qspi,0x000000);	
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
	// ���� 3��Dummy
	//qspi->TWI_QSPIx_REV = 0xA05F0700;
	QSPIx_Write_ComSet(qspi,QSPI_LMode_0Line,QSPI_DWidth_24bit,QSPI_CLKONLY_OFF);
	QSPI_SendData32(qspi,0x000000);	
	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����

	// �ض� 2�� bytes 
	QSPIx_Read_ComSet(qspi,QSPI_LMode_4Line,QSPI_DWidth_8bit,0);//,QSPI_CLKONLY_ON
  //QSPIx_CLKONLYSet(qspi, QSPI_CLKONLY_ON);
	QSPIx_ReceiveMultipleData(qspi,u8RxData,2);	
	PD_BIT(0) = 0;
	while(DL_OK==0);
	DL_OK = 0;
  // CS ����
	if(qspi == QSPI0)
	{
		PB_BIT(13) = 1;
	}
	else
	{
		PB_BIT(2) = 1;
	}; 

	return ((u8RxData[0]<<8) | u8RxData[1]);
	
}


