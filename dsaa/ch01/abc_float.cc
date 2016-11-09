// abc_float.cc

#include <iostream>

// calc the value of "a+b+b*c+(a+b-c)/(a+b)+4"
float abc(float a, float b, float c)
{
    return a + b + b*c + (a+b-c) / (a+b) + 4;
}
