NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0028 =     40. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       007C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   007C   03E2 =    994. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003E  __text_start
       003E  __start
       005E  _exit
       005F  _Delay
       0074  _SPI_RW
       008C  _SPI_Read
       0099  _SPI_RW_Reg
       00A8  _SPI_Read_Buf
       00C7  _SPI_Write_Buf
       00DE  _SetRX_Mode
       00E7  _nRF24L01_RxPacket
       0102  _nRF24L01_TxPacket
       011A  _init_NRF24L01
       0141  _GetADResult
       0157  _GetBaiwei
       0162  _GetShiwei
       0175  _GetGewei
       0180  _dis_zhuye
       01B5  _main
       01F2  mod8u
       01F4  div8u
       01F5  xdiv8u
       020A  pop_gset2
       020D  pop_gset4
       0210  push_gset5
       0212  push_gset4
       0214  push_gset3
       0216  push_gset2
       0218  push_gset1
       021B  pop_gset1
       021C  pop
       022F  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0028 =     40. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _table
       0060  __data_start
       006A  _seg
       0074  _seg1
       007E  _TX_ADDRESS
       0083  _RX_ADDRESS
       0088  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0088   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0088  __bss_start
       0088  _sta
       0089  _AD_data
       008D  _AD_num
       008E  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
fasong.o	[ fasong.c ]
<library>	[ div8u.s, gpop2.s, gpop4.s, gpush.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

