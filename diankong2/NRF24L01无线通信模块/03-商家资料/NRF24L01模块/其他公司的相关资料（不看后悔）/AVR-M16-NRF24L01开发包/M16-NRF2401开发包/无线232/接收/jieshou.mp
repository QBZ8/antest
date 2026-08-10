NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0034 =     52. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0088  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0088   0306 =    774. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0044  __start
       0044  __text_start
       0064  _exit
       0065  _Delay
       007A  _SPI_RW
       0092  _SPI_Read
       009F  _SPI_RW_Reg
       00AE  _SPI_Read_Buf
       00CD  _SPI_Write_Buf
       00E4  _SetRX_Mode
       00EA  _nRF24L01_RxPacket
       0105  _nRF24L01_TxPacket
       011D  _init_NRF24L01
       0144  _StartUART
       014F  _R_S_Byte
       0151  _display
       0174  _main
       01A2  pop_gset2
       01A5  pop_gset4
       01A8  push_gset5
       01AA  push_gset4
       01AC  push_gset3
       01AE  push_gset2
       01B0  push_gset1
       01B3  pop_gset1
       01B4  pop
       01C7  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0034 =     52. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _seg
       006A  _TxBuf
       008A  _TX_ADDRESS
       008F  _RX_ADDRESS
       0094  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0094   0002 =      2. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0094  _count
       0094  __bss_start
       0095  _sta
       0096  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
jieshou.o	[ jieshou.c ]
<library>	[ gpop2.s, gpop4.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

