
#include "uart.h"
#include "string.h"
#include "task.h"

static char stack_a[1024] __attribute__ ((aligned (4)));;
static char stack_b[1024] __attribute__ ((aligned (4)));;
static char stack_c[1024] __attribute__ ((aligned (4)));;

void task_a(void *param)
{
	char c = (char)param;
	putchar(c);
//	while (1)
//	{
//		putchar(c);
//	}
}
void task_c(void *param)
{
	int i;
	int sum = 0;
	
	for (i = 0; i <= 100; i++)
		sum += i;
	put_s_hex("sum = ", sum);
//	while (1)
//	{
//		put_s_hex("sum = ", sum);
//	}
}

int mymain()
{
	create_task(task_a, (void*)'a', stack_a, 1024);
	create_task(task_a, (void*)'b', stack_b, 1024);
	create_task(task_c, 0, stack_c, 1024);
	start_task();
	while(1);
	return 0;
}
