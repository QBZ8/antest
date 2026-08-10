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
                            text   0088   028A =    650. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0044  __text_start
       0044  __start
       0064  _exit
       0065  _Delay
       007A  _inerDelay_us
       0080  _SPI_RW
       0098  _SPI_Read
       00A5  _SPI_RW_Reg
       00B4  _SPI_Read_Buf
       00D3  _SPI_Write_Buf
       00EA  _SetRX_Mode
       00F2  _nRF24L01_RxPacket
       010D  _nRF24L01_TxPacket
       0124  _init_NRF24L01
       014A  _main
       0164  pop_gset2
       0167  pop_gset4
       016A  push_gset5
       016C  push_gset4
       016E  push_gset3
       0170  push_gset2
       0172  push_gset1
       0175  pop_gset1
       0176  pop
       0189  __text_end

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
                             bss   0094   0001 =      1. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0094  __bss_start
       0094  _sta
       0095  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
fasong.o	[ fasong.c ]
<library>	[ gpop2.s, gpop4.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

