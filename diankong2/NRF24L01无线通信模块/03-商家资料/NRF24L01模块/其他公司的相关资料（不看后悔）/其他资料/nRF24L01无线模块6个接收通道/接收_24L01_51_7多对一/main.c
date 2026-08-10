#include "nRF24L01.h"

/**************************************************
函数：main()

描述：
    主函数
/**************************************************/
void main(void)
{
    EX0=1;
	IT0=1;
	EA=1;
	init_io();		              // 初始化IO
	StartUART();
	Init_24L01();
	R_S_Byte(2);
	TX_Mode(TX_BUF);			// 把nRF24L01设置为发送模式并发送数据
	Check_ACK(1);               // 等待发送完毕，清除TX FIFO
	delay_ms(250);
	delay_ms(250);
	RX_Mode();			        // 设置为接收模式

	while(1)
	{
		CheckButtons();           // 按键扫描
	}
}
