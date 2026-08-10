	.module main.c
	.area data(ram, con, rel)
_Buffer::
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbsym e Buffer _Buffer A[64:64]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_accept_flag::
	.blkb 1
	.area idata
	.byte 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbsym e accept_flag _accept_flag c
_send_flag::
	.blkb 1
	.area idata
	.byte 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbsym e send_flag _send_flag c
_accept_time::
	.blkb 2
	.area idata
	.word 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbsym e accept_time _accept_time i
	.area text(rom, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbfunc e main _main fV
;         Get_SO -> R20
	.even
_main::
	sbiw R28,1
	.dbline -1
	.dbline 158
; //ICC-AVR application builder : 2006-02-12 14:00:00
; // Target : ATmega48
; // Crystal: 8.000Mhz
; // Author:  jackyan
; // Oled Type : white
; //#define fosc 8000000
; //#define baud 9600
; #include "iom48v.h"
; #include "macros.h"
; #include "defs.h"
; /*-----------------------------------------------------------------------------
;    Global Defines
; ------------------------------------------------------------------------------*/
; unsigned char   key_debug;
; unsigned char 	Buffer[]={
; 0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
; 0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
; 0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
; 0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
; };
; #define TX_ADR_WIDTH    5   // 5 bytes TX(RX) address width
; #define TX_PLOAD_WIDTH  20  // 16 bytes TX payload
; unsigned char TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define a static TX address
; void init_CPU (void);
; void delayms(unsigned short	dly);//当dly=1时，延时的时间是1ms  4MHz晶震
; void INIT_io(void);
; void RX_Mode(void);
; void TX_Mode(void);
; void delay(void);
; unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
; unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
; unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value);
; unsigned char SPI_Read(unsigned char reg);
; void clear_buf(unsigned char	*ptr,unsigned char number);
; unsigned char accept_flag=0;
; unsigned char send_flag=0;
; unsigned int accept_time=0;
; void nrf24l01init(void);
; void timer0_init(void);
; //****************************************************************//
; // SPI(nRF24L01) commands
; #define READ_REG        0x00  // Define read command to register
; #define WRITE_REG       0x20  // Define write command to register
; #define RD_RX_PLOAD     0x61  // Define RX payload register address
; #define WR_TX_PLOAD     0xA0  // Define TX payload register address
; #define FLUSH_TX        0xE1  // Define flush TX register command
; #define FLUSH_RX        0xE2  // Define flush RX register command
; #define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
; //#define NOP             0xFF  // Define No Operation, might be used to read status register
; //***************************************************//
; // SPI(nRF24L01) registers(addresses)
; #define CONFIG          0x00  // 'Config' register address
; #define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
; #define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
; #define SETUP_AW        0x03  // 'Setup address width' register address
; #define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
; #define RF_CH           0x05  // 'RF channel' register address
; #define RF_SETUP        0x06  // 'RF setup' register address
; #define STATUS          0x07  // 'Status' register address
; #define OBSERVE_TX      0x08  // 'Observe TX' register address
; #define CD              0x09  // 'Carrier Detect' register address
; #define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
; #define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
; #define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
; #define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
; #define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
; #define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
; #define TX_ADDR         0x10  // 'TX address' register address
; #define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
; #define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
; #define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
; #define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
; #define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
; #define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
; #define FIFO_STATUS     0x17  // 'FIFO Status Register' register address
; #define MAX_RT  	0x10  // Max #of TX retrans interrupt
; #define TX_DS   	0x20  // TX data sent interrupt
; #define RX_DR   	0x40  // RX data received
; //-----------------------------------------------------------------------------
; //------------------------------------------------------
; unsigned char t20ms;
; #define BIT(x)	           (1 << (x))
; #define SETBIT(x, y)   	   (x |= y)
; #define CLEARBIT(x, y) 	   (x &= ~y)
; #define CHECKBIT(x, y) 	   (x & y)
; #define BIT7 0x80
; #define BIT6 0x40
; #define BIT5 0x20
; #define BIT4 0x10
; #define BIT3 0x08
; #define BIT2 0x04
; #define BIT1 0x02
; #define BIT0 0x01
; #define nRF24L01_CSN        BIT6
; #define nRF24L01_SCK        BIT7
; #define nRF24L01_MOSI       BIT0
; #define nRF24L01_CE         BIT5   
; #define nRF24L01_MISO 	    BIT1
; #define nRF24L01_IRQ  	    BIT2
; #define nRF24L01_CSNH       SETBIT(PORTD, nRF24L01_CSN)     
; #define nRF24L01_CSNL       CLEARBIT(PORTD, nRF24L01_CSN)   
; 
; #define nRF24L01_CSN_DIR    SETBIT(DDRD, nRF24L01_CSN)  //OUTPUT
; 
; #define nRF24L01_SCKH       SETBIT(PORTD,nRF24L01_SCK)      
; #define nRF24L01_SCKL       CLEARBIT(PORTD,nRF24L01_SCK)    
; #define nRF24L01_SCK_DIR   SETBIT(DDRD,nRF24L01_SCK)  //OUTPUT
;  
; #define nRF24L01_MOSIH      SETBIT(PORTB,nRF24L01_MOSI)     
; #define nRF24L01_MOSIL	    CLEARBIT(PORTB,nRF24L01_MOSI)   
; #define nRF24L01_MOSI_DIR   SETBIT(DDRB,nRF24L01_MOSI)
; 
; #define nRF24L01_CEH        SETBIT(PORTD,nRF24L01_CE)  //OUTPUT   
; #define nRF24L01_CEL        CLEARBIT(PORTD,nRF24L01_CE)
; #define nRF24L01_CE_DIR     SETBIT(DDRD,nRF24L01_CE)
; 
; #define nRF24L01_IRQ_DIR     CLEARBIT(DDRB,nRF24L01_IRQ) //INPUT
; 
; #define nRF24L01_MISO_DIR    CLEARBIT(DDRB,nRF24L01_MISO) //INPUT
; #define key1 	BIT4
; #define key2 	BIT3
; #define key3 	BIT2
; #define key4 	BIT5
; #define key5 	BIT4
; #define key6 	BIT3
; #define key7 	BIT2
; #define key8 	BIT1
; #define 	bit20ms 					BIT0
; unsigned char flag;
; unsigned char key1_pulse;
; unsigned char key2_pulse;
; unsigned char key3_pulse;
; unsigned char key4_pulse;
; unsigned char key5_pulse;
; unsigned char key6_pulse;
; unsigned char key7_pulse;
; unsigned char key8_pulse;
; unsigned char key1_flag;
; unsigned char key2_flag;
; unsigned char key3_flag;
; unsigned char key4_flag;
; unsigned char key5_flag;
; unsigned char key6_flag;
; unsigned char key7_flag;
; unsigned char key8_flag;
; unsigned char key8_long_flag;
; unsigned char send_flag;
; unsigned char key1_time;
; unsigned char key2_time;
; unsigned char key3_time;
; unsigned char key4_time;
; unsigned char key5_time;
; unsigned char key6_time;
; unsigned char key7_time;
; unsigned char key8_time;
; //-----------------------------------------------------------------------------
; void main(void)
; {
	.dbline 159
;  	unsigned char Get_SO=0;
	clr R20
	.dbline 160
;     CLI();                   /* global interrupt disable */
	cli
	.dbline 161
;     init_CPU ();
	rcall _init_CPU
	.dbline 162
;     delayms(100);	//延时10ms*10=100ms
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 163
;     delayms(100);	//延时10ms*10=100ms
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 164
; 	timer0_init();
	rcall _timer0_init
	.dbline 165
; 	RX_Mode();
	rcall _RX_Mode
	.dbline 166
; 	SEI();
	sei
	rjmp L3
L2:
	.dbline 168
; 	while(1)
; 	{		
	.dbline 170
; 		//	if(!(PINB& 0x01))
; 		WDR();
	wdr
	.dbline 171
; 		if(!(PINB& nRF24L01_IRQ))
	sbic 0x3,2
	rjmp L5
	.dbline 172
; 		{//nRF24L01 接收数据
	.dbline 173
; 			key_debug=SPI_Read(STATUS);			// read register STATUS's value
	ldi R16,7
	rcall _SPI_Read
	sts _key_debug,R16
	.dbline 174
; 			if(key_debug&RX_DR)					// if renRF24L01_CEive data ready (RX_DR) interrupt
	sbrs R16,6
	rjmp L7
	.dbline 175
; 				SPI_Read_Buf(RD_RX_PLOAD,Buffer,TX_PLOAD_WIDTH);// read renRF24L01_CEive payload from RX_FIFO buffer
	ldi R24,20
	std y+0,R24
	ldi R18,<_Buffer
	ldi R19,>_Buffer
	ldi R16,97
	rcall _SPI_Read_Buf
L7:
	.dbline 176
; 			if(key_debug&MAX_RT) SPI_RW_Reg(FLUSH_TX,0);
	lds R2,_key_debug
	sbrs R2,4
	rjmp L9
	.dbline 176
	clr R18
	ldi R16,225
	rcall _SPI_RW_Reg
L9:
	.dbline 177
; 			SPI_RW_Reg(WRITE_REG+STATUS,0xff);// clear RX_DR or TX_DS or MAX_RT interrupt flag
	ldi R18,255
	ldi R16,39
	rcall _SPI_RW_Reg
	.dbline 178
; 			RX_Mode();
	rcall _RX_Mode
	.dbline 179
; 			if((Buffer[0]==80)&&(Buffer[1]==01))//data accept
	lds R24,_Buffer
	cpi R24,80
	brne L11
	lds R24,_Buffer+1
	cpi R24,1
	brne L11
	.dbline 180
; 			{
	.dbline 181
; 			 	accept_flag=1;
	ldi R24,1
	sts _accept_flag,R24
	.dbline 182
; 			}
L11:
	.dbline 183
; 		}
L5:
	.dbline 184
; 		if(send_flag==1)//data send
	lds R24,_send_flag
	cpi R24,1
	brne L14
	.dbline 185
; 		{
	.dbline 186
; 		 		Buffer[0]=80;
	ldi R24,80
	sts _Buffer,R24
	.dbline 187
; 				Buffer[1]=02;
	ldi R24,2
	sts _Buffer+1,R24
	.dbline 188
; 				TX_Mode();			// set TX Mode and transmitting
	rcall _TX_Mode
	.dbline 189
; 				delayms(100);
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 190
; 				RX_Mode();
	rcall _RX_Mode
	.dbline 191
; 				Buffer[0]=00;
	clr R2
	sts _Buffer,R2
	.dbline 192
; 				Buffer[1]=00;
	sts _Buffer+1,R2
	.dbline 193
; 		}
L14:
	.dbline 195
; //========================================数据一直发送
; 		if(key8_long_flag==1)//data send
	lds R24,_key8_long_flag
	cpi R24,1
	brne L18
	.dbline 196
; 		{
	.dbline 197
; 		 		Buffer[0]=80;
	ldi R24,80
	sts _Buffer,R24
	.dbline 198
; 				Buffer[1]=02;
	ldi R24,2
	sts _Buffer+1,R24
	.dbline 199
; 				TX_Mode();			// set TX Mode and transmitting
	rcall _TX_Mode
	.dbline 200
; 				delayms(100);
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 201
; 				RX_Mode();
	rcall _RX_Mode
	.dbline 202
; 				Buffer[0]=00;
	clr R2
	sts _Buffer,R2
	.dbline 203
; 				Buffer[1]=00;
	sts _Buffer+1,R2
	.dbline 204
; 		}
L18:
	.dbline 206
; //========================================数据一直发送
; 		if(send_flag==1)
	lds R24,_send_flag
	cpi R24,1
	brne L22
	.dbline 207
; 		{
	.dbline 208
; 		   accept_time++;
	lds R24,_accept_time
	lds R25,_accept_time+1
	adiw R24,1
	sts _accept_time+1,R25
	sts _accept_time,R24
	.dbline 209
; 		   if(accept_time>30)
	ldi R24,30
	ldi R25,0
	lds R2,_accept_time
	lds R3,_accept_time+1
	cp R24,R2
	cpc R25,R3
	brsh L24
	.dbline 210
; 		   {
	.dbline 211
; 		   	 send_flag=0;
	clr R2
	sts _send_flag,R2
	.dbline 212
; 			 accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 213
; 		   }
L24:
	.dbline 214
; 		}
L22:
	.dbline 215
; 		if(accept_flag==1)
	lds R24,_accept_flag
	cpi R24,1
	brne L26
	.dbline 216
; 		{
	.dbline 217
; 		    accept_flag=0;
	clr R2
	sts _accept_flag,R2
	.dbline 218
;     	 	PORTB = 0x80;
	ldi R24,128
	out 0x5,R24
	.dbline 219
; 		    delayms(5000);	//延时10ms*10=100ms
	ldi R16,5000
	ldi R17,19
	rcall _delayms
	.dbline 220
; 		    PORTB = 0x00;
	clr R2
	out 0x5,R2
	.dbline 221
; 		}
L26:
	.dbline 222
L3:
	.dbline 167
	rjmp L2
X0:
	.dbline -2
L1:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbsym r Get_SO 20 c
	.dbend
	.dbfunc e nrf24l01init _nrf24l01init fV
	.even
_nrf24l01init::
	.dbline -1
	.dbline 227
; 	}
; 
; 
; }
; void nrf24l01init(void)
; {
	.dbline 228
;  	 nRF24L01_IRQ_DIR;
	cbi 0x4,2
	.dbline 229
; 	 nRF24L01_MISO_DIR;
	cbi 0x4,1
	.dbline 230
; 	 nRF24L01_CE_DIR;
	sbi 0xa,5
	.dbline 231
; 	 nRF24L01_SCK_DIR;
	sbi 0xa,7
	.dbline 232
; 	 nRF24L01_CSN_DIR;
	sbi 0xa,6
	.dbline 233
; 	 nRF24L01_MOSI_DIR;
	sbi 0x4,0
	.dbline -2
L28:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e init_CPU _init_CPU fV
	.even
_init_CPU::
	.dbline -1
	.dbline 240
; }
; /*-----------------------------------------------------------------------------
;    Module:   init_CPU
;    Function: Initialization of CPU
; ------------------------------------------------------------------------------*/
; void init_CPU (void)
; {
	.dbline 241
;  	MCUCR = 0x00;	// 
	clr R2
	out 0x35,R2
	.dbline 242
; 	EICRA = 0x00; //extended ext ints
	sts 105,R2
	.dbline 243
;     EIMSK = 0x00;
	out 0x1d,R2
	.dbline 245
; 	 
; 	TIMSK0 = 0x01; //timer 0 interrupt sources
	ldi R24,1
	sts 110,R24
	.dbline 246
; 	TIMSK1 = 0x00; //timer 1 interrupt sources
	sts 111,R2
	.dbline 247
; 	TIMSK2 = 0x00; //timer 2 interrupt sources
	sts 112,R2
	.dbline 248
; 	 CLI(); //disable all interrupts
	cli
	.dbline 249
; 	 NOP();
	nop
	.dbline 250
; 	PORTB = 0x01;
	out 0x5,R24
	.dbline 251
;  	DDRB  = 0xf3;
	ldi R24,243
	out 0x4,R24
	.dbline 252
; 	PORTD = 0x80;
	ldi R24,128
	out 0xb,R24
	.dbline 253
; 	DDRD  = 0xE3;
	ldi R24,227
	out 0xa,R24
	.dbline 254
; 	PORTC = 0x80;
	ldi R24,128
	out 0x8,R24
	.dbline 255
; 	DDRC  = 0x40;
	ldi R24,64
	out 0x7,R24
	.dbline 256
; 	nrf24l01init();
	rcall _nrf24l01init
	.dbline 257
;     nRF24L01_CEL;
	cbi 0xb,5
	.dbline 258
; 	delay();
	rcall _delay
	.dbline 259
; 	nRF24L01_CSNH;			// Spi disable
	sbi 0xb,6
	.dbline 260
; 	delay();
	rcall _delay
	.dbline 261
; 	nRF24L01_SCKL;	
	cbi 0xb,7
	.dbline 262
; 	delay();
	rcall _delay
	.dbline -2
L29:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e delay _delay fV
	.even
_delay::
	.dbline -1
	.dbline 265
; }
; void delay(void)//
; {
	.dbline 266
; 	NOP();
	nop
	.dbline 267
; 	NOP();
	nop
	.dbline 268
; 	NOP();
	nop
	.dbline 269
; 	NOP();
	nop
	.dbline 270
; 	NOP();
	nop
	.dbline 271
; 	NOP();
	nop
	.dbline -2
L30:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e delayms _delayms fV
;            dly -> R16,R17
	.even
_delayms::
	.dbline -1
	.dbline 274
; }
; void delayms(unsigned short	dly)//
; {
	.dbline 275
	rjmp L35
L32:
	.dbline 275
L33:
	.dbline 275
	subi R16,1
	sbci R17,0
L35:
	.dbline 275
; 	for(;dly>0;dly--) ;
	cpi R16,0
	cpc R16,R17
	brne L32
X1:
	.dbline -2
L31:
	.dbline 0 ; func end
	ret
	.dbsym r dly 16 s
	.dbend
	.dbfunc e clear_buf _clear_buf fV
;         number -> R18
;            ptr -> R16,R17
	.even
_clear_buf::
	.dbline -1
	.dbline 279
; }
; 
; void clear_buf(unsigned char	*ptr,unsigned char number)//清零buffer,指定字节个数
; {
	.dbline 280
	rjmp L40
L37:
	.dbline 280
	clr R2
	movw R30,R16
	st Z+,R2
	movw R16,R30
L38:
	.dbline 280
	dec R18
L40:
	.dbline 280
; 	for (;number>0;number--) *ptr++=0;
	clr R2
	cp R2,R18
	brlo L37
	.dbline -2
L36:
	.dbline 0 ; func end
	ret
	.dbsym r number 18 c
	.dbsym r ptr 16 pc
	.dbend
	.dbfunc e SPI_RW _SPI_RW fc
;        bit_ctr -> R20
;           byte -> R22
	.even
_SPI_RW::
	rcall push_gset2
	mov R22,R16
	.dbline -1
	.dbline 291
; }
; //------------------------------------------------------
; /**************************************************
; Function: SPI_RW();
; 
; Description:
;   Writes one byte to nRF24L01, and return the byte read
;   from nRF24L01 during write, according to SPI protocol  */
; /**************************************************/
; unsigned char SPI_RW(unsigned char byte)
; {
	.dbline 293
; 	unsigned char  bit_ctr;	
;    	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   	// output 8-bit
	clr R20
	rjmp L45
L42:
	.dbline 294
;    	{
	.dbline 295
;    		if(byte & 0x80) 
	sbrs R22,7
	rjmp L46
	.dbline 296
;    			nRF24L01_MOSIH;
	sbi 0x5,0
	rjmp L47
L46:
	.dbline 298
;    		else 
;    			nRF24L01_MOSIL;
	cbi 0x5,0
L47:
	.dbline 299
; 		delay();
	rcall _delay
	.dbline 300
;    		byte = (byte << 1);           		// shift next bit into MSB..
	lsl R22
	.dbline 301
;    		nRF24L01_SCKH;
	sbi 0xb,7
	.dbline 302
; 		delay();
	rcall _delay
	.dbline 303
;  		if(PINB&nRF24L01_MISO) byte |= 1;
	sbis 0x3,1
	rjmp L48
	.dbline 303
	ori R22,1
L48:
	.dbline 304
	cbi 0xb,7
	.dbline 305
	rcall _delay
	.dbline 306
L43:
	.dbline 293
	inc R20
L45:
	.dbline 293
	cpi R20,8
	brlo L42
	.dbline 307
;    		nRF24L01_SCKL;
; 		delay();
;    	}
;     return(byte);           		  		// return read byte
	mov R16,R22
	.dbline -2
L41:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r bit_ctr 20 c
	.dbsym r byte 22 c
	.dbend
	.dbfunc e SPI_RW_Reg _SPI_RW_Reg fc
;         status -> R20
;          value -> R22
;            reg -> R20
	.even
_SPI_RW_Reg::
	rcall push_gset2
	mov R22,R18
	mov R20,R16
	.dbline -1
	.dbline 316
; }
; /**************************************************
; Function: SPI_RW_Reg();
; 
; Description:
;   Writes value 'value' to register 'reg' */
; /**************************************************/
; unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value)
; {
	.dbline 318
; 	unsigned char status;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 319
; 	delay();
	rcall _delay
	.dbline 320
; 	status = SPI_RW(reg);      // select register
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 321
;   	SPI_RW(value);             // ..and write value to it..
	mov R16,R22
	rcall _SPI_RW
	.dbline 322
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 323
; 	delay();
	rcall _delay
	.dbline 324
;   	return(status);            // return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L50:
	rcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r status 20 c
	.dbsym r value 22 c
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Read _SPI_Read fc
;        reg_val -> R20
;            reg -> R20
	.even
_SPI_Read::
	rcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 333
; }
; /**************************************************
; Function: SPI_Read();
; 
; Description:
;   Read one byte from nRF24L01 register, 'reg'  */
; /**************************************************/
; unsigned char SPI_Read(unsigned char reg)
; {
	.dbline 335
; 	unsigned char reg_val;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 336
; 	delay();
	rcall _delay
	.dbline 337
;   	SPI_RW(reg);            // Select register to read from..
	mov R16,R20
	rcall _SPI_RW
	.dbline 338
;   	reg_val = SPI_RW(0);    // ..then read registervalue
	clr R16
	rcall _SPI_RW
	mov R20,R16
	.dbline 339
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 340
; 	delay();
	rcall _delay
	.dbline 341
;   	return(reg_val);        // return register value
	mov R16,R20
	.dbline -2
L51:
	rcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r reg_val 20 c
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Read_Buf _SPI_Read_Buf fc
;         status -> R20
;       byte_ctr -> R22
;          bytes -> R10
;           pBuf -> R12,R13
;            reg -> R20
	.even
_SPI_Read_Buf::
	rcall push_gset4
	movw R12,R18
	mov R20,R16
	ldd R10,y+8
	.dbline -1
	.dbline 351
; }
; /**************************************************
; Function: SPI_Read_Buf();
; 
; Description:
;   Reads 'bytes' #of bytes from register 'reg'
;   Typically used to read RX payload, Rx/Tx address */
; /**************************************************/
; unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes)
; {
	.dbline 353
; 	unsigned char status,byte_ctr;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 354
; 	delay();
	rcall _delay
	.dbline 355
;   	status = SPI_RW(reg);       		// Select register to write to and read status byte
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 356
; 	for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
	clr R22
	rjmp L56
L53:
	.dbline 357
	clr R16
	rcall _SPI_RW
	mov R30,R22
	clr R31
	add R30,R12
	adc R31,R13
	std z+0,R16
L54:
	.dbline 356
	inc R22
L56:
	.dbline 356
	cp R22,R10
	brlo L53
	.dbline 358
;     	pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read byte from nRF24L01
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 359
; 	delay();
	rcall _delay
	.dbline 360
;   	return(status);                    // return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L52:
	rcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status 20 c
	.dbsym r byte_ctr 22 c
	.dbsym r bytes 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Write_Buf _SPI_Write_Buf fc
;         status -> R20
;       byte_ctr -> R22
;          bytes -> R10
;           pBuf -> R12,R13
;            reg -> R20
	.even
_SPI_Write_Buf::
	rcall push_gset4
	movw R12,R18
	mov R20,R16
	ldd R10,y+8
	.dbline -1
	.dbline 370
; }
; /**************************************************
; Function: SPI_Write_Buf();
; 
; Description:
;   Writes contents of buffer '*pBuf' to nRF24L01
;   Typically used to write TX payload, Rx/Tx address */
; /**************************************************/
; unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes)
; {
	.dbline 372
; 	unsigned char status,byte_ctr;
; 	nRF24L01_CSNL;                   		// Set nRF24L01_CSN low, init SPI tranaction
	cbi 0xb,6
	.dbline 373
;   	delay();
	rcall _delay
	.dbline 374
; 	status = SPI_RW(reg);    					// Select register to write to and read status byte
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 375
;   	for(byte_ctr=0; byte_ctr<bytes; byte_ctr++) // then write all byte in buffer(*pBuf)
	clr R22
	rjmp L61
L58:
	.dbline 376
	movw R30,R12
	ld R16,Z+
	movw R12,R30
	rcall _SPI_RW
	mov R20,R16
L59:
	.dbline 375
	inc R22
L61:
	.dbline 375
	cp R22,R10
	brlo L58
	.dbline 377
;     	status = SPI_RW(*pBuf++);            
; 	nRF24L01_CSNH; 								// Set nRF24L01_CSN high again
	sbi 0xb,6
	.dbline 378
; 	delay();
	rcall _delay
	.dbline 379
;   	return(status);          					// return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L57:
	rcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status 20 c
	.dbsym r byte_ctr 22 c
	.dbsym r bytes 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e RX_Mode _RX_Mode fV
	.even
_RX_Mode::
	sbiw R28,1
	.dbline -1
	.dbline 392
; }
; /**************************************************
; Function: RX_Mode();
; 
; Description:
;   This function initializes one nRF24L01 device to
;   RX Mode, set RX address, writes RX payload width,
;   select RF channel, datarate & LNA HCURR.
;   After init, CE is toggled high, which means that
;   this device is now ready to receive a datapacket. */
; /**************************************************/
; void RX_Mode(void)
; {
	.dbline 393
; 	nRF24L01_CEL;
	cbi 0xb,5
	.dbline 394
; 	delay();
	rcall _delay
	.dbline 395
;   	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // Use the same address on the RX device as the TX device
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	rcall _SPI_Write_Buf
	.dbline 397
; 
;   	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
	ldi R18,1
	ldi R16,33
	rcall _SPI_RW_Reg
	.dbline 398
;   	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
	ldi R18,1
	ldi R16,34
	rcall _SPI_RW_Reg
	.dbline 399
;   	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
	ldi R18,40
	ldi R16,37
	rcall _SPI_RW_Reg
	.dbline 400
;   	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH); // Select same RX payload width as TX Payload width
	ldi R18,20
	ldi R16,49
	rcall _SPI_RW_Reg
	.dbline 401
