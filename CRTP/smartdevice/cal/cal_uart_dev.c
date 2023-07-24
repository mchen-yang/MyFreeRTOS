
#include <cal_uart_dev.h>

extern void USART3_SendBytes(char *buf, int len);

/**********************************************************************
 * 函数名称： CAL_UART3Write
 * 功能描述： 芯片抽象层函数,通过UART3发出多个数据
 * 输入参数： Data-数据缓冲区
 * 输入参数： iLen-数据长度
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期       版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2021/10/15	     V1.0	  韦东山	      创建
 ***********************************************************************/
int CAL_UART3Write(char *Data, int iLen)
{
	USART3_SendBytes(Data, iLen);
	return 0;
}
