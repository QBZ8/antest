//ICC-AVR application builder : 2006-02-12 14:00:00
// Target : ATmega48
// Crystal: 8.000Mhz
// Author:  jackyan
// Oled Type : white
//#define fosc 8000000
//#define baud 9600
#include "iom48v.h"
#include "macros.h"
#include "defs.h"
/*-----------------------------------------------------------------------------
   Global Defines
------------------------------------------------------------------------------*/
unsigned char   key_debug;
unsigned char 	Buffer[]={
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
#define TX_ADR_WIDTH    5   // 5 bytes TX(RX) address width
#define TX_PLOAD_WIDTH  20  // 16 bytes TX payload
unsigned char TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define a static TX address
void init_CPU (void);
void delayms(unsigned short	dly);//当dly=1时，延时的时间是1ms  4MHz晶震
void INIT_io(void);
void RX_Mode(void);
void TX_Mode(void);
void delay(void);
unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value);
unsigned char SPI_Read(unsigned char reg);
void clear_buf(unsigned char	*ptr,unsigned char number);
unsigned char accept_flag=0;
unsigned char send_flag=0;
unsigned int accept_time=0;
void nrf24l01init(void);
void timer0_init(void);
//****************************************************************//
// SPI(nRF24L01) commands
#define READ_REG        0x00  // Define read command to register
#define WRITE_REG       0x20  // Define write command to register
#define RD_RX_PLOAD     0x61  // Define RX payload register address
#define WR_TX_PLOAD     0xA0  // Define TX payload register address
#define FLUSH_TX        0xE1  // Define flush TX register command
#define FLUSH_RX        0xE2  // Define flush RX register command
#define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
//#define NOP             0xFF  // Define No Operation, might be used to read status register
//***************************************************//
// SPI(nRF24L01) registers(addresses)
#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define CD              0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address
#define MAX_RT  	0x10  // Max #of TX retrans interrupt
#define TX_DS   	0x20  // TX data sent interrupt
#define RX_DR   	0x40  // RX data received
//-----------------------------------------------------------------------------
//------------------------------------------------------
unsigned char t20ms;
#define BIT(x)	           (1 << (x))
#define SETBIT(x, y)   	   (x |= y)
#define CLEARBIT(x, y) 	   (x &= ~y)
#define CHECKBIT(x, y) 	   (x & y)
#define BIT7 0x80
#define BIT6 0x40
#define BIT5 0x20
#define BIT4 0x10
#define BIT3 0x08
#define BIT2 0x04
#define BIT1 0x02
#define BIT0 0x01
#define nRF24L01_CSN        BIT6
#define nRF24L01_SCK        BIT7
#define nRF24L01_MOSI       BIT0
#define nRF24L01_CE         BIT5   
#define nRF24L01_MISO 	    BIT1
#define nRF24L01_IRQ  	    BIT2
#define nRF24L01_CSNH       SETBIT(PORTD, nRF24L01_CSN)     
#define nRF24L01_CSNL       CLEARBIT(PORTD, nRF24L01_CSN)   

#define nRF24L01_CSN_DIR    SETBIT(DDRD, nRF24L01_CSN)  //OUTPUT

#define nRF24L01_SCKH       SETBIT(PORTD,nRF24L01_SCK)      
#define nRF24L01_SCKL       CLEARBIT(PORTD,nRF24L01_SCK)    
#define nRF24L01_SCK_DIR   SETBIT(DDRD,nRF24L01_SCK)  //OUTPUT
 
#define nRF24L01_MOSIH      SETBIT(PORTB,nRF24L01_MOSI)     
#define nRF24L01_MOSIL	    CLEARBIT(PORTB,nRF24L01_MOSI)   
#define nRF24L01_MOSI_DIR   SETBIT(DDRB,nRF24L01_MOSI)

#define nRF24L01_CEH        SETBIT(PORTD,nRF24L01_CE)  //OUTPUT   
#define nRF24L01_CEL        CLEARBIT(PORTD,nRF24L01_CE)
#define nRF24L01_CE_DIR     SETBIT(DDRD,nRF24L01_CE)

#define nRF24L01_IRQ_DIR     CLEARBIT(DDRB,nRF24L01_IRQ) //INPUT

