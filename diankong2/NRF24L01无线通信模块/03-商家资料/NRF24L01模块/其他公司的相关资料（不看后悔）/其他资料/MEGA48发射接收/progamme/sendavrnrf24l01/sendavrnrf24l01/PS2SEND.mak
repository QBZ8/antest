CC = iccavr
CFLAGS =  -IC:\icc\include\ -e -DATMega48  -l -g -Mavr_enhanced_small 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -LC:\icc\lib\ -g -bfunc_lit:0x34.0x1000 -dram_end:0x2ff -bdata:0x100.0x2ff -dhwstk_size:16 -beeprom:1.256 -fihx_coff -S2
FILES = main.o 

PS2SEND:	$(FILES)
	$(CC) -o PS2SEND $(LFLAGS) @PS2SEND.lk  
main.o: E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01/iom48v.h C:/icc/include/macros.h E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01/defs.h
main.o:	E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
	$(CC) -c $(CFLAGS) E:\项目\PS2无~1\progamme\sendavrnrf24l01\sendavrnrf24l01\main.c
