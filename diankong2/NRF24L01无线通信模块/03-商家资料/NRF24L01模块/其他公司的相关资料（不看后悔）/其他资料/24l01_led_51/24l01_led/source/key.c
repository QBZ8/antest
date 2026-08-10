/**********************************************************
;copyright		:shenzhen coolwaveasia 
;filename		:key.c
;writeb			:dengyihong
;describe		:按键扫描
;notice			:
;*********************************************************/

#include "..\header\key.h"


enum Key_Info Key_Value;		// 按键值

U8  Key_Old_Buf = MASK_KEY;

bit Key_Msg = 0;				// 处理按键消息标志
bit Have_Key_Push = 0;			// 按键按下标志



/**********************************************************
name:        key_scan
input:       none
output:	     none
describe:    按键扫描
notice:
creat date:  2008-6-10
creator:     dengyihong
**********************************************************/
void key_scan(void)
{
    U8 i = 0;
    U8 key_buf = 0;
    U8 temp_buf = 0;
    
    KEY_PIN_INPUT();
    delay_2us(1);
    key_buf = GET_KEY_VALUE();
    for(i=0; i<3; i++)
    {   
        delay_2us(500);    	
        temp_buf = GET_KEY_VALUE();
        if(key_buf != temp_buf)
        {
            return;	
        }
    }
            
    if(key_buf != Key_Old_Buf)
    {
        if(key_buf != MASK_KEY)					// 新键按下
        {
            switch(key_buf)
            {
                case 0x70: 
                     Key_Value = SEND_KEY;		// send key
                break;
                       
                case 0xb0:  
                     Key_Value = ADD_KEY;		// + key
                break;
                    
                case 0xd0:  
                     Key_Value = DEC_KEY;		// - key
                break; 
                    
                case 0xe0:  
                     Key_Value = MODE_KEY;		// mode key
                break;                 
                                                                                  
                default:    
                     Key_Value = NONE_KEY;	
                break;
			}
			if(Key_Value != NONE_KEY)		// 是否有按键按下
			{
				Have_Key_Push = 1;
				Key_Old_Buf = key_buf;	
			}
		}
		else if(Have_Key_Push)				// 按键释放
		{
			Have_Key_Push = 0;
			Key_Old_Buf = MASK_KEY;
			switch(Key_Value)
			{
				case 0x04:
				case 0x03:
				case 0x02:
				case 0x01:
					 Key_Msg = 1 ;
				break; 
            			
				default:
					Key_Msg = 0;  
				break;             	
			}
		}   	
	}    	
}


