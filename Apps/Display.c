#include "sc32_conf.h"
#include "Function_Init.h"
#include "..\FWLib\TK_LIB\sc32f10xx_TK_ParameterAnalysis.h"
#include "..\FWLib\TK_LIB\sc32f10xx_TK_FunctionResource.h"
#include "..\SOC_DebugTouchKey_Lib\sc32f10xx_TK_DynamicDebug.h"
uint32_t TK_exKeyValueFlag = 0; //��ǰ�ְ�����־
uint8_t exKeyValue = 0;
uint8_t gTkIsValid = 0;
uint8_t KeyValue = 0;

uint8_t j = 0;
uint8_t PicNum = 0;
uint8_t menu = 1;
int value = 10; // ��ʼֵ
int picLeft1[] = {4, 13, 26, 36}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight1[] = {13, 26, 36, 48};											//Сѭ��������
int n1 = sizeof(picLeft1)/sizeof(picLeft1[0]); 
int n2 = sizeof(picRight1)/sizeof(picRight1[0]);
int picLeft2[] = {50, 66, 83}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight2[] = {66, 83, 98};											//Сѭ��������
int n3 = sizeof(picLeft2)/sizeof(picLeft2[0]); 
int n4 = sizeof(picRight2)/sizeof(picRight2[0]);
int picLeft3[] = {101, 112, 123,134}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight3[] = {112, 123, 134, 144};											//Сѭ��������
int n5 = sizeof(picLeft3)/sizeof(picLeft3[0]); 
int n6 = sizeof(picRight3)/sizeof(picRight3[0]);
int picLeft4[] = {146,155,166}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight4[] = {155,166,175};											//Сѭ��������
int n7 = sizeof(picLeft4)/sizeof(picLeft4[0]); 
int n8 = sizeof(picRight4)/sizeof(picRight4[0]);
int a;

extern void Striaight_Mode_Test(TWI_QSPIx_TypeDef *qspi_flash,TWI_QSPIx_TypeDef *qspi_lcd, uint32_t addr);
int  PicLeft(void)
{
	if(menu==2)
	{
	for (a = 0; a < n1; a++) // �����ų���ֵ�б�
	{ 
		if (j == picLeft1[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picLeft1[a];
		}
	}
	}
	if(menu==3)
	{
	for (a = 0; a < n3; a++) // �����ų���ֵ�б�
	{ 
		if (j == picLeft2[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picLeft2[a];
		}
	}
	}
	if(menu==4)
	{
	for (a = 0; a < n5; a++) // �����ų���ֵ�б�
	{ 
		if (j == picLeft3[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picLeft3[a];
		}
	}
	}
	if(menu==5)
	{
	for (a = 0; a < n7; a++) // �����ų���ֵ�б�
	{ 
		if (j == picLeft4[a]) // ����ҵ���ƥ�����ֵ
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
	for (a = 0; a < n2; a++) // �����ų���ֵ�б�
	{ 
		if (j == picRight1[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picRight1[a];
		}
	}
	}
	if(menu==3)
	{
	for (a = 0; a < n4; a++) // �����ų���ֵ�б�
	{ 
		if (j == picRight2[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picRight2[a];
		}
	}
	}
	if(menu==4)
	{
	for (a = 0; a < n6; a++) // �����ų���ֵ�б�
	{ 
		if (j == picRight3[a]) // ����ҵ���ƥ�����ֵ
		{ 
			return picRight3[a];
		}
	}
	}
	if(menu==5)
	{
	for (a = 0; a < n8; a++) // �����ų���ֵ�б�
	{ 
		if (j == picRight4[a]) // ����ҵ���ƥ�����ֵ
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


void SwitchPic(void)//ѡ���Ӧ�Ĳ˵������Ӷ�Ӧ��jֵ
{
	switch(PicNum)   
    {        						//0-3Ϊһ���˵�
        case 0:j = 4+0;break;    //��һ�Ų˵�
        case 1:j = 4+45;break; 	//�ڶ��Ų˵�
        case 2:j = 4+96;break;	//�����Ų˵�
		case 3:j = 4+151;break;   //
	
        default:break;             
    }
}
void UpdateDisplay(void)
{
	if(exKeyValue != 0xff)
    {
        if(gTkIsValid == 0)    //����ǰֻ��һ�μ�
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
/*				ѡ���һ��ͼƬ��Ĳ˵����ܸı�						*/
			else if(menu == 2)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//����ִ�к�����forѭ��
					if(j ==4||j ==3)  j=48;		
					for(;j!=PicLeft();j--)//�����������ֹͣ
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//����ִ�к�����forѭ��
					if(j ==49||j ==48)  j=4;					
					for(;j!=PicRight();j++)//�ӵ��������ֹͣ
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
			/*				ѡ��ڶ���ͼƬ��Ĳ˵����ܸı�						*/
			else if(menu == 3)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//����ִ�к�����forѭ��
					if(j ==50||j ==49)  j=98;		
					for(;j!=PicLeft();j--)//�����������ֹͣ
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//����ִ�к�����forѭ��			
					for(;j!=PicRight();j++)//�ӵ��������ֹͣ
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==99||j ==98) 
					{	
						j=49;	
					Striaight_Mode_Test(QSPI0,QSPI1,j);
					}//���⴦�����99��һ֡��Ϊ��49֡
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
/*				ѡ�������ͼƬ��Ĳ˵����ܸı�						*/
			else if(menu == 4)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//����ִ�к�����forѭ��
					if(j ==100||j ==101)  j=144;		
					for(;j!=PicLeft();j--)//�����������ֹͣ
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}

				}
				if(KeyValue == 3)
				{	
					if(j == PicRight()) j++;//����ִ�к�����forѭ��					
					for(;j!=PicRight();j++)//�ӵ��������ֹͣ
					{
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}
					if(j ==144||j ==145)  
					{
						j=100;
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}//���⴦��
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
/*				ѡ�������ͼƬ��Ĳ˵����ܸı�						*/
			else if(menu == 5)
			{
				if(KeyValue == 4)
				{	
					if(j == PicLeft()) j--;//����ִ�к�����forѭ��		
					if(j ==145||j ==144)  
					{
						j=175;
					}
					for(;j!=PicLeft();j--)//�����������ֹͣ
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
					if(j == PicRight()) j++;//����ִ�к�����forѭ��		
					if(j ==175||j ==176)  
					{
						j=146;
						Striaight_Mode_Test(QSPI0,QSPI1,j);
					}						
					for(;j!=PicRight();j++)//�ӵ��������ֹͣ
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
	if(TK_TouchKeyStatus&0x80)	    //��Ҫ����2:  ������ɨ��һ�ֱ�־���Ƿ����TouchKeyScan()һ��Ҫ���ݴ˱�־λ�����
	 {	   																	
		TK_TouchKeyStatus &= 0x7f;	//��Ҫ����3: �����־λ�� ��Ҫ�ⲿ�����													    
		TK_exKeyValueFlag = TK_TouchKeyScan();//�������ݴ����� 
				 
		ChangeTouchKeyvalue();
		UpdateDisplay();
		                 
		TK_Restart();				//������һ��ת��																														 			
	}
}
