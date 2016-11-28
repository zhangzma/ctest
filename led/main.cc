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
#include "led.h"

int main(int argc, char *argv[])
{
    led_status_u led_status;
    led_status.status.A = 1;
    led_status.status.B = 1;
    led_status.status.C = 0;
    led_status.status.D = 1;

    printf("sizeof(led_status_u) = %d\n", sizeof(led_status_u));
    printf("led_status_u = 0x%02X\n", led_status);

    for (int i = 0; i < 40; i++) {
        printf("i/10 = %d\n", i/10);
    }

    return 0;
}




