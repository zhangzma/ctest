
// def.cc
#include <iostream>

#define MOUNT_POINT "fs/microsd"
const char * inf_root = MOUNT_POINT "/inf";

int main(int argc, char *argv[])
{
    std::cout << "info root is: " << inf_root << std::endl;
    return 0;
}

