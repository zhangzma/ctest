// radians.cpp
// ################################################################################
// #
// #   Copyright (c) 2015 www.bjfz.com. All rights reserved.
// #
// # 说明：
// ################################################################################


#include <iostream>
#include <string>
#include <cmath>

const double PI    = 3.141592654;      // 
const double EPSON = 0.00000001;       // 


double radians(double degree)
{
    return (degree/180.0) * PI;
}

int main(int argc, char *argv[])
{
    for (int d=30; d<=360; d+=30) {
        std::cout << d <<  "^o=" << radians(d) << std::endl;
        std::cout << "sin(" << d << "f^o)="
                  << sin(radians(d))<< std::endl;
        std::string str = (fabs(sin(radians(d))) < EPSON) ? "Zero" : "NO Zero";
        std::cout << str  << std::endl;
    }

    return 0;
}
