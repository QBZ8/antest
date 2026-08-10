/*
目    的：2401测试
编译环境：avr studio+winavr
功能演示：PC2外接LED，LED闪烁，表示收发正常，模块正常；led没变化，模块有问题
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "spi.h"			//2401管脚连接
#include "2401.h"		

int main()
{
	SPI_Init();
	sei();
	DDRD|=(1<<4);
	PORTD|=(1<<4);			//指示灯

//***********************************************************
	RF2401_Init();			//初始化2401
 	Rx_Mode();				//接收模式

	PORT_SPI&=~(1<<CSN);
	SpiRW(1|W_REGSITER);	//写 寄存器1
	SpiRW(0x0);				//禁止自动应答  
	PORT_SPI|=(1<<CSN);

	PORT_SPI&=~(1<<CSN);   
	SpiRW(0x31);			
	SpiRW(0X20);			//通道0有效数据宽度32
	PORT_SPI|=(1<<CSN);
	_delay_ms(1);

	while(1) 
	{
		if(!(PINB&(1<<IRQ)))
		{
			unsigned char irq_sta;
			irq_sta=Read_IRQ();
			if(irq_sta&(1<<RX_DR))
			{
				Clr_IRQ(1<<RX_DR);
				Read_Rx(32);
				unsigned char i;
				for(i=0;i<32;i++)			//发送接收到的数据
					TxData[i]=RxData[i];
				W_Send_Data(32);
				Tx_Mode();
				PORTD^=(1<<4);
			}
			if(irq_sta&(1<<TX_DS))
			{
				Clr_IRQ(1<<TX_DS);
				Rx_Mode();
			}
		}
	}
}
