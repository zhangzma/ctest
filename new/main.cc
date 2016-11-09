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

using namespace std;

int main(int argc, char *argv[])
{
    int *pi = new int[5];
    int *pheader = pi;

    for (int i=0; i<5; i++) {
        *pi = i;
        pi++;
    }

    pi = pheader;
    for (int i=0; i<5; i++) {
        std::cout << *pi << "\t";
        pi++;
    }
    std::cout << std::endl;

    return 0;
}

