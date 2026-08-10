/************************************************************************************
;copyrightn   :shenzhen coolwaveasia 
;filename     :lcd.h
;writeby      :dengyihong
;*************************************************************************************/

#ifndef _LCD_H
#define	_LCD_H

#include "maindef.h"
#include "io.h"


void ini_lcd(void);
void lcd_printf_char(U8 disp_char, U8 row_col);
void lcd_printf_string(U8 *disp_str, U8 row_len_col);
void lcd_write_reg(U8 command);
void lcd_write_data(U8 value);
void lcd_wait(void);


extern void delay_2us(U16 delay_cnt);


#endif