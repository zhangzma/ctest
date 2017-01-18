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
#include "file.h"

int main(int argc, char *argv[])
{
    File log("app.log");
    log.open("a");
    log.write("log1");
    log.close();
    return 0;
}


