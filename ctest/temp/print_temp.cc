// print_temp.cc

#include <iostream>
#include <string>

/**
 * Print the infomation.
 * @param var -- the infomation to print.
 */
template<typename T>
void print(const T& var)
{
    std::cout << var << std::endl;
}

int main(int argc, char *argv[])
{
    std::string str("Hello World");
    const int num(1234);

    print(str);
    print(num);
    
    return 0;
}

