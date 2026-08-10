#include "test.h"
#include "ANO_DT_LX.h"
#include "ANO_LX.h"
#include "Drv_RcIn.h"
#include "LX_FC_EXT_Sensor.h"
#include "Drv_led.h"
#include "LX_FC_State.h"
#include "Drv_Uart.h"
#include "Drv_AnoOf.h"
u8 DataToSend[100];
u8 DataGet[100];
s32 userPar10=123;

void sendtest()
{
	u8 cnt=0;
	DataToSend[cnt++]=0xAA;
	DataToSend[cnt++]=0xFF;
	DataToSend[cnt++]=0xF1;
	DataToSend[cnt++]=0;
	
	DataToSend[cnt++]=BYTE0(ano_of.of_alt_cm);
	DataToSend[cnt++]=BYTE1(ano_of.of_alt_cm);
	DataToSend[cnt++]=BYTE2(ano_of.of_alt_cm);
	DataToSend[cnt++]=BYTE3(ano_of.of_alt_cm);
	
	DataToSend[3]=cnt-4;
	
	u8 sc=0;
	u8 ac=0;
	for(u8 i=0;i<DataToSend[3]+4;i++)
	{
		sc+=DataToSend[i];
		ac+=sc;
	}
	
	DataToSend[cnt++]=sc;
	DataToSend[cnt++]=ac;
	DrvUart2SendBuf(DataToSend,cnt);
}

void U2_SendPar(u16 id,s32 val)
{
	u8 cnt=0;
	DataToSend[cnt++]=0xAA;
	DataToSend[cnt++]=0xFF;
	DataToSend[cnt++]=0xE2;
	DataToSend[cnt++]=0;
	
	DataToSend[cnt++]=BYTE0(id);
	DataToSend[cnt++]=BYTE1(id);
	
	DataToSend[cnt++]=BYTE0(val);
	DataToSend[cnt++]=BYTE1(val);
	DataToSend[cnt++]=BYTE2(val);
	DataToSend[cnt++]=BYTE3(val);
	
	DataToSend[3]=cnt-4;
	
	u8 sc=0;
	u8 ac=0;
	for(u8 i=0;i<DataToSend[3]+4;i++)
	{
		sc+=DataToSend[i];
		ac+=sc;
	}
	
	DataToSend[cnt++]=sc;
	DataToSend[cnt++]=ac;
	DrvUart2SendBuf(DataToSend,cnt);
}

void U2_SendCheck(u8 id,u8 sc,u8 ac)
{
	u8 cnt=0;
	DataToSend[cnt++]=0xAA;
	DataToSend[cnt++]=0xFF;
	DataToSend[cnt++]=0x00;
	DataToSend[cnt++]=0;
	
	DataToSend[cnt++]=id;
	DataToSend[cnt++]=sc;	
	DataToSend[cnt++]=ac;
	
	DataToSend[3]=cnt-4;
	
	u8 check_sc=0;
	u8 check_ac=0;
	for(u8 i=0;i<DataToSend[3]+4;i++)
	{
		check_sc+=DataToSend[i];
		check_ac+=check_sc;
	}
	
	DataToSend[cnt++]=check_sc;
	DataToSend[cnt++]=check_ac;
	DrvUart2SendBuf(DataToSend,cnt);
}


void U2_Anl()
{
	u8 sc=0;
	u8 ac=0;
	
	//u8 datalen=DataGet[3];
	
	for(u8 i=0;i<DataGet[3]+4;i++)
	{
		sc+=DataGet[i];
		ac+=sc;
	}
	if(sc!=DataGet[DataGet[3]+4]||ac!=DataGet[DataGet[3]+5])
	{
		return;
	}
	
	if(DataGet[2]==0xE1)//读
	{
		u16 id=DataGet[4]+(u16)(DataGet[5]<<8);
		switch(id)
		{
			case 10:
				U2_SendPar(id,userPar10);
			break;
			
			default:
				U2_SendPar(id,0);
			break;
		}
	}
	else if(DataGet[2]==0xE2)//写
	{
		u16 id=DataGet[4]+(u16)(DataGet[5]<<8);
		switch(id)
		{
			case 10:
				userPar10=*(s32*)(&DataGet[6]);
				//U2_SendPar(id,userPar10);
			break;
			
			default:
				//U2_SendPar(id,0);
			break;
		}
		U2_SendCheck(DataGet[2],DataGet[DataGet[3]+4],DataGet[DataGet[3]+5]);
	}
	else if(DataGet[2]==0xDD)
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
		DataGet[0]=data;
		datacnt=0;
		if(data==0xAA)
		{
			sta=1;
		}
	}
	else if(sta==1)
	{
		DataGet[1]=data;
		sta=2;
	}
	else if(sta==2)
	{
		DataGet[2]=data;
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
			DataGet[3]=data;
			datalen=data;
		}	
	}
	else if(sta==4)
	{
		DataGet[4+datacnt++]=data;
		if(datacnt>=datalen)
		{
			sta=5;
		}
	}
	else if(sta==5)
	{
		DataGet[4+datacnt++]=data;
		sta=6;
	}
	else if(sta==6)
	{
		DataGet[4+datacnt++]=data;
		sta=0;
		
		U2_Anl();
	}
}


