CC = iccavr
CFLAGS =  -e -D__ICC_VERSION="7.07" -DATMEGA -DATMega16  -l -g -Wf-intenum -Mavr_enhanced 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -g -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:0.512 -fihx_coff -S2
FILES = fasong.o 

FASONG:	$(FILES)
	$(CC) -o FASONG $(LFLAGS) @FASONG.lk   -lcatmega
fasong.o: C:\iccv7avr\include\iom16v.h C:\iccv7avr\include\macros.h
fasong.o:	F:\开发板配套资料\开发板备份\JASK2001软件开发包\M16-NRF24L01开发包(JASK2001)\复件无~1\发送\fasong.c
	$(CC) -c $(CFLAGS) F:\开发板配套资料\开发板备份\JASK2001软件开发包\M16-NRF24L01开发包(JASK2001)\复件无~1\发送\fasong.c
