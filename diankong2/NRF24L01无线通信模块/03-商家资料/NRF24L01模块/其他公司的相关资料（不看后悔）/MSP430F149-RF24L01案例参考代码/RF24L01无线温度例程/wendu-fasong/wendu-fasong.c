#include <msp430x14x.h>
//===========================DS18B20端口========================================
#define  OUT_DS18B20_0     P6OUT &=~BIT7          //输出0
#define  OUT_DS18B20_1     P6OUT |= BIT7          //输出1
#define  DS18B20_IN        P6DIR &=~BIT7          //方向设置为输入
#define  DS18B20_OUT       P6DIR |= BIT7          //方向设置为输出
//==============================================================================
#define  RF24L01_CE_0        P3OUT &=~BIT1         
#define  RF24L01_CE_1        P3OUT |= BIT1        
//=============================RF24L01_CSN端口==================================
#define  RF24L01_CSN_0       P3OUT &=~BIT3         
#define  RF24L01_CSN_1       P3OUT |= BIT3     
//=============================RF24L01_SCK======================================
#define  RF24L01_SCK_0       P3OUT &=~BIT2      
#define  RF24L01_SCK_1       P3OUT |= BIT2   
//=============================MISO端口=========================================
#define  RF24L01_MISO_0      P3OUT &=~BIT0
#define  RF24L01_MISO_1      P3OUT |= BIT0
//============================= RF24L01_MOSI端口================================
#define  RF24L01_MOSI_0      P2OUT &=~BIT6
#define  RF24L01_MOSI_1      P2OUT |= BIT6
//==========================IRQ状态============================================
#define  RF24L01_IRQ_0       P2OUT &=~BIT7       
#define  RF24L01_IRQ_1       P2OUT |= BIT7
//==============================================================================
#define  LED1_0              P6OUT &=~BIT1          //输出0
#define  LED1_1              P6OUT |= BIT1          //输出1
#define  LED2_0              P6OUT &=~BIT2          //输出0
#define  LED2_1              P6OUT |= BIT2          //输出1
//============================DS18B20寄存器指令=================================
#define DS18B20_READ_ROM          0x33
#define DS18B20_MATCH_ROM         0X55
#define DS18B20_SKIP_ROM          0XCC
#define DS18B20_SEARCH_ROM        0XF0
#define DS18B20_ALARM_SEARCH_ROM  0XEC
#define DS18B20_WRITE_RAM         0X40
#define DS18B20_READ_RAM          0XBE
#define DS18B20_COPY_RAM          0X48 
#define DS18B20_CONVERT_TEM       0X44
#define DS18B20_EECALL_EEPROM     0XB8
#define DS18B20_READ_POWER_SUPPLY 0XB4
//==========================NRF24L01============================================
#define TX_ADR_WIDTH    5   	// 5 uints TX address width
#define RX_ADR_WIDTH    5   	// 5 uints RX address width
#define TX_PLOAD_WIDTH  32  	// 32 TX payload
#define RX_PLOAD_WIDTH  32  	// 32 uints TX payload
//=========================NRF24L01寄存器指令===================================
#define READ_REG        0x00  	// 读寄存器指令
#define WRITE_REG       0x20 	// 写寄存器指令
#define RD_RX_PLOAD     0x61  	// 读取接收数据指令
#define WR_TX_PLOAD     0xA0  	// 写待发数据指令
#define FLUSH_TX        0xE1 	// 冲洗发送 FIFO指令
#define FLUSH_RX        0xE2  	// 冲洗接收 FIFO指令
#define REUSE_TX_PL     0xE3  	// 定义重复装载数据指令
#define NOP1            0xFF  	// 保留
//========================SPI(nRF24L01)寄存器地址===============================
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
//=============================RF24l01状态=====================================
char  TX_ADDRESS[TX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//本地地址
char  RX_ADDRESS[RX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//接收地址
char  sta;
//===========================DS18B20相关变量====================================
char temp_data[2]={0x00,0x00};
char dispaly[32];
//******************************************************************************
//系统初始化
//******************************************************************************
void InitSys()
{
   unsigned int iq0;
   _DINT();
   BCSCTL1 &=~XT2OFF;
   do
   {
      IFG1 &= ~OFIFG;							// 清除振荡器失效标志
      for (iq0 = 0xFF; iq0 > 0; iq0--);	// 延时，等待XT2起振
   }
   while ((IFG1 & OFIFG) != 0);		// 判断XT2是否起振		
   BCSCTL2 =SELM1+SELS;                // MCLK,SMCLK时钟为XT2		
}
//===========================LED端口设置==========================================
void LED_IO_set(void)
{    
      P6DIR |= 0x06;   P6SEL&=0xf9;        
}
//==============================================================================
void DS18B20_IO_set(void)
{
  P6SEL&=0x7f; 
}
//===========================RF24L01端口设置==========================================
void RF24L01_IO_set(void)
{
      P2DIR &= 0x7f;    P2DIR |= 0x40;  P2SEL&=0x3F;   P2IE=P2IE&0x3f;
      P3DIR &= 0xFE;    P3DIR |= 0x0E;  P3SEL&=0xF0;
}
//========================延时约5ms=============================================
void ms_delay(void)
{ 
   unsigned int i=40000;
    while (i != 0)
    {
        i--;
    }
}
//========================================长延时================================
void Delay(int s)
{
	unsigned int i,j;
	for(i=0; i<s; i++);
	for(j=0; j<s; j++);
}
//===========================DS18B20延时========================================  
void DS1820_delay(int i)
{
	while(i--);
}
//==========================DS18B20复位=========================================
void ds18b20_reset(void) 
{ 

  DS18B20_OUT; //
  OUT_DS18B20_1;
  OUT_DS18B20_0;
  DS1820_delay(3000);  //500us
  OUT_DS18B20_1;
  DS18B20_IN;    //设置为输入
  DS1820_delay(40);
  while(P6IN&BIT7);
  DS18B20_OUT;
  OUT_DS18B20_1;
  DS1820_delay(300);
} 
//========================DS18B20读操作函数=====================================
char ds18b20_read(void) 
{ 
  char i;
  char temp=0;
  for(i=0;i<8;i++)
  {
   DS18B20_OUT;
   OUT_DS18B20_0;
   temp>>=1;
   OUT_DS18B20_1;
   DS18B20_IN;
   if(P6IN&BIT7)
   {
     temp|=0x80;
   }
     DS1820_delay(4);
     DS18B20_OUT;
     DS1820_delay(50);
  }
return (temp);
}
//========================DS18B20写操作函数=====================================
void ds18b20_write(char Date) 
{ 
  char i; 
    DS18B20_OUT;
     for(i=0;i<8;i++)
     {
       OUT_DS18B20_0;
      // DS1820_delay(6);
       if(Date & 0x01) 
       {
         OUT_DS18B20_1;
       }
       else
       {
         OUT_DS18B20_0;
       }
       DS1820_delay(40);
       OUT_DS18B20_1;
       Date>>=1;
     }
       DS1820_delay(8);
} 

//======================DS18B20温度转换函数=====================================
void Ds18b20Convert(void) 
{ 
   ds18b20_reset(); 
  ds18b20_write(0xCC); 
  ds18b20_write(0x44);
  
  Delay(200);
    
  ds18b20_reset(); 
  ds18b20_write(0xCC); //??????
  ds18b20_write(0xBE); //?RAM??
  
  temp_data[0]=ds18b20_read(); 
  temp_data[1]=ds18b20_read();
}
//=========================温度换算处理=========================================
void work_temp()
{
	char n=0;
if(temp_data[1]>127)
	{
	temp_data[1]=(256-temp_data[1]);			//负值
	temp_data[0]=(256-temp_data[0]);
	n=1;
	}
	dispaly[6]=((temp_data[0]&0xf0)>>4)|((temp_data[1]&0x0f)<<4);
	dispaly[5]=dispaly[6]/100;				//百位
	dispaly[4]=dispaly[6]%100;				//
	dispaly[2]=dispaly[4]/10;				//十位
	dispaly[1]=dispaly[4]%10;				//个位	
	switch	(temp_data[0]&0x0f)				//小数位
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
if(n)										//负值时显示aa,正直显示dd
	{
	dispaly[3]=0x11;						//
	}
else 	dispaly[3]=0x22;
}
//******************************************************************************************
//延时函数
//******************************************************************************************
void inerDelay_us(char n)
{
	for(;n>0;n--);
}
//==============================================================================
//函数：uint SPI_RW(uint uchar)
//功能：NRF24L01的SPI写时序
//******************************************************************************
char SPI_RW(char data)
{
	char i,temp=0;
   	for(i=0;i<8;i++) // output 8-bit
   	{
	if((data & 0x80)==0x80)
	{
		RF24L01_MOSI_1;         // output 'uchar', MSB to MOSI
	}
	else
	{
	 	RF24L01_MOSI_0; 
	}	
//==============================================================================
		data = (data << 1);            // shift next bit into MSB..
		temp<<=1;
		RF24L01_SCK_1;                // Set SCK high..
		if((P3IN&0x01)==0x01)temp++;         // capture current MISO bit
		RF24L01_SCK_0;              // ..then set SCK low again
   	}
    return(temp);           		  // return read uchar
}
//****************************************************************************************************
//函数：uchar SPI_Read(uchar reg)
//功能：NRF24L01的SPI时序
//****************************************************************************************************
char SPI_Read(char reg)
{
	char reg_val;
	RF24L01_CSN_0;           // CSN low, initialize SPI communication...
	SPI_RW(reg);            // Select register to read from..
	reg_val = SPI_RW(0);    // ..then read registervalue
	RF24L01_CSN_1;         // CSN high, terminate SPI communication
	return(reg_val);       // return register value
}
//****************************************************************************************************/
//功能：NRF24L01读写寄存器函数
//****************************************************************************************************/
char SPI_RW_Reg(char reg, char value)
{
	char status1;
	RF24L01_CSN_0;                   // CSN low, init SPI transaction
	status1 = SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	RF24L01_CSN_1;                   // CSN high again
	return(status1);            // return nRF24L01 status uchar
}
//****************************************************************************************************/
//函数：uint SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars)
//功能: 用于读数据，reg：为寄存器地址，pBuf：为待读出数据地址，uchars：读出数据的个数
//****************************************************************************************************/
char SPI_Read_Buf(char reg, char *pBuf, char chars)
{
	char status2,uchar_ctr;
	RF24L01_CSN_0;                    		// Set CSN low, init SPI tranaction
	status2 = SPI_RW(reg);       		// Select register to write to and read status uchar
	for(uchar_ctr=0;uchar_ctr<chars;uchar_ctr++)
        {
	pBuf[uchar_ctr] = SPI_RW(0);    // 
        }
	RF24L01_CSN_1;                           
	return(status2);                    // return nRF24L01 status uchar
}
//*********************************************************************************************************
//函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
//功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
//*********************************************************************************************************/
char SPI_Write_Buf(char reg, char *pBuf, char chars)
{
	char status1,uchar_ctr;
	RF24L01_CSN_0;             //SPI使能       
	status1 = SPI_RW(reg);   
	for(uchar_ctr=0; uchar_ctr<chars; uchar_ctr++) //
        {
	SPI_RW(*pBuf++);
        }
	RF24L01_CSN_1;           //关闭SPI
	return(status1);    		  // 
}
//****************************************************************************************************/
//函数：void SetRX_Mode(void)
//功能：数据接收配置 
//****************************************************************************************************/
void SetRX_Mode(void)
{
	RF24L01_CE_0 ;
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收
	RF24L01_CE_1; 
	inerDelay_us(130);//注意不能太小
}
//******************************************************************************************************/
//函数：unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
//功能：数据读取后放如rx_buf接收缓冲区中
//******************************************************************************************************/
char nRF24L01_RxPacket(char* rx_buf)
{
    char revale=0;
	sta=SPI_Read(STATUS);	     // 读取状态寄存其来判断数据接收状况		
	if(sta&0x40)                 // 判断是否接收到数据
	{
	    RF24L01_CE_0 ; 			//SPI使能
	    SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
	    revale =1;			//读取数据完成标志
	}
	SPI_RW_Reg(WRITE_REG+STATUS,sta);   //接收到数据后RX_DR,TX_DS,MAX_PT都置高为1，通过写1来清楚中断标志
	return revale;
}
//***********************************************************************************************************
//函数：void nRF24L01_TxPacket(char * tx_buf)
//功能：发送 tx_buf中数据
//**********************************************************************************************************/
void nRF24L01_TxPacket(char * tx_buf)
{
	RF24L01_CE_0 ;			//StandBy I模式	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 			 // 装载数据	
   //     SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	RF24L01_CE_1;		 //置高CE，激发数据发送
	inerDelay_us(10);
}
//****************************************************************************************
//NRF24L01初始化
//***************************************************************************************/
void init_NRF24L01(void)
{
        inerDelay_us(100);
 	RF24L01_CE_0 ;    // chip enable
 	RF24L01_CSN_1;   // Spi disable 
 	RF24L01_SCK_0;   // Spi clock line init high
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      //  频道0自动	ACK应答允许	
	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	SPI_RW_Reg(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   //设置发射速率为1MHZ，发射功率为最大值0dB
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0E);   // IRQ收发完成中断响应，16位CRC	，主接收}
} 
//=============================================================================
main()
{     
      WDTCTL = WDTPW + WDTHOLD; //禁止看门狗
      LED_IO_set();
      RF24L01_IO_set();
      DS18B20_IO_set(); 
      InitSys();
      init_NRF24L01() ;
      Ds18b20Convert();
      LED1_1;LED2_1;
      while(1)
      {
       Ds18b20Convert();          //采集温度
       LED1_0;
       work_temp();	
       nRF24L01_TxPacket(dispaly);  //把采集好的温度数据发送出去	
       SPI_RW_Reg(WRITE_REG+STATUS,0XFF);   //清状态寄存器
       ms_delay();          
       ms_delay();
       LED1_1;
       ms_delay();          
       ms_delay();
      }
}