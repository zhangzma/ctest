/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file cmd.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _CMD_C_
#include "cmd.h"
#include "about.h"
#include <string>
#include <iostream>
using namespace std;

string cmd_input()
{
    string input;
    std::cin >> input;
}

void exec_cmd(cmd_t cmd)
{
    switch (cmd) {
    case CMD_I:
        print_info();
        break;
    case CMD_C:
        break;
    case CMD_D:
        break;
    case CMD_V:
        print_all_mode();
        break;
    default:
        break;
    }

    print_main_menu();
}

