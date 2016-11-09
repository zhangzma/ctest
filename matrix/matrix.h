
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

typedef unsigned int uint32_t;

class Matrix
{
public:
    Matrix();
    Matrix(size_t m, size_t n);
    virtual ~Matrix();

    void set_matrix(uint32_t **value, size_t m, size_t n);
    uint32_t get(size_t m, size_t n);

    // Matrix operator-();
    

    // friend Matrix operator+(const Matrix& B);
    // friend Matrix operator-(const Matrix& B);

private:
    void clear_matrix();

private:
    uint32_t **_value;
    size_t     _row;
    size_t     _col;
};


#endif /* _MATRIX_H_ */
