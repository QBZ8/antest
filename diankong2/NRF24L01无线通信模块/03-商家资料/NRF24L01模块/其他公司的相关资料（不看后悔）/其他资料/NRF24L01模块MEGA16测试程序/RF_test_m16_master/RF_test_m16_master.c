/*
目    的：2401测试
编译环境：avr studio+winavr
功能演示：PC2外接LED，LED闪烁，表示收发正常，模块正常；led没变化，模块有问题
		主机从机的led都闪动，表示两个模块收发都正常！！
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "spi.h"
#include "usart.h"
#include "2401.h"		//内部管脚连接

int main()
{
	Usart_Init(25);
	SPI_Init();
	sei();

	DDRD|=(1<<4);
	PORTD|=(1<<4);			//指示灯


	RF2401_Init();			//初始化2401
 	Rx_Mode();				//接收模式

	PORT_SPI&=~(1<<CSN);
	SpiRW(1|W_REGSITER);	//写 寄存器1
	SpiRW(0x0);				//禁止自动应答
	PORT_SPI|=(1<<CSN);

	PORTB&=~(1<<CSN);   
	SpiRW(0x31);			
	SpiRW(0X20);			//通道0有效数据宽度32
	PORTB|=(1<<CSN);
	_delay_ms(1);

	unsigned int  counter=0;
	unsigned char send_data=0,right=0;
	while(1) 
	{
		if(counter++>20000)
		{
			counter=0;
			TxData[0]=send_data;
			unsigned char i;
			for(i=1;i<32;i++)
				TxData[i]=i;
			W_Send_Data(32);
			Tx_Mode();
			
			PORTD|=(1<<4);		// 指示灯
		}
		if(!(PINB&(1<<IRQ)))
		{
			unsigned char irq_sta;
			irq_sta=Read_IRQ();
			if(irq_sta&(1<<RX_DR))
			{
				Clr_IRQ(1<<RX_DR);
				Read_Rx(32);
				_delay_ms(1);
				unsigned char i;
				for(i=0;i<32;i++)			
					Usart_Transmit(RxData[i]);
				if(RxData[0]==send_data)
				{
					right+=1;
					for(i=1;i<32;i++)			
					if(RxData[i]==i)
					{
						right+=1;
					}
				}
				if(32==right)
				{
					PORTD&=~(1<<4);
				}
				right=0;
			}
			if(irq_sta&(1<<TX_DS))
			{
				Clr_IRQ(1<<TX_DS);
				Rx_Mode();
			}
		}
	}
}
