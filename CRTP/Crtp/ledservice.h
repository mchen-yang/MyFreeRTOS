/**
 *    ||          ____  _ __                           
 * +------+      / __ )(_) /_______________ _____  ___ 
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2012 Bitcraze AB
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
 * link.h - Used to send/receive link packats
 */

#ifndef __LEDSERVICE_H__
#define __LEDSERVICE_H__

#include <stdbool.h>

#define led_SRV_TASK_STACKSIZE       150
#define led_SRV_TASK_NAME      "led-SRV"
#define led_SRV_TASK_PRI       0
/**
 * Initialize the link task
 */
void ledserviceInit(void);

bool ledserviceTest(void);


#endif /* __CRTPSERVICE_H__ */

