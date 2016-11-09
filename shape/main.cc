/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * @author zhanghb zhanghb@foxmail.com
 *
 *************************************************************************/
#include "shape.h"

int main(int argc, char *argv[])
{
    Shape *ps;
    Shape *pc = new Circle;
    Shape *pr = new Rectangle;

    pr->draw();

    return 0;
}

