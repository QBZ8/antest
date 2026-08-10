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
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbsym e Buffer _Buffer A[64:64]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_accept_flag::
	.blkb 1
	.area idata
	.byte 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbsym e accept_flag _accept_flag c
_send_flag::
	.blkb 1
	.area idata
	.byte 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbsym e send_flag _send_flag c
_accept_time::
	.blkb 2
	.area idata
	.word 0
	.area data(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbsym e accept_time _accept_time i
	.area text(rom, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbfunc e main _main fV
;         Get_SO -> R20
	.even
_main::
	sbiw R28,1
	.dbline -1
	.dbline 149
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
; #define key1 	BIT5
; #define key2 	BIT6
; #define key3 	BIT7
; #define key4 	BIT0
; #define key5 	BIT1
; #define key6 	BIT2
; #define 	bit20ms 					BIT0
; unsigned char flag;
; unsigned char key1_pulse;
; unsigned char key2_pulse;
; unsigned char key3_pulse;
; unsigned char key4_pulse;
; unsigned char key5_pulse;
; unsigned char key6_pulse;
; unsigned char key1_flag;
; unsigned char key2_flag;
; unsigned char key3_flag;
; unsigned char key4_flag;
; unsigned char key5_flag;
; unsigned char key6_flag;
; unsigned char send_flag;
; unsigned char key1_time;
; unsigned char key2_time;
; unsigned char key3_time;
; unsigned char key4_time;
; unsigned char key5_time;
; unsigned char key6_time;
; 
; //-----------------------------------------------------------------------------
; void main(void)
; {
	.dbline 150
;  	unsigned char Get_SO=0;
	clr R20
	.dbline 151
;     CLI();                   /* global interrupt disable */
	cli
	.dbline 152
;     init_CPU ();
	rcall _init_CPU
	.dbline 153
;     delayms(100);	//延时10ms*10=100ms
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 154
;     delayms(100);	//延时10ms*10=100ms
	ldi R16,100
	ldi R17,0
	rcall _delayms
	.dbline 155
; 	RX_Mode();
	rcall _RX_Mode
	.dbline 156
; 	send_flag=0;
	clr R2
	sts _send_flag,R2
	rjmp L3
L2:
	.dbline 158
; 	while(1)
; 	{		
	.dbline 160
; 		//	if(!(PINB& 0x01))
; 		WDR();
	wdr
	.dbline 161
; 		if(!(PINB& nRF24L01_IRQ))
	sbic 0x3,2
	rjmp L5
	.dbline 162
; 		{//nRF24L01 接收数据
	.dbline 163
; 			key_debug=SPI_Read(STATUS);			// read register STATUS's value
	ldi R16,7
	rcall _SPI_Read
	sts _key_debug,R16
	.dbline 164
; 			if(key_debug&RX_DR)					// if renRF24L01_CEive data ready (RX_DR) interrupt
	sbrs R16,6
	rjmp L7
	.dbline 165
; 				SPI_Read_Buf(RD_RX_PLOAD,Buffer,TX_PLOAD_WIDTH);// read renRF24L01_CEive payload from RX_FIFO buffer
	ldi R24,20
	std y+0,R24
	ldi R18,<_Buffer
	ldi R19,>_Buffer
	ldi R16,97
	rcall _SPI_Read_Buf
L7:
	.dbline 166
; 			if(key_debug&MAX_RT) SPI_RW_Reg(FLUSH_TX,0);
	lds R2,_key_debug
	sbrs R2,4
	rjmp L9
	.dbline 166
	clr R18
	ldi R16,225
	rcall _SPI_RW_Reg
L9:
	.dbline 167
; 			SPI_RW_Reg(WRITE_REG+STATUS,0xff);// clear RX_DR or TX_DS or MAX_RT interrupt flag
	ldi R18,255
	ldi R16,39
	rcall _SPI_RW_Reg
	.dbline 168
; 			RX_Mode();
	rcall _RX_Mode
	.dbline 169
; 			if((Buffer[0]==80)&&(Buffer[1]==02))//data accept
	lds R24,_Buffer
	cpi R24,80
	brne L11
	lds R24,_Buffer+1
	cpi R24,2
	brne L11
	.dbline 170
; 			{
	.dbline 171
; 			 	accept_flag=1;
	ldi R24,1
	sts _accept_flag,R24
	.dbline 175
; 		//	 	PORTB = 0x80;
; 		//		delayms(5000);	//延时10ms*10=100ms
; 		//		PORTB = 0x00;
; 			}
L11:
	.dbline 176
; 		}
L5:
	.dbline 177
; 		if(send_flag==1)
	lds R24,_send_flag
	cpi R24,1
	brne L14
	.dbline 178
; 		{
	.dbline 179
; 		   accept_time++;
	lds R24,_accept_time
	lds R25,_accept_time+1
	adiw R24,1
	sts _accept_time+1,R25
	sts _accept_time,R24
	.dbline 181
; 	//	   PORTB = 0x00;
; 		   if(accept_time>1000)
	ldi R24,1000
	ldi R25,3
	lds R2,_accept_time
	lds R3,_accept_time+1
	cp R24,R2
	cpc R25,R3
	brsh L16
	.dbline 182
; 		   {
	.dbline 183
; 		   	 send_flag=0;
	clr R2
	sts _send_flag,R2
	.dbline 184
; 			 accept_time=0;
	clr R3
	sts _accept_time+1,R3
	sts _accept_time,R2
	.dbline 185
; 		   }
L16:
	.dbline 186
; 		}
L14:
	.dbline 187
; 		if(accept_flag==1)
	lds R24,_accept_flag
	cpi R24,1
	brne L18
	.dbline 188
; 		{
	.dbline 189
; 		    accept_flag=0;
	clr R2
	sts _accept_flag,R2
	.dbline 190
;     	 	PORTB = 0x80;
	ldi R24,128
	out 0x5,R24
	.dbline 191
; 		    delayms(1000);	//延时10ms*10=100ms
	ldi R16,1000
	ldi R17,3
	rcall _delayms
	.dbline 192
; 		    PORTB = 0x00;
	clr R2
	out 0x5,R2
	.dbline 201
; //			nrf24l01init();
; //    		nRF24L01_CEL;
; //			delay();
; //			nRF24L01_CSNH;			// Spi disable
; //			delay();
; //			nRF24L01_SCKL;	
; //			delay();
; //			Buffer[1]=0;
; 			RX_Mode();
	rcall _RX_Mode
	.dbline 203
; 	//		delayms(1000);	//延时10ms*10=100ms
; 		}
L18:
	.dbline 204
L3:
	.dbline 157
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
	.dbline 209
; 	}
; 
; 
; }
; void nrf24l01init(void)
; {
	.dbline 210
;  	 nRF24L01_IRQ_DIR;
	cbi 0x4,2
	.dbline 211
; 	 nRF24L01_MISO_DIR;
	cbi 0x4,1
	.dbline 212
; 	 nRF24L01_CE_DIR;
	sbi 0xa,5
	.dbline 213
; 	 nRF24L01_SCK_DIR;
	sbi 0xa,7
	.dbline 214
; 	 nRF24L01_CSN_DIR;
	sbi 0xa,6
	.dbline 215
; 	 nRF24L01_MOSI_DIR;
	sbi 0x4,0
	.dbline -2
L20:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e init_CPU _init_CPU fV
	.even
_init_CPU::
	.dbline -1
	.dbline 222
; }
; /*-----------------------------------------------------------------------------
;    Module:   init_CPU
;    Function: Initialization of CPU
; ------------------------------------------------------------------------------*/
; void init_CPU (void)
; {
	.dbline 223
;  	MCUCR = 0x00;	// 
	clr R2
	out 0x35,R2
	.dbline 224
; 	EICRA = 0x00; //extended ext ints
	sts 105,R2
	.dbline 225
;     EIMSK = 0x00;
	out 0x1d,R2
	.dbline 227
; 	 
; 	TIMSK0 = 0x01; //timer 0 interrupt sources
	ldi R24,1
	sts 110,R24
	.dbline 228
; 	TIMSK1 = 0x00; //timer 1 interrupt sources
	sts 111,R2
	.dbline 229
; 	TIMSK2 = 0x00; //timer 2 interrupt sources
	sts 112,R2
	.dbline 230
; 	 CLI(); //disable all interrupts
	cli
	.dbline 231
; 	 NOP();
	nop
	.dbline 232
; 	PORTB = 0x01;
	out 0x5,R24
	.dbline 233
;  	DDRB  = 0xf3;
	ldi R24,243
	out 0x4,R24
	.dbline 234
; 	PORTD = 0x80;
	ldi R24,128
	out 0xb,R24
	.dbline 235
; 	DDRD  = 0xff;
	ldi R24,255
	out 0xa,R24
	.dbline 236
; 	PORTC = 0x80;
	ldi R24,128
	out 0x8,R24
	.dbline 237
; 	DDRC  = 0x78;
	ldi R24,120
	out 0x7,R24
	.dbline 238
; 	nrf24l01init();
	rcall _nrf24l01init
	.dbline 239
;     nRF24L01_CEL;
	cbi 0xb,5
	.dbline 240
; 	delay();
	rcall _delay
	.dbline 241
; 	nRF24L01_CSNH;			// Spi disable
	sbi 0xb,6
	.dbline 242
; 	delay();
	rcall _delay
	.dbline 243
; 	nRF24L01_SCKL;	
	cbi 0xb,7
	.dbline 244
; 	delay();
	rcall _delay
	.dbline -2
L21:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e delay _delay fV
	.even
_delay::
	.dbline -1
	.dbline 247
; }
; void delay(void)//
; {
	.dbline 248
; 	NOP();
	nop
	.dbline 249
; 	NOP();
	nop
	.dbline 250
; 	NOP();
	nop
	.dbline 251
; 	NOP();
	nop
	.dbline 252
; 	NOP();
	nop
	.dbline 253
; 	NOP();
	nop
	.dbline -2
L22:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e delayms _delayms fV
;            dly -> R16,R17
	.even
_delayms::
	.dbline -1
	.dbline 256
; }
; void delayms(unsigned short	dly)//
; {
	.dbline 257
	rjmp L27
L24:
	.dbline 257
L25:
	.dbline 257
	subi R16,1
	sbci R17,0
L27:
	.dbline 257
; 	for(;dly>0;dly--) ;
	cpi R16,0
	cpc R16,R17
	brne L24
X1:
	.dbline -2
L23:
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
	.dbline 261
; }
; 
; void clear_buf(unsigned char	*ptr,unsigned char number)//清零buffer,指定字节个数
; {
	.dbline 262
	rjmp L32
L29:
	.dbline 262
	clr R2
	movw R30,R16
	st Z+,R2
	movw R16,R30
L30:
	.dbline 262
	dec R18
L32:
	.dbline 262
; 	for (;number>0;number--) *ptr++=0;
	clr R2
	cp R2,R18
	brlo L29
	.dbline -2
L28:
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
	.dbline 273
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
	.dbline 275
; 	unsigned char  bit_ctr;	
;    	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   	// output 8-bit
	clr R20
	rjmp L37
L34:
	.dbline 276
;    	{
	.dbline 277
;    		if(byte & 0x80) 
	sbrs R22,7
	rjmp L38
	.dbline 278
;    			nRF24L01_MOSIH;
	sbi 0x5,0
	rjmp L39
L38:
	.dbline 280
;    		else 
;    			nRF24L01_MOSIL;
	cbi 0x5,0
L39:
	.dbline 281
; 		delay();
	rcall _delay
	.dbline 282
;    		byte = (byte << 1);           		// shift next bit into MSB..
	lsl R22
	.dbline 283
;    		nRF24L01_SCKH;
	sbi 0xb,7
	.dbline 284
; 		delay();
	rcall _delay
	.dbline 285
;  		if(PINB&nRF24L01_MISO) byte |= 1;
	sbis 0x3,1
	rjmp L40
	.dbline 285
	ori R22,1
L40:
	.dbline 286
	cbi 0xb,7
	.dbline 287
	rcall _delay
	.dbline 288
L35:
	.dbline 275
	inc R20
L37:
	.dbline 275
	cpi R20,8
	brlo L34
	.dbline 289
;    		nRF24L01_SCKL;
; 		delay();
;    	}
;     return(byte);           		  		// return read byte
	mov R16,R22
	.dbline -2
L33:
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
	.dbline 298
; }
; /**************************************************
; Function: SPI_RW_Reg();
; 
; Description:
;   Writes value 'value' to register 'reg' */
; /**************************************************/
; unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value)
; {
	.dbline 300
; 	unsigned char status;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 301
; 	delay();
	rcall _delay
	.dbline 302
; 	status = SPI_RW(reg);      // select register
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 303
;   	SPI_RW(value);             // ..and write value to it..
	mov R16,R22
	rcall _SPI_RW
	.dbline 304
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 305
; 	delay();
	rcall _delay
	.dbline 306
;   	return(status);            // return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L42:
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
	.dbline 315
; }
; /**************************************************
; Function: SPI_Read();
; 
; Description:
;   Read one byte from nRF24L01 register, 'reg'  */
; /**************************************************/
; unsigned char SPI_Read(unsigned char reg)
; {
	.dbline 317
; 	unsigned char reg_val;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 318
; 	delay();
	rcall _delay
	.dbline 319
;   	SPI_RW(reg);            // Select register to read from..
	mov R16,R20
	rcall _SPI_RW
	.dbline 320
;   	reg_val = SPI_RW(0);    // ..then read registervalue
	clr R16
	rcall _SPI_RW
	mov R20,R16
	.dbline 321
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 322
; 	delay();
	rcall _delay
	.dbline 323
;   	return(reg_val);        // return register value
	mov R16,R20
	.dbline -2
L43:
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
	.dbline 333
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
	.dbline 335
; 	unsigned char status,byte_ctr;
; 	nRF24L01_CSNL;
	cbi 0xb,6
	.dbline 336
; 	delay();
	rcall _delay
	.dbline 337
;   	status = SPI_RW(reg);       		// Select register to write to and read status byte
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 338
; 	for(byte_ctr=0;byte_ctr<bytes;byte_ctr++)
	clr R22
	rjmp L48
L45:
	.dbline 339
	clr R16
	rcall _SPI_RW
	mov R30,R22
	clr R31
	add R30,R12
	adc R31,R13
	std z+0,R16
L46:
	.dbline 338
	inc R22
L48:
	.dbline 338
	cp R22,R10
	brlo L45
	.dbline 340
;     	pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read byte from nRF24L01
; 	nRF24L01_CSNH;
	sbi 0xb,6
	.dbline 341
; 	delay();
	rcall _delay
	.dbline 342
;   	return(status);                    // return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L44:
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
	.dbline 352
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
	.dbline 354
; 	unsigned char status,byte_ctr;
; 	nRF24L01_CSNL;                   		// Set nRF24L01_CSN low, init SPI tranaction
	cbi 0xb,6
	.dbline 355
;   	delay();
	rcall _delay
	.dbline 356
; 	status = SPI_RW(reg);    					// Select register to write to and read status byte
	mov R16,R20
	rcall _SPI_RW
	mov R20,R16
	.dbline 357
;   	for(byte_ctr=0; byte_ctr<bytes; byte_ctr++) // then write all byte in buffer(*pBuf)
	clr R22
	rjmp L53
L50:
	.dbline 358
	movw R30,R12
	ld R16,Z+
	movw R12,R30
	rcall _SPI_RW
	mov R20,R16
L51:
	.dbline 357
	inc R22
L53:
	.dbline 357
	cp R22,R10
	brlo L50
	.dbline 359
;     	status = SPI_RW(*pBuf++);            
; 	nRF24L01_CSNH; 								// Set nRF24L01_CSN high again
	sbi 0xb,6
	.dbline 360
; 	delay();
	rcall _delay
	.dbline 361
;   	return(status);          					// return nRF24L01 status byte
	mov R16,R20
	.dbline -2
L49:
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
	.dbline 374
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
	.dbline 375
; 	nRF24L01_CEL;
	cbi 0xb,5
	.dbline 376
; 	delay();
	rcall _delay
	.dbline 377
;   	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // Use the same address on the RX device as the TX device
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	rcall _SPI_Write_Buf
	.dbline 379
; 
;   	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
	ldi R18,1
	ldi R16,33
	rcall _SPI_RW_Reg
	.dbline 380
;   	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
	ldi R18,1
	ldi R16,34
	rcall _SPI_RW_Reg
	.dbline 381
;   	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
	ldi R18,40
	ldi R16,37
	rcall _SPI_RW_Reg
	.dbline 382
;   	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH); // Select same RX payload width as TX Payload width
	ldi R18,20
	ldi R16,49
	rcall _SPI_RW_Reg
	.dbline 383
;   	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	ldi R18,7
	ldi R16,38
	rcall _SPI_RW_Reg
	.dbline 384
;   	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:RX. RX_DR enabled..
	ldi R18,15
	ldi R16,32
	rcall _SPI_RW_Reg
	.dbline 385
;   	nRF24L01_CEH;
	sbi 0xb,5
	.dbline 386
; 	delay();
	rcall _delay
	.dbline -2
L54:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e TX_Mode _TX_Mode fV
	.even
_TX_Mode::
	sbiw R28,1
	.dbline -1
	.dbline 406
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
	.dbline 407
; 	nRF24L01_CEL;
	cbi 0xb,5
	.dbline 408
; 	delay();
	rcall _delay
	.dbline 409
;   	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // Writes TX_Address to nRF24L01
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,48
	rcall _SPI_Write_Buf
	.dbline 410
;   	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // RX_Addr0 same as TX_Adr for Auto.Ack
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	rcall _SPI_Write_Buf
	.dbline 411
;   	SPI_Write_Buf(WR_TX_PLOAD, Buffer, TX_PLOAD_WIDTH); // Writes data to TX payload
	ldi R24,20
	std y+0,R24
	ldi R18,<_Buffer
	ldi R19,>_Buffer
	ldi R16,160
	rcall _SPI_Write_Buf
	.dbline 413
; 
;   	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      // Enable Auto.Ack:Pipe0
	ldi R18,1
	ldi R16,33
	rcall _SPI_RW_Reg
	.dbline 414
;   	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  // Enable Pipe0
	ldi R18,1
	ldi R16,34
	rcall _SPI_RW_Reg
	.dbline 415
;   	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
	ldi R18,26
	ldi R16,36
	rcall _SPI_RW_Reg
	.dbline 416
;   	SPI_RW_Reg(WRITE_REG + RF_CH, 40);        // Select RF channel 40
	ldi R18,40
	ldi R16,37
	rcall _SPI_RW_Reg
	.dbline 417
;   	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	ldi R18,7
	ldi R16,38
	rcall _SPI_RW_Reg
	.dbline 418
;   	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);     // Set PWR_UP bit, enable CRC(2 bytes) & Prim:TX. MAX_RT & TX_DS enabled..
	ldi R18,14
	ldi R16,32
	rcall _SPI_RW_Reg
	.dbline 419
