NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0034   0049 =     73. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0034  __idata_start
       007D  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   007E   0378 =    888. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003F  __start
       003F  __text_start
       005E  _exit
       005F  _main
       00C3  _nrf24l01init
       00CA  _init_CPU
       00EB  _delay
       00F2  _delayms
       00F9  _clear_buf
       0103  _SPI_RW
       011B  _SPI_RW_Reg
       012A  _SPI_Read
       0138  _SPI_Read_Buf
       0152  _SPI_Write_Buf
       016A  _RX_Mode
       0189  _TX_Mode
       01B4  _timer0_init
       01BC  _timer0_ovf_isr
       01D8  pop_gset2
       01DA  pop_gset4
       01DC  push_gset5
       01DE  push_gset4
       01E0  push_gset3
       01E2  push_gset2
       01E4  push_gset1
       01E7  pop_gset1
       01E8  pop
       01FB  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0049 =     73. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _Buffer
       0100  __data_start
       0140  _TX_ADDRESS
       0145  _accept_flag
       0146  _send_flag
       0147  _accept_time
       0149  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0149   0015 =     21. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0149  _key6_time
       0149  __bss_start
       014A  _key5_time
       014B  _key4_time
       014C  _key3_time
       014D  _key2_time
       014E  _key1_time
       014F  _key6_flag
       0150  _key5_flag
       0151  _key4_flag
       0152  _key3_flag
       0153  _key2_flag
       0154  _key1_flag
       0155  _key6_pulse
       0156  _key5_pulse
       0157  _key4_pulse
       0158  _key3_pulse
       0159  _key2_pulse
       015A  _key1_pulse
       015B  _flag
       015C  _t20ms
       015D  _key_debug
       015E  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0022 =     34. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\icc\lib\crtAVR.o	[ crtavr.s ]
main.o	[ main.c ]
<library>	[ gpop2.s, gpop4.s, gpush.s ]

User Global Definitions

ram_end = 0x2ff
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x34
data = 0x100
eeprom:1.256

