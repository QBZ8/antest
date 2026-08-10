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
                            text   007E   07C2 =   1986. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       003F  __start
       003F  __text_start
       005E  _exit
       005F  _main
       00E9  _nrf24l01init
       00F0  _init_CPU
       0111  _delay
       0118  _delayms
       011F  _clear_buf
       0129  _SPI_RW
       0141  _SPI_RW_Reg
       0150  _SPI_Read
       015E  _SPI_Read_Buf
       0178  _SPI_Write_Buf
       0190  _RX_Mode
       01AF  _TX_Mode
       01DA  _timer0_init
       01E2  _timer0_ovf_isr
       03FD  pop_gset2
       03FF  pop_gset4
       0401  push_gset5
       0403  push_gset4
       0405  push_gset3
       0407  push_gset2
       0409  push_gset1
       040C  pop_gset1
       040D  pop
       0420  __text_end

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
                             bss   0149   001C =     28. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0149  __bss_start
       0149  _key8_time
       014A  _key7_time
       014B  _key6_time
       014C  _key5_time
       014D  _key4_time
       014E  _key3_time
       014F  _key2_time
       0150  _key1_time
       0151  _key8_long_flag
       0152  _key8_flag
       0153  _key7_flag
       0154  _key6_flag
       0155  _key5_flag
       0156  _key4_flag
       0157  _key3_flag
       0158  _key2_flag
       0159  _key1_flag
       015A  _key8_pulse
       015B  _key7_pulse
       015C  _key6_pulse
       015D  _key5_pulse
       015E  _key4_pulse
       015F  _key3_pulse
       0160  _key2_pulse
       0161  _key1_pulse
       0162  _flag
       0163  _t20ms
       0164  _key_debug
       0165  __bss_end

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

