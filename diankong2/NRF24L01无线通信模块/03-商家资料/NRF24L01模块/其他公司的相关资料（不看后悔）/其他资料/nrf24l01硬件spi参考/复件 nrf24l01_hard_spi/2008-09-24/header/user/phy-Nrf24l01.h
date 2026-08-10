    /* declare header file */
#include        "global.h"
/****************************************/
    /* declare const */
#define    positive             1
#define    negative             0

#define    cID_Code0            0x46
#define    cID_Code1            0x45
#define    cID_Code2            0x49
#define    cID_Code3            0x4b
#define    cID_Code4            0x41

#define    cCommand_RxFifoRead      0x61
#define    cCommand_TxFifoWrite     0xa0
#define    cCommand_TxFifoFlush     0xe1
#define    cCommand_RxFifoFlush     0xe2
/****************************************/
     /*  declare i/o define */
#define    direction_CE         ddrDbit4
   
#define    direction_Sck        ddrDbit5
#define    direction_Mosi       ddrDbit6
#define    direction_Miso       ddrDbit7
#define    direction_Csn        ddrBbit0
/****************************************/
#define    iRF_CE               portDbit4

#define    iSPI_Sck             portDbit5
#define    iSPI_Mosi            portDbit6
#define    iSPI_Miso            inputDbit7

#define    iSPI_Csn             portBbit0
/****************************************/
void    Initialisation_RF(void);
void    RF_Setup_StandBy(void);
void    RF_Setup_receiver(void);
void    RF_Reset_Interrupt(void);
void    RF_Setup_transmiter(void);

void    Nrf24l01_Reset_FifoTX(void);
void    Nrf24l01_Reset_FifoRX(void);
void    Nrf24l01_Fifo_Read(uchar *read_buff);
void    Nrf24l01_Fifo_Write(uchar *write_buff);

