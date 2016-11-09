// sizeof.cpp
// some tests of the sizeof()
#include <iostream>
#include <cstdio>
#include <cstring>

#define GYRO_PATH "/dev/gyro"

int main(int argc, char *argv[])
{
    const int kMax = 100;
    char sbuf[kMax];
    memset(sbuf, '\0', sizeof(sbuf));
    sprintf(sbuf, "sizeof(sbuf) = %d\n", sizeof(sbuf));
    printf(sbuf);

    char str[30];
    int s = 0;
    sprintf(str, "%s%u", GYRO_PATH, s);
    printf(str);
    return 0;
}

