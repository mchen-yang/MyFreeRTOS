/**
 *    ||          ____  _ __
 * +------+      / __ )(_) /_______________ _____  ___
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2021 Bitcraze AB
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
 * crtpservice.c - Implements low level services for CRTP
 */

#include <stdbool.h>
#include <string.h>

/* FreeRtos includes */
#include "FreeRTOS.h"
#include "task.h"

#include "crtp.h"
#include "ledservice.h"
#include "static_mem.h"
#include "param.h"


typedef enum {
  LEDSET  = 0x00,
  LEDGET 	= 0x01,
} LinkNbr;


static bool is_ledInit=false;

static int led0_status = 0;

static uint16_t echoDelay=0;

static void ledSrvTask(void*);
static void ledPortCB(CRTPPacket *packet);
void ledserviceInit(void)
{
  if (is_ledInit)
    return;
#if 0
  //Start the task
  xTaskCreate(ledSrvTask, led_SRV_TASK_NAME, led_SRV_TASK_STACKSIZE, NULL, led_SRV_TASK_PRI, NULL);
#else
	crtpRegisterPortCB(CRTP_PORT_LED, ledPortCB);
#endif
  is_ledInit = true;
}

bool ledserviceTest(void)
{
  return is_ledInit;
}


static void ledPortCB(CRTPPacket *packet){
//	crtpReceivePacketBlock(CRTP_PORT_LED, &packet);
	switch (packet->channel)
	{
		case LEDSET:
			/*根据参数控制led，使用uart假装*/
			led0_status = packet->data[1];
			printf("set led %d as %s \r\n", packet->data[0], packet->data[1] == 1? "on": "off");
			break;
		case LEDGET:
			if(packet->data[0] == 0){
				packet->size = 2;
				packet->data[1] = led0_status;
			}
			crtpSendPacketBlock(packet);
			break;
		default:
			break;
	}

}

static void ledSrvTask(void* prm)
{
  static CRTPPacket p;
	
  crtpInitTaskQueue(CRTP_PORT_LED);

  while(1) {
    crtpReceivePacketBlock(CRTP_PORT_LED, &p);

    switch (p.channel)
    {
      case LEDSET:
        /*根据参数控制led，使用uart假装*/
        led0_status = p.data[1];
        printf("set led %d as %s \r\n", p.data[0], p.data[1] == 1? "on": "off");
        break;
      case LEDGET:
				if(p.data[0] == 0){
					p.size = 2;
					p.data[1] = led0_status;
				}
				crtpSendPacketBlock(&p);
        break;
      default:
        break;
    }
  }
}

PARAM_GROUP_START(ledsrv)
PARAM_ADD(PARAM_UINT16, echoDelay, &echoDelay)
PARAM_GROUP_STOP(ledsrv)
