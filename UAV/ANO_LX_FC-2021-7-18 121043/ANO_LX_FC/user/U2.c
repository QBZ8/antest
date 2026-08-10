#include "U2.h"
#include "ANO_DT_LX.h"
#include "ANO_LX.h"
#include "Drv_RcIn.h"
#include "LX_FC_EXT_Sensor.h"
#include "Drv_led.h"
#include "LX_FC_State.h"
#include "Drv_Uart.h"
#include "Drv_AnoOf.h"
#include "control.h"
u8 U2_DataToSend[100];
u8 U2_DataGet[100];
s32 U2_userPar10=123;

void U2_sendtest()
{
	u8 cnt=0;
	s32 tem_data=0;
	U2_DataToSend[cnt++]=0xAA;
	U2_DataToSend[cnt++]=0xFF;
	U2_DataToSend[cnt++]=0xF1;
	U2_DataToSend[cnt++]=0;
	//tem_data=getheight();
	
	
	/*U2_DataToSend[cnt++]=BYTE0(tem_data);
	U2_DataToSend[cnt++]=BYTE1(tem_data);
	U2_DataToSend[cnt++]=BYTE2(tem_data);
	U2_DataToSend[cnt++]=BYTE3(tem_data);*/
	U2_DataToSend[cnt++]=BYTE0(ano_of.of_alt_cm);
	U2_DataToSend[cnt++]=BYTE1(ano_of.of_alt_cm);
	U2_DataToSend[cnt++]=BYTE2(ano_of.of_alt_cm);
	U2_DataToSend[cnt++]=BYTE3(ano_of.of_alt_cm);
	
	U2_DataToSend[3]=cnt-4;
	
	u8 sc=0;
	u8 ac=0;
	for(u8 i=0;i<U2_DataToSend[3]+4;i++)
	{
		sc+=U2_DataToSend[i];
		ac+=sc;
	}
	
	U2_DataToSend[cnt++]=sc;
	U2_DataToSend[cnt++]=ac;
	DrvUart2SendBuf(U2_DataToSend,cnt);
}

void U2_SendPar(u16 id,s32 val)
{
	u8 cnt=0;
	U2_DataToSend[cnt++]=0xAA;
	U2_DataToSend[cnt++]=0xFF;
	U2_DataToSend[cnt++]=0xE2;
	U2_DataToSend[cnt++]=0;
	
	U2_DataToSend[cnt++]=BYTE0(id);
	U2_DataToSend[cnt++]=BYTE1(id);
	
	U2_DataToSend[cnt++]=BYTE0(val);
	U2_DataToSend[cnt++]=BYTE1(val);
	U2_DataToSend[cnt++]=BYTE2(val);
	U2_DataToSend[cnt++]=BYTE3(val);
	
	U2_DataToSend[3]=cnt-4;
	
	u8 sc=0;
	u8 ac=0;
	for(u8 i=0;i<U2_DataToSend[3]+4;i++)
	{
		sc+=U2_DataToSend[i];
		ac+=sc;
	}
	
	U2_DataToSend[cnt++]=sc;
	U2_DataToSend[cnt++]=ac;
	DrvUart2SendBuf(U2_DataToSend,cnt);
}

void U2_SendCheck(u8 id,u8 sc,u8 ac)
{
	u8 cnt=0;
	U2_DataToSend[cnt++]=0xAA;
	U2_DataToSend[cnt++]=0xFF;
	U2_DataToSend[cnt++]=0x00;
	U2_DataToSend[cnt++]=0;
	
	U2_DataToSend[cnt++]=id;
	U2_DataToSend[cnt++]=sc;	
	U2_DataToSend[cnt++]=ac;
	
	U2_DataToSend[3]=cnt-4;
	
	u8 check_sc=0;
	u8 check_ac=0;
	for(u8 i=0;i<U2_DataToSend[3]+4;i++)
	{
		check_sc+=U2_DataToSend[i];
		check_ac+=check_sc;
	}
	
	U2_DataToSend[cnt++]=check_sc;
	U2_DataToSend[cnt++]=check_ac;
	DrvUart2SendBuf(U2_DataToSend,cnt);
}


void U2_Anl()
{
	u8 sc=0;
	u8 ac=0;
	
	//u8 datalen=DataGet[3];
	
	for(u8 i=0;i<U2_DataGet[3]+4;i++)
	{
		sc+=U2_DataGet[i];
		ac+=sc;
	}
	if(sc!=U2_DataGet[U2_DataGet[3]+4]||ac!=U2_DataGet[U2_DataGet[3]+5])
	{
		return;
	}
	
	if(U2_DataGet[2]==0xE1)//读
	{
		u16 id=U2_DataGet[4]+(u16)(U2_DataGet[5]<<8);
		switch(id)
		{
			case 10:
				U2_SendPar(id,U2_userPar10);
			break;
			
			default:
				U2_SendPar(id,0);
			break;
		}
	}
	else if(U2_DataGet[2]==0xE2)//写
	{
		u16 id=U2_DataGet[4]+(u16)(U2_DataGet[5]<<8);
		switch(id)
		{
			case 10:
				U2_userPar10=*(s32*)(&U2_DataGet[6]);
				//U2_SendPar(id,userPar10);
			break;
			
			default:
				//U2_SendPar(id,0);
			break;
		}
		U2_SendCheck(U2_DataGet[2],U2_DataGet[U2_DataGet[3]+4],U2_DataGet[U2_DataGet[3]+5]);
	}
	else if(U2_DataGet[2]==0xDD)
	{
		//sendtest();
	}
}

void U2_GetOneByte(u8 data)
{
	static u8 sta=0;
	static u8 datalen=0;//协议数据长
	static u8 datacnt=0;//接收到的数据长
	if(sta==0)
	{
		U2_DataGet[0]=data;
		datacnt=0;
		if(data==0xAA)
		{
			sta=1;
		}
	}
	else if(sta==1)
	{
		U2_DataGet[1]=data;
		sta=2;
	}
	else if(sta==2)
	{
		U2_DataGet[2]=data;
		sta=3;
	}
	else if(sta==3)
	{
		if(data>100)
		{
			sta=0;
		}
		else
		{
			sta=4;
			U2_DataGet[3]=data;
			datalen=data;
		}	
	}
	else if(sta==4)
	{
		U2_DataGet[4+datacnt++]=data;
		if(datacnt>=datalen)
		{
			sta=5;
		}
	}
	else if(sta==5)
	{
		U2_DataGet[4+datacnt++]=data;
		sta=6;
	}
	else if(sta==6)
	{
		U2_DataGet[4+datacnt++]=data;
		sta=0;
		
		U2_Anl();
	}
}
