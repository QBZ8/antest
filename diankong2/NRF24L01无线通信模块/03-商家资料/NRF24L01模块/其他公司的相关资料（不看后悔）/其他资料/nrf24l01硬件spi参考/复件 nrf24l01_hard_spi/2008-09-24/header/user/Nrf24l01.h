#ifndef _Nrf24l01_REG_h_

#define _Nrf24l01_REG_h_

#define    Reg_Config           0x00
#define    Reg_EnAutoAck        0x01
#define    Reg_EnRxAddr         0x02
#define    Reg_SetUpAddrWidth   0x03
#define    Reg_SetUpRetr        0x04
#define    Reg_FfChannel        0x05
#define    Reg_RfSetUp          0x06
#define    Reg_Status           0x07
#define    Reg_ObserveTx        0x08
#define    Reg_CarrierDetect    0x09

#define    Reg_RxAddressP0      0x0a
#define    Reg_RxAddressP1      0x0b
#define    Reg_RxAddressP2      0x0c
#define    Reg_RxAddressP3      0x0d
#define    Reg_RxAddressP4      0x0e
#define    Reg_RxAddressP5      0x0f

#define    Reg_TxAddress        0x10

#define    Reg_RxPayloadP0      0x11
#define    Reg_RxPayloadP1      0x12
#define    Reg_RxPayloadP2      0x13
#define    Reg_RxPayloadP3      0x14
#define    Reg_RxPayloadP4      0x15
#define    Reg_RxPayloadP5      0x16

#define    Reg_FifoStatus       0x17
#endif
