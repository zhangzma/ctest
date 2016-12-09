


#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int ival = 20, ival2 = 10;
    int* const pival = &ival;
    *pival = 30;
    pival = &ival2;

    return 0;
}
