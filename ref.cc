// ref.cc
#include <iostream>
using namespace std;

int& get_value()
{
    static int ival = 0;
    ival++;
    return ival;
}

int main(int argc, char *argv[])
{
    int &vi = get_value();

    vi++;

    std::cout << vi << std::endl;

    int &vi2 = get_value();

    std::cout << vi << std::endl;

    return 0;
}

// int / float / double .... 基本类型
// class struct 复合类型
//

