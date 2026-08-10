	.module jieshou.c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
_seg::
	.blkb 2
	.area idata
	.byte 192,207
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 164,176
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 153,146
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 130,248
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 128,144
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.dbsym e seg _seg A[10:10]c
_seg1::
	.blkb 2
	.area idata
	.byte 64,'O
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 36,48
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 25,18
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 2,'x
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 0,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.dbsym e seg1 _seg1 A[10:10]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_RX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.dbsym e RX_ADDRESS _RX_ADDRESS A[5:5]c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
	.dbfunc e Delay _Delay fV
;              i -> R20,R21
;              s -> R16,R17
	.even
_Delay::
	xcall push_gset1
	.dbline -1
	.dbline 121
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
; char temp[6],RxBuf[32];
; char seg[10]={0xC0,0xCF,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};         //0~~9段码
; char seg1[10]={0x40,0x4F,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; 
; char sta;
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
	.dbline 123
	clr R20
	clr R21
	xjmp L5
L2:
	.dbline 123
L3:
	.dbline 123
	subi R20,255  ; offset = 1
	sbci R21,255
L5:
	.dbline 123
; 	unsigned int i;
; 	for(i=0; i<s; i++);
	cp R20,R16
	cpc R21,R17
	brlo L2
	.dbline 124
	clr R20
	clr R21
	xjmp L9
L6:
	.dbline 124
L7:
	.dbline 124
	subi R20,255  ; offset = 1
	sbci R21,255
L9:
	.dbline 124
; 	for(i=0; i<s; i++);
	cp R20,R16
	cpc R21,R17
	brlo L6
	.dbline -2
L1:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 i
	.dbsym r s 16 I
	.dbend
	.dbfunc e SPI_RW _SPI_RW fc
;           temp -> R20
;              i -> R22
;           data -> R16
	.even
_SPI_RW::
	xcall push_gset2
	.dbline -1
	.dbline 132
; }
; 
; /****************************************************************************************************
; /*函数：uint SPI_RW(uint uchar)
; /*功能：NRF24L01的SPI写时序
; /****************************************************************************************************/
; char SPI_RW(char data)
; {
	.dbline 133
; 	char i,temp=0;
	clr R20
	.dbline 134
;    	for(i=0;i<8;i++) // output 8-bit
	clr R22
	xjmp L14
L11:
	.dbline 135
;    	{
	.dbline 136
; 	if(data & 0x80)
	sbrs R16,7
	rjmp L15
	.dbline 137
; 	{
	.dbline 138
; 		Hign_24L01_MOSI ;         // output 'uchar', MSB to MOSI
	sbi 0x18,2
	.dbline 139
; 	}
	xjmp L16
L15:
	.dbline 141
; 	else
; 	{
	.dbline 142
; 	 	Low_24L01_MOSI; 
	cbi 0x18,2
	.dbline 143
; 	}	
L16:
	.dbline 144
; 		data = (data << 1);           // shift next bit into MSB..
	lsl R16
	.dbline 145
; 		temp<<=1;
	lsl R20
	.dbline 146
; 		Hign_24L01_SCK ;                      // Set SCK high..
	sbi 0x18,6
	.dbline 147
; 		if(PINB&0x10)temp++;       		  // capture current MISO bit
	sbis 0x16,4
	rjmp L17
	.dbline 147
	inc R20
L17:
	.dbline 148
	cbi 0x18,6
	.dbline 149
L12:
	.dbline 134
	inc R22
L14:
	.dbline 134
	cpi R22,8
	brlo L11
	.dbline 150
; 		Low_24L01_SCK;            		  // ..then set SCK low again
;    	}
;     return(temp);           		  // return read uchar
	mov R16,R20
	.dbline -2
L10:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbsym r i 22 c
	.dbsym r data 16 c
	.dbend
	.dbfunc e SPI_Read _SPI_Read fc
;        reg_val -> R20
;            reg -> R20
	.even
_SPI_Read::
	xcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 157
; }
; /****************************************************************************************************
; /*函数：uchar SPI_Read(uchar reg)
; /*功能：NRF24L01的SPI时序
; /****************************************************************************************************/
; char SPI_Read(char reg)
; {
	.dbline 160
; 	char reg_val;
; 	
; 	Low_24L01_CSN;                // CSN low, initialize SPI communication...
	cbi 0x18,7
	.dbline 161
; 	SPI_RW(reg);            // Select register to read from..
	mov R16,R20
	xcall _SPI_RW
	.dbline 162
; 	reg_val = SPI_RW(0);    // ..then read registervalue
	clr R16
	xcall _SPI_RW
	mov R20,R16
	.dbline 163
; 	Hign_24L01_CSN;                // CSN high, terminate SPI communication
	sbi 0x18,7
	.dbline 165
; 	
; 	return(reg_val);        // return register value
	.dbline -2
L19:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r reg_val 20 c
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_RW_Reg _SPI_RW_Reg fc
;         status -> R20
;          value -> R22
;            reg -> R20
	.even
_SPI_RW_Reg::
	xcall push_gset2
	mov R22,R18
	mov R20,R16
	.dbline -1
	.dbline 171
; }
; /****************************************************************************************************/
; /*功能：NRF24L01读写寄存器函数
; /****************************************************************************************************/
; char SPI_RW_Reg(char reg, char value)
; {
	.dbline 174
; 	char status;
; 	
; 	Low_24L01_CSN;                   // CSN low, init SPI transaction
	cbi 0x18,7
	.dbline 175
; 	status = SPI_RW(reg);      // select register
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	.dbline 176
; 	SPI_RW(value);             // ..and write value to it..
	mov R16,R22
	xcall _SPI_RW
	.dbline 177
; 	Hign_24L01_CSN;                   // CSN high again
	sbi 0x18,7
	.dbline 179
; 	
; 	return(status);            // return nRF24L01 status uchar
	mov R16,R20
	.dbline -2
L20:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r status 20 c
	.dbsym r value 22 c
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Read_Buf _SPI_Read_Buf fc
;        status1 -> R20,R21
;      uchar_ctr -> R22,R23
;         uchars -> R10
;           pBuf -> R12,R13
;            reg -> R20
	.even
_SPI_Read_Buf::
	xcall push_gset4
	movw R12,R18
	mov R20,R16
	ldd R10,y+8
	.dbline -1
	.dbline 186
; }
; /****************************************************************************************************/
; /*函数：uint SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于读数据，reg：为寄存器地址，pBuf：为待读出数据地址，uchars：读出数据的个数
; /****************************************************************************************************/
; char SPI_Read_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 189
; 	int status1,uchar_ctr;
; 	
; 	Low_24L01_CSN;                    		// Set CSN low, init SPI tranaction
	cbi 0x18,7
	.dbline 190
