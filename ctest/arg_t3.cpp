/****************************************************************************
 *
 * File Name: arg_t3.cpp
 *
 * Copyright (c) 2015 Eva Information and Technology Co., Ltd.
 * All rights reserved.
 *
 ***************************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdarg>
namespace eva {
	/*函数 原型声明，至少需要一个确定的参数，注意括号内的省略号*/
	int demo(const char *, ... );
} // eva

int main(int argc, char const *argv[])
{
	eva::demo("demo", "this", "is", "a", "demo!", "");

	return 0;
}

/*ansi标准形式的声明方式，括号内的省略号表示可选参数*/
int eva::demo(const char *msg, ...)
{
	/*定义保存函数 参数的结构*/
	va_list argp;
	int  argno = 0;
	char *para = NULL;

	/*argp指向传入的第一个可选参数，msg是最后一个确定的参数*/
	va_start(argp, msg);
	while (1)
	{
		para = va_arg(argp, char*);
		if (strcmp( para, "") == 0)
			break;
		printf("parameter #%d is: %s ", argno, para);
		argno++;
	}
	/*将argp置为null*/
	va_end(argp);

	return 0;
}
