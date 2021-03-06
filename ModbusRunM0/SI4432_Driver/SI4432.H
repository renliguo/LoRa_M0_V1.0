#ifndef _SI4432_H
#define _SI4432_H

#include "M051Series.h"


#define SI4432_PWRSTATE_READY		1		              // 模块 Ready 状态定义
#define SI4432_PWRSTATE_TX		0x09		              // 模块 发射状态定义
#define SI4432_PWRSTATE_RX		5		                 // 模块 接收状态定义
#define SI4432_PACKET_SENT_INTERRUPT	4		        // 模块 发射完成中断
#define SI4432_Rx_packet_received_interrupt   0x02      // 模块 收到数据包中断

#define  TX1_RX0	spi_rw(0x0e|0x80, 0x01)		// 发射状态的天线开关定义
#define  TX0_RX1	spi_rw(0x0e|0x80, 0x02)		// 接收状态的天线开关定义
#define  TX0_RX0	spi_rw(0x0e|0x80, 0x00)         // 非发射，接收状态的天线开关定义



//tx宏
#define  TX_SUCCESS  1
#define  TX_TIMEOUT  2
#define  TX_RSSI_CHANNLE_OCCUPANCY 3
#define  TX_FAIL  0

//RX宏
#define RX_NO_RECIVER  0


	/* Configure P04-NSEL P07-SCLK P05-MOSI pins */
	 /* Configure P06-MISO pins */
	  /* Configure P03-NIRQ pins */
	  	/* Configure P41-SDN pins */


#define GET_SDO   P06

#define GET_NIRQ  P03

#define SDI_UP     P05=1 
#define SDI_DOWN   P05=0

#define SCK_UP     P07=1  
#define SCK_DOWN   P07=0

#define nSEL_UP    P04=1  
#define nSEL_DOWN  P04=0

#define SDN_UP     P41=1 
#define SDN_DOWN   P41=0


//指示433 RECIVED
#define LED_UP    //DrvGPIO_SetBit(E_PORT3, E_PIN7) 
#define LED_DOWN  //DrvGPIO_ClrBit(E_PORT3, E_PIN7)


void initsi4432(void) ;
unsigned char spi_rw(unsigned char addr, unsigned char data);
unsigned char spi_byte(unsigned char data);
void SI4432_init(void);
void rx_data(void);
void clr_interruput_si4432(void);
unsigned char tx_data(unsigned char *pt,unsigned char leg);
 signed char save_rec_data(unsigned char *recbuf_pt);
unsigned char RE_RSSI(void);
 unsigned char Check_si4432_HW(void);
 void  Si4432Thread(uint32_t t);
 #define SI4432BUFNUM 8
  #define SI4432MSGLEN	8

typedef struct
{
	unsigned char  b_Used;
	unsigned char msglen;
	unsigned char  sendbuf[SI4432MSGLEN];
}SI4432_buf;
#endif
