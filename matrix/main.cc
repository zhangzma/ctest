/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "matrix.h"

int main(int argc, char *argv[])
{
    Matrix   m(2, 2);
    uint32_t pv[2][2] = {{1, 0}, {0, 1}};

    m.set_matrix(pv, 2, 2);

    for (size_t i=0; i<2; i++) {
        for (size_t j=0; j<2; j++) {
            std::cout << m.get(i,j) << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}


