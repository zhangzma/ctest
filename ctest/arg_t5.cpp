/****************************************************************************
 *
 * File Name: arg_t5.cpp
 *
 * Copyright (c) 2015 Eva Information and Technology Co., Ltd.
 * All rights reserved.
 *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

namespace eva {
	void myprintf(const char* fmt, ...)        //一个简单的类似于printf 的实现，//参数必须都是int 类型
} // eva

int main(int argc, char* argv[])
{
	int i = 1234;
	int j = 5678;

	eva::myprintf("the first test:i=%d ", i, j);
	eva::myprintf("the secend test:i=%d;%x;j=%d; ", i, 0xabcd, j);

	return 0;
}

void eva::myprintf(const char *fmt, ...)
{
    char* parg=null;               //等价于原来的va_list
    char c;

    parg = (char*) &fmt;          //注意不要写成p = fmt !!因为这里要对//参数取址，而不是取值
    parg += sizeof(fmt);         //等价于原来的va_start
    do
    {
    	c = *fmt;
    	if (c != "%")
    	{
            putchar(c);            //照原样输出字符
        }
        else
        {
           //按格式字符输出数据
        	switch(*++fmt)
        	{
        		case"d":
        		printf("%d", *((int*)parg));
        		break;
        		case"x":
        		printf("%#x", *((int*)parg));
        		break;
        		default:
        		break;
        	}
            parg += sizeof(int);               //等价于原来的va_arg
        }
        ++fmt;
    } while (*fmt != '/0');

    parg = null;                               //等价于va_end
    return;
}
