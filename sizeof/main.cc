
#include <iostream>

int main(int argc, char *argv[])
{
    char buf[100];

    std::cout << sizeof(buf) << std::endl;


    int iv[200];


    std::cout << sizeof(iv)/sizeof(iv[0]) << std::endl;

    std::cout << sizeof(iv)  << std::endl 
              << sizeof(iv[0]) << std::endl;




    return 0;
}

