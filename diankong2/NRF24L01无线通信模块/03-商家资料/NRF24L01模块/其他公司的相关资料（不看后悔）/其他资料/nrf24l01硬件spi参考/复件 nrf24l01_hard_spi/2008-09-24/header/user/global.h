#ifndef uchar
        #define     uchar   unsigned char
        #define     uint    unsigned int

        #define     true    1
        #define     false   0

        #define     on      0
        #define     off     1                              

        #define     enable  1
        #define     disable 0                              

        #define     direction_output  1
        #define     direction_input   0                    
#endif
/****************************************/
#include  "intrinsics.h"
#include  "../sys/iom48.h"
#include  "../sys/sbit.h"
#include  "../user/Nrf24l01.h"
/****************************************/
#define    crystal              7372800
/****************************************/
    /* declare config */
#define    debug_RF             0
#define    debug_Master         0    
/****************************************/
    /* declare io */
#define    direction_ledRed     ddrBbit5
#define    direction_ledBlue    ddrBbit3

#define    direction_rxd        ddrDbit0
#define    direction_txd        ddrDbit1

#define    direction_IRQ        ddrDbit3
/****************************************/
#define    output_ledRed        portBbit5
#define    output_ledBlue       portBbit3

#define    iRF_IRQ              inputDbit3

#define    pullup_IRQ           portDbit3


/****************************************/
    /* declare const */        
#define    cFIFOlength          20            /* RFµÄFIFO³¤¶È */
/****************************************/
    /* declare flag */
__regvar __no_init volatile union{
                                  uchar R_flag0;
                                  struct{
                                         uchar
                                            flag_data_receive:1,
                                         
                                            flag_rs232data_check:1,
                                            
                                            bFlag_Packet_Transimit:1;             
                                        };
                                 }@ 0x0f;    
/****************************************/
     /* declare extern variable */
/* main.h */

/* init.h */
/****************************************/
     /* declare extern founction */

/* init.c */
extern  void    PowerOn_Initialisation(void);

/* phy-Nrf24l01.c */
extern	void    Initialisation_RF(void);
extern  void    RF_Setup_StandBy(void);
extern  void    RF_Setup_receiver(void);
extern  void    RF_Reset_Interrupt(void);
extern  void    RF_Setup_transmiter(void);
extern  void    RF_Setup_Channel(uchar channel);

extern  void    Nrf24l01_Reset_FifoTX(void);
extern  void    Nrf24l01_Reset_FifoRX(void);
extern  void    Nrf24l01_Fifo_Read(uchar *read_buff);
extern  void    Nrf24l01_Fifo_Write(uchar *write_buff);

extern  void delay_2us(unsigned int delay_cnt);

extern  uint    crc16_verify(uchar *crc_buff, uchar length);
