/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 *
 * @author Author email
 *
 *************************************************************************/
#include <iostream>
using namespace std;

void xor_test()
{
    int ival = 2;
    std::cout << ((ival*5) >> 1) << std::endl;
}

void iic_write_byte(unsigned char dat)
{
    for (int i = 0; i < 8; i++) {
        std::cout << ((dat&0x80) != 0) << std::endl;
        dat <<= 1;
    }
}

int main(int argc, char *argv[])
{
    // iic_write_byte(0xE8);
    std::cout << (2^6) << std::endl;
    return 0;
}