; 	status1 = SPI_RW(reg);       		// Select register to write to and read status uchar
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	clr R21
	.dbline 192
; 	
; 	for(uchar_ctr=0;uchar_ctr<uchars;uchar_ctr++)
	clr R22
	clr R23
	xjmp L25
L22:
	.dbline 193
	clr R16
	xcall _SPI_RW
	movw R30,R22
	add R30,R12
	adc R31,R13
	std z+0,R16
L23:
	.dbline 192
	subi R22,255  ; offset = 1
	sbci R23,255
L25:
	.dbline 192
	mov R2,R10
	clr R3
	cp R22,R2
	cpc R23,R3
	brlt L22
	.dbline 195
; 		pBuf[uchar_ctr] = SPI_RW(0);    // 
; 	
; 	Hign_24L01_CSN;                           
	sbi 0x18,7
	.dbline 197
; 	
; 	return(status1);                    // return nRF24L01 status uchar
	mov R16,R20
	.dbline -2
L21:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status1 20 I
	.dbsym r uchar_ctr 22 I
	.dbsym r uchars 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Write_Buf _SPI_Write_Buf fc
;        status1 -> R20
;      uchar_ctr -> R22
;         uchars -> R10
;           pBuf -> R12,R13
;            reg -> R20
	.even
_SPI_Write_Buf::
	xcall push_gset4
	movw R12,R18
	mov R20,R16
	ldd R10,y+8
	.dbline -1
	.dbline 204
; }
; /*********************************************************************************************************
; /*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
; /*********************************************************************************************************/
; char SPI_Write_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 207
; 	char status1,uchar_ctr;
; 	
; 	Low_24L01_CSN;             //SPI使能       
	cbi 0x18,7
	.dbline 208
; 	status1 = SPI_RW(reg);   
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	.dbline 209
; 	for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
	clr R22
	xjmp L30
L27:
	.dbline 210
	movw R30,R12
	ld R16,Z+
	movw R12,R30
	xcall _SPI_RW
L28:
	.dbline 209
	inc R22
L30:
	.dbline 209
	cp R22,R10
	brlo L27
	.dbline 211
; 	SPI_RW(*pBuf++);
; 	Hign_24L01_CSN;           //关闭SPI
	sbi 0x18,7
	.dbline 212
; 	return(status1);    		  // 
	mov R16,R20
	.dbline -2
L26:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status1 20 c
	.dbsym r uchar_ctr 22 c
	.dbsym r uchars 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SetRX_Mode _SetRX_Mode fV
	.even
_SetRX_Mode::
	.dbline -1
	.dbline 219
