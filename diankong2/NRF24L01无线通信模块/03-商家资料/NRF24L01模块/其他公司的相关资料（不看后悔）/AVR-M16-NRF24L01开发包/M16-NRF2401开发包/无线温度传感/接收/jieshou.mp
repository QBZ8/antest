NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   001E =     30. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0072  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0072   0318 =    792. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0039  __start
       0039  __text_start
       0059  _exit
       005A  _Delay
       006F  _SPI_RW
       0087  _SPI_Read
       0094  _SPI_RW_Reg
       00A3  _SPI_Read_Buf
       00C2  _SPI_Write_Buf
       00D9  _SetRX_Mode
       00DF  _nRF24L01_RxPacket
       00FA  _init_NRF24L01
       0121  _StartUART
       012C  _R_S_Byte
       012E  _display
       0163  _main
       01A0  pop_gset2
       01A3  pop_gset4
       01A6  push_gset5
       01A8  push_gset4
       01AA  push_gset3
       01AC  push_gset2
       01AE  push_gset1
       01B1  pop_gset1
       01B2  pop
       01C5  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   001E =     30. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _seg
       006A  _seg1
       0074  _TX_ADDRESS
       0079  _RX_ADDRESS
       007E  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   007E   0027 =     39. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       007E  __bss_start
       007E  _sta
       007F  _RxBuf
       009F  _temp
       00A5  __bss_end

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

