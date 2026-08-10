// GCC for SUNPLUS u'nSP version 1.0.23
// Command: C:\PROGRA~1\Sunplus\UNSPID~1.2D\toolchain\cc1.exe C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\cc8Qaaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -gstabs -o .\Debug/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×ÀÃæ/SPI_nRF24L01_TX/SPI_nRF24L01_TX/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "C:/Documents and Settings/Administrator/×/300Ã/346/SPI_nRF24L01_TX/SPI_nRF24L01_TX/main.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.code
Ltext0:
.debug
	.dw '.stabs "int:t1=r1;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "char:t2=r2;0;127;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long int:t3=r3;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned int:t4=r4;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long unsigned int:t5=r5;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long int:t6=r6;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long unsigned int:t7=r7;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short int:t8=r8;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short unsigned int:t9=r9;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "signed char:t10=r10;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned char:t11=r11;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "float:t12=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "double:t13=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long double:t14=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex int:t15=s2real:1,0,16;imag:1,16,16;;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex float:t16=r16;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex double:t17=r17;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex long double:t18=r18;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "void:t19=19",128,0,0,0',0x0d,0x0a
.CODE
.public _Buffer
.iram
_Buffer:
	.str '8', 0
	// length = 2
	.dw 3 dup(0)
.debug
	.dw '.stabs "Buffer:G20=ar1;0;4;11",32,0,0,',0,0,offset _Buffer,seg _Buffer,0x0d,0x0a
.CODE
.public _TX_ADDRESS
.text
_TX_ADDRESS:
	.dw 52
	.dw 67
	.dw 16
	.dw 16
	.dw 1
.debug
	.dw '.stabs "TX_ADDRESS:G21=ar1;0;4;11",32,0,0,',0,0,offset _TX_ADDRESS,seg _TX_ADDRESS,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "SPI_ReceiveData:G11",32,0,0,',0,0,offset _SPI_ReceiveData,seg _SPI_ReceiveData,0x0d,0x0a
.CODE
.debug
	.dw '.stabs "RX:G22=ar1;0;15;11",32,0,0,',0,0,offset _RX,seg _RX,0x0d,0x0a
.CODE
.public _Tx_Buffer
.iram
_Tx_Buffer:
	.str 'a', 'b', 'c', 0
	// length = 4
	.dw 1 dup(0)
.debug
	.dw '.stabs "Tx_Buffer:G20",32,0,0,',0,0,offset _Tx_Buffer,seg _Tx_Buffer,0x0d,0x0a
.CODE
.code
.debug
	.dw '.stabs "Initial_IOB:F19",36,0,0,',0,0,offset _Initial_IOB,seg _Initial_IOB,0x0d,0x0a
.CODE
.public _Initial_IOB
_Initial_IOB:	.proc
.debug
	.dw '.stabn 0x44,0,74,',0,0
	.dd LM1-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,75,',0,0
	.dd LM2-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM2:
	R2=(-49)	// QImode move
	[28679]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,76,',0,0
	.dd LM3-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM3:
	R2=(-49)	// QImode move
	[28680]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,77,',0,0
	.dd LM4-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM4:
	R2=0	// QImode move
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM5-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM5:
.debug
	.dw '.stabn 0x44,0,79,',0,0
	.dd LM6-_Initial_IOB
	.dw 0x0d,0x0a
.code
LM6:
L2:

	POP BP from [SP]
	RETF
	.endp	// end of Initial_IOB

.debug
	.dw '.stabf ',0,0
	.dd LME1-_Initial_IOB
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "delay1us:F19",36,0,0,',0,0,offset _delay1us,seg _delay1us,0x0d,0x0a
.CODE
.public _delay1us
_delay1us:	.proc
.debug
	.dw '.stabn 0x44,0,81,',0,0
	.dd LM7-_delay1us
	.dw 0x0d,0x0a
.code
LM7:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,82,',0,0
	.dd LM8-_delay1us
	.dw 0x0d,0x0a
.code
LM8:
L4:
	R2=R1	// QImode move
	R3=[R2]	// QImode move
	R2=R3+(-1)
	R3=R2	// QImode move
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	CMP R3,0	// QImode test
	NSJNZ L6	//QImode NE
	PC=L5	// jump
