/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include <iostream>
#include <stdio.h>
#include "mode_report.h"

int main(int argc, char *argv[])
{
    AC_ModeReport mr;
    mr.report(AUTO, ALT_HOLD);

    control_mode_t mode;
    mode = (control_mode_t)33;
    
    std::cout << "mode = " << mode << std::endl;
    
    return 0;
}
