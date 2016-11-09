// copyright (c) www.bjfz.cc
// mountpoint.cc

#include <iostream>

#define MOUNTPOINT "/fs/microsd"

int main(int argc, char *argv[])
{
    static const char *mountpoint = MOUNTPOINT;
    static const char *log_root = MOUNTPOINT "/log";

    std::cout << "MountPoint: " << mountpoint << "\n"
              << "LogRoot:" << log_root << std::endl;
    
    return 0;
}

