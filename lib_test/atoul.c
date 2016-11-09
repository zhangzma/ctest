// copyright (c) 2015 www.eva-tec.com
// atoul_test.c

#include <stdio.h>
#include <stdlib.h>

void usage()
{
    printf("Usage: str2ul [data]\n");
}

int main(int argc, char *argv[])
{
    char *endptr = NULL;
    unsigned int uival;
    
    if (argc > 1) {
        uival = strtoul(argv[1], &endptr, 0);
        printf("uival = %u\n", uival);
        printf("endPtr = %s\n", endptr);
    }
    else {
        usage();
    }

    return 0;
}
