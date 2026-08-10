/****************************************/
/*        nRF24L01_SPI通信程序
     连线方式：
             IOB0---》CE      （7脚）
             IOB1---》CSN     （6脚）
             IOB2---》SCK     （5脚）
             IOB3---》MOSI    （4脚）
             IOB4---》MISO    （3脚）
             IOB5---》IRQ     （2脚）
*/
/****************************************/
#include "SPCE061V004.H"
//#include "LCD.h"


#define MISO     *P_IOB_Data
#define uchar      unsigned char
#define MOSI_High *P_IOB_Data|=0x0008
#define MOSI_Low  *P_IOB_Data&=0xfff7
#define SCK_High  *P_IOB_Data|=0x0004
#define SCK_Low   *P_IOB_Data&=0xfffb
#define CE_High   *P_IOB_Data|=0x0001
#define CE_Low    *P_IOB_Data&=0xfffe
#define CSN_High  *P_IOB_Data|=0x0002
#define CSN_Low   *P_IOB_Data&=0xfffd

#define TX_ADR_WIDTH    5   		// 5 bytes TX(RX) address width
#define TX_PLOAD_WIDTH  20  		// 20 bytes TX payload
#define	RX_DS      sta&0x40       // RX_DR=sta^6;
#define TX_DS      sta&0x20       //	TX_DS	=sta^5;
#define MAX_RT     sta&0x10      //	MAX_RT	=sta^4;
// SPI(nRF24L01) commands
#define READ_REG    0x00 						// Define read command to register
#define WRITE_REG   0x20 						// Define write command to register
#define RD_RX_PLOAD 0x61 					// Define RX payload register address
#define WR_TX_PLOAD 0xA0 					// Define TX payload register address
#define FLUSH_TX    0xE1 						// Define flush TX register command
#define FLUSH_RX    0xE2 						// Define flush RX register command
#define REUSE_TX_PL 0xE3 					// Define reuse TX payload register command
#define NOP         0xFF 							// Define No Operation, might be used to read status register
//***************************************************//
// SPI(nRF24L01) registers(addresses)
#define CONFIG      0x00						 // 'Config' register address
#define EN_AA       0x01                      // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR   0x02                  // 'Enabled RX addresses' register address
#define SETUP_AW    0x03                     // 'Setup address width' register address
#define SETUP_RETR  0x04                  // 'Setup Auto. Retrans' register address
#define RF_CH       0x05                       // 'RF channel' register address
#define RF_SETUP    0x06 					// 'RF setup' register address
#define STATUS      0x07 					// 'Status' register address
#define OBSERVE_TX  0x08 				// 'Observe TX' register address
#define CD          0x09 						//'Carrier Detect' register address
#define RX_ADDR_P0  0x0A					 // 'RX address pipe0' register address
#define RX_ADDR_P1  0x0B 				// 'RX address pipe1' register address
#define RX_ADDR_P2  0x0C 				// 'RX address pipe2' register address
#define RX_ADDR_P3  0x0D 				// 'RX address pipe3' register address
#define RX_ADDR_P4  0x0E 				// 'RX address pipe4' register address
#define RX_ADDR_P5  0x0F				    // 'RX address pipe5' register address
#define TX_ADDR     0x10 					// 'TX address' register address
#define RX_PW_P0    0x11 					// 'RX payload width, pipe0' register address
#define RX_PW_P1    0x12 					// 'RX payload width, pipe1' register address
#define RX_PW_P2    0x13 					// 'RX payload width, pipe2' register address
#define RX_PW_P3    0x14 					// 'RX payload width, pipe3' register address
#define RX_PW_P4    0x15 					// 'RX payload width, pipe4' register address
#define RX_PW_P5    0x16 					// 'RX payload width, pipe5' register address
#define FIFO_STATUS 0x17 			    	// 'FIFO Status Register' register address

unsigned char Buffer[5]={"0","3","4","5","8"};
unsigned char const TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};  // Define a static TX address
unsigned char  SPI_ReceiveData;
unsigned char RX[16];
unsigned char Tx_Buffer[5]={"abc"};
void Initial_IOB()  //初始化IOB端口
{
   *P_IOB_Dir=0xffcf;    //set IRQ,MISO input ,the other output
   *P_IOB_Attrib=0xffcf;  
   *P_IOB_Data=0x0000;
   
}
  void delay1us(unsigned char t)
{
    while(--t)
       *P_Watchdog_Clear=1;
} 
unsigned char SPI_RW(unsigned char byte)   //写一个字节到24L01，同时读一个字节
{
     unsigned char bit_ctr;
        
     for(bit_ctr=0;bit_ctr<8;bit_ctr++)   //output 8-bit
       {
           if(byte&0x80)  
              MOSI_High;
           else
             MOSI_Low; 
             byte=(byte<<1); 
             SCK_High;
             if(MISO&0x0010) byte |= 1;       //SPI_ReceiveData=MISO;
             SCK_Low;
            
           //  SPI_ReceiveData =( SPI_ReceiveData<<1);
       }
       return(byte);  //return read byte
}
unsigned char SPI_Read(unsigned char reg)
{
	unsigned char reg_val;

  	CSN_Low;             // CSN low, initialize SPI communication...
  	SPI_RW(reg);            // Select register to read from..
  	reg_val = SPI_RW(0);    // ..then read registervalue
  	CSN_High;                // CSN high, terminate SPI communication

  	return(reg_val);        // return register value
}

