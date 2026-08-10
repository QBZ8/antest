/************************************************************************
;copyright		:shenzhen coolwaveasia
;filename		:lcd.c
;lcd			:TC802B-01
;control mcu	:w78e52b
;writeby		:dengyihong
;describe		:LCD control
;notice			:
;***********************************************************************/

#include "..\header\lcd.h"

/***********************************************************
name:		ini_lcd		
input:		none
output:		none
describe:	初始化LCD	
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
void ini_lcd(void)
{
    lcd_write_reg(0x38);
    lcd_write_reg(0x38);
    lcd_write_reg(0x38);
    lcd_write_reg(0x08);
    lcd_wait();
    lcd_write_reg(0x01);
    lcd_wait();
    delay_2us(50000);
    
    lcd_write_reg(0x14);
    lcd_wait();
    lcd_write_reg(0x06);
    lcd_wait();
    lcd_write_reg(0x80);
    lcd_wait();
    lcd_write_reg(0x0c);
    lcd_wait();	
}


/***********************************************************
name:		lcd_printf_string	
input:		*disp_str  ---  存放显示字符的头指针
			row_len_col  ---  显示坐标参数及显示字符数
			row_len_col:
				bit[7:6]: 显示行坐标
				bit[5:3]: 显示字符长度
				bit[2:0]: 显示字符的起始列坐标
output:		none
describe:	在屏幕上显示多个字符		
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
void lcd_printf_string(U8 *disp_str, U8 row_len_col)
{
    U8 i = 0;
    U8 len = 0;
    
    len = (row_len_col & LEN_MASK) >> 0x03;
    
    lcd_write_reg(row_len_col & ROW_COL);
    lcd_wait();
    
    for(i=0; i<=len; i++)
    {
        lcd_write_data(*disp_str++);
        lcd_wait();	
    }
}


/***********************************************************
name:		lcd_printf_char		
input:		disp_char  ---  要显示的字符
			row_col    ---  显示坐标
output:		none
describe:	在屏幕上显示一个字符		
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
/*
void lcd_printf_char(U8 disp_char, U8 row_col)
{
    lcd_write_reg(row_col & ROW_COL);
    lcd_wait();
    lcd_write_data(disp_char);
    lcd_wait();	
}
*/

/***********************************************************
name:		lcd_write_reg		
input:		command  ---  要写入的命令
output:		none
describe:	写控制命令到LCD	
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
void lcd_write_reg(U8 command)
{
    LCD_DATA = command;		// 写控制命令
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_EN = 1;
    delay_2us(100);
    LCD_EN = 0;
}


/***********************************************************
name:		lcd_write_data		
input:		value  ---  要写入的数据
output:		none
describe:	写数据到LCD	
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
void lcd_write_data(U8 value)
{
   LCD_DATA =  value;		//写数据
   LCD_RS = 1;
   LCD_RW = 0;
   LCD_EN = 1;
   delay_2us(100);
   LCD_EN = 0; 	
}

/***********************************************************
name:		lcd_wait	
input:		none
output:		none
describe:	等待LCD内部操作完成	
notice:
creat date: 2008-7-25
creator:	dengyihong
************************************************************/
void lcd_wait(void)
{
    U8 value = 0;
       
    do
    {
        LCD_RS = 0;
        LCD_RW = 1;
        LCD_EN = 1;
        value = LCD_DATA;	
        LCD_EN = 0;
    }while(value & 0x80);		// 等待内部操作完成	
}

