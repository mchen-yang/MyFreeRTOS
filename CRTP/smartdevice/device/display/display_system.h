
#ifndef __DISPLAY_SYSTEM_H
#define __DISPLAY_SYSTEM_H

#include "display_device.h"

/**********************************************************************
 * 函数名称： AddDisplayDevices
 * 功能描述： 注册多个显示设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/08	     V1.0	  韦东山	      创建
 ***********************************************************************/
void AddDisplayDevices(void);

/**********************************************************************
 * 函数名称： GetDisplayDevice
 * 功能描述： 获得显示设备
 * 输入参数： name-显示设备的名称
 * 输出参数： 无
 * 返 回 值： 成功-PDisplayDevice, 失败-NULL
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/08	     V1.0	  韦东山	      创建
 ***********************************************************************/
PDisplayDevice GetDisplayDevice(char *name);


#endif /* __DISPLAY_SYSTEM_H */
