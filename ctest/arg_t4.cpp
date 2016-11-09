/****************************************************************************
 *
 * File Name: arg_t3.cpp
 *
 * Copyright (c) 2015 Eva Information and Technology Co., Ltd.
 * All rights reserved.
 *
 ***************************************************************************/
#include <cstdio>
#include <cstdarg>

namespace eva {
	void va_fun(int start, ...);
} // eva

int main(int argc, char* argv[])
{
	eva::va_fun(100, -1);
	eva::va_fun(100, 200, -1);

	return 0;
}

void eva::va_fun(int start, ...)
{
	va_list arg_ptr;
	int nargvalue =start;
	int nargcout  = 0;        //可变参数的数目
	va_start(arg_ptr, start); //以固定参数的地址为起点确定变参的内存起始地址。
	do
	{
		++nargcout;
		printf("the %d th arg: %d\n", nargcout, nargvalue);    // 输出各参数的值
		nargvalue = va_arg(arg_ptr, int);                      // 得到下一个可变参数的值
	} while (nargvalue != -1);
}
