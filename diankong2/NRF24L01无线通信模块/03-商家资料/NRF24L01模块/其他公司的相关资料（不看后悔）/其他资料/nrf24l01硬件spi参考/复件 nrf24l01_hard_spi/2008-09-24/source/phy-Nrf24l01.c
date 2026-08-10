#include    "../header/user/phy-Nrf24l01.h"
/***********************************************
函 数:	Nrf24l01_InterFace()
功 能:	MCU与Nrf24l01的接口配置
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_InterFace(void)
{
        iRF_CE      = negative;
        
        iSPI_Csn    = positive;
        iSPI_Sck    = negative;
        
        direction_CE     = direction_output;
        direction_Csn    = direction_output;
        direction_Sck    = direction_output;
        direction_Mosi   = direction_output;
        direction_Miso   = direction_input;
}
/***********************************************
函 数:	Byte_Write()
功 能:	写bit数据到sck和sdio
输 入:	byte
输 出:	/
描 述:	左移位,bit7在先,sck负边缘触发
***********************************************/
void    Byte_Write(uchar byte)
{
        /*
        uchar i;

        for(i = 0x00; i < 0x08; i++)
        {
            if(byte&0x80)
                iSPI_Mosi    = positive;
            else
                iSPI_Mosi    = negative;
                
            iSPI_Sck         = positive;
            iSPI_Sck         = negative;
            
            byte           <<= 0x01;
        }
        */
        SPDR = byte;
        while(!(SPSR & (1<<SPIF)));

}
/***********************************************
函 数:	Byte_Read()
功 能:	读8bit数据从sck和miso
输 入:	/
输 出:	byte
描 述:	左移位,bit7在先,sck负边缘触发
***********************************************/
uchar   Byte_Read(void)
{
        //uchar i;
        uchar byte;
        /*
        for(i = 0x00; i < 0x08; i++)
        {
            byte           <<= 0x01;
            
            iSPI_Sck         = positive;
            
            if(iSPI_Miso)
                byte        |= 0x01;
            else
                byte        &= 0xfe;
                
            iSPI_Sck         = negative;
        }
        */
        
         while((SPSR & 0x80)==0);
                    
                    //SPDR = 0xaa;
                    //while((SPSR & (1<<SPIF))==0)
                    
         byte = SPDR;
         SPSR = 0x01; //setup SPI 

        /* 返回读取数值 */
        return    (byte);
}
/***********************************************
函 数:	Nrf24l01_Register_Write()
功 能:	写入数据到Nrf24l01寄存器
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_Register_Write(uchar address,uchar parameter)
{
        iSPI_Csn        = negative;
        
        address        &= 0x1f;
        address        |= 0x20;
        
        Byte_Write(address);
        Byte_Write(parameter);
        
        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_Register_Read()
功 能:	读出状态从Nrf24l01寄存器
输 入:	/
输 出:	/
描 述:	/
***********************************************/
uchar   Nrf24l01_Register_Read(uchar address)
{
        uchar temp;
        
        iSPI_Csn        = negative;
        
        address        &= 0x1f;
        
        Byte_Write(address);
        
        temp            = Byte_Read();
        
        iSPI_Csn        = positive;
        
        /* 返回读取数值 */
        return    (temp);
}
/***********************************************
函 数:	RF_Setup_Channel()
功 能:	Nrf24l01设置频点通道
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    RF_Setup_Channel(uchar channel)
{
        Nrf24l01_Register_Write(Reg_FfChannel,channel);
}
/***********************************************
函 数:	RF_Setup_StandBy()
功 能:	Nrf24l01设置为stby状态
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    RF_Setup_StandBy(void)
{
        uchar temp;
        
        iRF_CE   = negative;
        
        temp     = Nrf24l01_Register_Read(Reg_Config);
        temp    &= 0xfd;
        Nrf24l01_Register_Write(Reg_Config,temp);
}
/***********************************************
函 数:	RF_Reset_Interrupt()
功 能:	Nrf24l01设置中断标志清0
输 入:	/
输 出:	/
描 述:	clear TX_DS, RX_DR, MAX_RT interrupt flag
***********************************************/
void    RF_Reset_Interrupt(void)
{
        iRF_CE   = negative;
        Nrf24l01_Register_Write(Reg_Status,0x70);
        iRF_CE   = positive; 
}        
/***********************************************
函 数:	RF_Setup_receiver()
功 能:	Nrf24l01设置为接收状态
输 入:	/
输 出:	/
描 述:	mask TX_DS, enable RX_DR reflect IRQ
***********************************************/
void    RF_Setup_receiver(void)
{
        uchar temp;
        
        iRF_CE   = negative;     
        
        /* clear TX_DS, RX_DR, MAX_RT interrupt flag */
        Nrf24l01_Register_Write(Reg_Status,0x70);  
        
        temp     = Nrf24l01_Register_Read(Reg_Config);
        temp    &= 0x9c;
        temp    |= 0x23;
        Nrf24l01_Register_Write(Reg_Config,temp); 
        
        iRF_CE   = positive;        
}
/***********************************************
函 数:	RF_Setup_transmiter()
功 能:	Nrf24l01设置为发射状态
输 入:	/
输 出:	/
描 述:	mask RX_DR, enable TX_DS reflect IRQ
***********************************************/
void    RF_Setup_transmiter(void)
{
        uchar temp;
        
        iRF_CE   = negative;
        
        /* clear TX_DS, RX_DR, MAX_RT interrupt flag */
        Nrf24l01_Register_Write(Reg_Status,0x70);
        
        temp     = Nrf24l01_Register_Read(Reg_Config);
        temp    &= 0x8c;
        temp    |= 0x42;
        
        Nrf24l01_Register_Write(Reg_Config,temp);
        
        iRF_CE   = positive;
        /* delay 10us */
        for(temp = 0x00;temp < 0x10;temp++)
        {
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
        }
}
/***********************************************
函 数:	Nrf24l01_Reset_FifoTX()
功 能:	复位Nrf24l01发送FIFO指针
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_Reset_FifoTX(void)
{
        iSPI_Csn        = negative;
        
        Byte_Write(cCommand_TxFifoFlush);
        
        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_Reset_FifoRX()
功 能:	复位Nrf24l01接收FIFO指针
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_Reset_FifoRX(void)
{
        iSPI_Csn        = negative;
        
        Byte_Write(cCommand_RxFifoFlush);
        
        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_Fifo_Read()
功 能:	读FIFO数据
输 入:	read_buff
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_Fifo_Read(uchar *read_buff)
{
        uchar i;
        
        iSPI_Csn        = negative;

        /* 读命令 */
        Byte_Write(cCommand_RxFifoRead);
        
        /* 读FIFO数据 */
        for(i = 0x00;i < cFIFOlength;i++)
        {
            *read_buff  = Byte_Read();

            read_buff ++;
        }

        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_Fifo_Write()
