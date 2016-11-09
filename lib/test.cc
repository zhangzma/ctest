// test.cc

#include <iostream>
#include "eva_vector.h"
#include "eva_matrix.h"

int main(int argc, char *argv[])
{
    float d[2][3] = {{1.0, 2.0, 3.0},
                     {4.0, 5.0, 6.0}};
    // eva::Vector<2> vec(d);
    eva::Matrix<2, 3> mtx(d);


    std::cout << "(A) = \n"
              << mtx << std::endl;
    
    std::cout << "(A)T = \n"
              << mtx.transposed() << std::endl;

    return 0;
}
