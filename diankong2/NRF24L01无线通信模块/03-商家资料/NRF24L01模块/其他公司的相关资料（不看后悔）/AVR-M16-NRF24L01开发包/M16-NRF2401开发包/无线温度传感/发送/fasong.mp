NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0054   0020 =     32. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __func_lit_start
       0074  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0074   0020 =     32. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0074  __idata_start
       0094  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0094   0554 =   1364. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       004A  __text_start
       004A  __start
       006A  _exit
       006B  _Delay
       0080  _SPI_RW
       0098  _SPI_Read
       00A5  _SPI_RW_Reg
       00B4  _SPI_Read_Buf
       00D3  _SPI_Write_Buf
       00EA  _SetRX_Mode
       00F3  _nRF24L01_RxPacket
       010E  _nRF24L01_TxPacket
       0126  _init_NRF24L01
       014D  _DS1820_delay
       0155  _Init_DS18B20
       016D  _ReadOneChar
       0186  _WriteOneChar
       01A1  _ReadTemperature
       01B2  _work_temp
       025A  _dis_zhuye
       028F  _main
       02A7  mod8u
       02A9  div8u
       02AA  xdiv8u
       02BF  empy16s
       02CF  pop_gset2
       02D2  pop_gset4
       02D5  push_gset5
       02D7  push_gset4
       02D9  push_gset3
       02DB  push_gset2
       02DD  push_gset1
       02E0  pop_gset1
       02E1  pop
       02F4  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0020 =     32. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _temp_data
       0060  __data_start
       0062  _seg
       006C  _seg1
       0076  _TX_ADDRESS
       007B  _RX_ADDRESS
       0080  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0080   0008 =      8. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0080  __bss_start
       0080  _sta
       0081  _dispaly
       0088  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
fasong.o	[ fasong.c ]
<library>	[ div8u.s, emul16s.s, gpop2.s, gpop4.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

