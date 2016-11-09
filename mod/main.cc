// main.cc

#include <iostream>
using namespace std;

const int HOME_FZ = 10;

int main(int argc, char *argv[])
{
    int count = 0;
    while (count < 256) {
        if (count % HOME_FZ == 0) {
            std::cout << "Home Position:" << std::endl;
        }
        std::cout << "Gps Position" << std::endl;

        count++;
    }

    return 0;
}

