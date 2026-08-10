#include "stm32f10x.h"                  // Device header
#include "NRF24L01_Define.h"

uint8_t NRF24L01_TxAddress[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
#define NRF24L01_TX_PACKET_WIDTH		4
uint8_t NRF24L01_TxPacket[NRF24L01_TX_PACKET_WIDTH];

uint8_t NRF24L01_RxAddress[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
#define NRF24L01_RX_PACKET_WIDTH		4
uint8_t NRF24L01_RxPacket[NRF24L01_RX_PACKET_WIDTH];

/*引脚配置*/

void NRF24L01_W_CE(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)BitValue);
}

void NRF24L01_W_CSN(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)BitValue);
}

void NRF24L01_W_SCK(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)BitValue);
}

void NRF24L01_W_MOSI(uint8_t BitValue)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_3, (BitAction)BitValue);
}

uint8_t NRF24L01_R_MISO(void)
{
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
}

void NRF24L01_GPIO_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	NRF24L01_W_CE(0);
	NRF24L01_W_CSN(1);
	NRF24L01_W_SCK(0);
	NRF24L01_W_MOSI(0);
}

/*通信协议*/

uint8_t NRF24L01_SPI_SwapByte(uint8_t Byte)
{
	uint8_t i;
	
	for (i = 0; i < 8; i ++)
	{
		//SPI移出数据
		if (Byte & 0x80)
		{
			NRF24L01_W_MOSI(1);
		}
		else
		{
			NRF24L01_W_MOSI(0);
		}
		Byte <<= 1;
		
		//SCK置高电平
		NRF24L01_W_SCK(1);
		
		//SPI移入数据
		if (NRF24L01_R_MISO())
		{
			Byte |= 0x01;
		}
	//	else
	//	{
	//		Byte &= ~0x01;
	//	}
		
		//SPI置低电平
		NRF24L01_W_SCK(0);
	}
	
	return Byte;
}

/*指令实现*/

void NRF24L01_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_W_REGISTER | RegAddress);
	NRF24L01_SPI_SwapByte(Data);
	NRF24L01_W_CSN(1);
}

uint8_t NRF24L01_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_R_REGISTER | RegAddress);
	Data = NRF24L01_SPI_SwapByte(NRF24L01_NOP);
	NRF24L01_W_CSN(1);
	return Data;
}

void NRF24L01_WriteRegs(uint8_t RegAddress, uint8_t *DataArray, uint8_t Count)
{
	uint8_t i;
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_W_REGISTER | RegAddress);
	for (i = 0; i < Count; i ++)
	{
		NRF24L01_SPI_SwapByte(DataArray[i]);
	}
	NRF24L01_W_CSN(1);
}

void NRF24L01_ReadRegs(uint8_t RegAddress, uint8_t *DataArray, uint8_t Count)
{
	uint8_t i;
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_R_REGISTER | RegAddress);
	for (i = 0; i < Count; i ++)
	{
		DataArray[i] = NRF24L01_SPI_SwapByte(NRF24L01_NOP);
	}
	NRF24L01_W_CSN(1);
}

void NRF24L01_WriteTxPayload(uint8_t *DataArray, uint8_t Count)
{
	uint8_t i;
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_W_TX_PAYLOAD);
	for (i = 0; i < Count; i ++)
	{
		NRF24L01_SPI_SwapByte(DataArray[i]);
	}
	NRF24L01_W_CSN(1);
}

void NRF24L01_ReadRxPayload(uint8_t *DataArray, uint8_t Count)
{
	uint8_t i;
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_R_RX_PAYLOAD);
	for (i = 0; i < Count; i ++)
	{
		DataArray[i] = NRF24L01_SPI_SwapByte(NRF24L01_NOP);
	}
	NRF24L01_W_CSN(1);
}

void NRF24L01_FlushTx(void)
{
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_FLUSH_TX);
	NRF24L01_W_CSN(1);
}

void NRF24L01_FlushRx(void)
{
	NRF24L01_W_CSN(0);
	NRF24L01_SPI_SwapByte(NRF24L01_FLUSH_RX);
	NRF24L01_W_CSN(1);
}

