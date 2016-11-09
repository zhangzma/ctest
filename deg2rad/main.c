/* main.c */
#include <stdio.h>
#include <math.h>

#define PI                      3.141592654
#define RAD_TO_DEG              (180 / PI)
#define DEG_TO_RAD              (PI / 180)

int main(int argc, char *argv[])
{

    double tan_2_3 = atan2(1.0, 1.0);
    double deg_tan23 = tan_2_3 * RAD_TO_DEG;
    printf("atan23 = %f, deg_tan23 = %f\n", tan_2_3, deg_tan23);
    
    return 0;
}

