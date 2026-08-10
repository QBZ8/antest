#include  "../header/user/init.h"
/***********************************************
函 数:	Init_Ports
功 能:	初始化IO状态
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Init_Ports(void)
{
        output_ledRed             = off;
        output_ledBlue            = off;
        
        pullup_IRQ                = true;
        
        direction_rxd             = direction_input;
        direction_IRQ             = direction_input;
        
        direction_txd             = direction_output;
        direction_ledRed          = direction_output;
        direction_ledBlue         = direction_output;
}
/***********************************************
函 数:	Init_Timer1
功 能:	初始化MCU时间计数器
输 入:	/
输 出:	/
描 述:	作为收到串口数据字节后的等待时间定时
***********************************************/
void    Init_Timer1(void)
{
        /* timer1 time 10ms */
        OCR1AH       = 0x04;
        OCR1AL       = 0xe2;

        TCNT1H       = 0x00;
        TCNT1L       = 0x00;

        /* CLKi/o = 64,no prescaling,CTC mode */
        TCCR1A       = 0x00;
        TCCR1B       = 0x0b;
        TCCR1C       = 0x00;

        /* disable compareB,overflow interrupt,enable compareA */
        TIFR1        = 0x27;
#if debug_Master        
        TIMSK1       = 0x02;	
#else
        TIMSK1       = 0x02;
#endif        
}
/***********************************************
函 数:	Init_Rs232
功 能:	初始化MCU串口状态
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Init_Rs232(void)
{
        /* U2X0 =0 */
        UCSR0A                 = 0x00;
        
        /* TXEN0 = 1,RXEN0 = 1,enable USART0 TX and USART0 RX,enable USART0 RX interrupt */
        UCSR0B                 = 0x98;

        /* asynchronism,8 bit data,none parity,1 stop bit */
        UCSR0C                 = 0x06;
 	
        /* 串口速率设置 */
        UBRR0H                 = ((crystal/9600/16)-1)/256;
        UBRR0L                 = ((crystal/9600/16)-1)%256;                 
}
/***********************************************
函 数:	PowerOn_Initialisation
功 能:	上电初始化MCU内部资源和RF
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    PowerOn_Initialisation(void)
{
        uint  i;

        /* 上电稳定时间延迟 */
        for(i = 0;i < 0xffff;i++)
        {
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
        }

        /* 初始化MCU端口状态 */
        Init_Ports();
	
        /* 初始化timer1定时100ms */
        Init_Timer1();
        
        /* 初始化UART */
        //Init_Rs232();
        
        /* 初始化RF */
        Initialisation_RF();

        /* 标志寄存器为0 */
        R_flag0           = 0x00;        
}
