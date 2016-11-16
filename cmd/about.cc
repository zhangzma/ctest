/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file about.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _ABOUT_C_
#include "about.h"
#include <stdio.h>

void print_main_menu()
{
    printf("========== Smart Plug v1.0 ==========\n");
    printf("i: Info\n");
    printf("c: Create a new MODE.\n");
    printf("d: Delete an exist MODE.");
    printf("v: View all the MODE.\n");
}

void print_info()
{
    printf("========== About ==========\n");
    printf("No Smart Plug, Ver 1.00.\n");
    printf("\n");
    print_main_menu();
}

void print_all_mode()
{
    printf("all mode.");
}