#define nRF24L01_MISO_DIR    CLEARBIT(DDRB,nRF24L01_MISO) //INPUT
#define key1 	BIT4
#define key2 	BIT3
#define key3 	BIT2
#define key4 	BIT5
#define key5 	BIT4
#define key6 	BIT3
#define key7 	BIT2
#define key8 	BIT1
#define 	bit20ms 					BIT0
unsigned char flag;
unsigned char key1_pulse;
unsigned char key2_pulse;
unsigned char key3_pulse;
unsigned char key4_pulse;
unsigned char key5_pulse;
unsigned char key6_pulse;
unsigned char key7_pulse;
unsigned char key8_pulse;
unsigned char key1_flag;
unsigned char key2_flag;
unsigned char key3_flag;
unsigned char key4_flag;
unsigned char key5_flag;
unsigned char key6_flag;
unsigned char key7_flag;
unsigned char key8_flag;
unsigned char key8_long_flag;
unsigned char send_flag;
unsigned char key1_time;
unsigned char key2_time;
unsigned char key3_time;
unsigned char key4_time;
unsigned char key5_time;
unsigned char key6_time;
unsigned char key7_time;
unsigned char key8_time;
//-----------------------------------------------------------------------------
void main(void)
{
 	unsigned char Get_SO=0;
    CLI();                   /* global interrupt disable */
    init_CPU ();
    delayms(100);	//延时10ms*10=100ms
    delayms(100);	//延时10ms*10=100ms
	timer0_init();
	RX_Mode();
	SEI();
	while(1)
	{		
		//	if(!(PINB& 0x01))
		WDR();
		if(!(PINB& nRF24L01_IRQ))
		{//nRF24L01 接收数据
			key_debug=SPI_Read(STATUS);			// read register STATUS's value
			if(key_debug&RX_DR)					// if renRF24L01_CEive data ready (RX_DR) interrupt
				SPI_Read_Buf(RD_RX_PLOAD,Buffer,TX_PLOAD_WIDTH);// read renRF24L01_CEive payload from RX_FIFO buffer
			if(key_debug&MAX_RT) SPI_RW_Reg(FLUSH_TX,0);
			SPI_RW_Reg(WRITE_REG+STATUS,0xff);// clear RX_DR or TX_DS or MAX_RT interrupt flag
			RX_Mode();
			if((Buffer[0]==80)&&(Buffer[1]==01))//data accept
			{
			 	accept_flag=1;
			}
		}
		if(send_flag==1)//data send
		{
		 		Buffer[0]=80;
				Buffer[1]=02;
				TX_Mode();			// set TX Mode and transmitting
				delayms(100);
				RX_Mode();
				Buffer[0]=00;
				Buffer[1]=00;
		}
//========================================数据一直发送
		if(key8_long_flag==1)//data send
		{
		 		Buffer[0]=80;
				Buffer[1]=02;
				TX_Mode();			// set TX Mode and transmitting
				delayms(100);
				RX_Mode();
				Buffer[0]=00;
				Buffer[1]=00;
		}
//========================================数据一直发送
		if(send_flag==1)
		{
		   accept_time++;
		   if(accept_time>30)
		   {
		   	 send_flag=0;
			 accept_time=0;
		   }
		}
		if(accept_flag==1)
		{
		    accept_flag=0;
    	 	PORTB = 0x80;
		    delayms(5000);	//延时10ms*10=100ms
		    PORTB = 0x00;
		}
	}


}
void nrf24l01init(void)
{
 	 nRF24L01_IRQ_DIR;
	 nRF24L01_MISO_DIR;
	 nRF24L01_CE_DIR;
	 nRF24L01_SCK_DIR;
	 nRF24L01_CSN_DIR;
	 nRF24L01_MOSI_DIR;
}
/*-----------------------------------------------------------------------------
   Module:   init_CPU
   Function: Initialization of CPU
------------------------------------------------------------------------------*/
void init_CPU (void)
{
 	MCUCR = 0x00;	// 
	EICRA = 0x00; //extended ext ints
    EIMSK = 0x00;
	 
	TIMSK0 = 0x01; //timer 0 interrupt sources
	TIMSK1 = 0x00; //timer 1 interrupt sources
	TIMSK2 = 0x00; //timer 2 interrupt sources
	 CLI(); //disable all interrupts
	 NOP();
	PORTB = 0x01;
 	DDRB  = 0xf3;
	PORTD = 0x80;
	DDRD  = 0xE3;
	PORTC = 0x80;
	DDRC  = 0x40;
	nrf24l01init();
    nRF24L01_CEL;
	delay();
	nRF24L01_CSNH;			// Spi disable
	delay();
	nRF24L01_SCKL;	
	delay();
}
void delay(void)//
{
	NOP();
	NOP();
	NOP();
	NOP();
	NOP();
	NOP();
}
void delayms(unsigned short	dly)//
{
	for(;dly>0;dly--) ;
}

