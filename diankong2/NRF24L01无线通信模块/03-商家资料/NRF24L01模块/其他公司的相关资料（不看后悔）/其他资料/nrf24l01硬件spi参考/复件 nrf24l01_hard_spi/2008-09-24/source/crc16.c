#include  "../header/user/crc16.h"
/***********************************************
函 数:	crc16_verify
功 能:	crc16数据校验功能 
输 入:	/
输 出:	/
描 述:	/
***********************************************/
uint    crc16_verify(uchar *crc_buff, uchar length) 
{
        uint  crc_temp;
        uchar data_temp;
        
        crc_temp = 0x00;

        while((length--)!= 0x00)
        {
            data_temp        = crc_temp>>0x0c; 
            crc_temp       <<= 0x04; 
            crc_temp        ^= crc16_table[data_temp ^ ((*crc_buff)/16)]; 
                              
            data_temp        = crc_temp>>0x0c; 
            crc_temp       <<= 0x04; 
            crc_temp        ^= crc16_table[data_temp ^ ((*crc_buff) & 0x0f)]; 
            crc_buff ++;
        }

        return(crc_temp);
}
