/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file task.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _TASK_C_
#include "task.h"
#include <stdio.h>
static void task(const char *task_name);
static void print_led_status(uint32_t led_status);

void task1(void *pdat)
{
    const char *name = "1";
    task(name);
}

void task2(void *pdat)
{
    const char *name = "2";
    task(name);
}

void task3(void *pdat)
{
    const char *name = "3";
    task(name);
}

void task4(void *pdat)
{
    const char *name = "4";
    task(name);
}

void task5(void *pdat)
{
    static uint32_t led = 0;
    led = !led;
    print_led_status(led);
}

void task(const char *task_name)
{
    printf("%s", task_name);
}


void print_led_status(uint32_t led_status)
{
    printf("%d", led_status);
}