; 	nRF24L01_CEH;
	sbi 0xb,5
	.dbline 420
; 	delay();
	rcall _delay
	.dbline -2
L55:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e timer0_init _timer0_init fV
	.even
_timer0_init::
	.dbline -1
	.dbline 425
; 	
; }
; //------------------------------------------------------
; void timer0_init(void)
; {
	.dbline 426
;  TCCR0B = 0x00; //stop
	clr R2
	out 0x25,R2
	.dbline 427
;  TCNT0 = 0x06; //set count
	ldi R24,6
	out 0x26,R24
	.dbline 428
;  TCCR0A = 0x00; 
	out 0x24,R2
	.dbline 429
;  TCCR0B = 0x02; //start timer
	ldi R24,2
	out 0x25,R24
	.dbline -2
L56:
	.dbline 0 ; func end
	ret
	.dbend
	.area vector(rom, abs)
	.org 32
	rjmp _timer0_ovf_isr
	.area text(rom, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
	.dbfunc e timer0_ovf_isr _timer0_ovf_isr fV
	.even
_timer0_ovf_isr::
	st -y,R2
	st -y,R24
	in R2,0x3f
	st -y,R2
	.dbline -1
	.dbline 433
	.dbline 435
	ldi R24,6
	out 0x26,R24
	.dbline 437
	lds R24,_t20ms
	subi R24,1
	mov R2,R24
	sts _t20ms,R2
	tst R24
	brne L58
	.dbline 438
	.dbline 439
	.dbline 439
	lds R24,_flag
	ori R24,1
	sts _flag,R24
	.dbline 439
	.dbline 439
	.dbline 440
	ldi R24,80
	sts _t20ms,R24
	.dbline 442
	nop
	.dbline 449
L58:
	.dbline -2
L57:
	ld R2,y+
	out 0x3f,R2
	ld R24,y+
	ld R2,y+
	.dbline 0 ; func end
	reti
	.dbend
	.area bss(ram, con, rel)
	.dbfile E:\项目\PS2无~1\progamme\acceptavrnrf24l01\acceptavrnrf24l01\main.c
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
