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
 * @author Author email
 *
 *************************************************************************/

#include <iostream>
#include "UserInfo.h"

int main(int argc, char *argv[])
{
    UserInfo info;
    info._app = 5.0;
    info._edu = 4.0;
    info._val = 4.0;

    std::cout << "inf.app: " << info._app << "\t"
              << "inf.edu: " << info._edu << "\t"
              << "inf.val: " << info._val << "\n"
              << info.calc_grade() << std::endl;

    return 0;
}
