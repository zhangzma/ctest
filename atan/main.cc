// main.cc

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define PI 3.14159265

int main(int argc, char *argv[])
{
	double x, y, result;
	x = 1.0;
	y = sqrt(3.0);
	result = atan2(-x, y) * 180 / PI;
	printf("The arc tangent for (x=%lf, y=%lf) is %lf degrees\n",
			x, y, result);

    return 0;
}

