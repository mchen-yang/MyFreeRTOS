#include "uart.h"
#include "exception.h"
#include "systick.h"
#include "led.h"
#include "task.h"


void SysTickInit(void)
{
	SysTick_Type *SysTick = (SysTick_Type *)SysTick_BASE;
	/* 1. set period : 1S  */
	/* 2. set Load */
	SysTick->VAL  = SYSTICK_FRE/100;
	SysTick->LOAD = SYSTICK_FRE/100;
	
	/* 3. select clk source, enable systick, enable exception 
	 *  BIT[2] : clk source, process clk
	 *  BIT[1] : enable exception
	 *  BIT[0] : enable systick
	 */
	SysTick->CTRL = (1<<2) | (1<<1) | (1<<0);
}

void SysTick_Handler(int lr_bak, int old_sp)
{
	int stack;
	int pre_task;
	int new_task;
	SCB_Type * SCB = (SCB_Type *)SCB_BASE_ADDR;
		
	/* clear exception status */
	SCB->ICSR |= SCB_ICSR_PENDSTCLR_Msk;

	/* 如果还没有创建好任务, 直接返回 */
	if (!is_task_running())
	{
		return;
	}
	
	/* 启动第1个任务或者切换任务 */
	if (cur_task == -1)
	{
		/* 启动第1个任务 */
		cur_task = 0;
		
		/* 从栈里恢复寄存器 */
		/* 写汇编 */
		stack = get_stack(cur_task);
		StartTask_asm(stack, lr_bak);
	}
	else{
		//软保护
		//更新sp
		pre_task = cur_task;
		new_task = next_task(pre_task);
		
		if(pre_task != new_task)
		{
			set_task_stack(pre_task, old_sp);
			stack = get_stack(new_task);
			cur_task = new_task;
			StartTask_asm(stack, lr_bak);
		}

	}
}