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
                            text   0088   0352 =    850. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0044  __start
       0044  __text_start
       0064  _exit
       0065  _Delay
       007A  _inerDelay_us
       0080  _SPI_RW
       0097  _SPI_Read
       00A4  _SPI_RW_Reg
       00B2  _SPI_Read_Buf
       00CF  _SPI_Write_Buf
       00E5  _SetRX_Mode
       00ED  _nRF24L01_RxPacket
       0107  _nRF24L01_TxPacket
       011E  _init_NRF24L01
       0144  _main
       01BE  pop_xgset003C
       01C3  pop_xgset00FC
       01CA  push_xgsetF0FC
       01CC  push_xgset30FC
       01CE  push_xgset00FC
       01D0  push_xgset003C
       01D5  push_xgset300C
       01DA  pop_xgset300C
       01DF  push_xgset303C
       01E6  pop_xgset303C
       01ED  __text_end

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
       0094  __bss_start
       0094  _tf
       0095  _sta
       0096  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
fasong.o	[ fasong.c ]
<library>	[ gpop2.s, gpop3.s, gpush.s, gpushx.s, gpusha.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