void clear_buf(unsigned char	*ptr,unsigned char number)//清零buffer,指定字节个数
{
	for (;number>0;number--) *ptr++=0;
}
//------------------------------------------------------
/**************************************************
Function: SPI_RW();

Description:
  Writes one byte to nRF24L01, and return the byte read
  from nRF24L01 during write, according to SPI protocol  */
/**************************************************/
unsigned char SPI_RW(unsigned char byte)
{
	unsigned char  bit_ctr;	
   	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   	// output 8-bit
   	{
   		if(byte & 0x80) 
   			nRF24L01_MOSIH;
   		else 
   			nRF24L01_MOSIL;
		delay();
   		byte = (byte << 1);           		// shift next bit into MSB..
   		nRF24L01_SCKH;
		delay();
 		if(PINB&nRF24L01_MISO) byte |= 1;
   		nRF24L01_SCKL;
		delay();
   	}
    return(byte);           		  		// return read byte
}
/**************************************************
Function: SPI_RW_Reg();

Description:
  Writes value 'value' to register 'reg' */
/**************************************************/
unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value)
{
	unsigned char status;
	nRF24L01_CSNL;
	delay();
	status = SPI_RW(reg);      // select register
  	SPI_RW(value);             // ..and write value to it..
	nRF24L01_CSNH;
	delay();
  	return(status);            // return nRF24L01 status byte
}
/**************************************************
Function: SPI_Read();

Description:
  Read one byte from nRF24L01 register, 'reg'  */
/**************************************************/
unsigned char SPI_Read(unsigned char reg)
{
	unsigned char reg_val;
	nRF24L01_CSNL;
	delay();
  	SPI_RW(reg);            // Select register to read from..
  	reg_val = SPI_RW(0);    // ..then read registervalue
	nRF24L01_CSNH;
	delay();
  	return(reg_val);        // return register value
}
/**************************************************
Function: SPI_Read_Buf();

Description:
  Reads 'bytes' #of bytes from register 'reg'
  Typically used to read RX payload, Rx/Tx address */
/**************************************************/
unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes)
{
	unsigned char status,byte_ctr;
	nRF24L01_CSNL;
	delay();
  	status = SPI_RW(reg);       		// Select register to write to and read status byte
	for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
    	pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read byte from nRF24L01
	nRF24L01_CSNH;
	delay();
  	return(status);                    // return nRF24L01 status byte
}
/**************************************************
Function: SPI_Write_Buf();

Description:
  Writes contents of buffer '*pBuf' to nRF24L01
  Typically used to write TX payload, Rx/Tx address */
/**************************************************/
unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes)
{
	unsigned char status,byte_ctr;
	nRF24L01_CSNL;                   		// Set nRF24L01_CSN low, init SPI tranaction
  	delay();
	status = SPI_RW(reg);    					// Select register to write to and read status byte
  	for(byte_ctr=0; byte_ctr<bytes; byte_ctr++) // then write all byte in buffer(*pBuf)
    	status = SPI_RW(*pBuf++);            
	nRF24L01_CSNH; 								// Set nRF24L01_CSN high again
	delay();
  	return(status);          					// return nRF24L01 status byte
}
/**************************************************
Function: RX_Mode();

Description:
  This function initializes one nRF24L01 device to
  RX Mode, set RX address, writes RX payload width,
  select RF channel, datarate & LNA HCURR.
  After init, CE is toggled high, which means that
  this device is now ready to receive a datapacket. */
/**************************************************/
void RX_Mode(void)
{
	nRF24L01_CEL;
	delay();
  	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // Use the same address on the RX device as the TX device

  	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
  	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH); // Select same RX payload width as TX Payload width
  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:RX. RX_DR enabled..
  	nRF24L01_CEH;
	delay();
	//  This device is now ready to receive one packet of 16 bytes payload from a TX device sending to address
  //  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.

}
/**************************************************/

/**************************************************
Function: TX_Mode();

Description:
  This function initializes one nRF24L01 device to
  TX mode, set TX address, set RX address for auto.ack,
  fill TX payload, select RF channel, datarate & TX pwr.
  PWR_UP is set, CRC(2 bytes) is enabled, & PRIM:TX.

  ToDo: One high pulse(>10us) on CE will now send this
  packet and expext an acknowledgment from the RX device. */
