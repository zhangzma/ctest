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

#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;

uint16_t check_sum(uint8_t *data, uint16_t len)
{
    uint16_t sum(0);
    for (uint16_t i = 0; i < len; i++) {
        sum += *(data+i);
    }
    return sum;
}

uint8_t check_xor(uint8_t mydata[], uint8_t len)
{
    uint8_t sum(0);

    for (uint8_t i = 0; i < len; i++) {
        sum ^= mydata[i];
    }
    return sum;
}

int main(int argc, char *argv[])
{
    const uint16_t LEN = 10;
    uint8_t data[LEN] = {0x01, 0x2C, 0x01, 0x2C, 0x01, 0x2C, 0x01, 0x2C, 0xB4, 0x6A};
    uint16_t sum = check_sum(data, LEN);

    printf("sum = 0x%04X\n", sum);
    printf("sum = 0x%04X\n", get_checksum(data, LEN));

    return 0;
}


