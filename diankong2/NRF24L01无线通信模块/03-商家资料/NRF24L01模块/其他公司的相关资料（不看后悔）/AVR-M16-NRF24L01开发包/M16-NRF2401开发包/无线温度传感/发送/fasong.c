//ICC-AVR application builder : 2007-8-11 20:37:32
// Target : M16
// Crystal: 8.0000Mhz
#include <iom16v.h>
#include <macros.h>
//******************************************************************************
//***********************DS18B20--------PD6*************************************
//******************************************************************************
#define   In_DQ      DDRD &= ~(1 << PD6)       
#define   Out_DQ     DDRD |= (1 << PD6) 
//------------------------------------------------------------------------------
#define   Hign_DQ    PORTD |= (1 << PD6)   
#define   Low_DQ     PORTD &= ~(1 << PD6)
//------------------------------------------------------------------------------
#define   Read_DQ    PIND & (1 << PD6)
//------------------------------------------------------------------------------
//--------------------------------NRF24L01接口定义--------------------------------
//------------------------------------------------------------------------------
//#define NRF24L01_MISO          PB4		//输入0	
#define   Hign_24L01_MISO    PORTB |= (1 << PB4) 
#define   Low_24L01_MISO     PORTB &= ~(1 << PB4)
#define   Read_24L01_MISO    PINB & (1 << PB4) 

//#define NRF24L01_MOSI         PB2  	    //输出1
#define   Hign_24L01_MOSI    PORTB |= (1 << PB2)  
#define   Low_24L01_MOSI     PORTB &= ~(1 << PB2)
#define   Read_24L01_MOSI    PINB & (1 << PB2) 

//#define NRF24L01_CSN     		PB7	      //输出1
#define   Low_24L01_CSN     PORTB &= ~(1 << PB7)
#define   Hign_24L01_CSN   	PORTB |= (1 << PB7)

//#define NRF24L01_SCK  		PB6   	  //输出1
#define   Hign_24L01_SCK    PORTB |= (1 << PB6)   
#define   Low_24L01_SCK     PORTB &= ~(1 << PB6) 		
#define   Read_24L01_SCK    PINB & (1 << PB6);

//#define NRF24L01_CE    	    PB5	      //输出1
#define   Hign_24L01_CE    PORTB |= (1 << PB5)  
#define   Low_24L01_CE     PORTB &= ~(1 << PB5)		
#define   Read_24L01_CE    PINB & (1 << PB5)

//#define  NRF24L01_IRQ     PB3	       //输入
#define   Hign_NRF24L01_IRQ    PORTB |= (1 << PB3)   
#define   Low_NRF24L01_IRQ     PORTB &= ~(1 << PB3)
#define   Read_NRF24L01_IRQ    PINB & (1 << PB3)
  