/**************************************************/
void TX_Mode(void)
{
	nRF24L01_CEL;
	delay();
  	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
  	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
  	SPI_Write_Buf(WR_TX_PLOAD, Buffer, TX_PLOAD_WIDTH); // Writes data to TX payload

  	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
  	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
  	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
  	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
  	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
  	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:TX. MAX_RT & TX_DS enabled..
	nRF24L01_CEH;
	delay();
	
}
//------------------------------------------------------
void timer0_init(void)
{
 TCCR0B = 0x00; //stop
 TCNT0 = 0x06; //set count
 TCCR0A = 0x00; 
 TCCR0B = 0x02; //start timer
}
#pragma interrupt_handler timer0_ovf_isr:17
void timer0_ovf_isr(void)		// 5ms
{

 	TCNT0 = 0x06; //reload counter value

 	if((--t20ms)==0)
 		{
	 	set(flag,bit20ms);
		t20ms=t20msC;
		if(PIND& key1)
		{
		 	key1_pulse<<=1;
    		key1_pulse&=0xfe;
		}
		if(!(PIND& key1))
		{
			key1_pulse<<=1;
    		key1_pulse|=0x01;
		}
		if(key1_pulse==0x0f)
		{
		 	key1_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key1_pulse==0xff)
		{
		    key1_time++;
			if(key1_time>10)
			{
			  key1_time=0;
			  key1_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PIND& key2)
		{
		 	key2_pulse<<=1;
    		key2_pulse&=0xfe;
		}
		if(!(PIND& key2))
		{
			key2_pulse<<=1;
    		key2_pulse|=0x01;
		}
		if(key2_pulse==0x0f)
		{
		 	key2_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key2_pulse==0xff)
		{
		    key2_time++;
			if(key2_time>10)
			{
			  key2_time=0;
			  key2_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PIND& key3)
		{
		 	key3_pulse<<=1;
    		key3_pulse&=0xfe;
		}
		if(!(PIND& key3))
		{
			key3_pulse<<=1;
    		key3_pulse|=0x01;
		}
		if(key3_pulse==0x0f)
		{
		 	key3_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key3_pulse==0xff)
		{
		    key3_time++;
			if(key3_time>10)
			{
			  key3_time=0;
			  key3_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PINC& key4)
		{
		 	key4_pulse<<=1;
    		key4_pulse&=0xfe;
		}
		if(!(PINC& key4))
		{
			key4_pulse<<=1;
    		key4_pulse|=0x01;
		}
		if(key4_pulse==0x0f)
		{
		 	key4_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key4_pulse==0xff)
		{
		    key4_time++;
			if(key4_time>10)
			{
			  key4_time=0;
			  key4_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PINC& key5)
		{
		 	key5_pulse<<=1;
    		key5_pulse&=0xfe;
		}
		if(!(PINC& key5))
		{
			key5_pulse<<=1;
    		key5_pulse|=0x01;
		}
		if(key5_pulse==0x0f)
		{
		 	key5_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key5_pulse==0xff)
		{
		    key5_time++;
			if(key5_time>10)
			{
			  key5_time=0;
			  key5_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PINC& key6)
		{
		 	key6_pulse<<=1;
    		key6_pulse&=0xfe;
		}
		if(!(PINC& key6))
		{
			key6_pulse<<=1;
    		key6_pulse|=0x01;
		}
		if(key6_pulse==0x0f)
		{
		 	key6_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key6_pulse==0xff)
		{
		    key6_time++;
			if(key6_time>10)
			{
			  key6_time=0;
			  key6_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PINC& key7)
		{
		 	key7_pulse<<=1;
    		key7_pulse&=0xfe;
		}
		if(!(PINC& key7))
		{
			key7_pulse<<=1;
    		key7_pulse|=0x01;
		}
		if(key7_pulse==0x0f)
		{
		 	key7_flag=1;
			send_flag=1;	
			accept_time=0;
		}
		if(key7_pulse==0xff)
		{
		    key7_time++;
			if(key7_time>10)
			{
			  key7_time=0;
			  key7_flag=1;
			  send_flag=1;
			  accept_time=0;
			}
		}
		if(PINC& key8)
		{
		 	key8_pulse<<=1;
    		key8_pulse&=0xfe;
		}
		if(!(PINC& key8))
		{
			key8_pulse<<=1;
    		key8_pulse|=0x01;
		}
		if(key8_pulse==0x0f)
		{
//		 	key8_flag=1;
//			send_flag=1;	
			accept_time=0;
		}
		if(key8_pulse==0xff)
		{
		    key8_time++;
			if(key8_time>50)
			{
			  key8_time=0;
			  key8_long_flag=1;
			  send_flag=0;
			  accept_time=0;
			}
		}
//=================================
 		}
}