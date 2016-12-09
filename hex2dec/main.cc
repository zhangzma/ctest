

#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned char uint8_t;

uint8_t hex2dec(uint8_t dat)
{
    dat &= 0x0f;

    if (dat <= 9)	{
        return (dat + '0');
    } else {
        return (dat + 'A' - 0xa);
    }
}

int main(int argc, char *argv[])
{
    for (uint8_t i = 0; i < 200; i++) {
        printf("%c\t", hex2dec(i));
        if (!((i+1) %10)) {
            printf("\n");
        }

    }

    
    return 0;
}

