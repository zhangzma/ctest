// main.cc
// Copyright (c) 2015 www.eva-tec.com

#include "array.h"

int main(int argc, char *argv[])
{
    const int LEN = CArray::NUM;
    double elems[LEN][LEN];

    for (int r=0; r<LEN; r++) {
        for (int c=0; c<LEN; c++) {
            elems[r][c] = r*LEN + c;
        }
    }

    CArray a1(elems);
    CArray a2, a3;
    a2 = a1;
    a3 = a1 + a2;

    a1.print();
    a2.print();
    a3.print();     

    return 0;
}

