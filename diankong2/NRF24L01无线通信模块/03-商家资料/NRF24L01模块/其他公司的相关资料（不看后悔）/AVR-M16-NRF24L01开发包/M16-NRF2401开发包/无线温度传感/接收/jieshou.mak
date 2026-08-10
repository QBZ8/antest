CC = iccavr
CFLAGS =  -e -D__ICC_VERSION="7.00" -DATMEGA -DATMega16  -l -g -Wf-intenum -Mavr_enhanced 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -g -ucrtatmega.o -bfunc_lit:0x54.0x1000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:1.512 -fihx_coff -S2
FILES = jieshou.o 

jieshou:	$(FILES)
	$(CC) -o jieshou $(LFLAGS) @jieshou.lk   -lcatmega
jieshou.o: C:\iccv7avr\include\iom16v.h C:\iccv7avr\include\macros.h
jieshou.o:	F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\接收\jieshou.c
	$(CC) -c $(CFLAGS) F:\开发板配套资料\开发板备份\AVR24L01\无线温度传感\接收\jieshou.c