L6:
.debug
	.dw '.stabn 0x44,0,83,',0,0
	.dd LM9-_delay1us
	.dw 0x0d,0x0a
.code
LM9:
	R2=1	// QImode move
	[28690]=R2	// QImode move
	PC=L4	// jump
L5:
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM10-_delay1us
	.dw 0x0d,0x0a
.code
LM10:
.debug
	.dw '.stabn 0x44,0,84,',0,0
	.dd LM11-_delay1us
	.dw 0x0d,0x0a
.code
LM11:
L3:

	POP BP from [SP]
	RETF
	.endp	// end of delay1us

.debug
	.dw '.stabs "t:p11",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME2-_delay1us
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "SPI_RW:F11",36,0,0,',0,0,offset _SPI_RW,seg _SPI_RW,0x0d,0x0a
.CODE
.public _SPI_RW
_SPI_RW:	.proc
.debug
	.dw '.stabn 0x44,0,86,',0,0
	.dd LM12-_SPI_RW
	.dw 0x0d,0x0a
.code
LM12:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R2=BP+4
LBB2:
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM13-_SPI_RW
	.dw 0x0d,0x0a
.code
LM13:
	R1=0	// QImode move
	[BP]=R1	// QImode move
L9:
	R1=[BP]	// QImode move
	CMP R1,7	// QImode compare
	NSJNA L12	//QImode LEU
	PC=L10	// jump
L12:
.debug
	.dw '.stabn 0x44,0,91,',0,0
	.dd LM14-_SPI_RW
	.dw 0x0d,0x0a
.code
LM14:
	R3=R2	// QImode move
	R3=[R3]
	R1=R3&128
	CMP R1,0	// QImode test
	NSJZ L13	//QImode EQ
.debug
	.dw '.stabn 0x44,0,92,',0,0
	.dd LM15-_SPI_RW
	.dw 0x0d,0x0a
.code
LM15:
	R1=[28677]	// QImode move
	R3=R1|8
	[28677]=R3	// QImode move
	PC=L14	// jump
L13:
.debug
	.dw '.stabn 0x44,0,94,',0,0
	.dd LM16-_SPI_RW
	.dw 0x0d,0x0a
.code
LM16:
	R1=[28677]	// QImode move
	R3=R1&(-9)
	[28677]=R3	// QImode move
L14:
.debug
	.dw '.stabn 0x44,0,95,',0,0
	.dd LM17-_SPI_RW
	.dw 0x0d,0x0a
.code
LM17:
	R4=R2	// QImode move
	R1=[R4]	// QImode move
	R3=R1 lsl 1
	R1=R2	// QImode move
	[R1]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,96,',0,0
	.dd LM18-_SPI_RW
	.dw 0x0d,0x0a
.code
LM18:
	R1=[28677]	// QImode move
	R3=R1|4
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,97,',0,0
	.dd LM19-_SPI_RW
	.dw 0x0d,0x0a
.code
LM19:
	R3=[28677]	// QImode move
	R1=R3&16
	CMP R1,0	// QImode test
	NSJZ L15	//QImode EQ
	R3=R2	// QImode move
	R4=[R3]
	R4=R4|1
	[R3]=R4	// QImode move
L15:
.debug
	.dw '.stabn 0x44,0,98,',0,0
	.dd LM20-_SPI_RW
	.dw 0x0d,0x0a
.code
LM20:
	R1=[28677]	// QImode move
	R3=R1&(-5)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,89,',0,0
	.dd LM21-_SPI_RW
	.dw 0x0d,0x0a
.code
LM21:
L11:
	R1=[BP]	// QImode move
	R3=R1+1
	[BP]=R3	// QImode move
	PC=L9	// jump
L10:
.debug
	.dw '.stabn 0x44,0,102,',0,0
	.dd LM22-_SPI_RW
	.dw 0x0d,0x0a
.code
LM22:
	R1=R2	// QImode move
	R3=[R1]	// QImode move
	R1=R3	// QImode move
	PC=L8	// jump
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM23-_SPI_RW
	.dw 0x0d,0x0a
.code
LM23:
LBE2:
.debug
	.dw '.stabn 0x44,0,103,',0,0
	.dd LM24-_SPI_RW
	.dw 0x0d,0x0a
.code
LM24:
L8:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of SPI_RW

