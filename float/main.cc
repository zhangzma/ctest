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
#include <cstdio>


int main(int argc, char *argv[])
{
    const static float cof = 1.0e7f;
    const static float ncof = 1.0e-7f;

    float fval = 3.1415926;
    fval *= ncof;

    printf("fval=%.17f", fval);
    
    return 0;
}

