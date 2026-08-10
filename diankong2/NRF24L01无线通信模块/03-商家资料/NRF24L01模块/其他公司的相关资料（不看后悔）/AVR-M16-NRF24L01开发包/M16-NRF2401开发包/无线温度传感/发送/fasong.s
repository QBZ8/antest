	.module fasong.c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
_temp_data::
	.blkb 2
	.area idata
	.byte 0,0
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.dbsym e temp_data _temp_data A[2:2]c
_seg::
	.blkb 2
	.area idata
	.byte 192,207
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 164,176
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 153,146
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 130,248
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 128,144
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.dbsym e seg _seg A[10:10]c
_seg1::
	.blkb 2
	.area idata
	.byte 64,'O
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 36,48
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 25,18
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 2,'x
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 0,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.dbsym e seg1 _seg1 A[10:10]c
_TX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.dbsym e TX_ADDRESS _TX_ADDRESS A[5:5]c
_RX_ADDRESS::
	.blkb 2
	.area idata
	.byte 52,'C
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 2
	.area idata
	.byte 16,16
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.blkb 1
	.area idata
	.byte 1
	.area data(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
	.dbsym e RX_ADDRESS _RX_ADDRESS A[5:5]c
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
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
; //***********************************数码管0-9编码*******************************************
; //----------------------------温度变量------------------------------------------
; char  temp_data[2]={0x00,0x00};
; char  dispaly[7];
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
	.dbfunc e DS1820_delay _DS1820_delay fV
;              i -> R16,R17
	.even
_DS1820_delay::
	.dbline -1
	.dbline 299
; }
; //******************************************************************************
; //**********************************DS18B20温度采集*****************************
; //******************************************************************************
; 
; //----------------------------------延时函数------------------------------------
; void DS1820_delay(int i)
; {
L38:
	.dbline 300
L39:
	.dbline 300
; 	while(i--);
	movw R2,R16
	subi R16,1
	sbci R17,0
	tst R2
	brne L38
	tst R3
	brne L38
X0:
	.dbline -2
L37:
	.dbline 0 ; func end
	ret
	.dbsym r i 16 I
	.dbend
	.dbfunc e Init_DS18B20 _Init_DS18B20 fV
;              x -> R20
	.even
_Init_DS18B20::
	xcall push_gset1
	.dbline -1
	.dbline 304
; }
; //---------------------------------DS18B20初始化--------------------------------
; void Init_DS18B20(void)
; {
	.dbline 305
;     unsigned char x=1;
	ldi R20,1
	.dbline 307
; 	
; 	Out_DQ;                //配置输出
	sbi 0x11,6
	.dbline 308
; 	Hign_DQ;              //置高电平
	sbi 0x12,6
	.dbline 309
; 	Low_DQ;			     //置低电平
	cbi 0x12,6
	.dbline 310
; 	DS1820_delay(3000);	    //400-960us
	ldi R16,3000
	ldi R17,11
	xcall _DS1820_delay
	.dbline 311
; 	Hign_DQ;		   //置高电平
	sbi 0x12,6
	.dbline 312
; 	In_DQ ;
	cbi 0x11,6
	.dbline 313
; 	DS1820_delay(40);		  //15-60us
	ldi R16,40
	ldi R17,0
	xcall _DS1820_delay
L42:
	.dbline 314
L43:
	.dbline 314
; 	while(Read_DQ)	 ; 
	sbic 0x10,6
	rjmp L42
	.dbline 315
; 	Out_DQ ;
	sbi 0x11,6
	.dbline 316
; 	Hign_DQ;
	sbi 0x12,6
	.dbline 317
; 	DS1820_delay(300);	
	ldi R16,300
	ldi R17,1
	xcall _DS1820_delay
	.dbline -2
L41:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r x 20 c
	.dbend
	.dbfunc e ReadOneChar _ReadOneChar fc
;            dat -> R20
;              i -> R22
	.even
_ReadOneChar::
	xcall push_gset2
	.dbline -1
	.dbline 321
; }
; //---------------------------------DS18B20读函数--------------------------------
; char ReadOneChar(void)
; {
	.dbline 323
;     char i;
; 	char dat = 0;
	clr R20
	.dbline 325
; 	
; 	for(i=8;i>0;i--)
	ldi R22,8
	xjmp L49
L46:
	.dbline 326
; 	{
	.dbline 327
; 	    Out_DQ;    //配置输出
	sbi 0x11,6
	.dbline 328
; 	    Low_DQ;   //置低电平
	cbi 0x12,6
	.dbline 329
; 		dat >>= 1;
	lsr R20
	.dbline 330
; 		Hign_DQ; //置高电平
	sbi 0x12,6
	.dbline 331
; 		In_DQ;  //设置输入
	cbi 0x11,6
	.dbline 332
; 		if(Read_DQ)//读取电平
	sbis 0x10,6
	rjmp L50
	.dbline 333
;         {
	.dbline 334
; 		dat |= 0x80;
	ori R20,128
	.dbline 335
;         }
L50:
	.dbline 336
	sbi 0x11,6
	.dbline 337
	ldi R16,50
	ldi R17,0
	xcall _DS1820_delay
	.dbline 338
L47:
	.dbline 325
	dec R22
L49:
	.dbline 325
	ldi R24,0
	cp R24,R22
	brlo L46
	.dbline 339
; 		Out_DQ;//配置输出
;         DS1820_delay(50);
; 	}
; 	return(dat);
	mov R16,R20
	.dbline -2
L45:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r dat 20 c
	.dbsym r i 22 c
	.dbend
	.dbfunc e WriteOneChar _WriteOneChar fV
;              i -> R20
;            dat -> R22
	.even
_WriteOneChar::
	xcall push_gset2
	mov R22,R16
	.dbline -1
	.dbline 343
; }
; //------------------------------DS18B20写函数-----------------------------------
; void WriteOneChar(char dat)
; {
	.dbline 345
;     char i;
; 	Out_DQ;//配置输出
	sbi 0x11,6
	.dbline 346
; 	for(i=8;i>0;i--)
	ldi R20,8
	xjmp L56
L53:
	.dbline 347
; 	{
	.dbline 348
; 	    Low_DQ;//置低电平
	cbi 0x12,6
	.dbline 349
; 		if(dat&0x01)//写电平
	sbrs R22,0
	rjmp L57
	.dbline 350
;         {
	.dbline 351
;         Hign_DQ;//置高电平
	sbi 0x12,6
	.dbline 352
;         }
	xjmp L58
L57:
	.dbline 354
;         else
;         {
	.dbline 355
;          Low_DQ;//置低电平
	cbi 0x12,6
	.dbline 356
;         }
L58:
	.dbline 357
	ldi R16,40
	ldi R17,0
	xcall _DS1820_delay
	.dbline 358
	sbi 0x12,6
	.dbline 359
	lsr R22
	.dbline 360
L54:
	.dbline 346
	dec R20
L56:
	.dbline 346
	ldi R24,0
	cp R24,R20
	brlo L53
	.dbline 361
; 		DS1820_delay(40);
; 		Hign_DQ;//置高电平
; 		dat >>= 1;
; 	}
; 	DS1820_delay(8);
	ldi R16,8
	ldi R17,0
	xcall _DS1820_delay
	.dbline -2
L52:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbsym r dat 22 c
	.dbend
	.dbfunc e ReadTemperature _ReadTemperature fV
	.even
_ReadTemperature::
	.dbline -1
	.dbline 365
; }
; //------------------------------------读取温度------------------------------------
; void ReadTemperature(void)
; {		
	.dbline 366
; 	Init_DS18B20();
	xcall _Init_DS18B20
	.dbline 367
; 	WriteOneChar(0xCC); 			// 跳过读序号列号的操作
	ldi R16,204
	xcall _WriteOneChar
	.dbline 368
; 	WriteOneChar(0x44); 			// 启动温度转换
	ldi R16,68
	xcall _WriteOneChar
	.dbline 371
; 	
; 	
; 	Init_DS18B20();
	xcall _Init_DS18B20
	.dbline 372
; 	WriteOneChar(0xCC); 			//跳过读序号列号的操作
	ldi R16,204
	xcall _WriteOneChar
	.dbline 373
; 	WriteOneChar(0xBE); 			//读取温度寄存器等（共可读9个寄存器） 前两个就是温度
	ldi R16,190
	xcall _WriteOneChar
	.dbline 375
; 
; 	temp_data[0]= ReadOneChar();   		//读取温度值低位LSB
	xcall _ReadOneChar
	sts _temp_data,R16
	.dbline 376
; 	temp_data[1]= ReadOneChar();   //读取温度值高位MSB
	xcall _ReadOneChar
	sts _temp_data+1,R16
	.dbline -2
L59:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e work_temp _work_temp fV
	.area func_lit(rom, con, rel)
L96:
	.word `L95
	.word `L94
	.word `L93
	.word `L92
	.word `L91
	.word `L90
	.word `L89
	.word `L88
	.word `L87
	.word `L86
	.word `L85
	.word `L84
	.word `L83
	.word `L82
	.word `L81
	.word `L80
	.area text(rom, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
;              n -> R20
	.even
_work_temp::
	xcall push_gset2
	.dbline -1
	.dbline 386
; 	
; }
; //-----------------------------------BCD码温度处理------------------------------
; //dispaly[0]十位
; //dispaly[1]个位
; //dispaly[2]小数位
; //dispaly[3]临界标志位
; //------------------------------------------------------------------------------
; void work_temp()
; {
	.dbline 387
; 	char n=0;
	clr R20
	.dbline 388
; 	if(temp_data[1]>127)
	ldi R24,127
	lds R2,_temp_data+1
	cp R24,R2
	brsh L62
	.dbline 389
; 	{
	.dbline 390
; 	temp_data[1]=(256-temp_data[1]);
	clr R3
	ldi R24,256
	ldi R25,1
	sub R24,R2
	sbc R25,R3
	sts _temp_data+1,R24
	.dbline 391
; 	temp_data[0]=(256-temp_data[0]);
	lds R2,_temp_data
	clr R3
	ldi R24,256
	ldi R25,1
	sub R24,R2
	sbc R25,R3
	sts _temp_data,R24
	.dbline 392
; 	n=1;
	ldi R20,1
	.dbline 393
; 	}
L62:
	.dbline 395
; //------------------------------------------------------------------------------
; 	dispaly[6]=((temp_data[0]&0xf0)>>4)|((temp_data[1]&0x0f)<<4);
	lds R24,_temp_data+1
	andi R24,15
	andi R24,#0x0F
	swap R24
	lds R25,_temp_data
	andi R25,240
	swap R25
	andi R25,#0x0F
	or R25,R24
	sts _dispaly+6,R25
	.dbline 396
; 	dispaly[5]=dispaly[6]/100;				//百位
	ldi R17,100
	mov R16,R25
	xcall div8u
	sts _dispaly+5,R16
	.dbline 397
; 	dispaly[4]=dispaly[6]%100;				//
	ldi R17,100
	lds R16,_dispaly+6
	xcall mod8u
	sts _dispaly+4,R16
	.dbline 398
; 	dispaly[2]=dispaly[4]/10;               //十位
	ldi R17,10
	xcall div8u
	sts _dispaly+2,R16
	.dbline 399
; 	dispaly[1]=dispaly[4]%10;			    //个位
	ldi R17,10
	lds R16,_dispaly+4
	xcall mod8u
	sts _dispaly+1,R16
	.dbline 401
; 	
; 	switch	(temp_data[0]&0x0f)
	lds R22,_temp_data
	clr R23
	andi R22,15
	andi R23,0
	cpi R22,0
	ldi R30,0
	cpc R23,R30
	brge X2
	xjmp L78
X2:
	ldi R24,15
	ldi R25,0
	cp R24,R22
	cpc R25,R23
	brge X3
	xjmp L78
X3:
	ldi R16,2
	ldi R17,0
	movw R18,R22
	xcall empy16s
	movw R30,R16
	ldi R24,<L96
	ldi R25,>L96
	add R30,R24
	adc R31,R25
	lpm R0,Z+
	lpm R1,Z
	movw R30,R0
	ijmp
X1:
	.dbline 402
; 	{
L80:
	.dbline 403
; 	case 0x0f:dispaly[0]=9;break;
	ldi R24,9
	sts _dispaly,R24
	.dbline 403
	xjmp L78
L81:
	.dbline 404
; 	case 0x0e:dispaly[0]=9;break;
	ldi R24,9
	sts _dispaly,R24
	.dbline 404
	xjmp L78
L82:
	.dbline 405
; 	case 0x0d:dispaly[0]=8;break;
	ldi R24,8
	sts _dispaly,R24
	.dbline 405
	xjmp L78
L83:
	.dbline 406
; 	case 0x0c:dispaly[0]=8;break;
	ldi R24,8
	sts _dispaly,R24
	.dbline 406
	xjmp L78
L84:
	.dbline 407
; 	case 0x0b:dispaly[0]=7;break;
	ldi R24,7
	sts _dispaly,R24
	.dbline 407
	xjmp L78
L85:
	.dbline 408
; 	case 0x0a:dispaly[0]=6;break;
	ldi R24,6
	sts _dispaly,R24
	.dbline 408
	xjmp L78
L86:
	.dbline 409
; 	case 0x09:dispaly[0]=6;break;
	ldi R24,6
	sts _dispaly,R24
	.dbline 409
	xjmp L78
L87:
	.dbline 410
; 	case 0x08:dispaly[0]=5;break;
	ldi R24,5
	sts _dispaly,R24
	.dbline 410
	xjmp L78
L88:
	.dbline 411
; 	case 0x07:dispaly[0]=4;break;
	ldi R24,4
	sts _dispaly,R24
	.dbline 411
	xjmp L78
L89:
	.dbline 412
; 	case 0x06:dispaly[0]=4;break;
	ldi R24,4
	sts _dispaly,R24
	.dbline 412
	xjmp L78
L90:
	.dbline 413
; 	case 0x05:dispaly[0]=3;break;
	ldi R24,3
	sts _dispaly,R24
	.dbline 413
	xjmp L78
L91:
	.dbline 414
; 	case 0x04:dispaly[0]=3;break;
	ldi R24,3
	sts _dispaly,R24
	.dbline 414
	xjmp L78
L92:
	.dbline 415
; 	case 0x03:dispaly[0]=2;break;
	ldi R24,2
	sts _dispaly,R24
	.dbline 415
	xjmp L78
L93:
	.dbline 416
; 	case 0x02:dispaly[0]=1;break;
	ldi R24,1
	sts _dispaly,R24
	.dbline 416
	xjmp L78
L94:
	.dbline 417
; 	case 0x01:dispaly[0]=1;break;
	ldi R24,1
	sts _dispaly,R24
	.dbline 417
	xjmp L78
L95:
	.dbline 418
; 	case 0x00:dispaly[0]=1;break;
	ldi R24,1
	sts _dispaly,R24
	.dbline 418
	.dbline 419
; 	default:break;
L78:
	.dbline 421
; 	}
; 		if(n)								//温度正负区分
	tst R20
	breq L97
	.dbline 422
; 	{
	.dbline 423
; 	dispaly[3]=0x11;						//零下
	ldi R24,17
	sts _dispaly+3,R24
	.dbline 424
; 	}
	xjmp L98
L97:
	.dbline 426
	.dbline 427
	ldi R24,34
	sts _dispaly+3,R24
	.dbline 428
L98:
	.dbline -2
L61:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r n 20 c
	.dbend
	.dbfunc e dis_zhuye _dis_zhuye fV
	.even
_dis_zhuye::
	.dbline -1
	.dbline 432
; 	else
; 	{
; 	dispaly[3]=0x22;				  	//零上
; 	}
; }
; //------------------------------------------------------------------------------
; void  dis_zhuye()
; {
	.dbline 433
; 	 PORTC=seg[dispaly[2]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_dispaly+2
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 434
; 	 Hign_Display4;
	sbi 0x1b,4
	.dbline 434
	.dbline 435
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 435
	.dbline 436
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 436
	.dbline 437
; 	 Low_Display1;
	cbi 0x1b,1
	.dbline 437
	.dbline 438
; 	Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 439
; 	 Hign_Display1;
	sbi 0x1b,1
	.dbline 439
	.dbline 441
; //------------------------------------------------------------------------------
; 	 PORTC=seg1[dispaly[1]];
	ldi R24,<_seg1
	ldi R25,>_seg1
	lds R30,_dispaly+1
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 442
; 	 Low_Display2;
	cbi 0x1b,2
	.dbline 442
	.dbline 443
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 444
; 	 Hign_Display2;
	sbi 0x1b,2
	.dbline 444
	.dbline 446
; //------------------------------------------------ ---------------------------
; 	 PORTC=seg[dispaly[0]];
	ldi R24,<_seg
	ldi R25,>_seg
	lds R30,_dispaly
	clr R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	out 0x15,R2
	.dbline 447
; 	 Low_Display3;
	cbi 0x1b,3
	.dbline 447
	.dbline 448
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 449
; 	 Hign_Display3;
	sbi 0x1b,3
	.dbline 449
	.dbline 451
; //----------------------------------------------------------------------------- 
; 	 PORTC=0xc6;
	ldi R24,198
	out 0x15,R24
	.dbline 452
; 	 Low_Display4;
	cbi 0x1b,4
	.dbline 452
	.dbline 453
; 	 Delay(80);
	ldi R16,80
	ldi R17,0
	xcall _Delay
	.dbline 454
; 	 Hign_Display4;	 
	sbi 0x1b,4
	.dbline 454
	.dbline -2
L101:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e main _main fI
	.even
_main::
	.dbline -1
	.dbline 457
; }
; main()
; {
	.dbline 458
;  	DDRB=0xe4;
	ldi R24,228
	out 0x17,R24
	.dbline 459
; 	DDRC=0xff;
	ldi R24,255
	out 0x14,R24
	.dbline 460
; 	DDRA=0x1e;
	ldi R24,30
	out 0x1a,R24
	.dbline 461
; 	PORTA=0x00;
	clr R2
	out 0x1b,R2
	.dbline 462
; 	PORTC=0xbf;
	ldi R24,191
	out 0x15,R24
	.dbline 463
; 	Init_DS18B20();
	xcall _Init_DS18B20
	.dbline 464
;     init_NRF24L01() ;
	xcall _init_NRF24L01
	xjmp L106
L105:
	.dbline 467
	.dbline 468
	xcall _ReadTemperature
	.dbline 469
	xcall _work_temp
	.dbline 470
	xcall _dis_zhuye
	.dbline 471
	ldi R16,<_dispaly
	ldi R17,>_dispaly
	xcall _nRF24L01_TxPacket
	.dbline 472
	ldi R18,255
	ldi R16,39
	xcall _SPI_RW_Reg
	.dbline 473
L106:
	.dbline 466
	xjmp L105
X4:
	.dbline -2
L104:
	.dbline 0 ; func end
	ret
	.dbend
	.area bss(ram, con, rel)
	.dbfile F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\发送\fasong.c
_sta::
	.blkb 1
	.dbsym e sta _sta c
_dispaly::
	.blkb 7
	.dbsym e dispaly _dispaly A[7:7]c
