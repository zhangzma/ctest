/* modf.c */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float dval = 1000.25;
    float df;
    float ival;

    df = modff(dval, &ival);

    printf("ival = %d, df = %f\n", (int)ival, df);
    
    return 0;
}
