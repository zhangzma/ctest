/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file encrypt.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _ENCRYPT_C_
#include "encrypt.h"
#include <cstdlib>
#include <cstdio>

static uint16_t check_sum(uint8_t *buf, uint16_t len);
static uint8_t  convert(uint8_t ch);

static char sn[100]  = {'\0'};
static int  count = 0;

void encrypt_epri(uint8_t* in, uint16_t in_len, uint8_t* out, uint16_t& out_len)
{
    init_sn(0x35);
    out_len = 0;

    for (uint16_t i = 0; i < in_len; i++) {
        out[out_len++] = convert(in[i]);
    }
}

uint8_t convert(uint8_t ch)
{
    int i;
    for (i = 0; i < count; i++) {
        if (sn[i] == ch) {
            break;
        }
    }

    if (i < count) {
        i += 31;
        if (i >= count) {
            i -= count;
        }
        return sn[i];
    } else {
        return ch;
    }
}

void init_sn(uint8_t sr)
{
    static bool init = false;
    
    if (init) {
        return;
    }

    char txt[100] = {'\0'};
    
    srand(sr);
    count = 0;
    for (int i = 0; i < 10; i++) {
        txt[count++] = i + '0';
    }

    for (int i = 0; i < 26; i++) {
        txt[count++] = i + 'a';
        txt[count++] = i + 'A';
    }
    
    for (int i = 0; i < count; i++) {
        int index = rand() % 62;
        if (txt[index] != '#') {
            sn[i] = txt[index];
            txt[index] = '#';
        } else {
            i--;
        }
    }

    init = true;
}
