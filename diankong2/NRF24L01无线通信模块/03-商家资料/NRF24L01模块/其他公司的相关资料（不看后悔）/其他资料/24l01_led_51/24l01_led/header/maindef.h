/************************************************************************
;copyright	:shenzhen 
;filename 	:maindef.h
;mcu        :W78E52B
;LCD		:TC802B-01
;RF         :NRF24L01
;writeby    :dengyihong
;***********************************************************************
;                            --------------------
;                     P1.0  |1                 40|  VCC                  
;                     P1.1  |2                 39|  P0.0    
; RF_SCK  ----        P1.2  |3                 38|  P0.1   
; RF_MOSI ----        P1.3  |4                 37|  P0.2       
;                     P1.4  |5                 36|  P0.3    
; RF_CSN  ----        P1.5  |6                 35|  P0.4     
;                     P1.6  |7                 34|  P0.5     
;                     P1.7  |8                 33|  P0.6      
;                  RST/Vpd  |9                 32|  P0.7     
;                 RXD/P3.0  |10                31|  /EA/Vpp
;                 TXD/P3.1  |11                30|  ALE/PROG
; RF_IRQ  ----  /INT0/P3.2  |12                29|  /PSEN
; RF_MISO ----  /INT1/P3.3  |13                28|  P2.7     ----  KEY4 (send)
;                  T0/P3.4  |14                27|  P2.6     ----  KEY3 (+)
; RF_CE   ----     T1/P3.5  |15                26|  P2.5     ----  KEY2 (-)
;                 /WR/P3.6  |16                25|  P2.4     ----  KEY1 (mode)
;                 /RD/P3.7  |17                24|  P2.3
;                    XTAL2  |18                23|  P2.2     
;                    XTAL1  |19                22|  P2.1     ----  green_led
;                      VSS  |20                21|  P2.0     ----  red_led
;                            --------------------
;                                   W78E52B
;***********************************************************************/
#ifndef _MAINDEF_h
#define _MAINDEF_h

#include <REG52.H>
#include <stdlib.h>

typedef  unsigned char U8; 
typedef  unsigned int  U16; 

#define TX_ADR_WIDTH    5   // 5 bytes TX(RX) address width
#define TX_PLOAD_WIDTH  20  // 16 bytes TX payload

#define  RF_UP_CMD    0x77
#define  RF_DOWN_CMD  0x88
#define  RF_TEST_CMD  0x99


#define  NONE_KEY     0x00
#define  MODE_KEY     0x01
#define  DEC_KEY      0x02
#define  ADD_KEY      0x03
#define  SEND_KEY     0x04

enum Key_Info {none_key,mode_key,dec_key,add_key,send_key};	// 定义按键类型

#define	NORMAL_MODE		0
#define	TEST_MODE		1

#define	REC_STATUS		0x00
#define	SEND_STATUS		0x01

enum Rf_Status {rec_status,send_status};	// 定义RF模式


#endif