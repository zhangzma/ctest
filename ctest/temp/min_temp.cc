// min_temp.c
#include <iostream>

/**
 * Find the min value of v1, v2, v3. Template implementation
 * @param v1 -- first value
 * @param v2 -- second value
 * @param v3 -- third value
 * @return the min value
 */
template<typename T>
T min(T v1, T v2, T v3)
{
    T min = v1 < v2 ? v1 : v2;
    min = min < v3 ? min : v3;

    return min;
}

struct Int {
    int val;
};

int min(Int i1, Int i2, Int i3)
{
    Int min = i1.val < i2.val ? i1 : i2;
    min = min.val < i3.val ? min : i3;

    return min.val;    
}

int main(int argc, char *argv[])
{
    int v1 = 3, v2 = 5, v3 = 4;
    float f1 = 45.45, f2 = 3.4, f3 = -5.6;
    char c1 = 'a', c2 = 'D', c3 = 'f';

    std::cout << "(INT): The min value is: " << min(v1, v2, v3) << std::endl;
    std::cout << "(FLOAT): The min value is: " << min(f1, f2, f3) << std::endl;
    std::cout << "(CHAR): The min value is: " << min(c1, c2, c3) << std::endl;
    std::cout << min("anderson", "Wash", "Smith") << std::endl;

    Int I1, I2, I3;
    I1.val = v1;
    I2.val = v2;
    I3.val = v3;
    std::cout << min(I1, I2, I3) << std::endl;

    return 0;
}
