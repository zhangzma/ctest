//
#include <iostream>
#include "my_math.h"


int main(int argc, char *argv[])
{
    math::Vector<2> sp(1.0, 25.8);
    sp.print();

    
    float d[2] = {2.1, 3.2};
    
    sp.set(d);
    sp.print();

    for (int i=0; i<2; i++) {
        sp(i) = i * 4.0 + sp(i);
        
        std::cout << "sp(" << i << ") = "
                  << sp(i) << std::endl;
    }

    sp.print();

    return 0;
}

