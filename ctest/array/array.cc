// array.cc
// Copyright (c) 2015 www.eva-tec.com


#include "array.h"
#include <iostream>


CArray::CArray(double a[NUM][NUM])
{
    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < NUM; c++) {
            elems[r][c] = a[r][c];
        }
    }
}

CArray::CArray()
{
    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < NUM; c++) {
            elems[r][c] = 0.0;
        }
    }    
}

CArray::~CArray()
{
    
}


CArray& CArray::operator=(const CArray &rhs)
{
    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < NUM; c++) {
            elems[r][c] = rhs.elems[r][c];
        }
    }

	return *this;
}

const CArray CArray::operator+(const CArray &rhs)
{
    CArray result;
    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < NUM; c++) {
            result.elems[r][c] = elems[r][c] + rhs.elems[r][c];
        }
    }

    return result;
}

void CArray::print()
{
    std::cout << "\nThe Array is:" << std::endl;
    for (int r = 0; r < NUM; r++) {
        for (int c = 0; c < NUM; c++) {
            std::cout << elems[r][c] << "\t";
        }
        std::cout << "\t" << std::endl;
    }
}

