/*
 * lib_test.c
 */

#include "eva_random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    eva::Random rd;
    printf("random data is %d\n", rd.data());
    return 0;
}