功 能:	写FIFO数据
输 入:	write_buff
输 出:	/
描 述:	/
***********************************************/
void    Nrf24l01_Fifo_Write(uchar *write_buff)
{
        uchar i;
        
        iSPI_Csn        = negative;

        /* 写命令 */
        Byte_Write(cCommand_TxFifoWrite);

        /* 写FIFO数据 */
        for(i = 0x00;i < cFIFOlength;i++)
        {
            Byte_Write(*write_buff);

            write_buff ++;
        }

        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_Id_Write()
功 能:	写ID到Nrf24l01内部寄存器
输 入:	ID_Register_Addr
输 出:	/
描 述:	ID_Register_Addr  = ID寄存器地址
***********************************************/
void    Nrf24l01_TXaddress_Write(void)
{
        iSPI_Csn        = negative;
        
        Byte_Write(Reg_TxAddress&0x1f|0x20);
        
        Byte_Write(0x46);
        Byte_Write(0x45);
        Byte_Write(0x49);
        Byte_Write(0x4b);
        Byte_Write(0x41);
        

        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Nrf24l01_RXaddress_Write()
功 能:	写ID到Nrf24l01内部寄存器
输 入:	ID_Register_Addr
输 出:	/
描 述:	ID_Register_Addr  = ID寄存器地址
***********************************************/
void    Nrf24l01_RXaddress_Write(void)
{
        iSPI_Csn        = negative;
        
        Byte_Write(Reg_RxAddressP0&0x1f|0x20);
        
        Byte_Write(0x46);
        Byte_Write(0x45);
        Byte_Write(0x49);
        Byte_Write(0x4b);
        Byte_Write(0x41);
        

        iSPI_Csn        = positive;
}
/***********************************************
函 数:	Initialisation_RF()
功 能:	上电初始化Nrf24l01
输 入:	/
输 出:	/
描 述:	/
***********************************************/
void    Initialisation_RF(void)
{   
#if debug_RF
        uchar test[cFIFOlength]     = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa};
#endif
        
        Nrf24l01_InterFace();       
        
        /* mask all interrupt reflected on the IRQ,disable 2 bytes CRC,Power Down mode */
        Nrf24l01_Register_Write(Reg_Config,0x05);
        
        /* disable all pipe's Auto Acknowledgment */
        Nrf24l01_Register_Write(Reg_EnAutoAck,0x00);
        
        /* only enable data pipe 0 */
        Nrf24l01_Register_Write(Reg_EnRxAddr,0x01);
        
        /* Rx/Tx address field width 5 bytes */
        Nrf24l01_Register_Write(Reg_SetUpAddrWidth,0x03);
        
        
        Nrf24l01_Register_Write(Reg_SetUpRetr,0x10);
        
        /* data rate = 2Mbps,output power = 0dbm */
        Nrf24l01_Register_Write(Reg_RfSetUp,0x0f);

        /* clear RF interrupt */
        Nrf24l01_Register_Write(Reg_Status,0x70);
        
        /* receive address data pipe 0 */
        Nrf24l01_RXaddress_Write();
        
        /* transimiter address */
        Nrf24l01_TXaddress_Write();
        
        /* number of bytes in Rx payload in data pipe 0 */
        Nrf24l01_Register_Write(Reg_RxPayloadP0,cFIFOlength);
        
        /* flush Tx fifo buffer */
        Nrf24l01_Reset_FifoTX();
        
        /* flush Rx fifo buffer */
        Nrf24l01_Reset_FifoRX();
        
        /* RF channel */
        RF_Setup_Channel(0x00);
        
#if debug_RF
        while(1)
        {
            Nrf24l01_Fifo_Write(&test[0]);
            RF_Setup_transmiter(); 
            while(iRF_IRQ){};
        }
#else
        #if !debug_Master
            RF_Setup_receiver();
        #endif
#endif        
}

/**********************************************************
name:		delay_2us
input:		delay_cnt
output:		none
describe:	delay 2*delay_cnt(us)
notice:
**********************************************************/
void delay_2us(unsigned int delay_cnt)
{	    
    while(delay_cnt--) 
    { 
        asm("wdr");		 
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop"); 
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");    
        asm("nop"); 
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");    
    }	
}	

