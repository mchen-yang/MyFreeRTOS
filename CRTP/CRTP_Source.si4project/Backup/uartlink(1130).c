/*
 *    ||          ____  _ __
 * +------+      / __ )(_) /_______________ _____  ___
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2012 BitCraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * uartlink.c
 */

#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "cmsis_os.h"
//#include "uartlink.h"
#include "crtp.h"

static uint8_t isInit = false;
static xQueueHandle crtpPacketDelivery;
static xQueueHandle crtpPacketStore;
TaskHandle_t xUartParserTask;

static uint8_t sendBuffer[64];

static int uartlinkSetEnable(bool enable);

static int uartlinkSendPacket(CRTPPacket *p);

static int uartlinkReceivePacket(CRTPPacket *p);


static struct crtpLinkOperations uartlinkOp =
{
  .setEnable         = uartlinkSetEnable,
  .sendPacket        = uartlinkSendPacket,
  .receivePacket     = uartlinkReceivePacket,
};

/* Radio task handles the CRTP packet transfers as well as the radio link
 * specific communications (eg. Scann and ID ports, communication error handling
 * and so much other cool things that I don't have time for it ...)
 */
static int uartlinkSetEnable(bool enable)
{
  return 0;
}

static int uartlinkReceivePacket(CRTPPacket *p)
{
	//从一个队列里面接受数据
	if(xQueueReceive( crtpPacketDelivery, p, 100) == pdTRUE){
		return 0;
	}
  return -1;
}

static int uartlinkSendPacket(CRTPPacket *p)
{
  int dataSize;
	FILE* f = NULL;
	//发送头部识别
	fputc(p->size, f);
	//发送数据大小
  fputc(p->size, f);
	//发送头->port, reserved, chanel
	fputc(p->header, f);
	
	//发送数据
	for(int i = 0; i < p->size; i++)
		fputc(p->data[i], f);
	//执行发送数据
	
	//返回
  return 1;
}
/*解析数据*/
static int UARTParserPacket(void * params){
	char c;
	int i = 0;
	enum recv_status{
		WAITING = 0,
		GET_SIZE,
		GET_HEADER,
		GET_DATA}status;
	status = WAITING;
	CRTPPacket p;
	while(1){
		xQueueReceive( crtpPacketDelivery, &c, 0 )
		switch(status){
			WAITING:
				if(c != 0x55){
					status++;
				}			
				break;
			GET_SIZE:
				p.size = c;
				status++;
				break;
			GET_HEADER:
				p.header = c;
				i = 0;
				status++;
				break;
			GET_DATA:
				
				p.size[i++] = c;
				if(i == p.size){
					xQueueSend(crtpPacketStore, &p, 100);
					status = WAITING;		
				}
				
				break;
		}
	}
	return 0;
}

/*
 * Public functions
 */

void uartlinkInit()
{
  if(isInit)
    return;
	//创建队列
  crtpPacketDelivery = xQueueCreate(16, sizeof(CRTPPacket));
	crtpPacketStore = xQueueCreate(64, 1);

	
	xTaskCreate(UARTParserPacket, "ParserPacket", 150, NULL, 3, xUartParserTask);
	
  isInit = 1;
}

struct crtpLinkOperations * uartlinkGetLink()
{
  return &uartlinkOp;
}
