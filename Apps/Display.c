#include "sc32_conf.h"
#include "Function_Init.h"
#include "..\FWLib\TK_LIB\sc32f10xx_TK_ParameterAnalysis.h"
#include "..\FWLib\TK_LIB\sc32f10xx_TK_FunctionResource.h"
#include "..\SOC_DebugTouchKey_Lib\sc32f10xx_TK_DynamicDebug.h"
uint32_t TK_exKeyValueFlag = 0; //当前轮按键标志
uint8_t exKeyValue = 0;
uint8_t gTkIsValid = 0;
uint8_t KeyValue = 0;

uint8_t j = 0;
uint8_t PicNum = 0;
uint8_t menu = 1;
int value = 10; // 初始值
int picLeft1[] = {4, 13, 26, 36}; // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight1[] = {13, 26, 36, 48};											//小循环右区间
int n1 = sizeof(picLeft1)/sizeof(picLeft1[0]); 
int n2 = sizeof(picRight1)/sizeof(picRight1[0]);
int picLeft2[] = {50, 66, 83}; // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight2[] = {66, 83, 98};											//小循环右区间
int n3 = sizeof(picLeft2)/sizeof(picLeft2[0]); 
int n4 = sizeof(picRight2)/sizeof(picRight2[0]);
int picLeft3[] = {101, 112, 123,134}; // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight3[] = {112, 123, 134, 144};											//小循环右区间
int n5 = sizeof(picLeft3)/sizeof(picLeft3[0]); 
int n6 = sizeof(picRight3)/sizeof(picRight3[0]);
int picLeft4[] = {146,155,166}; // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight4[] = {155,166,175};											//小循环右区间
int n7 = sizeof(picLeft4)/sizeof(picLeft4[0]); 
int n8 = sizeof(picRight4)/sizeof(picRight4[0]);
int a;

extern void Striaight_Mode_Test(TWI_QSPIx_TypeDef *qspi_flash,TWI_QSPIx_TypeDef *qspi_lcd, uint32_t addr);
int  PicLeft(void)
{
	if(menu==2)
	{
	for (a = 0; a < n1; a++) // 遍历排除数值列表
	{ 
		if (j == picLeft1[a]) // 如果找到了匹配的数值
		{ 
			return picLeft1[a];
		}
	}
	}
	if(menu==3)
	{
	for (a = 0; a < n3; a++) // 遍历排除数值列表
	{ 
		if (j == picLeft2[a]) // 如果找到了匹配的数值
		{ 
			return picLeft2[a];
		}
	}
	}
	if(menu==4)
	{
	for (a = 0; a < n5; a++) // 遍历排除数值列表
	{ 
		if (j == picLeft3[a]) // 如果找到了匹配的数值
		{ 
			return picLeft3[a];
		}
	}
	}
	if(menu==5)
	{
	for (a = 0; a < n7; a++) // 遍历排除数值列表
	{ 
		if (j == picLeft4[a]) // 如果找到了匹配的数值
		{ 
			return picLeft4[a];
		}
	}
	}
	return 0xff;
}

int  PicRight(void)
{
	if(menu==2)
	{
	for (a = 0; a < n2; a++) // 遍历排除数值列表
	{ 
		if (j == picRight1[a]) // 如果找到了匹配的数值
		{ 
			return picRight1[a];
		}
	}
	}
	if(menu==3)
	{
	for (a = 0; a < n4; a++) // 遍历排除数值列表
	{ 
		if (j == picRight2[a]) // 如果找到了匹配的数值
		{ 
			return picRight2[a];
		}
	}
	}
	if(menu==4)
	{
	for (a = 0; a < n6; a++) // 遍历排除数值列表
	{ 
		if (j == picRight3[a]) // 如果找到了匹配的数值
		{ 
			return picRight3[a];
		}
	}
	}
	if(menu==5)
	{
	for (a = 0; a < n8; a++) // 遍历排除数值列表
	{ 
		if (j == picRight4[a]) // 如果找到了匹配的数值
		{ 
			return picRight4[a];
		}
	}
	}
	return 0xff;
}

void ChangeTouchKeyvalue(void)
{
	switch(TK_exKeyValueFlag)   //0x0003C000
    {        
        case 0x00004000:exKeyValue = 1;break;    
        case 0x00008000:exKeyValue = 2;break; 
        case 0x00010000:exKeyValue = 3;break;
		case 0x00020000:exKeyValue = 4;break;    
        default:exKeyValue = 0xff;break;             
    }
}


