
//--------------------------------------------------------------------------------------------
//配置头文件
#include <pic.h>
#include "delay.h"
#include "nRF24L01.h"

extern unsigned char Buffer[16];

//--------------------------------------------------------------------------------------------
void DelayMs(unsigned char cnt)
{
	unsigned char i;
	
	do
	{
		i = 4;
		do
		{
			DelayUs(250);
		}
		while(--i);
	}
	while(--cnt);
}

//--------------------------------------------------------------------------------------------
void SendArray ( unsigned char *data , unsigned char count )
{
	CLRWDT();
	while( count-- )
	{
		TXREG = *data;
		TXIF = 0;
		while( !TXIF );
		data++;
	}
	while(!TRMT);
}

//--------------------------------------------------------------------------------------------
//主程序
void main( void )
{
	unsigned char tt, i;

	CLRWDT();
	WDTCON = 0B10111;
	OSCCON = 0B01100001;
	OSCTUNE=0X00;
	OPTION=0b10010000;
	ADCON0=0X00;
	ADCON1=0X06;
	ANSEL=0X00;
	ANSELH = 0;
	TRISA = 0B00000100;
	TRISB = 0B00010000;
	TRISC = 0b00100100;
	WPUA = 0;
	WPUB = 0;
	IOCA = 0;
	IOCB = 0;
	PORTA = 0B00000100;
	PORTB = 0B00010000;
	PORTC = 0B00100100;		
	INTCON = 0;
	RC0 = 1;
	RC4 = 1;
	RC1 = 1;
	DelayMs(250);
	DelayMs(250);
	DelayMs(250);
	RC0 = 0;
	RC4 = 0;
	RC1 = 0;

	TXSTA=0B00100100;
	RCSTA=0B10010000;
	BAUDCTL = 0b00001000;
	SPBRG=103;

	Buffer[0] = 'A';
	Buffer[1] = 'B';
	Buffer[2] = 'C';
	Buffer[3] = 0;
	SendArray( Buffer , 4 );

	///////////////24L01 Register test//////////
	SPI_RW_Reg(SETUP_AW, 7);	
	tt = SPI_Read(WRITE_REG + SETUP_AW);
	SendArray (&tt,1);
///////////////24L01 Register test//////////

	nRF24L01ioConfig();
	if( !RC2 )
	{
		RX_Mode();
		DelayMs(250);
		RC0 = 1;
		DelayMs(250);
		RC0 = 0;
		DelayMs(250);
	}
	else
	{
		TX_Mode();
		DelayMs(250);
		RC4 = 1;
		DelayMs(250);
		RC4 = 0;
		DelayMs(250);
	}
	
	while(1)
	{
		CLRWDT();		

		if( RC2 )
		{			
			Buffer[0]=0x80;
			Buffer[1]=0x02;
			TX_Mode();			// set TX Mode and transmitting	
			RC4 = 1;
			DelayMs(150);
			RC4 = 0;
			DelayMs(150);
		}
		else
		{
			RX_Mode();
			//nRF24L01 接收数据 
			if( !nRF24L01_MISO )
			{
				unsigned char key_debug;
	
				key_debug=SPI_Read(STATUS);			// read register STATUS's value
				if(key_debug&RX_DR)					// if renRF24L01_CEive data ready (RX_DR) interrupt
					SPI_Read_Buf(RD_RX_PLOAD,Buffer,TX_PLOAD_WIDTH);// read renRF24L01_CEive payload from RX_FIFO buffer
				if(key_debug&MAX_RT) 
					SPI_RW_Reg(FLUSH_TX,0);
				SPI_RW_Reg(WRITE_REG+STATUS,0xff);// clear RX_DR or TX_DS or MAX_RT interrupt flag
				RX_Mode();
				RC0 = 1;
				RC4 = 1;
				DelayMs(150);
				RC0 = 0;
				RC4 = 0;
				DelayMs(150);
			}
		}
	}
}
