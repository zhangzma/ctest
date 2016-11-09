/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include <iostream>

#define CONFIG_HAL_BOARD 2

#ifndef CONFIG_HAL_BOARD
#error  CONFIG_HAL_BOARD must be defined to build ArduCopter.
#endif /* CONFIG_BOARD_TYPE */

using namespace std;

template<class T>
class Name
{
public:
    Name(int i)
    {
        _size = i;
        p = new T[i];
    }

    virtual ~Name()
    {
        std::cout << "destroy the linearlist. size = "
                  << _size << std::endl;
        delete[] p;
    }

    int get_val() {
        return _size;
    }

private:
    T *p;
    int _size;
};


int main(int argc, char *argv[])
{
    // Name n{4};
    // std::cout << n.get_val() << std::endl;

    Name<int> n(4);
    return 0;
}
