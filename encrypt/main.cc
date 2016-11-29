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
#include "encrypt.h"

#include <cstdio>
#include <cstring>
#include <iostream>


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("ec 1.0.0 bate \n");
        printf("ec password/encrypt\n");
        return 1;
    }

    char *pstr = argv[1];
    uint8_t pl[50]={'\0'};
    uint8_t en[50]={'\0'};
    uint16_t len = strlen(argv[1]);
    memcpy(pl, pstr, len);
    // printf("pl = %s\n", pl);
    
    encrypt_epri(pl, len, en, len);
    printf("en = %s\n", en);

    printf("\n");
    return 0;
}

