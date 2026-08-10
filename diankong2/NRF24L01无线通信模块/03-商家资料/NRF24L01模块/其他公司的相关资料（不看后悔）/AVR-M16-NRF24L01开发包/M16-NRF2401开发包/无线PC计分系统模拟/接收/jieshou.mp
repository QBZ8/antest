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
                            text   0088   042E =   1070. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0044  __start
       0044  __text_start
       0064  _exit
       0065  _Delay
       007A  _SPI_RW
       0091  _SPI_Read
       009E  _SPI_RW_Reg
       00AC  _SPI_Read_Buf
       00C9  _SPI_Write_Buf
       00DF  _SetRX_Mode
       00E5  _nRF24L01_RxPacket
       00FF  _nRF24L01_TxPacket
       011A  _init_NRF24L01
       0141  _dis_zhuye
       0191  _main
       01F2  mod16s
       01F6  div16s
       0210  mod16u
       0212  div16u
       0213  xdiv16u
       022C  pop_xgset003C
       0231  pop_xgset00FC
       0238  push_xgsetF0FC
       023A  push_xgset30FC
       023C  push_xgset00FC
       023E  push_xgset003C
       0243  push_xgset300C
       0248  pop_xgset300C
       024D  push_xgset303C
       0254  pop_xgset303C
       025B  __text_end

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
                             bss   0094   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0094  _count2
       0094  __bss_start
       0095  _count1
       0096  _count
       0097  _sta
       0098  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
jieshou.o	[ jieshou.c ]
<library>	[ div16s.s, div16u.s, gpop2.s, gpop3.s, gpush.s, gpushx.s, gpusha.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