void SwitchPic(void)//选择对应的菜单，增加对应的j值
{
	switch(PicNum)   
    {        						//0-3为一级菜单
        case 0:j = 4+0;break;    //第一张菜单
        case 1:j = 4+45;break; 	//第二张菜单
        case 2:j = 4+96;break;	//第三张菜单
		case 3:j = 4+151;break;   //
	
        default:break;             
    }
}
void UpdateDisplay(void)
{
	if(exKeyValue != 0xff)
    {
        if(gTkIsValid == 0)    //松手前只出一次键
        {        
            gTkIsValid = 1;
            KeyValue=exKeyValue;             
			if(menu == 1)
			{
				if(KeyValue == 4)
				{
					if(PicNum==0) PicNum=4;
					PicNum--;
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);
				}
				if(KeyValue == 3)
				{
					PicNum++;
					if(PicNum==4) PicNum=0;
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);					
				}
				if(KeyValue == 2)
				{
					SwitchPic();
					Striaight_Mode_Test(QSPI0,QSPI1,j);
					menu = 2+PicNum;
				}				
			}
/*				选择第一张图片后的菜单功能改变						*/
			else if(menu == 2)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//方便执行后续的for循环
					if(j ==4||j ==3)  j=48;		
					for(;j!=PicLeft();j--)//减到左区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//方便执行后续的for循环
					if(j ==49||j ==48)  j=4;					
					for(;j!=PicRight();j++)//加到右区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
				}
				if(KeyValue == 2)
				{
					
				}				
				if(KeyValue == 1)
				{
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);
					menu = 1;
				}			
			}
			/*				选择第二张图片后的菜单功能改变						*/
			else if(menu == 3)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//方便执行后续的for循环
					if(j ==50||j ==49)  j=98;		
					for(;j!=PicLeft();j--)//减到左区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//方便执行后续的for循环			
					for(;j!=PicRight();j++)//加到右区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==99||j ==98) 
					{	
						j=49;	
					Striaight_Mode_Test(QSPI0,QSPI1,j);
					}//特殊处理最后99那一帧变为第49帧
				}
				if(KeyValue == 2)
				{
					
				}				
				if(KeyValue == 1)
				{
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);
					menu = 1;
				}			
			}
/*				选择第三张图片后的菜单功能改变						*/
			else if(menu == 4)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//方便执行后续的for循环
					if(j ==100||j ==101)  j=144;		
					for(;j!=PicLeft();j--)//减到左区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//方便执行后续的for循环					
					for(;j!=PicRight();j++)//加到右区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==144||j ==145)  
					{
						j=100;
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}//特殊处理
				}
				if(KeyValue == 2)
				{
					
				}				
				if(KeyValue == 1)
				{
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);
					menu = 1;
				}			
			}
/*				选择第四张图片后的菜单功能改变						*/
			else if(menu == 5)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//方便执行后续的for循环		
					if(j ==145||j ==144)  
					{
						j=175;
					}
					for(;j!=PicLeft();j--)//减到左区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==145||j ==146)  
					{
						j=175;
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//方便执行后续的for循环		
					if(j ==175||j ==176)  
					{
						j=146;
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}						
					for(;j!=PicRight();j++)//加到右区间就停止
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==175)
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
				}
				if(KeyValue == 2)
				{
					
				}				
				if(KeyValue == 1)
				{
					Striaight_Mode_Test(QSPI0,QSPI1,PicNum);
					menu = 1;
				}			
			}
			}

    }
		
		
		
    else
    {
        gTkIsValid = 0;        
    }
}
void Sys_Scan(void)
{	
	if(TK_TouchKeyStatus&0x80)	    //重要步骤2:  触摸键扫描一轮标志，是否调用TouchKeyScan()一定要根据此标志位置起后
	 {	   																	
		TK_TouchKeyStatus &= 0x7f;	//重要步骤3: 清除标志位， 需要外部清除。													    
		TK_exKeyValueFlag = TK_TouchKeyScan();//按键数据处理函数 
				 
		ChangeTouchKeyvalue();
		UpdateDisplay();
		                 
		TK_Restart();				//启动下一轮转换																														 			
	}
}
