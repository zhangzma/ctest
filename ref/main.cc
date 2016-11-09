
#include "fence.h"

#include <iostream>

int main(int argc, char *argv[])
{
    Fence fence(11);

    std::cout << fence.polygon(0).count() << std::endl;

    return 0;
}
