/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file common.h
 *
 * 功能函数声明
 *
 * @author zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned short uint16_t;

void RandDat(uint16_t num_count)
{
    while (num_count--) {
        int num = rand() % 1000;
        printf("%03d \t", num);
        if (num_count % 10 == 0) {
            printf("\n");
        }

    }
}

#endif /* _COMMON_H_ */



