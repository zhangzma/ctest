// Copyright (c) www.bjfz.cc
// memchr.cc

#include <iostream>
#include <cstring>
// #include <syslib.h>

int main(int argc, char *argv[])
{
    const char *ps = "Hell, Memchr.";
    char *p;
    // clrscr();

    p = (char*)memchr(ps, 'e', strlen(ps));
    if (p) {
        std::cout << p << std::endl;
    }
    else {
        std::cout << "Not Found!" << std::endl;
    }

    return 0;
}

