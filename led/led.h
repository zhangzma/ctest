/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file led.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _LED_H_
#define _LED_H_

#include <stdio.h>

typedef signed char   int8_t;
typedef unsigned char uint8_t;

#define ON  0
#define OFF 1

void open()
{
    printf("X");
}

void close()
{
    printf("_");
}

typedef union _led_status_u
{
    uint8_t _led_status;
    struct _led_status_s {
        uint8_t A:1;
        uint8_t B:1;
        uint8_t C:1;
        uint8_t D:1;
    }status;
}led_status_u;


#endif /* _LED_H_ */