; }
; /****************************************************************************************************/
; /*函数：void SetRX_Mode(void)
; /*功能：数据接收配置 
; /****************************************************************************************************/
; void SetRX_Mode(void)
; {
	.dbline 220
; 	Low_24L01_CE;
	cbi 0x18,5
	.dbline 222
; 	//SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收
; 	Hign_24L01_CE; 
	sbi 0x18,5
	.dbline 223
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
;         rx_buf -> R22,R23
	.even
_nRF24L01_RxPacket::
	xcall push_gset2
	movw R22,R16
	sbiw R28,1
	.dbline -1
	.dbline 230
; }
; /******************************************************************************************************/
; /*函数：unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
; /*功能：数据读取后放如rx_buf接收缓冲区中
; /******************************************************************************************************/
; char nRF24L01_RxPacket(char* rx_buf)
; {
	.dbline 231
;     char revale=0;
	clr R20
	.dbline 232
; 	sta=SPI_Read(STATUS);	     // 读取状态寄存其来判断数据接收状况		
	ldi R16,7
	xcall _SPI_Read
	sts _sta,R16
	.dbline 233
; 	if(sta&0x40)                 // 判断是否接收到数据
	sbrs R16,6
	rjmp L33
	.dbline 234
; 	{
	.dbline 235
; 	    Low_24L01_CE; 			//SPI使能
	cbi 0x18,5
	.dbline 236
; 		SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
	ldi R24,32
	std y+0,R24
	movw R18,R22
	ldi R16,97
	xcall _SPI_Read_Buf
	.dbline 237
; 		revale =1;			//读取数据完成标志
	ldi R20,1
	.dbline 238
; 	}
L33:
	.dbline 239
; 	SPI_RW_Reg(WRITE_REG+STATUS,sta);   //接收到数据后RX_DR,TX_DS,MAX_PT都置高为1，通过写1来清楚中断标志
	lds R18,_sta
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 240
; 	return revale;
	mov R16,R20
	.dbline -2
L32:
	adiw R28,1
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r revale 20 c
	.dbsym r rx_buf 22 pc
	.dbend
	.dbfunc e init_NRF24L01 _init_NRF24L01 fV
	.even
_init_NRF24L01::
	sbiw R28,1
	.dbline -1
	.dbline 247
; }
; 
; //****************************************************************************************
; /*NRF24L01初始化
; //***************************************************************************************/
; void init_NRF24L01(void)
; {
	.dbline 249
; 
;  	Low_24L01_CE;    // chip enable
	cbi 0x18,5
	.dbline 250
;  	Hign_24L01_CSN;   // Spi disable 
	sbi 0x18,7
	.dbline 251
;  	Low_24L01_SCK;   // Spi clock line init high
	cbi 0x18,6
	.dbline 252
; 	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,48
	xcall _SPI_Write_Buf
	.dbline 253
; 	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	ldi R24,5
	std y+0,R24
	ldi R18,<_RX_ADDRESS
	ldi R19,>_RX_ADDRESS
	ldi R16,42
	xcall _SPI_Write_Buf
	.dbline 254
; 	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      //  频道0自动	ACK应答允许	
	ldi R18,1
	ldi R16,33
	xcall _SPI_RW_Reg
	.dbline 255
; 	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	ldi R18,1
	ldi R16,34
	xcall _SPI_RW_Reg
	.dbline 256
; 	SPI_RW_Reg(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	clr R18
	ldi R16,37
	xcall _SPI_RW_Reg
	.dbline 257
; 	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
	ldi R18,32
	ldi R16,49
	xcall _SPI_RW_Reg
	.dbline 258
; 	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   		//设置发射速率为1MHZ，发射功率为最大值0dB
	ldi R18,7
	ldi R16,38
	xcall _SPI_RW_Reg
	.dbline 259
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收}
	ldi R18,15
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 260
;     Delay(6000);
	ldi R16,6000
	ldi R17,23
	xcall _Delay
	.dbline -2
L35:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e StartUART _StartUART fV
	.even
_StartUART::
	.dbline -1
	.dbline 264
; }
; //-------------------------------串口初始化-------------------------------------
; void StartUART(void)
; {
	.dbline 265
;  	 UCSRA=0x00;	
	clr R2
	out 0xb,R2
	.dbline 266
; 	 UCSRB=0x18;	
	ldi R24,24
	out 0xa,R24
	.dbline 267
; 	 UCSRC=0x06;	
	ldi R24,6
	out 0x20,R24
	.dbline 268
; 	 UBRRL=0x67;
	ldi R24,103
	out 0x9,R24
	.dbline 269
; 	 UBRRH=0x00;
	out 0x20,R2
	.dbline 270
; 	 UCSRA=UCSRA|0x08;	
	sbi 0xb,3
	.dbline -2
L36:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e R_S_Byte _R_S_Byte fV
;         R_Byte -> R16
	.even
_R_S_Byte::
	.dbline -1
	.dbline 274
; }
; //------------------------------串口发送----------------------------------------
; void R_S_Byte(char R_Byte)
; {	
	.dbline 275
;      UDR= R_Byte;  
	out 0xc,R16
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbsym r R_Byte 16 c
	.dbend
	.dbfunc e display _display fV
	.even
_display::
	.dbline -1
	.dbline 279
; }
; //******************************************************************************
; void display()
; {
	.dbline 280
; 	 PORTC=seg[RxBuf[1]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_RxBuf+1
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 281
; 	 Hign_Display4;
	sbi 0x1b,4
	.dbline 281
	.dbline 282
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 282
	.dbline 283
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 283
	.dbline 284
; 	 Low_Display1;
	cbi 0x1b,1
	.dbline 284
	.dbline 285
; 	Delay(100);
	ldi R16,100
	ldi R17,0
	xcall _Delay
	.dbline 286
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 286
	.dbline 288
; //------------------------------------------------------------------------------
; 	 PORTC=seg1[RxBuf[2]];
	ldi R24,<_seg1
	ldi R25,>_seg1
	lds R30,_RxBuf+2
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 289
; 	 Low_Display2;
	cbi 0x1b,2
	.dbline 289
	.dbline 290
; 	 Delay(100);
	ldi R16,100
	ldi R17,0
	xcall _Delay
	.dbline 291
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 291
	.dbline 293
; //------------------------------------------------ ---------------------------
; 	 PORTC=seg[RxBuf[3]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_RxBuf+3
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 294
; 	 Low_Display3;
	cbi 0x1b,3
	.dbline 294
	.dbline 295
; 	 Delay(100);
	ldi R16,100
	ldi R17,0
	xcall _Delay
	.dbline 296
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 296
	.dbline 298
; //----------------------------------------------------------------------------- 
; 	 PORTC=0xc1;
	ldi R24,193
	out 0x15,R24
	.dbline 299
; 	 Low_Display4;
	cbi 0x1b,4
	.dbline 299
	.dbline 300
; 	 Delay(100);
	ldi R16,100
	ldi R17,0
	xcall _Delay
	.dbline 301
; 	 Hign_Display4;	 
	sbi 0x1b,4
	.dbline 301
	.dbline -2
L38:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e main _main fI
;              i -> <dead>
	.even
_main::
	.dbline -1
	.dbline 306
; 		
; }
; //******************************************************************************
; main()
; {
	.dbline 308
;  	char i;
;  	DDRB=0xe4;
	ldi R24,228
	out 0x17,R24
	.dbline 309
; 	DDRC=0xff;
	ldi R24,255
	out 0x14,R24
	.dbline 310
; 	DDRA=0x1e;
	ldi R24,30
	out 0x1a,R24
	.dbline 311
; 	DDRD=0xb2;	
	ldi R24,178
	out 0x11,R24
	.dbline 312
; 	PORTA=0x00;
	clr R2
	out 0x1b,R2
	.dbline 313
; 	PORTC=0xbf;
	ldi R24,191
	out 0x15,R24
	.dbline 314
;  	Hign_BELL ;//关闭蜂明器报警
	sbi 0x12,5
	.dbline 314
	.dbline 315
; 	Hign_JDQ;  //关闭继电器
	sbi 0x12,7
	.dbline 317
; //******************************************************************************
; 	StartUART();
	xcall _StartUART
	.dbline 318
;     init_NRF24L01() ;
	xcall _init_NRF24L01
	xjmp L44
L43:
	.dbline 320
; 	while(1)
; 	{
	.dbline 321
; 		SetRX_Mode();
	xcall _SetRX_Mode
	.dbline 322
;    		if(nRF24L01_RxPacket(RxBuf))   //判断是否收到数据
	ldi R16,<_RxBuf
	ldi R17,>_RxBuf
	xcall _nRF24L01_RxPacket
	tst R16
	breq L46
	.dbline 323
; 		{
	.dbline 332
; 		/*用于串口显示
; 			R_S_Byte(RxBuf[1]);
; 			Delay(2000);
; 			R_S_Byte(RxBuf[2]);				 
; 			Delay(2000);
; 			R_S_Byte(RxBuf[3])	;			 	 
; 			Delay(2000);	
; 		*/		
; 		}
L46:
	.dbline 333
	xcall _display
	.dbline 334
L44:
	.dbline 319
	xjmp L43
X0:
	.dbline -2
L42:
	.dbline 0 ; func end
	ret
	.dbsym l i 1 c
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\接收\jieshou.c
_sta::
	.blkb 1
	.dbsym e sta _sta c
_RxBuf::
	.blkb 32
	.dbsym e RxBuf _RxBuf A[32:32]c
_temp::
	.blkb 6
	.dbsym e temp _temp A[6:6]c
