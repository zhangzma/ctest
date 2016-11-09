// wrap_cd.cc
#include <iostream>

typedef unsigned int uint32;
typedef int int32;

uint32 wrap_360_cd(uint32 error)
{
    if (error > 360000 || error < -360000) {
        error %= 36000;
    }

    std::cout << "[debug:] " << error << std::endl;

    while (error >= 36000) {
        error -= 36000;
    }

    while (error < 0) {
        error += 36000;
    }

    return error;
}

/*
  wrap an angle in centi-degrees to -18000..18000
 */
int32 wrap_180_cd(int32 error)
{
    if (error > 360000 || error < -360000) {
        // for very large numbers use modulus
        error = error % 36000;
    }
    while (error > 18000) { error -= 36000; }
    while (error < -18000) { error += 36000; }
    return error;
}

int main(int argc, char *argv[])
{
    uint32 deg;

    std::cout << "Please input the deg:(Ctrl+Z to end)" << std::endl;
    while (std::cin >> deg) {
        std::cout << "wrap_360_cd(" << deg << ") = "
                  << wrap_360_cd(deg*100)/100.0 << std::endl;

        std::cout << "wrap_180_cd(" << deg << ") = "
                  << wrap_180_cd(deg*100)/100.0 << std::endl;
        
        std::cout << "Please input the deg:(Ctrl+Z to end)" << std::endl;
    }
    
    return 0;
}

