/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file builtin.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _BUILTIN_C_
#include "builtin.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "sizeof(g_builtins) = " << sizeof(builtin_s) << std::endl;
    std::cout << g_builtin_count << std::endl;
    return 0;
}


