/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file matrix.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "matrix.h"

Matrix::Matrix()
    : _row(0),
      _col(0),
      _value(NULL)
{

}


Matrix::Matrix(size_t m, size_t n)
    : _row(m),
      _col(n)
{
    _value = new uint32_t*[_row];

    for (size_t i=0; i<_row; i++) {
        _value[i] = new uint32_t[_col];
        for (size_t j=0; j<_col; j++) {
            _value[i][j] = 1.0;
        }
    }
}

Matrix::~Matrix()
{
    clear_matrix();
}

uint32_t Matrix::get(size_t m, size_t n)
{
    if (_value != NULL && m < _row && n < _col) {
        return _value[m][n];
    } else {
        return 0;
    }
}

void Matrix::set_matrix(uint32_t **value, size_t m, size_t n)
{
    if (_value != NULL && (m != _row || n != _col)) {
        clear_matrix();

        _row = m;
        _col = n;
        _value = new uint32_t*[_row];

        for (size_t i=0; i<_row; i++) {
            _value[i] = new uint32_t[_col];
        }
    }

    for (size_t i=0; i<_row; i++) {
        for (size_t j=0; j<_col; j++) {
            _value[i][j] = value[i][j];
        }
    } 
}

/**************************************************************************
 **                    private functions
 *************************************************************************/
void Matrix::clear_matrix()
{
    for (size_t i=0; i<_row; i++) {
        delete _value[i];
    }
    
    delete _value;
}