/****向寄存器reg写一个字节，同时返回状态字节**************/
unsigned char SPI_RW_Reg(unsigned char reg,unsigned char value)
{
   unsigned char status;
   CSN_Low;
   status=SPI_RW(reg);   //select register  and write value to it
   SPI_RW(value);   
   CSN_High;
   return(status);     
}
/********读出bytes字节的数据*************************/
unsigned char SPI_Read_Buf(uchar reg,uchar *pBuf,uchar bytes)
{
  uchar status,byte_ctr;
  CSN_Low;
  status=SPI_RW(reg);       
  for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
   	pBuf[byte_ctr]=SPI_RW(0);
   CSN_High;
   return(status);
}
/****************写入bytes字节的数据*******************/
unsigned char SPI_Write_Buf(uchar reg,uchar *pBuf,uchar bytes)
{
   uchar status,byte_ctr;
   CSN_Low;
   delay1us(1);
   status=SPI_RW(reg);       
   for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
   		SPI_RW(*pBuf++);
   CSN_High;
   delay1us(1);
   return(status);
}
/*接收函数，返回1表示有数据收到，否则没有数据接收到**/
unsigned char nRF24L01_RxPacket(unsigned char *rx_buf)
{
   unsigned char sta,revale=0;               
   SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);  
   CE_High;
   delay1us(10);
   
  sta=SPI_Read(STATUS); 		// read register STATUS's value
   if(RX_DS) 					   // if receive data ready (RX_DR) interrupt
    {
		  CE_Low;                // stand by mode
		  SPI_Read_Buf(RD_RX_PLOAD,rx_buf,WR_TX_PLOAD); // read receive payload from RX_FIFO buffer
	   	  revale =1;
     }
     SPI_RW_Reg(WRITE_REG+STATUS,sta);   // clear RX_DR or TX_DS or MAX_RT interrupt flag
     return revale;
   
} 
 /****************发送函数***************************/
void nRF24L01_TxPacket(unsigned char *tx_buf)
{
     CE_Low;		//  CE=0;
     SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);       // WritesTX_Address to nRF24L01
     SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);     //RX_Addr0 same as TX_Adr for Auto.Ack
     SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH);   // Writes data to TX payload
     SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);            // Set PWR_UP bit, enable CRC(2 bytes) &Prim:TX. MAX_RT & TX_DS enabled..
     CE_High;		//CE=1;
     delay1us(10);
     CE_Low;       //CE=0;
}   
void RX_Mode(void)
{
	CE_Low;   //CE=0;
	delay1us(1);
    SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
  	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
  	SPI_Write_Buf(WR_TX_PLOAD, Buffer, TX_PLOAD_WIDTH); // Writes data to TX payload

  	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
  	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:TX. MAX_RT & TX_DS enabled..


  	CE_High;   //CE = 1   Set CE pin high to enable RX device
    delay1us(1);
  //  This device is now ready to receive one packet of 16 bytes payload from a TX device sending to address
  //  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.
}
void TX_Mode(void)
{
	CE_Low;      //CE=0;
	delay1us(1);
  	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
  	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
  	SPI_Write_Buf(WR_TX_PLOAD,Tx_Buffer, TX_PLOAD_WIDTH);         // Writes data to TX payload

 	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
  	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:TX. MAX_RT & TX_DS enabled..
   
    CE_High;    //	CE=1;  
    delay1us(1);  
} 
void nRF24L01_Initial(void)
{
	  CE_Low;			//nRF24L01_CE=0;			 chip enable
	  CSN_High;			//nRF24L01_CSN=1;			 Spi disable
	  SCK_Low;          //nRF24L01_SCK=0;			 Spi clock line init high
	
	
}
/****************** 配置函数********************************/
void nRF24L01_Config(void)
{
          //initial io
     CE_Low;          //        CE=0 ;chip enable
     CSN_High;       //CSN=1   Spi disable
     SCK_Low;       //SCK=0   // Spi clock line init high
     CE_Low;        //CE=0;
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f); // Set PWR_UP bit, enable CRC(2 bytes) &Prim:RX. RX_DR enabled..
    SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);
    SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01); // Enable Pipe0
    SPI_RW_Reg(WRITE_REG + SETUP_AW, 0x02); // Setup address width=5 bytes
    SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
    SPI_RW_Reg(WRITE_REG + RF_CH, 0);
    SPI_RW_Reg(WRITE_REG + RF_SETUP,0x0f); // TX_PWR:0dBm, Datarate:2Mbps,
}  
main()
{   
   int a;
  Initial_IOB();
  nRF24L01_Initial();
  TX_Mode(); 
  // RX_Mode();
   while(1)
    {
         
	   //自己添加要发送的内容到数组里
	   
      ///   nRF24L01_TxPacket(*****)
	      delay1us(100);
		  *P_Watchdog_Clear=1;
    }
}