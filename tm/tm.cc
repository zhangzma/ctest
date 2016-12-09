/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file tm.c
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _TM_C_
#include "tm.h"


std::ostream& operator<<(std::ostream& s, const tm_t& tm)
{
    std::cout << (uint16_t)tm.year << "/" 
              << (uint16_t)tm.month << "/" 
              << (uint16_t)tm.day << " "
              << (uint16_t)tm.hour << ":" 
              << (uint16_t)tm.min << ":" 
              << (uint16_t)tm.sec << std::endl;
    return s;
}

void print()
{
    print_info();
}


static void print_info()
{
    std::cout << "print_info" << std::endl;
}






