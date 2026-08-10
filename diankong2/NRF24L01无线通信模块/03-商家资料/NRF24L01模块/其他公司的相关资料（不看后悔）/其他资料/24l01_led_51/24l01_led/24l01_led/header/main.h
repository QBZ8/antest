/************************************************************************
;copyright	:shenzhen coolwaveasia 
;filename 	:main.h
;writeby    :dengyihong
;***********************************************************************/

#ifndef _MAIN_H
#define	_MAIN_H

#include "maindef.h"
#include "io.h"

extern bit Key_Msg;
extern enum Key_Info Key_Value;

void ini_mcu(void);
void ini_int0(void);
void ini_int1(void);
void ini_timer0(void);

void dispose_key_info(void);
void dispose_timer0(void);
void dispose_rf_data(void);
void delay_2us(U16 delay_cnt);


//外部函数声明 按键部分
extern void key_scan(void);


//RF 部分

extern void nRF24L01ioConfig(void);//initial 24l01 IO.
extern unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
extern unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);


//extern unsigned char SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
//extern unsigned char SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);
//extern unsigned char SPI_RW_Reg(unsigned char reg, unsigned char value);
//extern unsigned char SPI_Read(unsigned char reg);
//extern void nRF24L01_Interrupt(void);


extern void RX_Mode(void);
extern void TX_Mode(void);
extern void rec_rf_data(void);
#endif