uint8_t NRF24L01_ReadStatus(void)
{
	uint8_t Status;
	NRF24L01_W_CSN(0);
	Status = NRF24L01_SPI_SwapByte(NRF24L01_NOP);
	NRF24L01_W_CSN(1);
	return Status;
}

/*功能函数*/

void NRF24L01_PowerDown(void)
{
	uint8_t Config;
	
	NRF24L01_W_CE(0);
	
	Config = NRF24L01_ReadReg(NRF24L01_CONFIG);
	Config &= ~0x02;
	NRF24L01_WriteReg(NRF24L01_CONFIG, Config);
}

void NRF24L01_StandbyI(void)
{
	uint8_t Config;
	
	NRF24L01_W_CE(0);
	
	Config = NRF24L01_ReadReg(NRF24L01_CONFIG);
	Config |= 0x02;
	NRF24L01_WriteReg(NRF24L01_CONFIG, Config);
}

void NRF24L01_RxMode(void)
{
	uint8_t Config;
	
	NRF24L01_W_CE(0);
	
	Config = NRF24L01_ReadReg(NRF24L01_CONFIG);
	Config |= 0x03;
	NRF24L01_WriteReg(NRF24L01_CONFIG, Config);
	
	NRF24L01_W_CE(1);
}

void NRF24L01_TxMode(void)
{
	uint8_t Config;
	
	NRF24L01_W_CE(0);
	
	Config = NRF24L01_ReadReg(NRF24L01_CONFIG);
	Config |= 0x02;
	Config &= ~0x01;
	NRF24L01_WriteReg(NRF24L01_CONFIG, Config);
	
	NRF24L01_W_CE(1);
}

void NRF24L01_Init(void)
{
	NRF24L01_GPIO_Init();
	
	NRF24L01_WriteReg(NRF24L01_CONFIG, 0x08);
	NRF24L01_WriteReg(NRF24L01_EN_AA, 0x3F);
	NRF24L01_WriteReg(NRF24L01_EN_RXADDR, 0x01);
	NRF24L01_WriteReg(NRF24L01_SETUP_AW, 0x03);
	NRF24L01_WriteReg(NRF24L01_SETUP_RETR, 0x03);
	NRF24L01_WriteReg(NRF24L01_RF_CH, 0x02);
	NRF24L01_WriteReg(NRF24L01_RF_SETUP, 0x0E);
	
	NRF24L01_WriteRegs(NRF24L01_RX_ADDR_P0, NRF24L01_RxAddress, 5);
	
	NRF24L01_WriteReg(NRF24L01_RX_PW_P0, NRF24L01_RX_PACKET_WIDTH);
	
	NRF24L01_RxMode();
}

void NRF24L01_Send(void)
{
	uint8_t Status;
	
	NRF24L01_WriteRegs(NRF24L01_TX_ADDR, NRF24L01_TxAddress, 5);
	NRF24L01_WriteTxPayload(NRF24L01_TxPacket, NRF24L01_TX_PACKET_WIDTH);
	NRF24L01_WriteRegs(NRF24L01_RX_ADDR_P0, NRF24L01_TxAddress, 5);
	
	NRF24L01_TxMode();
	
	while (1)
	{
		Status = NRF24L01_ReadStatus();
		
		if (Status & 0x20)
		{
			//发送成功
			break;
		}
		else if (Status & 0x10)
		{
			//发送失败
			break;
		}
		
		//超时break
	}
	
	NRF24L01_WriteReg(NRF24L01_STATUS, 0x30);
	
	NRF24L01_FlushTx();
	
	NRF24L01_WriteRegs(NRF24L01_RX_ADDR_P0, NRF24L01_RxAddress, 5);
	
	NRF24L01_RxMode();
}

uint8_t NRF24L01_Receive(void)
{
	uint8_t Status;
	
	Status = NRF24L01_ReadStatus();
	
	if (Status & 0x40)
	{
		NRF24L01_ReadRxPayload(NRF24L01_RxPacket, NRF24L01_RX_PACKET_WIDTH);
		
		NRF24L01_WriteReg(NRF24L01_STATUS, 0x40);
		
		NRF24L01_FlushRx();
		
		return 1;
	}
	
	return 0;
}
