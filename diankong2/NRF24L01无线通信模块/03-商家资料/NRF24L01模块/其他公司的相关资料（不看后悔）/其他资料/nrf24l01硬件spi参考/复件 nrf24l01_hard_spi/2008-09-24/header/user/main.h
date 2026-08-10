#include        "global.h"
/****************************************/
    /* declare const */
#define    buff_length       26    
    
#define    point_top         buff_length-1
#define    point_bottom      0

/****************************************/
    /*  declare variable */
uchar  time_rs232_over;

uchar  point       = 0x00;    
uchar  data_length = 0x00;
uchar  channel;

uchar  data_buff_send[buff_length]    = {0xaa};

uchar  rece_buff[cFIFOlength] = {0xaa};  
uchar  send_buff[cFIFOlength] = {0x49,0x45};                           
/****************************************/
     /* declare founction */
     
