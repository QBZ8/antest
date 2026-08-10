#ifndef _API_DEF_
#define _API_DEF_

#include <reg51.h>
#define uchar unsigned char

/***************************************************/
#define TX_ADR_WIDTH   5  // 5字节宽度的发送/接收地址
#define TX_PLOAD_WIDTH 32  // 数据通道有效数据宽度
#define LED P1


extern uchar RX_BUF[TX_PLOAD_WIDTH];
extern uchar TX_BUF[TX_PLOAD_WIDTH];
/*********************************************************************/
// Define SPI pins
sbit CE   = P2^0;  // Chip Enable pin signal (output)
sbit CSN  = P2^1;  // Slave Select pin, (output to CSN, nRF24L01)
sbit IRQ  = P3^2;  // Interrupt signal, from nRF24L01 (input)
sbit MISO = P2^4;  // Master In, Slave Out pin (input)
sbit MOSI = P2^5;  // Serial Clock pin, (output)
sbit SCK  = P2^7;  // Master Out, Slave In pin (output)

// SPI(nRF24L01) commands
#define READ_REG    0x00  // Define read command to register
#define WRITE_REG   0x20  // Define write command to register
#define RD_RX_PLOAD 0x61  // Define RX payload register address
#define WR_TX_PLOAD 0xA0  // Define TX payload register address
#define FLUSH_TX    0xE1  // Define flush TX register command
#define FLUSH_RX    0xE2  // Define flush RX register command
#define REUSE_TX_PL 0xE3  // Define reuse TX payload register command
#define NOP         0xFF  // Define No Operation, might be used to read status register

// SPI(nRF24L01) registers(addresses)
#define CONFIG      0x00  // 'Config' register address
#define EN_AA       0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR   0x02  // 'Enabled RX addresses' register address
#define SETUP_AW    0x03  // 'Setup address width' register address
#define SETUP_RETR  0x04  // 'Setup Auto. Retrans' register address
#define RF_CH       0x05  // 'RF channel' register address
#define RF_SETUP    0x06  // 'RF setup' register address
#define STATUS      0x07  // 'Status' register address
#define OBSERVE_TX  0x08  // 'Observe TX' register address
#define CD          0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0  0x0A  // 频道0接收数据地址
#define RX_ADDR_P1  0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2  0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3  0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4  0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5  0x0F  // 'RX address pipe5' register address
#define TX_ADDR     0x10  // 'TX address' register address
#define RX_PW_P0    0x11  // 接收频道0接收数据长度
#define RX_PW_P1    0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2    0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3    0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4    0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5    0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS 0x17  // 'FIFO Status Register' register address


extern void StartUART( void );//串行口初始化
extern void R_S_Byte(uchar R_Byte); //通过串口发送一个字节给PC
extern void init_io(void);
extern void delay_ms(uchar x);
extern uchar SPI_RW(uchar byte);
extern uchar SPI_RW_Reg(uchar reg, uchar value);
extern uchar SPI_Read(uchar reg);
extern uchar SPI_Read_Buf(uchar reg, uchar * pBuf, uchar bytes);
extern uchar SPI_Write_Buf(uchar reg, uchar * pBuf, uchar bytes);
extern void RX_Mode(void);
extern void TX_Mode(uchar * BUF);
extern uchar Check_ACK(bit clear);
extern void CheckButtons();

#endif   /* _API_DEF_ */