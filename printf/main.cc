// main.cc

#include <iostream>
#include <cstdio>
#include <string.h>

void test_sprintf();
int main(int argc, char *argv[])
{
    // int ival = 0x0034;
    // int *pi = &ival;
    // printf("ival = 0x%04x, pi = %p\n", ival, pi);

    test_sprintf();

    return 0;
}

void test_sprintf()
{
    char str[80];
    int  n;
    char *pstr = str;

    n = sprintf(str, "Fly mode changed: old mode = %d, current mode = %d. changed reaseon: %d",
                1, 2, 3);

    printf("str = %s\n", pstr);
    printf("n = %d\n", n);
    printf("strlen(pstr) = %d\n", strlen(pstr));
}

