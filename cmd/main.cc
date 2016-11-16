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
#include "about.h"
#include "arg_parse.h"
#include "cmd.h"
#include <string>

int main(int argc, char *argv[])
{
    cmd_t cmd = CMD_I;
    string input;
    while (cmd != CMD_Q) {
        print_main_menu();
        input = cmd_input();
        parse_input(input, cmd);
        exec_cmd(cmd);
    }
    return 0;
}



