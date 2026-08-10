#####################################################################
#																	 
#	Created by u'nSP IDE		20:35:37	08/27/09
#
#####################################################################




APPDIR	= C:\PROGRA~1\Sunplus\UNSPID~1.2D

OUTDIR	= .\Debug

CC	= $(APPDIR)\toolchain\gcc

AS	= $(APPDIR)\toolchain\xasm16

LD	= $(APPDIR)\toolchain\xlink16

AR	= $(APPDIR)\toolchain\xlib16

RESC	= $(APPDIR)\toolchain\resc

RM	= $(APPDIR)\toolchain\rm -f

INCLUDES	= -I"C:/Documents and Settings/Administrator/桌面/SPI_nRF24L01_TX/SPI_nRF24L01_TX" -I"C:/Program Files/Sunplus/unSP IDE 2.6.2D/library/include" -I"C:/Program Files/Sunplus/unSP IDE 2.6.2D/library/include/sys"

BODY	= -body SPCE060A_061A -bfile "C:\Program Files\Sunplus\unSP IDE Common\Body\SPCE060A_061A.cpt"

BINFILE	= "$(OUTDIR)\SPI_nRF24L01_TX.S37"

ARYFILE	= "$(OUTDIR)\SPI_nRF24L01_TX.ary"

SBMFILE	= "$(OUTDIR)\SPI_nRF24L01_TX.sbm"

OPT	= -S -gstabs -mglobal-var-iram

ASFLAGS	= -t2 -d

CASFLAGS	= -t2 -wpop

CFLAGS	= $(OPT) -B$(APPDIR)\toolchain\ $(INCLUDES) 

BINTYPE	= -as

LDFLAGS	= -listfile

EXTRAFLAGS	= 


OBJFILES	= \
	"$(OUTDIR)\Resource.obj" \
	"$(OUTDIR)\main.obj" 

"$(OUTDIR)\Resource.obj": "C:\Documents and Settings\Administrator\桌面\SPI_nRF24L01_TX\SPI_nRF24L01_TX\Resource.asm" 
	$(AS) $(ASFLAGS) $(INCLUDES) -l "$(OUTDIR)\Resource.lst" -o "$(OUTDIR)\Resource.obj" "C:\Documents and Settings\Administrator\桌面\SPI_nRF24L01_TX\SPI_nRF24L01_TX\Resource.asm" 

"$(OUTDIR)\main.asm": "C:\Documents and Settings\Administrator\桌面\SPI_nRF24L01_TX\SPI_nRF24L01_TX\main.c" 
	set PATH="$(APPDIR)\toolchain\";%PATH% & \
	$(CC) $(CFLAGS) -o "$(OUTDIR)/main.asm" "C:/Documents and Settings/Administrator/桌面/SPI_nRF24L01_TX/SPI_nRF24L01_TX/main.c" 

"$(OUTDIR)\main.obj": "$(OUTDIR)\main.asm"
	$(AS) $(CASFLAGS) $(INCLUDES) -l "$(OUTDIR)\main.lst" -o "$(OUTDIR)\main.obj" "$(OUTDIR)\main.asm" 


.SUFFIXES : .c .asm .obj .s37 .tsk .res

all :	 BEFOREBUILD "$(OUTDIR)" $(BINFILE)

BEFOREBUILD :

"$(OUTDIR)" :
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(BINFILE) : $(OBJFILES) 
	$(LD) $(BINTYPE) $(ARYFILE) $(BINFILE) $(LDFLAGS) $(BODY) $(EXTRAFLAGS)

compile :	 $(OBJFILES)

clean :
	$(RM) "$(OUTDIR)\Resource.obj" 
	$(RM) "$(OUTDIR)\Resource.lst" 
	$(RM) "$(OUTDIR)\main.obj" 
	$(RM) "$(OUTDIR)\main.lst" 
	$(RM) "$(OUTDIR)\main.asm" 
	$(RM) $(BINFILE) $(SBMFILE) 

.c.asm:
	$(CC) $(CFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

.asm.obj:
	$(AS) $(ASFLAGS) $(INCLUDES) -o "$(OUTDIR)/$@" $<

