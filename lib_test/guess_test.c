// guess_test.c

#include "my_math.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    char *strData[] = {
        "1212",
        "0x12fe",
        "0123",
        "10001b"
    };
    
    if (argc > 1) {
        int base = lib_guess_base(argv[1]);
        printf("%s's base is %d\n", argv[1], base);
    }

    return 0;
}


