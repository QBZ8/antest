/************************************************************************************
;copyrightn   :shenzhen coolwaveasia 
;filename     :key.h
;writeby      :dengyihong
;*************************************************************************************/
#ifndef _KEY_H
#define	_KEY_H

#include "..\header\maindef.h"
#include "io.h"



#define  MASK_KEY     0xf0

#define  KEY_PIN_INPUT()  P2 |= MASK_KEY  
#define  GET_KEY_VALUE()  (P2 & MASK_KEY)

void key_scan(void);

extern void delay_2us(U16 delay_cnt);

#endif