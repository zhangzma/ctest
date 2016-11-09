// c05.cpp
// ################################################################################
// #
// #   Copyright (c) 2015 www.bjfz.com. All rights reserved.
// #
// # 说明：
// ################################################################################

#include <iostream>

template<typename T>

void swap(T &t1, T &t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;    
}

int main(int argc, char *argv[])
{
    int x, y, z;
    std::cout << "Please input three number: " << std::endl;
    std::cin >> x >> y >> z;

    if (x > y) {
        swap(x, y);
    }

    if (x > z) {
        swap(x, z);
    }

    if (y > z) {
        swap(y, z);
    }

    std::cout << x << " "
              << y << " "
              << z << std::endl;
    return 0;
}

