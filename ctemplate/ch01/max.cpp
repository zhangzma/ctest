// max.cpp

#include <iostream>
#include <string>
#include "max.hpp"

int main(int argc, char *argv[])
{
    int i1, i2;
    i1 = 3;
    i2 = 5;
    std::cout << man(i1, i2) << std::endl;

    float f1, f2;
    f1 = 3.4;
    f2 = -4.5;
    std::cout << man(f1, f2) << std::endl;

    std::string s1, s2;
    s1 = "zhang";
    s2 = "zhaingbo";
    std::cout << man(s1, s2) << std::endl;

    // std::complex c1, c2;
    // std::cout << max(c1, c2)<< std::endl;
    
    return 0;
}

