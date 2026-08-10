	.module fasong.c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
_table::
	.blkb 2
	.area idata
	.byte 0,1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 2,3
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 4,5
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 6,7
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 8,9
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbsym e table _table A[10:10]c
_seg::
	.blkb 2
	.area idata
	.byte 192,207
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 164,176
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 153,146
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 130,248
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 128,144
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbsym e seg _seg A[10:10]c
_seg1::
	.blkb 2
	.area idata
	.byte 64,'O
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 36,48
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 25,18
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 2,'x
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 0,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbsym e seg1 _seg1 A[10:10]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_RX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbsym e RX_ADDRESS _RX_ADDRESS A[5:5]c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
	.dbfunc e Delay _Delay fV
;              i -> R20,R21
;              s -> R16,R17
	.even
_Delay::
	xcall push_gset1
	.dbline -1
	.dbline 140
; //ICC-AVR application builder : 2007-8-11 20:37:32
; // Target : M16
; // Crystal: 8.0000Mhz
; #include <iom16v.h>
; #include <macros.h>
; //******************************************************************************
; //***********************DS18B20--------PD6*************************************
; //******************************************************************************
; #define   In_DQ      DDRD &= ~(1 << PD6)       
; #define   Out_DQ     DDRD |= (1 << PD6) 
; //------------------------------------------------------------------------------
; #define   Hign_DQ    PORTD |= (1 << PD6)   
; #define   Low_DQ     PORTD &= ~(1 << PD6)
; //------------------------------------------------------------------------------
; #define   Read_DQ    PIND & (1 << PD6)
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
; //------------------------------AD变量------------------------------------------
; char  AD_num,AD_data[4];
; char table[]={0,1,2,3,4,5,6,7,8,9};
; //------------------------------------------------------------------------------
; char seg[10]={0xC0,0xCF,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};         //0~~9段码
; char seg1[10]={0x40,0x4F,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
; //------------------------------------------------------------------------------
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
; //----------------------------------函数申明------------------------------------
; 
; void Init_DS18B20(void);
; char ReadOneChar(void);
; void WriteOneChar(char dat);
; void ReadTemperature(void);
; void work_temp();
; void StartUART(void);
; void R_S_Byte(char R_Byte);
; void DS1820_delay(int i);
; //------------------------------------------------------------------------------
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
; //-------------------------------延时-----------------------------------------
; void Delay(int s)
; {
	.dbline 142
	clr R20
	clr R21
	xjmp L5
L2:
	.dbline 142
L3:
	.dbline 142
	subi R20,255  ; offset = 1
	sbci R21,255
L5:
	.dbline 142
; 	unsigned int i;
; 	for(i=0; i<s; i++);
	cp R20,R16
	cpc R21,R17
	brlo L2
	.dbline 143
	clr R20
	clr R21
	xjmp L9
L6:
	.dbline 143
L7:
	.dbline 143
	subi R20,255  ; offset = 1
	sbci R21,255
L9:
	.dbline 143
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
	.dbline 151
; }
; 
; /****************************************************************************************************
; /*函数：uint SPI_RW(uint uchar)
; /*功能：NRF24L01的SPI写时序
; /****************************************************************************************************/
; char SPI_RW(char data)
; {
	.dbline 152
; 	char i,temp=0;
	clr R20
	.dbline 153
;    	for(i=0;i<8;i++) // output 8-bit
	clr R22
	xjmp L14
L11:
	.dbline 154
;    	{
	.dbline 155
; 	if(data & 0x80)
	sbrs R16,7
	rjmp L15
	.dbline 156
; 	{
	.dbline 157
; 		Hign_24L01_MOSI ;         // output 'uchar', MSB to MOSI
	sbi 0x18,2
	.dbline 158
; 	}
	xjmp L16
L15:
	.dbline 160
; 	else
; 	{
	.dbline 161
; 	 	Low_24L01_MOSI; 
	cbi 0x18,2
	.dbline 162
; 	}	
L16:
	.dbline 163
; 		data = (data << 1);           // shift next bit into MSB..
	lsl R16
	.dbline 164
; 		temp<<=1;
	lsl R20
	.dbline 165
; 		Hign_24L01_SCK ;                      // Set SCK high..
	sbi 0x18,6
	.dbline 166
; 		if(Read_24L01_MISO )temp++;       		  // capture current MISO bit
	sbis 0x16,4
	rjmp L17
	.dbline 166
	inc R20
L17:
	.dbline 167
	cbi 0x18,6
	.dbline 168
L12:
	.dbline 153
	inc R22
L14:
	.dbline 153
	cpi R22,8
	brlo L11
	.dbline 169
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
	.dbline 176
; }
; /****************************************************************************************************
; /*函数：uchar SPI_Read(uchar reg)
; /*功能：NRF24L01的SPI时序
; /****************************************************************************************************/
; char SPI_Read(char reg)
; {
	.dbline 179
; 	char reg_val;
; 	
; 	Low_24L01_CSN;                // CSN low, initialize SPI communication...
	cbi 0x18,7
	.dbline 180
; 	SPI_RW(reg);            // Select register to read from..
	mov R16,R20
	xcall _SPI_RW
	.dbline 181
; 	reg_val = SPI_RW(0);    // ..then read registervalue
	clr R16
	xcall _SPI_RW
	mov R20,R16
	.dbline 182
; 	Hign_24L01_CSN;                // CSN high, terminate SPI communication
	sbi 0x18,7
	.dbline 184
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
	.dbline 190
; }
; /****************************************************************************************************/
; /*功能：NRF24L01读写寄存器函数
; /****************************************************************************************************/
; char SPI_RW_Reg(char reg, char value)
; {
	.dbline 193
; 	char status;
; 	
; 	Low_24L01_CSN;                   // CSN low, init SPI transaction
	cbi 0x18,7
	.dbline 194
; 	status = SPI_RW(reg);      // select register
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	.dbline 195
; 	SPI_RW(value);             // ..and write value to it..
	mov R16,R22
	xcall _SPI_RW
	.dbline 196
; 	Hign_24L01_CSN;                   // CSN high again
	sbi 0x18,7
	.dbline 198
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
;         status -> R20,R21
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
	.dbline 205
; }
; /****************************************************************************************************/
; /*函数：uint SPI_Read_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于读数据，reg：为寄存器地址，pBuf：为待读出数据地址，uchars：读出数据的个数
; /****************************************************************************************************/
; char SPI_Read_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 208
; 	int status,uchar_ctr;
; 	
; 	Low_24L01_CSN;                    		// Set CSN low, init SPI tranaction
	cbi 0x18,7
	.dbline 209
; 	status = SPI_RW(reg);       		// Select register to write to and read status uchar
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	clr R21
	.dbline 211
; 	
; 	for(uchar_ctr=0;uchar_ctr<uchars;uchar_ctr++)
	clr R22
	clr R23
	xjmp L25
L22:
	.dbline 212
	clr R16
	xcall _SPI_RW
	movw R30,R22
	add R30,R12
	adc R31,R13
	std z+0,R16
L23:
	.dbline 211
	subi R22,255  ; offset = 1
	sbci R23,255
L25:
	.dbline 211
	mov R2,R10
	clr R3
	cp R22,R2
	cpc R23,R3
	brlt L22
	.dbline 214
; 		pBuf[uchar_ctr] = SPI_RW(0);    // 
; 	
; 	Hign_24L01_CSN;                           
	sbi 0x18,7
	.dbline 216
; 	
; 	return(status);                    // return nRF24L01 status uchar
	mov R16,R20
	.dbline -2
L21:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status 20 I
	.dbsym r uchar_ctr 22 I
	.dbsym r uchars 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SPI_Write_Buf _SPI_Write_Buf fc
;         status -> R20
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
	.dbline 223
; }
; /*********************************************************************************************************
; /*函数：uint SPI_Write_Buf(uchar reg, uchar *pBuf, uchar uchars)
; /*功能: 用于写数据：为寄存器地址，pBuf：为待写入数据地址，uchars：写入数据的个数
; /*********************************************************************************************************/
; char SPI_Write_Buf(char reg, char *pBuf, char uchars)
; {
	.dbline 226
; 	char status,uchar_ctr;
; 	
; 	Low_24L01_CSN;             //SPI使能       
	cbi 0x18,7
	.dbline 227
; 	status = SPI_RW(reg);   
	mov R16,R20
	xcall _SPI_RW
	mov R20,R16
	.dbline 228
; 	for(uchar_ctr=0; uchar_ctr<uchars; uchar_ctr++) //
	clr R22
	xjmp L30
L27:
	.dbline 229
	movw R30,R12
	ld R16,Z+
	movw R12,R30
	xcall _SPI_RW
L28:
	.dbline 228
	inc R22
L30:
	.dbline 228
	cp R22,R10
	brlo L27
	.dbline 230
; 	SPI_RW(*pBuf++);
; 	Hign_24L01_CSN;           //关闭SPI
	sbi 0x18,7
	.dbline 231
; 	return(status);    		  // 
	mov R16,R20
	.dbline -2
L26:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r status 20 c
	.dbsym r uchar_ctr 22 c
	.dbsym r uchars 10 c
	.dbsym r pBuf 12 pc
	.dbsym r reg 20 c
	.dbend
	.dbfunc e SetRX_Mode _SetRX_Mode fV
	.even
_SetRX_Mode::
	.dbline -1
	.dbline 238
; }
; /****************************************************************************************************/
; /*函数：void SetRX_Mode(void)
; /*功能：数据接收配置 
; /****************************************************************************************************/
; void SetRX_Mode(void)
; {
	.dbline 239
; 	Low_24L01_CE;
	cbi 0x18,5
	.dbline 240
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);   		// IRQ收发完成中断响应，16位CRC	，主接收
	ldi R18,15
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 241
; 	Hign_24L01_CE; 
	sbi 0x18,5
	.dbline 242
; 	Delay(1000);
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
	.dbline 249
; }
; /******************************************************************************************************/
; /*函数：unsigned char nRF24L01_RxPacket(unsigned char* rx_buf)
; /*功能：数据读取后放如rx_buf接收缓冲区中
; /******************************************************************************************************/
; char nRF24L01_RxPacket(char* rx_buf)
; {
	.dbline 250
;     char revale=0;
	clr R20
	.dbline 251
; 	sta=SPI_Read(STATUS);	// 读取状态寄存其来判断数据接收状况
	ldi R16,7
	xcall _SPI_Read
	sts _sta,R16
	.dbline 252
; 	if(sta&0x40)				// 判断是否接收到数据
	sbrs R16,6
	rjmp L33
	.dbline 253
; 	{
	.dbline 254
; 	    Low_24L01_CE; 			//SPI使能
	cbi 0x18,5
	.dbline 255
; 		SPI_Read_Buf(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);// read receive payload from RX_FIFO buffer
	ldi R24,32
	std y+0,R24
	movw R18,R22
	ldi R16,97
	xcall _SPI_Read_Buf
	.dbline 256
; 		revale =1;			//读取数据完成标志
	ldi R20,1
	.dbline 257
; 	}
L33:
	.dbline 258
; 	SPI_RW_Reg(WRITE_REG+STATUS,sta);   //接收到数据后RX_DR,TX_DS,MAX_PT都置高为1，通过写1来清楚中断标志
	lds R18,_sta
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 259
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
	.dbfunc e nRF24L01_TxPacket _nRF24L01_TxPacket fV
;         tx_buf -> R20,R21
	.even
_nRF24L01_TxPacket::
	xcall push_gset1
	movw R20,R16
	sbiw R28,1
	.dbline -1
	.dbline 266
; }
; /***********************************************************************************************************
; /*函数：void nRF24L01_TxPacket(char * tx_buf)
; /*功能：发送 tx_buf中数据
; /**********************************************************************************************************/
; void nRF24L01_TxPacket(char * tx_buf)
; {
	.dbline 267
; 	Low_24L01_CE;			//StandBy I模式	
	cbi 0x18,5
	.dbline 268
; 	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); // 装载接收端地址
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,42
	xcall _SPI_Write_Buf
	.dbline 269
