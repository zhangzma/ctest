/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.c
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "common.h"


int main(int argc, char *argv[])
{
    /* srand(time(NULL)); */
    /* RandDat(300); */

    srand(0x37);
    char txt[100] = {'\0'};
    char sn[100] = {'\0'};
    int  idx = 0;
    
    for (int i = 0; i < 10; i++) {
        txt[idx++] = i + '0';
    }

    for (int i = 0; i < 26; i++) {
        txt[idx+i] = i + 'a';
        txt[idx+i+26] = i + 'A';
    }
    idx += 26*2;

    for (int i = 0; i < idx; i++) {
        int index = rand() % 62;
        if (txt[index] != '#') {
            sn[i] = txt[index];
            txt[index] = '#';
        } else {
            i--;
        }
    }

    printf("sn = %s\n", sn);
    printf("src = %s\n", txt);
    /* printf("sizeof(txt) = %d", idx); */


    return 0;
}




