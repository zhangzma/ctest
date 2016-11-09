// min_nr.cc

#include <iostream>

/**
 * Find the min value in i1, i2, i3.
 * @param v1
 * @param v2
 * @param v3
 * @return the min value of v1, v2, v3
 */
int min(int v1, int v2, int v3)
{
    int min = v1 < v2 ? v1 : v2;
    min = min < v3 ? min : v3;

    return min;
}

float min(float v1, float v2, float v3)
{
    float min = v1 < v2 ? v1 : v2;
    min = min < v3 ? min : v3;

    return min;
}

char min(char v1, char v2, char v3)
{
    char min = v1 < v2 ? v1 : v2;
    min = min < v3 ? min : v3;

    return min;
}

template<typename T>
void print(T var)
{
    std::cout << var << std::endl;
}

int main(int argc, char *argv[])
{
    int v1 = 3, v2 = 5, v3 = 4;
    float f1 = 45.45, f2 = 3.4, f3 = -5.6;
    char c1 = 'a', c2 = 'D', c3 = 'f';

    std::cout << "(INT): The min value is: " << min(v1, v2, v3) << std::endl;
    std::cout << "(FLOAT): The min value is: " << min(f1, f2, f3) << std::endl;
    std::cout << "(CHAR): The min value is: " << min(c1, c2, c3) << std::endl;
    
    return 0;
}
