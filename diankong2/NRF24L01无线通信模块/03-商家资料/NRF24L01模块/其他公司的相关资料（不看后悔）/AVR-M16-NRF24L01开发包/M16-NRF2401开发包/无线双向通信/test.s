	.module test.c
	.area text(rom, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
_seg::
	.blkb 2
	.area idata
	.byte 192,207
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 164,176
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 153,146
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 130,248
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 128,144
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.dbsym e seg _seg A[10:10]c
_TxBuf::
	.blkb 2
	.area idata
	.byte 1,2
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 3,4
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 5,6
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 7,8
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 9,16
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 17,18
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 19,20
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 21,22
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 23,24
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 25,32
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 33,34
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 35,36
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 37,38
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 39,40
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 41,48
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 49,50
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.dbsym e TxBuf _TxBuf A[32:32]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_RX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.dbsym e RX_ADDRESS _RX_ADDRESS A[5:5]c
	.area text(rom, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
	.dbfunc e Delay _Delay fV
;              i -> R20,R21
;              s -> R16,R17
	.even
_Delay::
	st -y,R20
	st -y,R21
	.dbline -1
	.dbline 126
; //ICC-AVR application builder : 2007-8-11 20:37:32
; // Target : M16
; // Crystal: 8.0000Mhz
; #include <iom16v.h>
; #include <macros.h>
; //------------------------------------------------------------------------------
; //--------------------------------NRF24L01接口定义--------------------------------
; //------------------------------------------------------------------------------
; //#define NRF24L01_MISO          PB4		//输入0	
; #define   Hign_24L01_MISO    PORTB |= (1 << PB4) 
; #define   Low_24L01_MISO     PORTB &= ~(1 << PB4)
; #define   Read_24L01_MISO    PINB & (1 << PB4) 
; 
; //#define NRF24L01_MOSI         PB2  	    //输出1
; #define   Hign_24L01_MOSI    PORTB |= (1 << PB2)  
; #define   Low_24L01_MOSI     PORTB &= ~(1 << PB2)
; #define   Read_24L01_MOSI    PINB & (1 << PB2) 
; 
; //#define NRF24L01_CSN     		PB7	      //输出1
; #define   Low_24L01_CSN     PORTB &= ~(1 << PB7)
; #define   Hign_24L01_CSN   	PORTB |= (1 << PB7)
; 
; //#define NRF24L01_SCK  		PB6   	  //输出1
; #define   Hign_24L01_SCK    PORTB |= (1 << PB6)   
; #define   Low_24L01_SCK     PORTB &= ~(1 << PB6) 		
; #define   Read_24L01_SCK    PINB & (1 << PB6);
; 
; //#define NRF24L01_CE    	    PB5	      //输出1
; #define   Hign_24L01_CE    PORTB |= (1 << PB5)  
; #define   Low_24L01_CE     PORTB &= ~(1 << PB5)		
; #define   Read_24L01_CE    PINB & (1 << PB5)
; 
; //#define  NRF24L01_IRQ     PB3	       //输入
; #define   Hign_NRF24L01_IRQ    PORTB |= (1 << PB3)   
; #define   Low_NRF24L01_IRQ     PORTB &= ~(1 << PB3)
; #define   Read_NRF24L01_IRQ    PINB & (1 << PB3)
;   
; //------------------------------数码管位选--------------------------------------
; //#define Display1   PA1  		    //输出1
; #define   Hign_Display1     PORTA |= (1 << PA1);   
; #define   Low_Display1    	PORTA &= ~(1 << PA1); 
; //#define Display2      PA2  		//输出1
; #define   Hign_Display2     PORTA |= (1 << PA2);   
; #define   Low_Display2    	PORTA &= ~(1 << PA2); 
; //#define Display3     PA3  		//输出1
; #define   Hign_Display3     PORTA |= (1 << PA3);   
; #define   Low_Display3     	PORTA &= ~(1 << PA3); 
; //#define Display4      PA4 		//输出1
; #define   Hign_Display4     PORTA |= (1 << PA4);   
; #define   Low_Display4     	PORTA &= ~(1 << PA4);   
; //-------------------------------BELL蜂明器-------------------------------------
; #define   Hign_BELL 		PORTD |= (1 << PD5);   
; #define   Low_BELL     	    PORTD &= ~(1 << PD5); 
; //-------------------------------JDQ继电器--------------------------------------
; #define   Hign_JDQ  		PORTD |= (1 << PD7)
; #define   Low_JDQ    		PORTD &= ~(1 << PD7) 
; //***********************************数码管0-9编码*******************************************
; char seg[10]={0xC0,0xCF,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};         //0~~9段码
; char TxBuf[32]=
; {
; 0x01,0x02,0x03,0x4,0x05,0x06,0x07,0x08,
; 0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
; 0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,
; 0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32,
; };
; char sta,count,tf;
; //*********************************************NRF24L01*************************************
; #define TX_ADR_WIDTH    5   	// 5 uints TX address width
; #define RX_ADR_WIDTH    5   	// 5 uints RX address width
; #define TX_PLOAD_WIDTH  32  	// 20 uints TX payload
; #define RX_PLOAD_WIDTH  32  	// 20 uints TX payload
; char  TX_ADDRESS[TX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//本地地址
; char  RX_ADDRESS[RX_ADR_WIDTH]= {0x34,0x43,0x10,0x10,0x01};	//接收地址
; //***************************************NRF24L01寄存器指令*******************************************************
; #define READ_REG        0x00  	// 读寄存器指令
; #define WRITE_REG       0x20 	// 写寄存器指令
; #define RD_RX_PLOAD     0x61  	// 读取接收数据指令
; #define WR_TX_PLOAD     0xA0  	// 写待发数据指令
; #define FLUSH_TX        0xE1 	// 冲洗发送 FIFO指令
; #define FLUSH_RX        0xE2  	// 冲洗接收 FIFO指令
; #define REUSE_TX_PL     0xE3  	// 定义重复装载数据指令
; #define NOP1             0xFF  	// 保留
; //*************************************SPI(nRF24L01)寄存器地址****************************************************
; #define CONFIG          0x00  // 配置收发状态，CRC校验模式以及收发状态响应方式
; #define EN_AA           0x01  // 自动应答功能设置
; #define EN_RXADDR       0x02  // 可用信道设置
; #define SETUP_AW        0x03  // 收发地址宽度设置
; #define SETUP_RETR      0x04  // 自动重发功能设置
; #define RF_CH           0x05  // 工作频率设置
; #define RF_SETUP        0x06  // 发射速率、功耗功能设置
; #define STATUS          0x07  // 状态寄存器
; #define OBSERVE_TX      0x08  // 发送监测功能
; #define CD              0x09  // 地址检测           
; #define RX_ADDR_P0      0x0A  // 频道0接收数据地址
; #define RX_ADDR_P1      0x0B  // 频道1接收数据地址
; #define RX_ADDR_P2      0x0C  // 频道2接收数据地址
; #define RX_ADDR_P3      0x0D  // 频道3接收数据地址
; #define RX_ADDR_P4      0x0E  // 频道4接收数据地址
; #define RX_ADDR_P5      0x0F  // 频道5接收数据地址
; #define TX_ADDR         0x10  // 发送地址寄存器
; #define RX_PW_P0        0x11  // 接收频道0接收数据长度
; #define RX_PW_P1        0x12  // 接收频道0接收数据长度
; #define RX_PW_P2        0x13  // 接收频道0接收数据长度
; #define RX_PW_P3        0x14  // 接收频道0接收数据长度
; #define RX_PW_P4        0x15  // 接收频道0接收数据长度
; #define RX_PW_P5        0x16  // 接收频道0接收数据长度
; #define FIFO_STATUS     0x17  // FIFO栈入栈出状态寄存器设置
; //**************************************************************************************
; void Delay(int s);
; void inerDelay_us(char n);
; void init_NRF24L01(void);
; char SPI_RW(char data);
; char SPI_Read(char reg);
; char SPI_RW_Reg(char reg, char value);
; char SPI_Read_Buf(char reg, char *pBuf, char uchars);
; char SPI_Write_Buf(char reg, char *pBuf, char uchars);
; void SetRX_Mode(void);
; char nRF24L01_RxPacket(char* rx_buf);
; void nRF24L01_TxPacket(char * tx_buf);
; void StartUART(void);
; void R_S_Byte(char R_Byte);
; void display();
; 
; //*****************************************长延时*****************************************
; void Delay(int s)
; {
	.dbline 128
; 	unsigned int i;
; 	for(i=0; i<s; i++);
	clr R20
	clr R21
	xjmp L5
L2:
	.dbline 128
L3:
	.dbline 128
	subi R20,255  ; offset = 1
	sbci R21,255
L5:
	.dbline 128
	cp R20,R16
	cpc R21,R17
	brlo L2
X0:
	.dbline 129
; 	for(i=0; i<s; i++);
	clr R20
	clr R21
	xjmp L9
L6:
	.dbline 129
L7:
	.dbline 129
	subi R20,255  ; offset = 1
	sbci R21,255
L9:
	.dbline 129
	cp R20,R16
	cpc R21,R17
	brlo L6
X1:
	.dbline -2
L1:
	.dbline 0 ; func end
	ld R21,y+
	ld R20,y+
	ret
	.dbsym r i 20 i
	.dbsym r s 16 I
	.dbend
	.dbfunc e SPI_RW _SPI_RW fc
;           temp -> R10
;              i -> R20
;           data -> R16
	.even
_SPI_RW::
	xcall push_xgset300C
	.dbline -1
	.dbline 137
; }
; 
; /****************************************************************************************************
; /*函数：uint SPI_RW(uint uchar)
; /*功能：NRF24L01的SPI写时序
; /****************************************************************************************************/
; char SPI_RW(char data)
; {
	.dbline 138
; 	char i,temp=0;
	clr R10
	.dbline 139
;    	for(i=0;i<8;i++) // output 8-bit
	clr R20
	xjmp L14
L11:
	.dbline 140
;    	{
	.dbline 141
; 	if(data & 0x80)
	sbrs R16,7
	rjmp L15
X2:
	.dbline 142
; 	{
	.dbline 143
; 		Hign_24L01_MOSI ;         // output 'uchar', MSB to MOSI
	sbi 0x18,2
	.dbline 144
; 	}
	xjmp L16
L15:
	.dbline 146
; 	else
; 	{
	.dbline 147
; 	 	Low_24L01_MOSI; 
	cbi 0x18,2
	.dbline 148
; 	}	
L16:
	.dbline 149
; 		data = (data << 1);           // shift next bit into MSB..
	lsl R16
	.dbline 150
; 		temp<<=1;
	lsl R10
	.dbline 151
; 		Hign_24L01_SCK ;                      // Set SCK high..
	sbi 0x18,6
	.dbline 152
; 		if(PINB&0x10)temp++;       		  // capture current MISO bit
	sbis 0x16,4
	rjmp L17
X3:
	.dbline 152
	inc R10
L17:
	.dbline 153
; 		Low_24L01_SCK;            		  // ..then set SCK low again
	cbi 0x18,6
	.dbline 154
;    	}
L12:
	.dbline 139
	inc R20
L14:
	.dbline 139
	cpi R20,8
	brlo L11
X4:
	.dbline 155
;     return(temp);           		  // return read uchar
	mov R16,R10
	.dbline -2
L10:
	.dbline 0 ; func end
	xjmp pop_xgset300C
	.dbsym r temp 10 c
	.dbsym r i 20 c
	.dbsym r data 16 c
	.dbend
	.dbfunc e SPI_Read _SPI_Read fc
;        reg_val -> R10
;            reg -> R10
	.even
_SPI_Read::
	st -y,R10
	st -y,R11
	mov R10,R16
	.dbline -1
	.dbline 162
; }
; /****************************************************************************************************
; /*函数：uchar SPI_Read(uchar reg)
; /*功能：NRF24L01的SPI时序
; /****************************************************************************************************/
; char SPI_Read(char reg)
; {
	.dbline 165
; 	char reg_val;
; 	
; 	Low_24L01_CSN;                // CSN low, initialize SPI communication...
	cbi 0x18,7
	.dbline 166
; 	SPI_RW(reg);            // Select register to read from..
	mov R16,R10
	xcall _SPI_RW
	.dbline 167
; 	reg_val = SPI_RW(0);    // ..then read registervalue
	clr R16
	xcall _SPI_RW
	mov R10,R16
	.dbline 168
; 	Hign_24L01_CSN;                // CSN high, terminate SPI communication
	sbi 0x18,7
	.dbline 170
; 	
; 	return(reg_val);        // return register value
	.dbline -2
L19:
	.dbline 0 ; func end
	ld R11,y+
	ld R10,y+
	ret
	.dbsym r reg_val 10 c
	.dbsym r reg 10 c
	.dbend
	.dbfunc e SPI_RW_Reg _SPI_RW_Reg fc
;         status -> R10
;          value -> R12
;            reg -> R10
	.even
_SPI_RW_Reg::
	xcall push_xgset003C
	mov R12,R18
	mov R10,R16
	.dbline -1
	.dbline 176
; }
; /****************************************************************************************************/
; /*功能：NRF24L01读写寄存器函数
; /****************************************************************************************************/
; char SPI_RW_Reg(char reg, char value)
; {
	.dbline 179
; 	char status;
; 	
; 	Low_24L01_CSN;                   // CSN low, init SPI transaction
	cbi 0x18,7
	.dbline 180
; 	status = SPI_RW(reg);      // select register
	mov R16,R10
	xcall _SPI_RW
	mov R10,R16
	.dbline 181
; 	SPI_RW(value);             // ..and write value to it..
	mov R16,R12
	xcall _SPI_RW
	.dbline 182
; 	Hign_24L01_CSN;                   // CSN high again
	sbi 0x18,7
	.dbline 184
; 	
; 	return(status);            // return nRF24L01 status uchar
	mov R16,R10
	.dbline -2
L20:
	.dbline 0 ; func end
	xjmp pop_xgset003C
	.dbsym r status 10 c
	.dbsym r value 12 c
	.dbsym r reg 10 c
	.dbend
	.dbfunc e SPI_Read_Buf _SPI_Read_Buf fc
;        status1 -> R10,R11
;      uchar_ctr -> R20,R21
;         uchars -> y+6
;           pBuf -> R12,R13
;            reg -> R10
	.even
_SPI_Read_Buf::
	xcall push_xgset303C
	movw R12,R18
	mov R10,R16
	.dbline -1
	.dbline 191
; }
; /****************************************************************************************************/
; /*函数：uint SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于读数据，reg：为寄存器地址，pBuf：为待读出数据地址，uchars：读出数据的个数
; /****************************************************************************************************/
; char SPI_Read_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 194
; 	int status1,uchar_ctr;
; 	
; 	Low_24L01_CSN;                    		// Set CSN low, init SPI tranaction
	cbi 0x18,7
	.dbline 195
; 	status1 = SPI_RW(reg);       		// Select register to write to and read status uchar
	mov R16,R10
	xcall _SPI_RW
	mov R10,R16
	clr R11
	.dbline 197
; 	
; 	for(uchar_ctr=0;uchar_ctr<uchars;uchar_ctr++)
	clr R20
	clr R21
	xjmp L25
L22:
	.dbline 198
; 		pBuf[uchar_ctr] = SPI_RW(0);    // 
	clr R16
	xcall _SPI_RW
	movw R30,R20
	add R30,R12
	adc R31,R13
	std z+0,R16
L23:
	.dbline 197
	subi R20,255  ; offset = 1
	sbci R21,255
L25:
	.dbline 197
	ldd R2,y+6
	clr R3
	cp R20,R2
	cpc R21,R3
	brlt L22
X5:
	.dbline 200
; 	
; 	Hign_24L01_CSN;                           
	sbi 0x18,7
	.dbline 202
; 	
; 	return(status1);                    // return nRF24L01 status uchar
	mov R16,R10
	.dbline -2
L21:
	.dbline 0 ; func end
	xjmp pop_xgset303C
	.dbsym r status1 10 I
	.dbsym r uchar_ctr 20 I
	.dbsym l uchars 6 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 10 c
	.dbend
	.dbfunc e SPI_Write_Buf _SPI_Write_Buf fc
;        status1 -> R10
;      uchar_ctr -> R12
;         uchars -> y+6
;           pBuf -> R14,R15
;            reg -> R10
	.even
_SPI_Write_Buf::
	xcall push_xgset00FC
	movw R14,R18
	mov R10,R16
	.dbline -1
	.dbline 209
; }
; /*********************************************************************************************************
; /*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
; /*********************************************************************************************************/
; char SPI_Write_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 212
; 	char status1,uchar_ctr;
; 	
; 	Low_24L01_CSN;             //SPI使能       
	cbi 0x18,7
	.dbline 213
; 	status1 = SPI_RW(reg);   
	mov R16,R10
	xcall _SPI_RW
	mov R10,R16
	.dbline 214
; 	for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
	clr R12
	xjmp L30
L27:
	.dbline 215
; 	SPI_RW(*pBuf++);
	movw R30,R14
	ld R16,Z+
	movw R14,R30
	xcall _SPI_RW
L28:
	.dbline 214
	inc R12
L30:
	.dbline 214
	ldd R0,y+6
	cp R12,R0
	brlo L27
X6:
	.dbline 216
; 	Hign_24L01_CSN;           //关闭SPI
	sbi 0x18,7
	.dbline 217
; 	return(status1);    		  // 
	mov R16,R10
	.dbline -2
L26:
	.dbline 0 ; func end
	xjmp pop_xgset00FC
	.dbsym r status1 10 c
	.dbsym r uchar_ctr 12 c
	.dbsym l uchars 6 c
	.dbsym r pBuf 14 pc
	.dbsym r reg 10 c
	.dbend
	.dbfunc e SetRX_Mode _SetRX_Mode fV
	.even
_SetRX_Mode::
	.dbline -1
	.dbline 224
; }
; /****************************************************************************************************/
; /*函数：void SetRX_Mode(void)
; /*功能：数据接收配置 
; /****************************************************************************************************/
; void SetRX_Mode(void)
; {
	.dbline 225
; 	Low_24L01_CE;
	cbi 0x18,5
	.dbline 226
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收
	ldi R18,15
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 227
; 	Hign_24L01_CE; 
	sbi 0x18,5
	.dbline 228
; 	Delay(1000);//注意不能太小
	ldi R16,1000
	ldi R17,3
	xcall _Delay
	.dbline -2
L31:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e nRF24L01_RxPacket _nRF24L01_RxPacket fc
;         revale -> R20
;         rx_buf -> R10,R11
	.even
_nRF24L01_RxPacket::
	xcall push_xgset300C
	movw R10,R16
	sbiw R28,1
	.dbline -1
	.dbline 235
; }
; /******************************************************************************************************/
; /*函数：unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
; /*功能：数据读取后放如rx_buf接收缓冲区中
; /******************************************************************************************************/
; char nRF24L01_RxPacket(char* rx_buf)
; {
	.dbline 236
;     char revale=0;
	clr R20
	.dbline 237
; 	sta=SPI_Read(STATUS);	     // 读取状态寄存其来判断数据接收状况		
	ldi R16,7
	xcall _SPI_Read
	sts _sta,R16
	.dbline 238
; 	if(sta&0x40)                 // 判断是否接收到数据
	sbrs R16,6
	rjmp L33
X7:
	.dbline 239
; 	{
	.dbline 240
; 	    Low_24L01_CE; 			//SPI使能
	cbi 0x18,5
	.dbline 241
; 		SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
	ldi R24,32
	std y+0,R24
	movw R18,R10
	ldi R16,97
	xcall _SPI_Read_Buf
	.dbline 242
; 		revale =1;			//读取数据完成标志
	ldi R20,1
	.dbline 243
; 	}
L33:
	.dbline 244
; 	SPI_RW_Reg(WRITE_REG+STATUS,sta);   //接收到数据后RX_DR,TX_DS,MAX_PT都置高为1，通过写1来清楚中断标志
	lds R18,_sta
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 245
; 	return revale;
	mov R16,R20
	.dbline -2
L32:
	.dbline 0 ; func end
	adiw R28,1
	xjmp pop_xgset300C
	.dbsym r revale 20 c
	.dbsym r rx_buf 10 pc
	.dbend
	.dbfunc e nRF24L01_TxPacket _nRF24L01_TxPacket fV
;         tx_buf -> R10,R11
	.even
_nRF24L01_TxPacket::
	st -y,R10
	st -y,R11
	movw R10,R16
	sbiw R28,1
	.dbline -1
	.dbline 252
; }
; /***********************************************************************************************************
; /*函数：void nRF24L01_TxPacket(char * tx_buf)
; /*功能：发送 tx_buf中数据
; /**********************************************************************************************************/
; void nRF24L01_TxPacket(char * tx_buf)
; {
	.dbline 253
; 	Low_24L01_CE;			//StandBy I模式	
	cbi 0x18,5
	.dbline 254
; 	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	xcall _SPI_Write_Buf
	.dbline 255
; 	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 			 // 装载数据	
	ldi R24,32
	std y+0,R24
	movw R18,R10
	ldi R16,160
	xcall _SPI_Write_Buf
	.dbline 256
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	ldi R18,14
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 257
; 	Hign_24L01_CE;		 //置高CE，激发数据发送
	sbi 0x18,5
	.dbline 258
; 	Delay(600);
	ldi R16,600
	ldi R17,2
	xcall _Delay
	.dbline -2
L35:
	.dbline 0 ; func end
	adiw R28,1
	ld R11,y+
	ld R10,y+
	ret
	.dbsym r tx_buf 10 pc
	.dbend
	.dbfunc e init_NRF24L01 _init_NRF24L01 fV
	.even
_init_NRF24L01::
	sbiw R28,1
	.dbline -1
	.dbline 264
; }
; //****************************************************************************************
; /*NRF24L01初始化
; //***************************************************************************************/
; void init_NRF24L01(void)
; {
	.dbline 266
; 
;  	Low_24L01_CE;    // chip enable
	cbi 0x18,5
	.dbline 267
;  	Hign_24L01_CSN;   // Spi disable 
	sbi 0x18,7
	.dbline 268
;  	Low_24L01_SCK;   // Spi clock line init high
	cbi 0x18,6
	.dbline 269
; 	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,48
	xcall _SPI_Write_Buf
	.dbline 270
; 	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	ldi R24,5
	std y+0,R24
	ldi R18,<_RX_ADDRESS
	ldi R19,>_RX_ADDRESS
	ldi R16,42
	xcall _SPI_Write_Buf
	.dbline 271
; 	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      //  频道0自动	ACK应答允许	
	ldi R18,1
	ldi R16,33
	xcall _SPI_RW_Reg
	.dbline 272
; 	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	ldi R18,1
	ldi R16,34
	xcall _SPI_RW_Reg
	.dbline 273
; 	SPI_RW_Reg(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	clr R18
	ldi R16,37
	xcall _SPI_RW_Reg
	.dbline 274
; 	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
	ldi R18,32
	ldi R16,49
	xcall _SPI_RW_Reg
	.dbline 275
; 	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   		//设置发射速率为1MHZ，发射功率为最大值0dB
	ldi R18,7
	ldi R16,38
	xcall _SPI_RW_Reg
	.dbline 276
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收}
	ldi R18,15
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 277
;     Delay(6000);
	ldi R16,6000
	ldi R17,23
	xcall _Delay
	.dbline -2
L36:
	.dbline 0 ; func end
	adiw R28,1
	ret
	.dbend
	.dbfunc e StartUART _StartUART fV
	.even
_StartUART::
	.dbline -1
	.dbline 281
; }
; //-------------------------------串口初始化-------------------------------------
; void StartUART(void)
; {
	.dbline 282
;  	 UCSRA=0x00;	
	clr R2
	out 0xb,R2
	.dbline 283
; 	 UCSRB=0x18;	
	ldi R24,24
	out 0xa,R24
	.dbline 284
; 	 UCSRC=0x06;	
	ldi R24,6
	out 0x20,R24
	.dbline 285
; 	 UBRRL=0x67;
	ldi R24,103
	out 0x9,R24
	.dbline 286
; 	 UBRRH=0x00;
	out 0x20,R2
	.dbline 287
; 	 UCSRA=UCSRA|0x08;	
	sbi 0xb,3
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e R_S_Byte _R_S_Byte fV
;         R_Byte -> R16
	.even
_R_S_Byte::
	.dbline -1
	.dbline 291
; }
; //------------------------------串口发送----------------------------------------
; void R_S_Byte(char R_Byte)
; {	
	.dbline 292
;      UDR= R_Byte;  
	out 0xc,R16
	.dbline -2
L38:
	.dbline 0 ; func end
	ret
	.dbsym r R_Byte 16 c
	.dbend
	.dbfunc e main _main fI
;              i -> <dead>
;          RxBuf -> y+0
	.even
_main::
	sbiw R28,32
	.dbline -1
	.dbline 297
; }
; //******************************************************************************
; //******************************************************************************
; main()
; {
	.dbline 299
;  	char i,RxBuf[32];
;  	DDRB=0xe4;
	ldi R24,228
	out 0x17,R24
	.dbline 300
; 	DDRC=0xff;
	ldi R24,255
	out 0x14,R24
	.dbline 301
; 	DDRA=0x1e;
	ldi R24,30
	out 0x1a,R24
	.dbline 302
; 	PORTA=0x00;
	clr R2
	out 0x1b,R2
	.dbline 303
; 	PORTC=0xbf;
	ldi R24,191
	out 0x15,R24
	.dbline 305
; //******************************************************************************
; 	StartUART();
	xcall _StartUART
	.dbline 306
;     init_NRF24L01() ;
	xcall _init_NRF24L01
	xjmp L41
L40:
	.dbline 308
; 	while(1)
; 	{
	.dbline 311
; 	
; 		//-------------------------------------------------------------------------
; 	if((PINA & 0x20) == 0)		  //óD?ü°′??KEY1
	sbic 0x19,5
	rjmp L43
X8:
	.dbline 312
; 	{
L45:
	.dbline 313
; 	while(!(PINA & 0x20));   			//μè′y°′?ü?é?a
L46:
	.dbline 313
	sbis 0x19,5
	rjmp L45
X9:
	.dbline 314
; 	 TxBuf[0]=0x29;
	ldi R24,41
	sts _TxBuf,R24
	.dbline 315
; 	 tf=1;   
	ldi R24,1
	sts _tf,R24
	.dbline 316
; 	 PORTC=seg[1];
	lds R2,_seg+1
	out 0x15,R2
	.dbline 317
; 	 Low_Display4;
	cbi 0x1b,4
	.dbline 317
	.dbline 318
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 318
	.dbline 319
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 319
	.dbline 320
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 320
	.dbline 321
; 	 }
L43:
	.dbline 323
; //------------------------------------------------------------------------------
; 	if((PINA & 0x40) == 0)			//óD?ü°′??KEY2
	sbic 0x19,6
	rjmp L49
X10:
	.dbline 324
; 	{
L51:
	.dbline 325
; 	while(!(PINA & 0x40));   			//μè′y°′?ü?é?a
L52:
	.dbline 325
	sbis 0x19,6
	rjmp L51
X11:
	.dbline 326
;  	 TxBuf[0]=0x30; 
	ldi R24,48
	sts _TxBuf,R24
	.dbline 327
; 	 tf=1;    
	ldi R24,1
	sts _tf,R24
	.dbline 328
; 	 PORTC=seg[2];
	lds R2,_seg+2
	out 0x15,R2
	.dbline 329
; 	 Hign_Display4;
	sbi 0x1b,4
	.dbline 329
	.dbline 330
; 	 Low_Display3;
	cbi 0x1b,3
	.dbline 330
	.dbline 331
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 331
	.dbline 332
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 332
	.dbline 333
; 	 }
L49:
	.dbline 335
; //------------------------------------------------------------------------------
; 	if((PINA & 0x80) == 0)			//óD?ü°′??KEY3
	sbic 0x19,7
	rjmp L55
X12:
	.dbline 336
; 	{
L57:
	.dbline 337
; 	while(!(PINA & 0x80));   			//μè′y°′?ü?é?a
L58:
	.dbline 337
	sbis 0x19,7
	rjmp L57
X13:
	.dbline 338
;  	 TxBuf[0]=0x31;
	ldi R24,49
	sts _TxBuf,R24
	.dbline 339
; 	 tf=3;
	ldi R24,3
	sts _tf,R24
	.dbline 340
; 	 PORTC=seg[3];
	lds R2,_seg+3
	out 0x15,R2
	.dbline 341
; 	 Hign_Display4;
	sbi 0x1b,4
	.dbline 341
	.dbline 342
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 342
	.dbline 343
; 	 Low_Display2;
	cbi 0x1b,2
	.dbline 343
	.dbline 344
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 344
	.dbline 345
; 	}
L55:
	.dbline 347
; //------------------------------------------------------------------------------
; 	if(tf)
	lds R2,_tf
	tst R2
	breq L61
X14:
	.dbline 348
; 	{
	.dbline 349
; 	tf=0;
	clr R2
	sts _tf,R2
	.dbline 350
; 	Low_JDQ ;
	cbi 0x12,7
	.dbline 352
; 	//--------------------------------------------------------
; 	nRF24L01_TxPacket(TxBuf);	// Transmit Tx buffer data
	ldi R16,<_TxBuf
	ldi R17,>_TxBuf
	xcall _nRF24L01_TxPacket
	.dbline 353
; 	Delay(1000);
	ldi R16,1000
	ldi R17,3
	xcall _Delay
	.dbline 354
; 	SPI_RW_Reg(WRITE_REG+STATUS,0XFF);   //??×′ì???′??÷
	ldi R18,255
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 356
; 	//-------------------------------------------------
; 	TxBuf[0]=0;
	clr R2
	sts _TxBuf,R2
	.dbline 357
; 	Hign_JDQ ;
	sbi 0x12,7
	.dbline 358
; 	 }
L61:
	.dbline 361
; 	 
; //------------------------------------------------
; 		SetRX_Mode();
	xcall _SetRX_Mode
	.dbline 362
;    		if(nRF24L01_RxPacket(RxBuf))   //判断是否收到数据
	movw R16,R28
	xcall _nRF24L01_RxPacket
	tst R16
	brne X20
	xjmp L63
X20:
X15:
	.dbline 363
; 		{
	.dbline 364
; 		if(RxBuf[0]==0x29)
	ldd R24,y+0
	cpi R24,41
	brne L65
X16:
	.dbline 365
; 		{
	.dbline 366
; 		tf=1;
	ldi R24,1
	sts _tf,R24
	.dbline 367
; 		PORTC=seg[tf];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_tf
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 368
; 		Low_Display4;
	cbi 0x1b,4
	.dbline 368
	.dbline 369
; 	    Hign_Display3;
	sbi 0x1b,3
	.dbline 369
	.dbline 370
; 	    Hign_Display2;
	sbi 0x1b,2
	.dbline 370
	.dbline 371
; 	    Hign_Display1;
	sbi 0x1b,1
	.dbline 371
	.dbline 373
; 	
; 		}
L65:
	.dbline 374
; 		if(RxBuf[0]==0x30)
	ldd R24,y+0
	cpi R24,48
	brne L67
X17:
	.dbline 375
; 		{
	.dbline 376
; 		tf=2;
	ldi R24,2
	sts _tf,R24
	.dbline 377
; 		PORTC=seg[tf];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_tf
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 378
; 	 	Hign_Display4;
	sbi 0x1b,4
	.dbline 378
	.dbline 379
; 	    Low_Display3;
	cbi 0x1b,3
	.dbline 379
	.dbline 380
; 	    Hign_Display2;
	sbi 0x1b,2
	.dbline 380
	.dbline 381
; 	    Hign_Display1;
	sbi 0x1b,1
	.dbline 381
	.dbline 382
; 		}
L67:
	.dbline 383
; 		if(RxBuf[0]==0x31)
	ldd R24,y+0
	cpi R24,49
	brne L69
X18:
	.dbline 384
; 		{
	.dbline 385
; 		tf=3;
	ldi R24,3
	sts _tf,R24
	.dbline 386
; 		PORTC=seg[tf];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_tf
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 387
; 	 	Hign_Display4;
	sbi 0x1b,4
	.dbline 387
	.dbline 388
; 	    Hign_Display3;
	sbi 0x1b,3
	.dbline 388
	.dbline 389
; 	    Low_Display2;
	cbi 0x1b,2
	.dbline 389
	.dbline 390
; 	    Hign_Display1;
	sbi 0x1b,1
	.dbline 390
	.dbline 391
; 		}
L69:
	.dbline 392
; 		}	
L63:
	.dbline 393
; 		tf=0;
	clr R2
	sts _tf,R2
	.dbline 394
; 		RxBuf[0]=0;
	std y+0,R2
	.dbline 395
; 		}	
L41:
	.dbline 307
	xjmp L40
X19:
	.dbline -2
L39:
	.dbline 0 ; func end
	adiw R28,32
	ret
	.dbsym l i 1 c
	.dbsym l RxBuf 0 A[32:32]c
	.dbend
	.area bss(ram, con, rel)
	.dbfile C:\DOCUME~1\Administrator\桌面\无线双向通信\test.c
_tf::
	.blkb 1
	.dbsym e tf _tf c
_count::
	.blkb 1
	.dbsym e count _count c
_sta::
	.blkb 1
	.dbsym e sta _sta c
; }
