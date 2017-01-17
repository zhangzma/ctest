/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include "log_define.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

#ifndef DEBUG
#   define TRACE(s, ...)
#else
#   define TRACE(s, ...)      \
    {                             \
        printf(s, ##__VA_ARGS__); \
    }
#endif /* DEBUG */


int sum(const char * msg, ...);
int my_vsprintf(char * buf, const char * format, ...);
int test_sprintf();
void TestLogCase_One();

int main(int argc, char * argv[]) //
{
    // test_sprintf();
    TestLogCase_One();

    return 0;
}

void test_trace()
{
    int a(3), b(4), c(9);
    TRACE("[dbg] a=%d, b=%d, c=%d\n", a, b, c);
}



int test_sprintf()
{
    sum("The sum of the list is:", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0);
    cout << endl;

    char buf[256];
    my_vsprintf(buf, "%My name is %s and I am %d years old.", "Ben", 24);
    cout << buf << endl;
    // system("pause");
    return 0;
}

int sum(const char * msg, ...)
{
    va_list st;
    va_start(st, msg);
    int total = 0;
    int tmp;

    while ((tmp = va_arg(st, int)) != 0) {
        total += tmp;
    }

    va_end(st);
    cout << "The sum of the list is: " << total;
    return 0;
}

int my_vsprintf(char * buf, const char * format, ...)
{
    va_list st;
    va_start(st, format);
    vsprintf(buf, format, st);
    /***************************************************************************
     *       函数名: vsprintf                                       　　　　　　
     *       功 能: 送格式化输出到串中
     *       返回值: 正常情况下返回生成字串的长度(除去\0),错误情况返回负值
     *       用 法: int vsprintf(char *string, char *format, va_list param);
     *                将param 按格式format写入字符串string中
     *       注: 该函数会出现内存溢出情况,建议使用vsnprintf                　　 　
     ***************************************************************************/
    va_end(st);
    return 0;
}

void TestLogCase_One()
{
    Write_Log(LOG_TYPE_SYSTEM,
              "malloc memory for pFiled successful,memory size is: %ld",
              1000);

    // pFile = fopen(szFileName, "r");
    // if(NULL == pFile)
    // {
    //     fprintf(stderr, "open file failed.");
    //     Write_Log(LOG_TYPE_ERROR, "Open file %s failed. program exit!", szFileName);
    //     return;
    // }

    // Write_Log(LOG_TYPE_INFO, "Open file %s successful.", szFileName);

    // fread(pFieldContent, 1, TEST_CASE_MAX_FILE_LEN, pFile);
    // pFieldContent[TEST_CASE_MAX_FILE_LEN -1] = '\0';

    // fclose(pFile);
    // printf("The file %s content is: \n%s\n", szFileName, pFieldContent);
    // Write_Log(LOG_TYPE_INFO, "The file %s content is: \n%s\n", szFileName, pFieldContent);
}


void varInputTest(int unusedInt, ...)
{
    va_list itor;
    // va_start 使得 args 指向...的第一个参数的地址，
    // 例如在 varInputTest(1, 2, 3, 4); 的调用情况下，就是指向2
    // 这里第一个参数不用，不过也不好用占位符，毕竟还需要他的名称
    va_start(itor, unusedInt);
    int current = va_arg(itor, int);

    while (current != -1) {
        cout << current << endl;
        current = va_arg(itor, int);
    }

    va_end(itor);
}


void testf_var_input()
{
    varInputTest(0, 1, 2, 3, 4, -1);
}
