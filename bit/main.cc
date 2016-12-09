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

typedef unsigned char uint8_t;

void print(uint8_t data);


void set_bit(uint8_t* dat, uint8_t pos)
{
    (*dat) |= (1 << pos);
}

void clr_bit(uint8_t* dat, uint8_t pos)
{
    (*dat) &= ~(1<<pos);
}

int main(int argc, char *argv[])
{
    uint8_t data = 0xFF;
    
    printf("clr_bit test:\n");
    for (uint8_t i = 0; i < 8; i++) {
        clr_bit(&data, i);
        print(data);        
    }

    printf("\n\nset_bit test:\n");
    for (uint8_t i = 0; i < 8; i++) {
        set_bit(&data, i);
        print(data);
    }
    
    return 0;
}

void print(uint8_t data)
{
    printf("Data = ");
    for (uint8_t i = 0; i < 8; i++) {
        printf("%d", (data>>(7-i)) & 0x01);
    }

    printf("\n");
}