;   	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	ldi R18,7
	ldi R16,38
	rcall _SPI_RW_Reg
	.dbline 402
;   	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:RX. RX_DR enabled..
	ldi R18,15
	ldi R16,32
	rcall _SPI_RW_Reg
	.dbline 403
;   	nRF24L01_CEH;
	sbi 0xb,5
	.dbline 404
; 	delay();
	rcall _delay
	.dbline -2
L62:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e TX_Mode _TX_Mode fV
	.even
_TX_Mode::
	sbiw R28,1
	.dbline -1
	.dbline 424
; 	//  This device is now ready to receive one packet of 16 bytes payload from a TX device sending to address
;   //  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.
; 
; }
; /**************************************************/
; 
; /**************************************************
; Function: TX_Mode();
; 
; Description:
;   This function initializes one nRF24L01 device to
;   TX mode, set TX address, set RX address for auto.ack,
;   fill TX payload, select RF channel, datarate & TX pwr.
;   PWR_UP is set, CRC(2 bytes) is enabled, & PRIM:TX.
; 
;   ToDo: One high pulse(>10us) on CE will now send this
;   packet and expext an acknowledgment from the RX device. */
; /**************************************************/
; void TX_Mode(void)
; {
	.dbline 425
; 	nRF24L01_CEL;
	cbi 0xb,5
	.dbline 426
; 	delay();
	rcall _delay
	.dbline 427
;   	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,48
	rcall _SPI_Write_Buf
	.dbline 428
;   	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	rcall _SPI_Write_Buf
	.dbline 429
;   	SPI_Write_Buf(WR_TX_PLOAD, Buffer, TX_PLOAD_WIDTH); // Writes data to TX payload
	ldi R24,20
	std y+0,R24
	ldi R18,<_Buffer
	ldi R19,>_Buffer
	ldi R16,160
	rcall _SPI_Write_Buf
	.dbline 431
; 
;   	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
	ldi R18,1
	ldi R16,33
	rcall _SPI_RW_Reg
	.dbline 432
;   	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
	ldi R18,1
	ldi R16,34
	rcall _SPI_RW_Reg
	.dbline 433
;   	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
	ldi R18,26
	ldi R16,36
	rcall _SPI_RW_Reg
	.dbline 434
;   	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
	ldi R18,40
	ldi R16,37
	rcall _SPI_RW_Reg
	.dbline 435
;   	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	ldi R18,7
	ldi R16,38
	rcall _SPI_RW_Reg
	.dbline 436
;   	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:TX. MAX_RT & TX_DS enabled..
	ldi R18,14
	ldi R16,32
	rcall _SPI_RW_Reg
	.dbline 437
; 	nRF24L01_CEH;
	sbi 0xb,5
	.dbline 438
; 	delay();
	rcall _delay
	.dbline -2
L63:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e timer0_init _timer0_init fV
	.even
_timer0_init::
	.dbline -1
	.dbline 443
; 	
; }
; //------------------------------------------------------
; void timer0_init(void)
; {
	.dbline 444
;  TCCR0B = 0x00; //stop
	clr R2
	out 0x25,R2
	.dbline 445
;  TCNT0 = 0x06; //set count
	ldi R24,6
	out 0x26,R24
	.dbline 446
;  TCCR0A = 0x00; 
	out 0x24,R2
	.dbline 447
;  TCCR0B = 0x02; //start timer
	ldi R24,2
	out 0x25,R24
	.dbline -2
L64:
	.dbline 0 ; func end
	ret
	.dbend
	.area vector(rom, abs)
	.org 32
	rjmp _timer0_ovf_isr
	.area text(rom, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	.dbfunc e timer0_ovf_isr _timer0_ovf_isr fV
	.even
_timer0_ovf_isr::
	st -y,R2
	st -y,R3
	st -y,R24
	st -y,R25
	in R2,0x3f
	st -y,R2
	.dbline -1
	.dbline 451
; }
; #pragma interrupt_handler timer0_ovf_isr:17
; void timer0_ovf_isr(void)		// 5ms
; {
	.dbline 453
; 
;  	TCNT0 = 0x06; //reload counter value
	ldi R24,6
	out 0x26,R24
	.dbline 455
; 
;  	if((--t20ms)==0)
	lds R24,_t20ms
	subi R24,1
	mov R2,R24
	sts _t20ms,R2
	tst R24
	breq X2
	rjmp L66
X2:
	.dbline 456
;  		{
	.dbline 457
; 	 	set(flag,bit20ms);
	.dbline 457
	lds R24,_flag
	ori R24,1
	sts _flag,R24
	.dbline 457
	.dbline 457
	.dbline 458
; 		t20ms=t20msC;
	ldi R24,20
	sts _t20ms,R24
	.dbline 459
; 		if(PIND& key1)
	sbis 0x9,4
	rjmp L68
	.dbline 460
; 		{
	.dbline 461
; 		 	key1_pulse<<=1;
	lds R2,_key1_pulse
	lsl R2
	sts _key1_pulse,R2
	.dbline 462
;     		key1_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key1_pulse,R24
	.dbline 463
; 		}
L68:
	.dbline 464
; 		if(!(PIND& key1))
	sbic 0x9,4
	rjmp L70
	.dbline 465
; 		{
	.dbline 466
; 			key1_pulse<<=1;
	lds R2,_key1_pulse
	lsl R2
	sts _key1_pulse,R2
	.dbline 467
;     		key1_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key1_pulse,R24
	.dbline 468
; 		}
L70:
	.dbline 469
; 		if(key1_pulse==0x0f)
	lds R24,_key1_pulse
	cpi R24,15
	brne L72
	.dbline 470
; 		{
	.dbline 471
; 		 	key1_flag=1;
	ldi R24,1
	sts _key1_flag,R24
	.dbline 472
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 473
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 474
; 		}
L72:
	.dbline 475
; 		if(key1_pulse==0xff)
	lds R24,_key1_pulse
	cpi R24,255
	brne L74
	.dbline 476
; 		{
	.dbline 477
; 		    key1_time++;
	lds R24,_key1_time
	subi R24,255    ; addi 1
	sts _key1_time,R24
	.dbline 478
; 			if(key1_time>10)
	ldi R24,10
	lds R2,_key1_time
	cp R24,R2
	brsh L76
	.dbline 479
; 			{
	.dbline 480
; 			  key1_time=0;
	clr R2
	sts _key1_time,R2
	.dbline 481
; 			  key1_flag=1;
	ldi R24,1
	sts _key1_flag,R24
	.dbline 482
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 483
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 484
; 			}
L76:
	.dbline 485
; 		}
L74:
	.dbline 486
; 		if(PIND& key2)
	sbis 0x9,3
	rjmp L78
	.dbline 487
; 		{
	.dbline 488
; 		 	key2_pulse<<=1;
	lds R2,_key2_pulse
	lsl R2
	sts _key2_pulse,R2
	.dbline 489
;     		key2_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key2_pulse,R24
	.dbline 490
; 		}
L78:
	.dbline 491
; 		if(!(PIND& key2))
	sbic 0x9,3
	rjmp L80
	.dbline 492
; 		{
	.dbline 493
; 			key2_pulse<<=1;
	lds R2,_key2_pulse
	lsl R2
	sts _key2_pulse,R2
	.dbline 494
;     		key2_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key2_pulse,R24
	.dbline 495
; 		}
L80:
	.dbline 496
; 		if(key2_pulse==0x0f)
	lds R24,_key2_pulse
	cpi R24,15
	brne L82
	.dbline 497
; 		{
	.dbline 498
; 		 	key2_flag=1;
	ldi R24,1
	sts _key2_flag,R24
	.dbline 499
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 500
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 501
; 		}
L82:
	.dbline 502
; 		if(key2_pulse==0xff)
	lds R24,_key2_pulse
	cpi R24,255
	brne L84
	.dbline 503
; 		{
	.dbline 504
; 		    key2_time++;
	lds R24,_key2_time
	subi R24,255    ; addi 1
	sts _key2_time,R24
	.dbline 505
; 			if(key2_time>10)
	ldi R24,10
	lds R2,_key2_time
	cp R24,R2
	brsh L86
	.dbline 506
; 			{
	.dbline 507
; 			  key2_time=0;
	clr R2
	sts _key2_time,R2
	.dbline 508
; 			  key2_flag=1;
	ldi R24,1
	sts _key2_flag,R24
	.dbline 509
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 510
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 511
; 			}
L86:
	.dbline 512
; 		}
L84:
	.dbline 513
; 		if(PIND& key3)
	sbis 0x9,2
	rjmp L88
	.dbline 514
; 		{
	.dbline 515
; 		 	key3_pulse<<=1;
	lds R2,_key3_pulse
	lsl R2
	sts _key3_pulse,R2
	.dbline 516
;     		key3_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key3_pulse,R24
	.dbline 517
; 		}
L88:
	.dbline 518
; 		if(!(PIND& key3))
	sbic 0x9,2
	rjmp L90
	.dbline 519
; 		{
	.dbline 520
; 			key3_pulse<<=1;
	lds R2,_key3_pulse
	lsl R2
	sts _key3_pulse,R2
	.dbline 521
;     		key3_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key3_pulse,R24
	.dbline 522
; 		}
L90:
	.dbline 523
; 		if(key3_pulse==0x0f)
	lds R24,_key3_pulse
	cpi R24,15
	brne L92
	.dbline 524
; 		{
	.dbline 525
; 		 	key3_flag=1;
	ldi R24,1
	sts _key3_flag,R24
	.dbline 526
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 527
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 528
; 		}
L92:
	.dbline 529
; 		if(key3_pulse==0xff)
	lds R24,_key3_pulse
	cpi R24,255
	brne L94
	.dbline 530
; 		{
	.dbline 531
; 		    key3_time++;
	lds R24,_key3_time
	subi R24,255    ; addi 1
	sts _key3_time,R24
	.dbline 532
; 			if(key3_time>10)
	ldi R24,10
	lds R2,_key3_time
	cp R24,R2
	brsh L96
	.dbline 533
; 			{
	.dbline 534
; 			  key3_time=0;
	clr R2
	sts _key3_time,R2
	.dbline 535
; 			  key3_flag=1;
	ldi R24,1
	sts _key3_flag,R24
	.dbline 536
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 537
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 538
; 			}
L96:
	.dbline 539
; 		}
L94:
	.dbline 540
; 		if(PINC& key4)
	sbis 0x6,5
	rjmp L98
	.dbline 541
; 		{
	.dbline 542
; 		 	key4_pulse<<=1;
	lds R2,_key4_pulse
	lsl R2
	sts _key4_pulse,R2
	.dbline 543
;     		key4_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key4_pulse,R24
	.dbline 544
; 		}
L98:
	.dbline 545
; 		if(!(PINC& key4))
	sbic 0x6,5
	rjmp L100
	.dbline 546
; 		{
	.dbline 547
; 			key4_pulse<<=1;
	lds R2,_key4_pulse
	lsl R2
	sts _key4_pulse,R2
	.dbline 548
;     		key4_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key4_pulse,R24
	.dbline 549
; 		}
L100:
	.dbline 550
; 		if(key4_pulse==0x0f)
	lds R24,_key4_pulse
	cpi R24,15
	brne L102
	.dbline 551
; 		{
	.dbline 552
; 		 	key4_flag=1;
	ldi R24,1
	sts _key4_flag,R24
	.dbline 553
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 554
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 555
; 		}
L102:
	.dbline 556
; 		if(key4_pulse==0xff)
	lds R24,_key4_pulse
	cpi R24,255
	brne L104
	.dbline 557
; 		{
	.dbline 558
; 		    key4_time++;
	lds R24,_key4_time
	subi R24,255    ; addi 1
	sts _key4_time,R24
	.dbline 559
; 			if(key4_time>10)
	ldi R24,10
	lds R2,_key4_time
	cp R24,R2
	brsh L106
	.dbline 560
; 			{
	.dbline 561
; 			  key4_time=0;
	clr R2
	sts _key4_time,R2
	.dbline 562
; 			  key4_flag=1;
	ldi R24,1
	sts _key4_flag,R24
	.dbline 563
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 564
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 565
; 			}
L106:
	.dbline 566
; 		}
L104:
	.dbline 567
; 		if(PINC& key5)
	sbis 0x6,4
	rjmp L108
	.dbline 568
; 		{
	.dbline 569
; 		 	key5_pulse<<=1;
	lds R2,_key5_pulse
	lsl R2
	sts _key5_pulse,R2
	.dbline 570
;     		key5_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key5_pulse,R24
	.dbline 571
; 		}
L108:
	.dbline 572
; 		if(!(PINC& key5))
	sbic 0x6,4
	rjmp L110
	.dbline 573
; 		{
	.dbline 574
; 			key5_pulse<<=1;
	lds R2,_key5_pulse
	lsl R2
	sts _key5_pulse,R2
	.dbline 575
;     		key5_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key5_pulse,R24
	.dbline 576
; 		}
L110:
	.dbline 577
; 		if(key5_pulse==0x0f)
	lds R24,_key5_pulse
	cpi R24,15
	brne L112
	.dbline 578
; 		{
	.dbline 579
; 		 	key5_flag=1;
	ldi R24,1
	sts _key5_flag,R24
	.dbline 580
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 581
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 582
; 		}
L112:
	.dbline 583
; 		if(key5_pulse==0xff)
	lds R24,_key5_pulse
	cpi R24,255
	brne L114
	.dbline 584
; 		{
	.dbline 585
; 		    key5_time++;
	lds R24,_key5_time
	subi R24,255    ; addi 1
	sts _key5_time,R24
	.dbline 586
; 			if(key5_time>10)
	ldi R24,10
	lds R2,_key5_time
	cp R24,R2
	brsh L116
	.dbline 587
; 			{
	.dbline 588
; 			  key5_time=0;
	clr R2
	sts _key5_time,R2
	.dbline 589
; 			  key5_flag=1;
	ldi R24,1
	sts _key5_flag,R24
	.dbline 590
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 591
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 592
; 			}
L116:
	.dbline 593
; 		}
L114:
	.dbline 594
; 		if(PINC& key6)
	sbis 0x6,3
	rjmp L118
	.dbline 595
; 		{
	.dbline 596
; 		 	key6_pulse<<=1;
	lds R2,_key6_pulse
	lsl R2
	sts _key6_pulse,R2
	.dbline 597
;     		key6_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key6_pulse,R24
	.dbline 598
; 		}
L118:
	.dbline 599
; 		if(!(PINC& key6))
	sbic 0x6,3
	rjmp L120
	.dbline 600
; 		{
	.dbline 601
; 			key6_pulse<<=1;
	lds R2,_key6_pulse
	lsl R2
	sts _key6_pulse,R2
	.dbline 602
;     		key6_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key6_pulse,R24
	.dbline 603
; 		}
L120:
	.dbline 604
; 		if(key6_pulse==0x0f)
	lds R24,_key6_pulse
	cpi R24,15
	brne L122
	.dbline 605
; 		{
	.dbline 606
; 		 	key6_flag=1;
	ldi R24,1
	sts _key6_flag,R24
	.dbline 607
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 608
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 609
; 		}
L122:
	.dbline 610
; 		if(key6_pulse==0xff)
	lds R24,_key6_pulse
	cpi R24,255
	brne L124
	.dbline 611
; 		{
	.dbline 612
; 		    key6_time++;
	lds R24,_key6_time
	subi R24,255    ; addi 1
	sts _key6_time,R24
	.dbline 613
; 			if(key6_time>10)
	ldi R24,10
	lds R2,_key6_time
	cp R24,R2
	brsh L126
	.dbline 614
; 			{
	.dbline 615
; 			  key6_time=0;
	clr R2
	sts _key6_time,R2
	.dbline 616
; 			  key6_flag=1;
	ldi R24,1
	sts _key6_flag,R24
	.dbline 617
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 618
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 619
; 			}
L126:
	.dbline 620
; 		}
L124:
	.dbline 621
; 		if(PINC& key7)
	sbis 0x6,2
	rjmp L128
	.dbline 622
; 		{
	.dbline 623
; 		 	key7_pulse<<=1;
	lds R2,_key7_pulse
	lsl R2
	sts _key7_pulse,R2
	.dbline 624
;     		key7_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key7_pulse,R24
	.dbline 625
; 		}
L128:
	.dbline 626
; 		if(!(PINC& key7))
	sbic 0x6,2
	rjmp L130
	.dbline 627
; 		{
	.dbline 628
; 			key7_pulse<<=1;
	lds R2,_key7_pulse
	lsl R2
	sts _key7_pulse,R2
	.dbline 629
;     		key7_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key7_pulse,R24
	.dbline 630
; 		}
L130:
	.dbline 631
; 		if(key7_pulse==0x0f)
	lds R24,_key7_pulse
	cpi R24,15
	brne L132
	.dbline 632
; 		{
	.dbline 633
; 		 	key7_flag=1;
	ldi R24,1
	sts _key7_flag,R24
	.dbline 634
; 			send_flag=1;	
	sts _send_flag,R24
	.dbline 635
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 636
; 		}
L132:
	.dbline 637
; 		if(key7_pulse==0xff)
	lds R24,_key7_pulse
	cpi R24,255
	brne L134
	.dbline 638
; 		{
	.dbline 639
; 		    key7_time++;
	lds R24,_key7_time
	subi R24,255    ; addi 1
	sts _key7_time,R24
	.dbline 640
; 			if(key7_time>10)
	ldi R24,10
	lds R2,_key7_time
	cp R24,R2
	brsh L136
	.dbline 641
; 			{
	.dbline 642
; 			  key7_time=0;
	clr R2
	sts _key7_time,R2
	.dbline 643
; 			  key7_flag=1;
	ldi R24,1
	sts _key7_flag,R24
	.dbline 644
; 			  send_flag=1;
	sts _send_flag,R24
	.dbline 645
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 646
; 			}
L136:
	.dbline 647
; 		}
L134:
	.dbline 648
; 		if(PINC& key8)
	sbis 0x6,1
	rjmp L138
	.dbline 649
; 		{
	.dbline 650
; 		 	key8_pulse<<=1;
	lds R2,_key8_pulse
	lsl R2
	sts _key8_pulse,R2
	.dbline 651
;     		key8_pulse&=0xfe;
	mov R24,R2
	andi R24,254
	sts _key8_pulse,R24
	.dbline 652
; 		}
L138:
	.dbline 653
; 		if(!(PINC& key8))
	sbic 0x6,1
	rjmp L140
	.dbline 654
; 		{
	.dbline 655
; 			key8_pulse<<=1;
	lds R2,_key8_pulse
	lsl R2
	sts _key8_pulse,R2
	.dbline 656
;     		key8_pulse|=0x01;
	mov R24,R2
	ori R24,1
	sts _key8_pulse,R24
	.dbline 657
; 		}
L140:
	.dbline 658
; 		if(key8_pulse==0x0f)
	lds R24,_key8_pulse
	cpi R24,15
	brne L142
	.dbline 659
; 		{
	.dbline 662
; //		 	key8_flag=1;
; //			send_flag=1;	
; 			accept_time=0;
	clr R2
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 663
; 		}
L142:
	.dbline 664
; 		if(key8_pulse==0xff)
	lds R24,_key8_pulse
	cpi R24,255
	brne L144
	.dbline 665
; 		{
	.dbline 666
; 		    key8_time++;
	lds R24,_key8_time
	subi R24,255    ; addi 1
	sts _key8_time,R24
	.dbline 667
; 			if(key8_time>50)
	ldi R24,50
	lds R2,_key8_time
	cp R24,R2
	brsh L146
	.dbline 668
; 			{
	.dbline 669
; 			  key8_time=0;
	clr R2
	sts _key8_time,R2
	.dbline 670
; 			  key8_long_flag=1;
	ldi R24,1
	sts _key8_long_flag,R24
	.dbline 671
; 			  send_flag=0;
	sts _send_flag,R2
	.dbline 672
; 			  accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 673
; 			}
L146:
	.dbline 674
; 		}
L144:
	.dbline 676
L66:
	.dbline -2
L65:
	ld R2,y+
	out 0x3f,R2
	ld R25,y+
	ld R24,y+
	ld R3,y+
	ld R2,y+
	.dbline 0 ; func end
	reti
	.dbend
	.area bss(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
_key8_time::
	.blkb 1
	.dbsym e key8_time _key8_time c
_key7_time::
	.blkb 1
	.dbsym e key7_time _key7_time c
_key6_time::
	.blkb 1
	.dbsym e key6_time _key6_time c
_key5_time::
	.blkb 1
	.dbsym e key5_time _key5_time c
_key4_time::
	.blkb 1
	.dbsym e key4_time _key4_time c
_key3_time::
	.blkb 1
	.dbsym e key3_time _key3_time c
_key2_time::
	.blkb 1
	.dbsym e key2_time _key2_time c
_key1_time::
	.blkb 1
	.dbsym e key1_time _key1_time c
_key8_long_flag::
	.blkb 1
	.dbsym e key8_long_flag _key8_long_flag c
_key8_flag::
	.blkb 1
	.dbsym e key8_flag _key8_flag c
_key7_flag::
	.blkb 1
	.dbsym e key7_flag _key7_flag c
_key6_flag::
	.blkb 1
	.dbsym e key6_flag _key6_flag c
_key5_flag::
	.blkb 1
	.dbsym e key5_flag _key5_flag c
_key4_flag::
	.blkb 1
	.dbsym e key4_flag _key4_flag c
_key3_flag::
	.blkb 1
	.dbsym e key3_flag _key3_flag c
_key2_flag::
	.blkb 1
	.dbsym e key2_flag _key2_flag c
_key1_flag::
	.blkb 1
	.dbsym e key1_flag _key1_flag c
_key8_pulse::
	.blkb 1
	.dbsym e key8_pulse _key8_pulse c
_key7_pulse::
	.blkb 1
	.dbsym e key7_pulse _key7_pulse c
_key6_pulse::
	.blkb 1
	.dbsym e key6_pulse _key6_pulse c
_key5_pulse::
	.blkb 1
	.dbsym e key5_pulse _key5_pulse c
_key4_pulse::
	.blkb 1
	.dbsym e key4_pulse _key4_pulse c
_key3_pulse::
	.blkb 1
	.dbsym e key3_pulse _key3_pulse c
_key2_pulse::
	.blkb 1
	.dbsym e key2_pulse _key2_pulse c
_key1_pulse::
	.blkb 1
	.dbsym e key1_pulse _key1_pulse c
_flag::
	.blkb 1
	.dbsym e flag _flag c
_t20ms::
	.blkb 1
	.dbsym e t20ms _t20ms c
_key_debug::
	.blkb 1
	.dbsym e key_debug _key_debug c
