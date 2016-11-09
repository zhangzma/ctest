// main.cc

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    int ival = 0x0034;
    int *pi = &ival;
    printf("ival = 0x%04x, pi = %p\n", ival, pi);

    return 0;
}

