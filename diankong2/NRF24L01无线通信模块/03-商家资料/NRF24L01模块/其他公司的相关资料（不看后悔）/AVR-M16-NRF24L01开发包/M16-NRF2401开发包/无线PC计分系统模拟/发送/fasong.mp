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
                            text   0088   03A2 =    930. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0044  __text_start
       0044  __start
       0064  _exit
       0065  _Delay
       007A  _inerDelay_us
       0080  _uart0_init
       008D  _uart0_rx_isr
       0098  _SPI_RW
       00AF  _SPI_Read
       00BC  _SPI_RW_Reg
       00CA  _SPI_Read_Buf
       00E7  _SPI_Write_Buf
       00FD  _SetRX_Mode
       0105  _nRF24L01_RxPacket
       011F  _nRF24L01_TxPacket
       0136  _init_NRF24L01
       015C  _main
       01E6  pop_xgset003C
       01EB  pop_xgset00FC
       01F2  push_xgsetF0FC
       01F4  push_xgset30FC
       01F6  push_xgset00FC
       01F8  push_xgset003C
       01FD  push_xgset300C
       0202  pop_xgset300C
       0207  push_xgset303C
       020E  pop_xgset303C
       0215  __text_end

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
                             bss   0094   0003 =      3. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0094  __bss_start
       0094  _KEY0
       0095  _tf
       0096  _sta
       0097  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0030 =     48. bytes (abs,ovr,rom)

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