//------------------------------数码管位选--------------------------------------
//#define Display1   PA1  		    //输出1
#define   Hign_Display1     PORTA |= (1 << PA1);   
#define   Low_Display1    	PORTA &= ~(1 << PA1); 
//#define Display2      PA2  		//输出1
#define   Hign_Display2     PORTA |= (1 << PA2);   
#define   Low_Display2    	PORTA &= ~(1 << PA2); 
//#define Display3     PA3  		//输出1
#define   Hign_Display3     PORTA |= (1 << PA3);   
#define   Low_Display3     	PORTA &= ~(1 << PA3); 
//#define Display4      PA4 		//输出1
#define   Hign_Display4     PORTA |= (1 << PA4);   
#define   Low_Display4     	PORTA &= ~(1 << PA4);   
//-------------------------------BELL蜂明器-------------------------------------
#define   Hign_BELL 		PORTD |= (1 << PD5);   
#define   Low_BELL     	    PORTD &= ~(1 << PD5); 
//-------------------------------JDQ继电器--------------------------------------
#define   Hign_JDQ  		PORTD |= (1 << PD7)
#define   Low_JDQ    		PORTD &= ~(1 << PD7) 
//***********************************数码管0-9编码*******************************************
//----------------------------温度变量------------------------------------------
char  temp_data[2]={0x00,0x00};
char  dispaly[7];
char seg[10]={0xC0,0xCF,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};         //0~~9段码
char seg1[10]={0x40,0x4F,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; 
//------------------------------------------------------------------------------
char sta;
//*********************************************NRF24L01*************************************
#define TX_ADR_WIDTH    5   	// 5 uints TX address width
#define RX_ADR_WIDTH    5   	// 5 uints RX address width
#define TX_PLOAD_WIDTH  32  	// 20 uints TX payload
#define RX_PLOAD_WIDTH  32  	// 20 uints TX payload
char  TX_ADDRESS[TX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//本地地址
char  RX_ADDRESS[RX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//接收地址
//***************************************NRF24L01寄存器指令*******************************************************
#define READ_REG        0x00  	// 读寄存器指令
#define WRITE_REG       0x20 	// 写寄存器指令
#define RD_RX_PLOAD     0x61  	// 读取接收数据指令
#define WR_TX_PLOAD     0xA0  	// 写待发数据指令
#define FLUSH_TX        0xE1 	// 冲洗发送 FIFO指令
#define FLUSH_RX        0xE2  	// 冲洗接收 FIFO指令
#define REUSE_TX_PL     0xE3  	// 定义重复装载数据指令
#define NOP1             0xFF  	// 保留
//*************************************SPI(nRF24L01)寄存器地址****************************************************
#define CONFIG          0x00  // 配置收发状态，CRC校验模式以及收发状态响应方式
#define EN_AA           0x01  // 自动应答功能设置
#define EN_RXADDR       0x02  // 可用信道设置
#define SETUP_AW        0x03  // 收发地址宽度设置
#define SETUP_RETR      0x04  // 自动重发功能设置
#define RF_CH           0x05  // 工作频率设置
#define RF_SETUP        0x06  // 发射速率、功耗功能设置
#define STATUS          0x07  // 状态寄存器
#define OBSERVE_TX      0x08  // 发送监测功能
#define CD              0x09  // 地址检测           
#define RX_ADDR_P0      0x0A  // 频道0接收数据地址
#define RX_ADDR_P1      0x0B  // 频道1接收数据地址
#define RX_ADDR_P2      0x0C  // 频道2接收数据地址
#define RX_ADDR_P3      0x0D  // 频道3接收数据地址
#define RX_ADDR_P4      0x0E  // 频道4接收数据地址
#define RX_ADDR_P5      0x0F  // 频道5接收数据地址
#define TX_ADDR         0x10  // 发送地址寄存器
#define RX_PW_P0        0x11  // 接收频道0接收数据长度
#define RX_PW_P1        0x12  // 接收频道0接收数据长度
#define RX_PW_P2        0x13  // 接收频道0接收数据长度
#define RX_PW_P3        0x14  // 接收频道0接收数据长度
#define RX_PW_P4        0x15  // 接收频道0接收数据长度
#define RX_PW_P5        0x16  // 接收频道0接收数据长度
#define FIFO_STATUS     0x17  // FIFO栈入栈出状态寄存器设置
//----------------------------------函数申明------------------------------------

void Init_DS18B20(void);
char ReadOneChar(void);
void WriteOneChar(char dat);
void ReadTemperature(void);
void work_temp();
void StartUART(void);
void R_S_Byte(char R_Byte);
void DS1820_delay(int i);
//------------------------------------------------------------------------------
void Delay(int s);
void inerDelay_us(char n);
void init_NRF24L01(void);
char SPI_RW(char data);
char SPI_Read(char reg);
char SPI_RW_Reg(char reg, char value);
char SPI_Read_Buf(char reg, char *pBuf, char uchars);
char SPI_Write_Buf(char reg, char *pBuf, char uchars);
void SetRX_Mode(void);
char nRF24L01_RxPacket(char* rx_buf);
void nRF24L01_TxPacket(char * tx_buf);
//-------------------------------延时-----------------------------------------
void Delay(int s)
{
	unsigned int i;
	for(i=0; i<s; i++);
	for(i=0; i<s; i++);
}

/****************************************************************************************************
/*函数：uint SPI_RW(uint uchar)
/*功能：NRF24L01的SPI写时序
/****************************************************************************************************/
char SPI_RW(char data)
{
	char i,temp=0;
   	for(i=0;i<8;i++) // output 8-bit
   	{
	if(data & 0x80)
	{
		Hign_24L01_MOSI ;         // output 'uchar', MSB to MOSI
	}
	else
	{
	 	Low_24L01_MOSI; 
	}	
		data = (data << 1);           // shift next bit into MSB..
		temp<<=1;
		Hign_24L01_SCK ;                      // Set SCK high..
		if(Read_24L01_MISO )temp++;       		  // capture current MISO bit
		Low_24L01_SCK;            		  // ..then set SCK low again
   	}
    return(temp);           		  // return read uchar
}
/****************************************************************************************************
/*函数：uchar SPI_Read(uchar reg)
/*功能：NRF24L01的SPI时序
/****************************************************************************************************/
char SPI_Read(char reg)
{
	char reg_val;
	
	Low_24L01_CSN;                // CSN low, initialize SPI communication...
	SPI_RW(reg);            // Select register to read from..
	reg_val = SPI_RW(0);    // ..then read registervalue
	Hign_24L01_CSN;                // CSN high, terminate SPI communication
	
	return(reg_val);        // return register value
}
/****************************************************************************************************/
/*功能：NRF24L01读写寄存器函数
/****************************************************************************************************/
char SPI_RW_Reg(char reg, char value)
{
	char status;
	
	Low_24L01_CSN;                   // CSN low, init SPI transaction
	status = SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	Hign_24L01_CSN;                   // CSN high again
	
	return(status);            // return nRF24L01 status uchar
}
/****************************************************************************************************/
/*函数：uint SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars)
/*功能: 用于读数据，reg：为寄存器地址，pBuf：为待读出数据地址，uchars：读出数据的个数
/****************************************************************************************************/
char SPI_Read_Buf(char reg, char *pBuf, char uchars)
{
	int status,uchar_ctr;
	
	Low_24L01_CSN;                    		// Set CSN low, init SPI tranaction
	status = SPI_RW(reg);       		// Select register to write to and read status uchar
	
	for(uchar_ctr=0;uchar_ctr<uchars;uchar_ctr++)
		pBuf[uchar_ctr] = SPI_RW(0);    // 
	
	Hign_24L01_CSN;                           
	
	return(status);                    // return nRF24L01 status uchar
}
/*********************************************************************************************************
/*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
/*功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
/*********************************************************************************************************/
char SPI_Write_Buf(char reg, char *pBuf, char uchars)
{
	char status,uchar_ctr;
	
	Low_24L01_CSN;             //SPI使能       
	status = SPI_RW(reg);   
	for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
	SPI_RW(*pBuf++);
	Hign_24L01_CSN;           //关闭SPI
	return(status);    		  // 
}
/****************************************************************************************************/
/*函数：void SetRX_Mode(void)
/*功能：数据接收配置 
/****************************************************************************************************/
void SetRX_Mode(void)
{
	Low_24L01_CE;
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收
	Hign_24L01_CE; 
	Delay(1000);
}
/******************************************************************************************************/
/*函数：unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
/*功能：数据读取后放如rx_buf接收缓冲区中
/******************************************************************************************************/
char nRF24L01_RxPacket(char* rx_buf)
{
    char revale=0;
	sta=SPI_Read(STATUS);	// 读取状态寄存其来判断数据接收状况
	if(sta&0x40)				// 判断是否接收到数据
	{
	    Low_24L01_CE; 			//SPI使能
		SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
		revale =1;			//读取数据完成标志
	}
	SPI_RW_Reg(WRITE_REG+STATUS,sta);   //接收到数据后RX_DR,TX_DS,MAX_PT都置高为1，通过写1来清楚中断标志
	return revale;
}
/***********************************************************************************************************
/*函数：void nRF24L01_TxPacket(char * tx_buf)
/*功能：发送 tx_buf中数据
/**********************************************************************************************************/
void nRF24L01_TxPacket(char * tx_buf)
{
	Low_24L01_CE;			//StandBy I模式	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 			 // 装载数据	
//	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	Hign_24L01_CE;		 //置高CE，激发数据发送
	Delay(1000);
}
//****************************************************************************************
/*NRF24L01初始化
//***************************************************************************************/
void init_NRF24L01(void)
{

 	Low_24L01_CE;    // chip enable
 	Hign_24L01_CSN;   // Spi disable 
 	Low_24L01_SCK;   // Spi clock line init high
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      //  频道0自动	ACK应答允许	
	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	SPI_RW_Reg(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   		//设置发射速率为1MHZ，发射功率为最大值0dB	
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	Delay(6000);
}
//******************************************************************************
//**********************************DS18B20温度采集*****************************
//******************************************************************************

//----------------------------------延时函数------------------------------------
void DS1820_delay(int i)
{
	while(i--);
}
//---------------------------------DS18B20初始化--------------------------------
void Init_DS18B20(void)
{
    unsigned char x=1;
	
	Out_DQ;                //配置输出
	Hign_DQ;              //置高电平
	Low_DQ;			     //置低电平
	DS1820_delay(3000);	    //400-960us
	Hign_DQ;		   //置高电平
	In_DQ ;
	DS1820_delay(40);		  //15-60us
	while(Read_DQ)	 ; 
	Out_DQ ;
	Hign_DQ;
	DS1820_delay(300);	
}
//---------------------------------DS18B20读函数--------------------------------
char ReadOneChar(void)
{
    char i;
	char dat = 0;
	
	for(i=8;i>0;i--)
	{
	    Out_DQ;    //配置输出
	    Low_DQ;   //置低电平
		dat >>= 1;
		Hign_DQ; //置高电平
		In_DQ;  //设置输入
		if(Read_DQ)//读取电平
        {
		dat |= 0x80;
        }
		Out_DQ;//配置输出
        DS1820_delay(50);
	}
	return(dat);
}
//------------------------------DS18B20写函数-----------------------------------
void WriteOneChar(char dat)
{
    char i;
	Out_DQ;//配置输出
	for(i=8;i>0;i--)
	{
	    Low_DQ;//置低电平
		if(dat&0x01)//写电平
        {
        Hign_DQ;//置高电平
        }
        else
        {
         Low_DQ;//置低电平
        }
		DS1820_delay(40);
		Hign_DQ;//置高电平
		dat >>= 1;
	}
	DS1820_delay(8);
}
//------------------------------------读取温度------------------------------------
void ReadTemperature(void)
{		
	Init_DS18B20();
	WriteOneChar(0xCC); 			// 跳过读序号列号的操作
	WriteOneChar(0x44); 			// 启动温度转换
	
	
	Init_DS18B20();
	WriteOneChar(0xCC); 			//跳过读序号列号的操作
	WriteOneChar(0xBE); 			//读取温度寄存器等（共可读9个寄存器） 前两个就是温度

	temp_data[0]= ReadOneChar();   		//读取温度值低位LSB
	temp_data[1]= ReadOneChar();   //读取温度值高位MSB
	
}
//-----------------------------------BCD码温度处理------------------------------
//dispaly[0]十位
//dispaly[1]个位
//dispaly[2]小数位
//dispaly[3]临界标志位
//------------------------------------------------------------------------------
void work_temp()
{
	char n=0;
	if(temp_data[1]>127)
	{
	temp_data[1]=(256-temp_data[1]);
	temp_data[0]=(256-temp_data[0]);
	n=1;
	}
//------------------------------------------------------------------------------
	dispaly[6]=((temp_data[0]&0xf0)>>4)|((temp_data[1]&0x0f)<<4);
	dispaly[5]=dispaly[6]/100;				//百位
	dispaly[4]=dispaly[6]%100;				//
	dispaly[2]=dispaly[4]/10;               //十位
	dispaly[1]=dispaly[4]%10;			    //个位
	
	switch	(temp_data[0]&0x0f)
	{
	case 0x0f:dispaly[0]=9;break;
	case 0x0e:dispaly[0]=9;break;
	case 0x0d:dispaly[0]=8;break;
	case 0x0c:dispaly[0]=8;break;
	case 0x0b:dispaly[0]=7;break;
	case 0x0a:dispaly[0]=6;break;
	case 0x09:dispaly[0]=6;break;
	case 0x08:dispaly[0]=5;break;
	case 0x07:dispaly[0]=4;break;
	case 0x06:dispaly[0]=4;break;
	case 0x05:dispaly[0]=3;break;
	case 0x04:dispaly[0]=3;break;
	case 0x03:dispaly[0]=2;break;
	case 0x02:dispaly[0]=1;break;
	case 0x01:dispaly[0]=1;break;
	case 0x00:dispaly[0]=1;break;
	default:break;
	}
		if(n)								//温度正负区分
	{
	dispaly[3]=0x11;						//零下
	}
	else
	{
	dispaly[3]=0x22;				  	//零上
	}
}
//------------------------------------------------------------------------------
void  dis_zhuye()
{
	 PORTC=seg[dispaly[2]];
	 Hign_Display4;
	 Hign_Display3;
	 Hign_Display2;
	 Low_Display1;
	Delay(80);
	 Hign_Display1;
//------------------------------------------------------------------------------
	 PORTC=seg1[dispaly[1]];
	 Low_Display2;
	 Delay(80);
	 Hign_Display2;
//------------------------------------------------ ---------------------------
	 PORTC=seg[dispaly[0]];
	 Low_Display3;
	 Delay(80);
	 Hign_Display3;
//----------------------------------------------------------------------------- 
	 PORTC=0xc6;
	 Low_Display4;
	 Delay(80);
	 Hign_Display4;	 
}
main()
{
 	DDRB=0xe4;
	DDRC=0xff;
	DDRA=0x1e;
	PORTA=0x00;
	PORTC=0xbf;
	Init_DS18B20();
    init_NRF24L01() ;
	
	while(1)
	{
	ReadTemperature();		//读取温度
	work_temp();			//温度处理
	dis_zhuye();
	nRF24L01_TxPacket(dispaly);	// Transmit Tx buffer data
    SPI_RW_Reg(WRITE_REG+STATUS,0XFF);  
	}	
}