; 	SPI_Write_Buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH); 			 // 装载数据	
	ldi R24,32
	std y+0,R24
	movw R18,R20
	ldi R16,160
	xcall _SPI_Write_Buf
	.dbline 271
; //	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
; 	Hign_24L01_CE;		 //置高CE，激发数据发送
	sbi 0x18,5
	.dbline 272
; 	Delay(1000);
	ldi R16,1000
	ldi R17,3
	xcall _Delay
	.dbline -2
L35:
	adiw R28,1
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r tx_buf 20 pc
	.dbend
	.dbfunc e init_NRF24L01 _init_NRF24L01 fV
	.even
_init_NRF24L01::
	sbiw R28,1
	.dbline -1
	.dbline 278
; }
; //****************************************************************************************
; /*NRF24L01初始化
; //***************************************************************************************/
; void init_NRF24L01(void)
; {
	.dbline 280
; 
;  	Low_24L01_CE;    // chip enable
	cbi 0x18,5
	.dbline 281
;  	Hign_24L01_CSN;   // Spi disable 
	sbi 0x18,7
	.dbline 282
;  	Low_24L01_SCK;   // Spi clock line init high
	cbi 0x18,6
	.dbline 283
; 	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址	
	ldi R24,5
	std y+0,R24
	ldi R18,<_TX_ADDRESS
	ldi R19,>_TX_ADDRESS
	ldi R16,48
	xcall _SPI_Write_Buf
	.dbline 284
; 	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	ldi R24,5
	std y+0,R24
	ldi R18,<_RX_ADDRESS
	ldi R19,>_RX_ADDRESS
	ldi R16,42
	xcall _SPI_Write_Buf
	.dbline 285
; 	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);      //  频道0自动	ACK应答允许	
	ldi R18,1
	ldi R16,33
	xcall _SPI_RW_Reg
	.dbline 286
