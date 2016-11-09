// atan.cc

#include <iostream>
#include <cmath>
#include <errno.h>

int main(int argc, char *argv[])
{
    std::cout << "atan(1) = " << atan(1) << "\n"
              << "atan2f(3.0, 3.0) = " << atan2f(3.0, 3.0) << "\n"
              << std::endl;
    return 0;
}
