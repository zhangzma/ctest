/* main.c */
#include <stdio.h>

typedef int int32_t;

int main(int argc, char *argv[])
{

    int32_t lat = (int32_t)47.378301e7f;
    int32_t lon = (int32_t)8.538777e7f;
    int32_t alt = (int32_t)1200e3f;

    printf("lat = %d, lon = %d, alt= %d\n",
           lat, lon, alt);
    
    return 0;
}