; 	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	ldi R18,1
	ldi R16,34
	xcall _SPI_RW_Reg
	.dbline 287
; 	SPI_RW_Reg(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	clr R18
	ldi R16,37
	xcall _SPI_RW_Reg
	.dbline 288
; 	SPI_RW_Reg(WRITE_REG + RX_PW_P0, RX_PLOAD_WIDTH); //设置接收数据长度，本次设置为32字节
	ldi R18,32
	ldi R16,49
	xcall _SPI_RW_Reg
	.dbline 289
; 	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);   		//设置发射速率为1MHZ，发射功率为最大值0dB	
	ldi R18,7
	ldi R16,38
	xcall _SPI_RW_Reg
	.dbline 290
; 	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);   		 // IRQ收发完成中断响应，16位CRC，主发送
	ldi R18,14
	ldi R16,32
	xcall _SPI_RW_Reg
	.dbline 291
; 	Delay(6000);
	ldi R16,6000
	ldi R17,23
	xcall _Delay
	.dbline -2
L36:
	adiw R28,1
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e GetADResult _GetADResult fc
;              i -> R16
	.even
_GetADResult::
	.dbline -1
	.dbline 298
; }
; //******************************************************************************
; //**********************************AD数据采集*****************************
; //******************************************************************************
; //-----------------------------AD转换函数----------------------------------------
; unsigned char GetADResult(void)
; {
	.dbline 305
; 	unsigned char i;
; /**********************ADC 多工选择寄存器－ ADMUX配置方法********************/
; /*      Bit   7     6     5     4    3    2    1    0     (Page203)        */
; /*          REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0                    */
; /*            1     1     1     0    0    1    1    1                    */
; /************************************************************************/
; 	ADMUX |= (1 << REFS1);  //2.56V 的片内基准电压源， AREF 引脚外加滤波电容
	sbi 0x7,7
	.dbline 306
; 	ADMUX |= (1 << REFS0);  //2.56V 的片内基准电压源， AREF 引脚外加滤波电容
	sbi 0x7,6
	.dbline 307
; 	ADMUX |= (1 << ADLAR);  //ADC 转换结果 左对齐
	sbi 0x7,5
	.dbline 308
; 	ADMUX &= ~(1 << MUX4);  //ADC0单端输入
	cbi 0x7,4
	.dbline 309
; 	ADMUX &= ~(1 << MUX3);  //ADC0单端输入
	cbi 0x7,3
	.dbline 310
; 	ADMUX &= ~(1 << MUX2);  //ADC0单端输入
	cbi 0x7,2
	.dbline 311
; 	ADMUX &= ~(1 << MUX1);  //ADC0单端输入
	cbi 0x7,1
	.dbline 312
; 	ADMUX &= ~(1 << MUX0);  //ADC0单端输入
	cbi 0x7,0
	.dbline 319
; 
; /********************ADC 控制和状态寄存器A -ADCSRA配置方法*************************/
; /*      Bit   7     6     5     4    3    2    1    0     (Page205)               */
; /*          ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0                           */
; /*            1     1     0     0    0    0    1    1                             */
; /**********************************************************************************/
; 	ADCSRA |= (1 << ADEN);  //ADC 使能
	sbi 0x6,7
	.dbline 320
; 	ADCSRA |= (1 << ADSC);  //ADC 开始转换
	sbi 0x6,6
	.dbline 321
; 	ADCSRA &= ~(1 << ADATE);//无ADC 自动触发使能
	cbi 0x6,5
	.dbline 322
; 	ADCSRA &= ~(1 << ADIF); //ADC 中断标志
	cbi 0x6,4
	.dbline 323
; 	ADCSRA &= ~(1 << ADIE); //不使用中断
	cbi 0x6,3
	.dbline 324
; 	ADCSRA |= (1 << ADPS2);//128分频时钟
	sbi 0x6,2
	.dbline 325
; 	ADCSRA |= (1 << ADPS1); //128分频时钟
	sbi 0x6,1
	.dbline 326
; 	ADCSRA |= (1 << ADPS0);//128分频时钟
	sbi 0x6,0
L38:
	.dbline 329
L39:
	.dbline 329
; 	
; //------------------------------------------------------------------------------
; 	while(!(ADCSRA & (1 << ADIF)));	//等待转换完成后ADIF自动置位
	sbis 0x6,4
	rjmp L38
	.dbline 330
; 	i = ADCH;
	in R16,0x5
	.dbline 331
; 	ADCSRA &= ~(1 << ADIF);		/*清标志*/
	cbi 0x6,4
	.dbline 332
; 	ADCSRA &= ~(1 << ADEN);		/*关闭转换*/
	cbi 0x6,7
	.dbline 334
; 
; 	return i;
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbsym r i 16 c
	.dbend
	.dbfunc e GetBaiwei _GetBaiwei fc
;           temp -> R20
	.even
_GetBaiwei::
	xcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 338
; }
; //--------------------------------//AD数据采集百位------------------------------
; unsigned char GetBaiwei(unsigned char temp)   
; {
	.dbline 339
; 	temp = temp/100;
	ldi R17,100
	mov R16,R20
	xcall div8u
	mov R20,R16
	.dbline 340
; 	return temp;
	.dbline -2
L41:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbend
	.dbfunc e GetShiwei _GetShiwei fc
;           temp -> R20
	.even
_GetShiwei::
	xcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 344
; }
; //-----------------------------//AD数据采集十位---------------------------------
; unsigned char GetShiwei(unsigned char temp)  
; {
	.dbline 345
; 	if(temp > 99)
	ldi R24,99
	cp R24,R20
	brsh L43
	.dbline 346
; 	{
	.dbline 347
; 		temp = temp - GetBaiwei(temp)*100;
	mov R16,R20
	xcall _GetBaiwei
	ldi R24,100
	mul R24,R16
	sub R20,R0
	.dbline 348
; 	}
L43:
	.dbline 349
; 	temp = temp/10;
	ldi R17,10
	mov R16,R20
	xcall div8u
	mov R20,R16
	.dbline 350
; 	return temp;
	.dbline -2
L42:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbend
	.dbfunc e GetGewei _GetGewei fc
;           temp -> R20
	.even
_GetGewei::
	xcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 354
; }
; //---------------------------- //AD数据采集个位---------------------------------
; unsigned char GetGewei(unsigned char temp)   
; {
	.dbline 355
; 	temp = temp%10;
	ldi R17,10
	mov R16,R20
	xcall mod8u
	mov R20,R16
	.dbline 356
; 	return temp;
	.dbline -2
L45:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r temp 20 c
	.dbend
	.dbfunc e dis_zhuye _dis_zhuye fV
	.even
_dis_zhuye::
	.dbline -1
	.dbline 360
; }
; //------------------------------------------------------------------------------
; void dis_zhuye()
; {
	.dbline 361
; 	 PORTC=seg1[AD_data[1]];
	ldi R24,<_seg1
	ldi R25,>_seg1
	lds R30,_AD_data+1
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 362
; 	 Hign_Display4;
	sbi 0x1b,4
	.dbline 362
	.dbline 363
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 363
	.dbline 364
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 364
	.dbline 365
; 	 Low_Display1;
	cbi 0x1b,1
	.dbline 365
	.dbline 366
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 367
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 367
	.dbline 369
; //------------------------------------------------------------------------------
; 	 PORTC=seg[AD_data[2]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_AD_data+2
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 370
; 	 Low_Display2;
	cbi 0x1b,2
	.dbline 370
	.dbline 371
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 372
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 372
	.dbline 374
; //------------------------------------------------ ---------------------------
; 	 PORTC=seg[AD_data[3]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_AD_data+3
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 375
; 	 Low_Display3;
	cbi 0x1b,3
	.dbline 375
	.dbline 376
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 377
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 377
	.dbline 379
; //----------------------------------------------------------------------------- 
; 	 PORTC=0xc1;
	ldi R24,193
	out 0x15,R24
	.dbline 380
; 	 Low_Display4;
	cbi 0x1b,4
	.dbline 380
	.dbline 381
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 382
; 	 Hign_Display4;	 
	sbi 0x1b,4
	.dbline 382
	.dbline -2
L46:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e main _main fI
	.even
_main::
	.dbline -1
	.dbline 386
; }
; 
; main()
; {
	.dbline 387
;  	DDRB=0xe4;
	ldi R24,228
	out 0x17,R24
	.dbline 388
; 	DDRC=0xff;
	ldi R24,255
	out 0x14,R24
	.dbline 389
; 	DDRA=0x1e;
	ldi R24,30
	out 0x1a,R24
	.dbline 390
; 	PORTA=0x00;
	clr R2
	out 0x1b,R2
	.dbline 391
; 	PORTC=0xbf;
	ldi R24,191
	out 0x15,R24
	.dbline 393
; 
;     init_NRF24L01() ;
	xcall _init_NRF24L01
	xjmp L52
L51:
	.dbline 396
	.dbline 397
	xcall _GetADResult
	sts _AD_num,R16
	.dbline 398
	ldi R24,170
	sts _AD_data,R24
	.dbline 399
	xcall _GetBaiwei
	ldi R24,<_table
	ldi R25,>_table
	mov R30,R16
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	sts _AD_data+1,R2
	.dbline 400
	lds R16,_AD_num
	xcall _GetShiwei
	ldi R24,<_table
	ldi R25,>_table
	mov R30,R16
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	sts _AD_data+2,R2
	.dbline 401
	lds R16,_AD_num
	xcall _GetGewei
	ldi R24,<_table
	ldi R25,>_table
	mov R30,R16
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	sts _AD_data+3,R2
	.dbline 402
	ldi R16,<_AD_data
	ldi R17,>_AD_data
	xcall _nRF24L01_TxPacket
	.dbline 403
	ldi R18,255
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 404
	xcall _dis_zhuye
	.dbline 405
L52:
	.dbline 395
	xjmp L51
X0:
	.dbline -2
L50:
	.dbline 0 ; func end
	ret
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线AD传感\发送\fasong.c
_sta::
	.blkb 1
	.dbsym e sta _sta c
_AD_data::
	.blkb 4
	.dbsym e AD_data _AD_data A[4:4]c
_AD_num::
	.blkb 1
	.dbsym e AD_num _AD_num c
