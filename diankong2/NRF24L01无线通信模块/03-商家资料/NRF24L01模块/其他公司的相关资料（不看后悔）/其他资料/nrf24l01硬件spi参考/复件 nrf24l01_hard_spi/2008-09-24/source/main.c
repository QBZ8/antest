		/***********************************************
		*	copyrite (c) 2003
		*公司:		  深圳科技有限公司
		*文件名: 	  main.c(IAR Embedded Workbench IDE 4.10 for AVR)
		*作者:		  larry
		*当前版本:        v1.0
		*开始时间:        2008-9-8 16:57  -  2008-9-8 18:09 (编程)
		                  2008-9-9 16:34  -  2008-9-9 17:48 (调试RF)
		*完成日期:	  
		*摘要:		  晶振7.3728Mhz,mega48,+3.3v supply
		*修改:		
		************************************************/				
#include	"../header/user/main.h"

/****************************************/
     /*  declare i/o define for main key */
#define    direction_key1         ddrCbit5
#define    direction_key2         ddrCbit4
#define    direction_key3         ddrCbit3

#define    key1                 inputCbit5
#define    key2                 inputCbit4
#define    key3                 inputCbit3


#define    key1_output          portCbit5
#define    key2_output          portCbit4
#define    key3_output          portCbit3
/****************************************/

/*  declare main functions  */
void  key_io_init(void);
void  put_senddata_buff(void);
void sending(void);
/****************************************/

/***********************************************
函 数:	main
功 能:	程序入口
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    main(void)
{

        //uchar i;
        //uint  crc_temp;
        unsigned long timeout;
        
        SPCR |= (1<<SPE)|(1<<MSTR);
        SPSR = 0x01; //setup SPI 
        
        /* 上电初始化系统 */
        PowerOn_Initialisation();
        
        output_ledRed      = off;
        output_ledBlue     = off;
        
        /* 使能全局中断 */
        __enable_interrupt();
        key_io_init();
        
        
        
        while(true)
        {  
            if(!key1)      //单频通讯   communciation....
            {  
               delay_2us(20);
               channel=0;
               /* RF channel */
               RF_Setup_Channel(channel);
               if(!key1)
               {
                   while(!key1){   asm("wdr");	}
                  /* 如果当前在接收状态下则进入发射模式 */
                  //output_ledRed      = on;
                  //output_ledBlue     = off;
                  //delay_2us(60000);
                  //output_ledRed      = off;
                  //output_ledBlue     = on;
                  //delay_2us(60000);
                   //for(i=0;i<10;i++)
                 //while(1)
                   //{ 
                   sending();
                   
                   timeout=0xffff;
                   
                   while(timeout!=0)
                   {   asm("wdr");
                       timeout--;
                       if(!iRF_IRQ)
                       {
                            Nrf24l01_Fifo_Read(&rece_buff[0]);                
                            RF_Reset_Interrupt();
                            if(rece_buff[17==17])
                            {
                                        rece_buff[17]=0;
                                        output_ledRed      = on;
                                        output_ledBlue     = off;
                                        delay_2us(60000);
                                        output_ledRed      = off;
                                        output_ledBlue     = on;
                                        delay_2us(60000);
                                        timeout=0;
                            }
                      
                       }
                   }
                   //}
               }      
               
             }
            
            if(!key2)     //单频发射    channel =0   transmitting
            {  
               delay_2us(20);
               if(!key2)
               {
                 delay_2us(20);                 
                 while(!key2){   asm("wdr");	}
                 channel=0;
                  /* RF channel */
                 
                 while((key1)&&(key3))
                 {      
                       channel++;
                       if(channel>82)
                       channel=0; 
                       RF_Setup_Channel(channel);
                       sending();                   
                 }
                 
               }
            }
                       
            if(!key3)     //跳频发射    hopping  transmitting
            {  
               delay_2us(20);
               if(!key3)
               {
                 delay_2us(20);                 
                 while(!key3){   asm("wdr");	}
                 channel=0;
                 while((key1)&&(key2))
                 {                                                    
                       sending();                       
                       channel++;     
                       if(channel>83)
                         channel=0;
                       /* RF channel */
                       RF_Setup_Channel(channel);
                 }
                 
               }
            }
           
       }
}


/***********************************************
函 数:	Timer1_CompareA_Entry
功 能:	时间比较中断处理
输 入:	/
输 出:	/
描 述:	/
***********************************************/
#pragma      vector = TIMER1_COMPA_vect
__interrupt  void  Timer1_CompareA_Entry(void)
{
        //if(time_rs232_over)
        //{
            //if((--time_rs232_over) == 0x00)
           // {/* 可以开始通过RF发送数据 */
                //data_length              = point;
                //point                    = point_bottom;
               // bFlag_Packet_Transimit   = true;
           // }
       // }
}
/***********************************************
函 数:	Uart0_Rx_Entry
功 能:	串口接收中断处理
输 入:	/
输 出:	/
描 述:	/
***********************************************/
#pragma      vector = USART_RX_vect
__interrupt  void  Uart0_Rx_Entry(void)
{
        //data_buff_send[point++]      = UDR0;
        
        //if(point > point_top)
           //point = point_bottom;

        //time_rs232_over      = 0x03;
}

/***********************************************
函 数:	main_key_io_init
功 能:	main key I/O 初始化
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void  key_io_init(void)
{
      direction_key1  =  direction_input;       
      direction_key2  =  direction_input;
      direction_key3  =  direction_input;
      
      key1_output = 1; 
      key2_output = 1; 
      key3_output = 1; 
}

/***********************************************
函 数:	put_senddata_buff
功 能:	打包数据到data_buff-send[]
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void  put_senddata_buff(void)
{
    uchar i;
    for(i = 0;i < cFIFOlength;i++)
    data_buff_send[i]=i;    
}

/***********************************************
函 数:	sending
功 能:	发送一包数据
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void sending()
{
    uchar i;
    //uint  crc_temp;
    output_ledRed           = on;
                
    data_length = cFIFOlength;
                                
    put_senddata_buff();
    //send_buff[2]= data_length;
                    
                    for(i = 0x0;i < data_length;i++)
                        send_buff[i]   = data_buff_send[i];
                        
                    /* 发射数据帧CRC16校验 */
                    //crc_temp     = crc16_verify(&send_buff[3],data_length);
                    //send_buff[data_length+4]     = crc_temp;
                   // send_buff[data_length+3]     = crc_temp>>0x08;
                    //send_buff[data_length+5]     = 0xaa; 

                    /* 写入NRF24L01内部FIFO,发射数据 */
                    RF_Setup_StandBy();
                    Nrf24l01_Fifo_Write(&send_buff[0]);
                    RF_Setup_transmiter();
                    delay_2us(500);
                    //while(iRF_IRQ){asm("wdr");};
                    
                    
                    RF_Setup_receiver();                   
                    output_ledRed            = off;
  
}