.debug
	.dw '.stabs "byte:p11",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB2-_SPI_RW
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "bit_ctr:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE2-_SPI_RW
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME3-_SPI_RW
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "SPI_Read:F11",36,0,0,',0,0,offset _SPI_Read,seg _SPI_Read,0x0d,0x0a
.CODE
.public _SPI_Read
_SPI_Read:	.proc
.debug
	.dw '.stabn 0x44,0,105,',0,0
	.dd LM25-_SPI_Read
	.dw 0x0d,0x0a
.code
LM25:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB3:
.debug
	.dw '.stabn 0x44,0,108,',0,0
	.dd LM26-_SPI_Read
	.dw 0x0d,0x0a
.code
LM26:
	R1=[28677]	// QImode move
	R2=R1&(-3)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,109,',0,0
	.dd LM27-_SPI_Read
	.dw 0x0d,0x0a
.code
LM27:
	R2=[BP+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,110,',0,0
	.dd LM28-_SPI_Read
	.dw 0x0d,0x0a
.code
LM28:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,111,',0,0
	.dd LM29-_SPI_Read
	.dw 0x0d,0x0a
.code
LM29:
	R1=[28677]	// QImode move
	R2=R1|2
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,113,',0,0
	.dd LM30-_SPI_Read
	.dw 0x0d,0x0a
.code
LM30:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	PC=L19	// jump
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM31-_SPI_Read
	.dw 0x0d,0x0a
.code
LM31:
LBE3:
.debug
	.dw '.stabn 0x44,0,114,',0,0
	.dd LM32-_SPI_Read
	.dw 0x0d,0x0a
.code
LM32:
L19:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of SPI_Read

.debug
	.dw '.stabs "reg:p11",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB3-_SPI_Read
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "reg_val:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE3-_SPI_Read
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME4-_SPI_Read
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "SPI_RW_Reg:F11",36,0,0,',0,0,offset _SPI_RW_Reg,seg _SPI_RW_Reg,0x0d,0x0a
.CODE
.public _SPI_RW_Reg
_SPI_RW_Reg:	.proc
.debug
	.dw '.stabn 0x44,0,118,',0,0
	.dd LM33-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM33:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB4:
.debug
	.dw '.stabn 0x44,0,120,',0,0
	.dd LM34-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM34:
	R1=[28677]	// QImode move
	R2=R1&(-3)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,121,',0,0
	.dd LM35-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM35:
	R2=[BP+1]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,122,',0,0
	.dd LM36-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM36:
	R1=[BP+1]	// QImode move
	R3=[BP+1]	// QImode move
	R2=R3+1
	R3=R2	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,123,',0,0
	.dd LM37-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM37:
	R1=[28677]	// QImode move
	R2=R1|2
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,124,',0,0
	.dd LM38-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM38:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	PC=L20	// jump
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM39-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM39:
LBE4:
.debug
	.dw '.stabn 0x44,0,125,',0,0
	.dd LM40-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LM40:
L20:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of SPI_RW_Reg

.debug
	.dw '.stabs "reg:p11",160,0,0,5',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "value:p11",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB4-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "status:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE4-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME5-_SPI_RW_Reg
	.dw 0x0d,0x0a
.code
LME5:
.code
.debug
	.dw '.stabs "SPI_Read_Buf:F11",36,0,0,',0,0,offset _SPI_Read_Buf,seg _SPI_Read_Buf,0x0d,0x0a
.CODE
.public _SPI_Read_Buf
_SPI_Read_Buf:	.proc
.debug
	.dw '.stabn 0x44,0,128,',0,0
	.dd LM41-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM41:
	// total=6, vars=6
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,6',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=6
	BP=SP+1

	R1=BP+9
	[BP+2]=R1	// QImode move
LBB5:
.debug
	.dw '.stabn 0x44,0,130,',0,0
	.dd LM42-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM42:
	R1=[28677]	// QImode move
	R2=R1&(-3)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,131,',0,0
	.dd LM43-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM43:
	R2=[BP+2]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM44-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM44:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L22:
	R2=BP	// QImode move
	R1=BP+1
	R2=[BP+2]	// QImode move
	R4=[BP+2]	// QImode move
	R3=R4+2
	R2=R1	// QImode move
	R1=[R2]	// QImode move
	R4=R3	// QImode move
	CMP R1,[R4]	// QImode compare
	NSJB L25	//QImode LTU
	PC=L23	// jump
L25:
.debug
	.dw '.stabn 0x44,0,133,',0,0
	.dd LM45-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM45:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
	R2=BP	// QImode move
	R2=BP+1
	[BP+3]=R2	// QImode move
	R2=[BP+3]	// QImode move
	R3=[R2]
	R4=0
	R2=[BP+2]	// QImode move
	R2=[BP+2]	// QImode move
	R2=R2+1
	[BP+5]=R2	// QImode move
	R2=[BP+5]	// QImode move
	R2=[R2]	// QImode move
	[BP+4]=R2	// QImode move
	R2=[BP+4]	// QImode move
	R2 = R2 + R3	//addqi3
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,132,',0,0
	.dd LM46-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM46:
L24:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	PC=L22	// jump
L23:
.debug
	.dw '.stabn 0x44,0,134,',0,0
	.dd LM47-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM47:
	R1=[28677]	// QImode move
	R2=R1|2
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,135,',0,0
	.dd LM48-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM48:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	PC=L21	// jump
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM49-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM49:
LBE5:
.debug
	.dw '.stabn 0x44,0,136,',0,0
	.dd LM50-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LM50:
L21:

	SP+=6
	POP BP from [SP]
	RETF
	.endp	// end of SPI_Read_Buf

.debug
	.dw '.stabs "reg:p11",160,0,0,9',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "pBuf:p23=*11",160,0,0,10',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "bytes:p11",160,0,0,11',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB5-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "status:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "byte_ctr:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE5-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME6-_SPI_Read_Buf
	.dw 0x0d,0x0a
.code
LME6:
.code
.debug
	.dw '.stabs "SPI_Write_Buf:F11",36,0,0,',0,0,offset _SPI_Write_Buf,seg _SPI_Write_Buf,0x0d,0x0a
.CODE
.public _SPI_Write_Buf
_SPI_Write_Buf:	.proc
.debug
	.dw '.stabn 0x44,0,139,',0,0
	.dd LM51-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM51:
	// total=3, vars=3
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,3',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=3
	BP=SP+1

	R1=BP+6
	[BP+2]=R1	// QImode move
LBB6:
.debug
	.dw '.stabn 0x44,0,141,',0,0
	.dd LM52-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM52:
	R1=[28677]	// QImode move
	R2=R1&(-3)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,142,',0,0
	.dd LM53-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM53:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,143,',0,0
	.dd LM54-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM54:
	R2=[BP+2]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,144,',0,0
	.dd LM55-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM55:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L28:
	R2=BP	// QImode move
	R1=BP+1
	R2=[BP+2]	// QImode move
	R4=[BP+2]	// QImode move
	R3=R4+2
	R2=R1	// QImode move
	R1=[R2]	// QImode move
	R4=R3	// QImode move
	CMP R1,[R4]	// QImode compare
	NSJB L31	//QImode LTU
	PC=L29	// jump
L31:
.debug
	.dw '.stabn 0x44,0,145,',0,0
	.dd LM56-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM56:
	R2=[BP+2]	// QImode move
	R2=[BP+2]	// QImode move
	R1=R2+1
	R3=R1	// QImode move
	R2=[R3]	// QImode move
	R4=R2	// QImode move
	R3=[R4]	// QImode move
	[SP--]=R3	// QImode move
	R2=R2+1
	R3=R1	// QImode move
	[R3]=R2	// QImode move
	CALL _SPI_RW	// call with return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,144,',0,0
	.dd LM57-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM57:
L30:
	R1=BP	// QImode move
	R2=BP+1
	R3=BP	// QImode move
	R1=BP+1
	R2=BP	// QImode move
	R3=BP+1
	R4=R3	// QImode move
	R2=[R4]	// QImode move
	R3=R2+1
	R2=R1	// QImode move
	[R2]=R3	// QImode move
	PC=L28	// jump
L29:
.debug
	.dw '.stabn 0x44,0,146,',0,0
	.dd LM58-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM58:
	R1=[28677]	// QImode move
	R2=R1|2
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,147,',0,0
	.dd LM59-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM59:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,148,',0,0
	.dd LM60-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM60:
	R2=[BP]	// QImode move
	R1=R2	// QImode move
	PC=L27	// jump
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM61-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM61:
LBE6:
.debug
	.dw '.stabn 0x44,0,149,',0,0
	.dd LM62-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LM62:
L27:

	SP+=3
	POP BP from [SP]
	RETF
	.endp	// end of SPI_Write_Buf

.debug
	.dw '.stabs "reg:p11",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "pBuf:p23",160,0,0,7',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "bytes:p11",160,0,0,8',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB6-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "status:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "byte_ctr:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE6-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME7-_SPI_Write_Buf
	.dw 0x0d,0x0a
.code
LME7:
.code
.debug
	.dw '.stabs "nRF24L01_RxPacket:F11",36,0,0,',0,0,offset _nRF24L01_RxPacket,seg _nRF24L01_RxPacket,0x0d,0x0a
.CODE
.public _nRF24L01_RxPacket
_nRF24L01_RxPacket:	.proc
.debug
	.dw '.stabn 0x44,0,152,',0,0
	.dd LM63-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM63:
	// total=3, vars=3
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,3',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=3
	BP=SP+1

	R1=BP+6
	[BP+2]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,153,',0,0
	.dd LM64-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM64:
LBB7:
	R1=BP	// QImode move
	R2=BP+1
	R1=0	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,154,',0,0
	.dd LM65-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM65:
	R1=15	// QImode move
	[SP--]=R1	// QImode move
	R1=32	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,155,',0,0
	.dd LM66-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM66:
	R1=[28677]	// QImode move
	R2=R1|1
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,156,',0,0
	.dd LM67-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM67:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,158,',0,0
	.dd LM68-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM68:
	R1=7	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Read	// call with return value
	SP = SP + 1	//SP
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,159,',0,0
	.dd LM69-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM69:
	R2=[BP]	// QImode move
	R1=R2&64
	CMP R1,0	// QImode test
	NSJZ L34	//QImode EQ
.debug
	.dw '.stabn 0x44,0,161,',0,0
	.dd LM70-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM70:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,162,',0,0
	.dd LM71-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM71:
	R1=160	// QImode move
	[SP--]=R1	// QImode move
	R3=[BP+2]	// QImode move
	R1=[R3]	// QImode move
	[SP--]=R1	// QImode move
	R1=97	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Read_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,163,',0,0
	.dd LM72-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM72:
	R1=BP	// QImode move
	R2=BP+1
	R1=1	// QImode move
	R3=R2	// QImode move
	[R3]=R1	// QImode move
L34:
.debug
	.dw '.stabn 0x44,0,165,',0,0
	.dd LM73-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM73:
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	R1=39	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,166,',0,0
	.dd LM74-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM74:
	R1=BP	// QImode move
	R2=BP+1
	R1=R2	// QImode move
	R3=[R1]	// QImode move
	R1=R3	// QImode move
	PC=L33	// jump
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM75-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM75:
LBE7:
.debug
	.dw '.stabn 0x44,0,168,',0,0
	.dd LM76-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LM76:
L33:

	SP+=3
	POP BP from [SP]
	RETF
	.endp	// end of nRF24L01_RxPacket

.debug
	.dw '.stabs "rx_buf:p23",160,0,0,6',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB7-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "sta:11",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "revale:11",128,0,0,1',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE7-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME8-_nRF24L01_RxPacket
	.dw 0x0d,0x0a
.code
LME8:
.code
.debug
	.dw '.stabs "nRF24L01_TxPacket:F19",36,0,0,',0,0,offset _nRF24L01_TxPacket,seg _nRF24L01_TxPacket,0x0d,0x0a
.CODE
.public _nRF24L01_TxPacket
_nRF24L01_TxPacket:	.proc
.debug
	.dw '.stabn 0x44,0,171,',0,0
	.dd LM77-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM77:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,172,',0,0
	.dd LM78-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM78:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,173,',0,0
	.dd LM79-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM79:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,174,',0,0
	.dd LM80-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM80:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=42	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,175,',0,0
	.dd LM81-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM81:
	R1=20	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	R1=[R2]	// QImode move
	[SP--]=R1	// QImode move
	R1=160	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,176,',0,0
	.dd LM82-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM82:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	R1=32	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,177,',0,0
	.dd LM83-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM83:
	R1=[28677]	// QImode move
	R2=R1|1
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,178,',0,0
	.dd LM84-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM84:
	R1=10	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,179,',0,0
	.dd LM85-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM85:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM86-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM86:
.debug
	.dw '.stabn 0x44,0,180,',0,0
	.dd LM87-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LM87:
L36:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of nRF24L01_TxPacket

.debug
	.dw '.stabs "tx_buf:p23",160,0,0,4',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME9-_nRF24L01_TxPacket
	.dw 0x0d,0x0a
.code
LME9:
.code
.debug
	.dw '.stabs "RX_Mode:F19",36,0,0,',0,0,offset _RX_Mode,seg _RX_Mode,0x0d,0x0a
.CODE
.public _RX_Mode
_RX_Mode:	.proc
.debug
	.dw '.stabn 0x44,0,182,',0,0
	.dd LM88-_RX_Mode
	.dw 0x0d,0x0a
.code
LM88:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,183,',0,0
	.dd LM89-_RX_Mode
	.dw 0x0d,0x0a
.code
LM89:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,184,',0,0
	.dd LM90-_RX_Mode
	.dw 0x0d,0x0a
.code
LM90:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,185,',0,0
	.dd LM91-_RX_Mode
	.dw 0x0d,0x0a
.code
LM91:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,186,',0,0
	.dd LM92-_RX_Mode
	.dw 0x0d,0x0a
.code
LM92:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=42	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,187,',0,0
	.dd LM93-_RX_Mode
	.dw 0x0d,0x0a
.code
LM93:
	R1=20	// QImode move
	[SP--]=R1	// QImode move
	R1=_Buffer	// QImode move
	[SP--]=R1	// QImode move
	R1=160	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,189,',0,0
	.dd LM94-_RX_Mode
	.dw 0x0d,0x0a
.code
LM94:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=33	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,190,',0,0
	.dd LM95-_RX_Mode
	.dw 0x0d,0x0a
.code
LM95:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=34	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,191,',0,0
	.dd LM96-_RX_Mode
	.dw 0x0d,0x0a
.code
LM96:
	R1=26	// QImode move
	[SP--]=R1	// QImode move
	R1=36	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,192,',0,0
	.dd LM97-_RX_Mode
	.dw 0x0d,0x0a
.code
LM97:
	R1=40	// QImode move
	[SP--]=R1	// QImode move
	R1=37	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,193,',0,0
	.dd LM98-_RX_Mode
	.dw 0x0d,0x0a
.code
LM98:
	R1=7	// QImode move
	[SP--]=R1	// QImode move
	R1=38	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,194,',0,0
	.dd LM99-_RX_Mode
	.dw 0x0d,0x0a
.code
LM99:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	R1=32	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,197,',0,0
	.dd LM100-_RX_Mode
	.dw 0x0d,0x0a
.code
LM100:
	R1=[28677]	// QImode move
	R2=R1|1
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,198,',0,0
	.dd LM101-_RX_Mode
	.dw 0x0d,0x0a
.code
LM101:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM102-_RX_Mode
	.dw 0x0d,0x0a
.code
LM102:
.debug
	.dw '.stabn 0x44,0,201,',0,0
	.dd LM103-_RX_Mode
	.dw 0x0d,0x0a
.code
LM103:
L37:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of RX_Mode

.debug
	.dw '.stabf ',0,0
	.dd LME10-_RX_Mode
	.dw 0x0d,0x0a
.code
LME10:
.code
.debug
	.dw '.stabs "TX_Mode:F19",36,0,0,',0,0,offset _TX_Mode,seg _TX_Mode,0x0d,0x0a
.CODE
.public _TX_Mode
_TX_Mode:	.proc
.debug
	.dw '.stabn 0x44,0,203,',0,0
	.dd LM104-_TX_Mode
	.dw 0x0d,0x0a
.code
LM104:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,204,',0,0
	.dd LM105-_TX_Mode
	.dw 0x0d,0x0a
.code
LM105:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,205,',0,0
	.dd LM106-_TX_Mode
	.dw 0x0d,0x0a
.code
LM106:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,206,',0,0
	.dd LM107-_TX_Mode
	.dw 0x0d,0x0a
.code
LM107:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=48	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,207,',0,0
	.dd LM108-_TX_Mode
	.dw 0x0d,0x0a
.code
LM108:
	R1=5	// QImode move
	[SP--]=R1	// QImode move
	R1=_TX_ADDRESS	// QImode move
	[SP--]=R1	// QImode move
	R1=42	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,208,',0,0
	.dd LM109-_TX_Mode
	.dw 0x0d,0x0a
.code
LM109:
	R1=20	// QImode move
	[SP--]=R1	// QImode move
	R1=_Tx_Buffer	// QImode move
	[SP--]=R1	// QImode move
	R1=160	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_Write_Buf	// call with return value
	SP = SP + 3	//SP
.debug
	.dw '.stabn 0x44,0,210,',0,0
	.dd LM110-_TX_Mode
	.dw 0x0d,0x0a
.code
LM110:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=33	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,211,',0,0
	.dd LM111-_TX_Mode
	.dw 0x0d,0x0a
.code
LM111:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=34	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,212,',0,0
	.dd LM112-_TX_Mode
	.dw 0x0d,0x0a
.code
LM112:
	R1=26	// QImode move
	[SP--]=R1	// QImode move
	R1=36	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,213,',0,0
	.dd LM113-_TX_Mode
	.dw 0x0d,0x0a
.code
LM113:
	R1=40	// QImode move
	[SP--]=R1	// QImode move
	R1=37	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,214,',0,0
	.dd LM114-_TX_Mode
	.dw 0x0d,0x0a
.code
LM114:
	R1=7	// QImode move
	[SP--]=R1	// QImode move
	R1=38	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,215,',0,0
	.dd LM115-_TX_Mode
	.dw 0x0d,0x0a
.code
LM115:
	R1=14	// QImode move
	[SP--]=R1	// QImode move
	R1=32	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,217,',0,0
	.dd LM116-_TX_Mode
	.dw 0x0d,0x0a
.code
LM116:
	R1=[28677]	// QImode move
	R2=R1|1
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,218,',0,0
	.dd LM117-_TX_Mode
	.dw 0x0d,0x0a
.code
LM117:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,219,',0,0
	.dd LM118-_TX_Mode
	.dw 0x0d,0x0a
.code
LM118:
.debug
	.dw '.stabn 0x44,0,219,',0,0
	.dd LM119-_TX_Mode
	.dw 0x0d,0x0a
.code
LM119:
L38:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of TX_Mode

.debug
	.dw '.stabf ',0,0
	.dd LME11-_TX_Mode
	.dw 0x0d,0x0a
.code
LME11:
.code
.debug
	.dw '.stabs "nRF24L01_Initial:F19",36,0,0,',0,0,offset _nRF24L01_Initial,seg _nRF24L01_Initial,0x0d,0x0a
.CODE
.public _nRF24L01_Initial
_nRF24L01_Initial:	.proc
.debug
	.dw '.stabn 0x44,0,221,',0,0
	.dd LM120-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM120:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,222,',0,0
	.dd LM121-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM121:
	R2=[28677]	// QImode move
	R3=R2&(-2)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,223,',0,0
	.dd LM122-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM122:
	R2=[28677]	// QImode move
	R3=R2|2
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,224,',0,0
	.dd LM123-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM123:
	R2=[28677]	// QImode move
	R3=R2&(-5)
	[28677]=R3	// QImode move
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM124-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM124:
.debug
	.dw '.stabn 0x44,0,227,',0,0
	.dd LM125-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LM125:
L39:

	POP BP from [SP]
	RETF
	.endp	// end of nRF24L01_Initial

.debug
	.dw '.stabf ',0,0
	.dd LME12-_nRF24L01_Initial
	.dw 0x0d,0x0a
.code
LME12:
.code
.debug
	.dw '.stabs "nRF24L01_Config:F19",36,0,0,',0,0,offset _nRF24L01_Config,seg _nRF24L01_Config,0x0d,0x0a
.CODE
.public _nRF24L01_Config
_nRF24L01_Config:	.proc
.debug
	.dw '.stabn 0x44,0,230,',0,0
	.dd LM126-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM126:
	// total=1, vars=1
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,1',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	[BP]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,232,',0,0
	.dd LM127-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM127:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,233,',0,0
	.dd LM128-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM128:
	R1=[28677]	// QImode move
	R2=R1|2
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,234,',0,0
	.dd LM129-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM129:
	R1=[28677]	// QImode move
	R2=R1&(-5)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,235,',0,0
	.dd LM130-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM130:
	R1=[28677]	// QImode move
	R2=R1&(-2)
	[28677]=R2	// QImode move
.debug
	.dw '.stabn 0x44,0,236,',0,0
	.dd LM131-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM131:
	R1=15	// QImode move
	[SP--]=R1	// QImode move
	R1=32	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,237,',0,0
	.dd LM132-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM132:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=33	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,238,',0,0
	.dd LM133-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM133:
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	R1=34	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,239,',0,0
	.dd LM134-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM134:
	R1=2	// QImode move
	[SP--]=R1	// QImode move
	R1=35	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,240,',0,0
	.dd LM135-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM135:
	R1=26	// QImode move
	[SP--]=R1	// QImode move
	R1=36	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,241,',0,0
	.dd LM136-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM136:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R1=37	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,242,',0,0
	.dd LM137-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM137:
	R1=15	// QImode move
	[SP--]=R1	// QImode move
	R1=38	// QImode move
	[SP--]=R1	// QImode move
	CALL _SPI_RW_Reg	// call with return value
	SP = SP + 2	//SP
.debug
	.dw '.stabn 0x44,0,243,',0,0
	.dd LM138-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM138:
.debug
	.dw '.stabn 0x44,0,243,',0,0
	.dd LM139-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LM139:
L40:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of nRF24L01_Config

.debug
	.dw '.stabf ',0,0
	.dd LME13-_nRF24L01_Config
	.dw 0x0d,0x0a
.code
LME13:
.code
.debug
	.dw '.stabs "main:F1",36,0,0,',0,0,offset _main,seg _main,0x0d,0x0a
.CODE
.public _main
_main:	.proc
.debug
	.dw '.stabn 0x44,0,245,',0,0
	.dd LM140-_main
	.dw 0x0d,0x0a
.code
LM140:
	// total=2, vars=2
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,2',0x0d, 0x0a
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=BP+5
	[BP+1]=R1	// QImode move
LBB8:
.debug
	.dw '.stabn 0x44,0,247,',0,0
	.dd LM141-_main
	.dw 0x0d,0x0a
.code
LM141:
	CALL _Initial_IOB	// call without return value
.debug
	.dw '.stabn 0x44,0,248,',0,0
	.dd LM142-_main
	.dw 0x0d,0x0a
.code
LM142:
	CALL _nRF24L01_Initial	// call without return value
.debug
	.dw '.stabn 0x44,0,249,',0,0
	.dd LM143-_main
	.dw 0x0d,0x0a
.code
LM143:
	CALL _TX_Mode	// call without return value
.debug
	.dw '.stabn 0x44,0,251,',0,0
	.dd LM144-_main
	.dw 0x0d,0x0a
.code
LM144:
L42:
	PC=L44	// jump
	PC=L43	// jump
L44:
.debug
	.dw '.stabn 0x44,0,257,',0,0
	.dd LM145-_main
	.dw 0x0d,0x0a
.code
LM145:
	R1=100	// QImode move
	[SP--]=R1	// QImode move
	CALL _delay1us	// call without return value
	SP = SP + 1	//SP
.debug
	.dw '.stabn 0x44,0,258,',0,0
	.dd LM146-_main
	.dw 0x0d,0x0a
.code
LM146:
	R1=1	// QImode move
	[28690]=R1	// QImode move
.debug
	.dw '.stabn 0x44,0,259,',0,0
	.dd LM147-_main
	.dw 0x0d,0x0a
.code
LM147:
	PC=L42	// jump
L43:
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM148-_main
	.dw 0x0d,0x0a
.code
LM148:
LBE8:
.debug
	.dw '.stabn 0x44,0,260,',0,0
	.dd LM149-_main
	.dw 0x0d,0x0a
.code
LM149:
L41:

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of main

.debug
	.dw '.stabn 0xc0,0,0,',0,0
	.dd LBB8-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabs "a:1",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabn 0xe0,0,0,',0,0
	.dd LBE8-_main
	.dw 0x0d,0x0a
.code
.debug
	.dw '.stabf ',0,0
	.dd LME14-_main
	.dw 0x0d,0x0a
.code
LME14:
.iram
.public _SPI_ReceiveData
_SPI_ReceiveData:
	.dw 0
.iram
.public _RX
_RX:
	.dw 16 dup(0)
	.end
