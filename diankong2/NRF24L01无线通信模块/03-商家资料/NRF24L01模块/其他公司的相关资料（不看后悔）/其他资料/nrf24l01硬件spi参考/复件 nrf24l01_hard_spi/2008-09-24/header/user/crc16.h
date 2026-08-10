#include         "global.h"
/****************************************/
    /*  declare const */
__flash uint crc16_table[0x10]={
                                 0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
                                 0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
                               };
/****************************************/
    /* declare founction */
uint    crc16_verify(uchar *crc_buff, uchar length);
