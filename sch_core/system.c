/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file system.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _SYSTEM_C_
#include "system.h"

void sys_init()
{
    sys_count = 0;
}

void sys_update_count()
{
    sys_count++;
    if (sys_count >= 1000) {
        sys_count++;
    }
}


