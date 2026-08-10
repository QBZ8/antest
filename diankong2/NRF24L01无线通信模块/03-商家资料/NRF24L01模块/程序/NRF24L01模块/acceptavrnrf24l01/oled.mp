NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0034   0048 =     72. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0034  __idata_start
       007C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   007C   03AA =    938. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003E  __start
       003E  __text_start
       005D  _exit
       005E  _main
       010A  _init_CPU
       012B  _delay
       0132  _delayms
       0139  _clear_buf
       0143  _SPI_RW
       015A  _SPI_RW_Reg
       0168  _SPI_Read
       0178  _SPI_Read_Buf
       0191  _SPI_Write_Buf
       01A8  _RX_Mode
       01C7  _TX_Mode
       01F2  pop_xgset003C
       01F7  pop_xgset00FC
       01FE  push_xgsetF0FC
       0200  push_xgset30FC
       0202  push_xgset00FC
       0204  push_xgset003C
       0209  push_xgsetF000
       020E  pop_xgsetF000
       0213  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0048 =     72. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _Buffer
       0100  __data_start
       0140  _TX_ADDRESS
       0145  _accept_flag
       0146  _accept_time
       0148  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0148   0001 =      1. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0148  _key_debug
       0148  __bss_start
       0149  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0002 =      2. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtAVR.o	[ crtavr.s ]
main.o	[ main.c ]
<library>	[ gpop2.s, gpop3.s, gpush.s, gpushy.s ]

User Global Definitions

ram_end = 0x2ff
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x34
data = 0x100
eeprom:0.256

