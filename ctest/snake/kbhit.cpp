// kbhit.cpp

#include <conio.h>
#include <iostream>

// using namespace std;


int main(int argc, char *argv[])
{
    while (!kbhit()) {
        std::cout << "No key" << std::endl;
    }

    std::cout << "key " << std::endl;
    return 0;
}
