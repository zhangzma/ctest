// eva_matrix.h

#ifndef _EVA_MATRIX_H_
#define _EVA_MATRIX_H_

#include <cstring>
#include <fstream>


namespace eva {

template<unsigned int M, unsigned int N>
class MatrixBase
{
public:
    MatrixBase() : data{}
    {}

    MatrixBase(const MatrixBase<M,N> &m)
    {
        memcpy(data, m.data, sizeof(data));
    }

    MatrixBase(const float *d)
    {
        memcpy(data, d, sizeof(data));
    }

    MatrixBase(const float d[M][N])
    {
        memcpy(data, d, sizeof(data));
    }

    virtual ~MatrixBase(){}

    MatrixBase<N, M> transposed()
    {
        float d[N][M];
        for (unsigned int row = 0; row < M; row++) {
            for (unsigned int col = 0; col < N; col++) {
                d[col][row] = data[row][col];
            }
        }

        MatrixBase<N, M> res(d);
        return res;
    }

friend std::ostream &operator<<(std::ostream &out, const MatrixBase &m)
    {
        for (unsigned int row = 0; row < M; row++) {
            for (unsigned int col = 0; col < N; col++) {
                out << m.data[row][col] << "\t";
            }
            out << std::endl;
        }

        return out;
    }

public:
    /**
     * matrix data[row][col]
     */
    float data[M][N];
};

/**
 * Matrix
 */
template<unsigned int M, unsigned int N >
class Matrix : public MatrixBase<M, N>
{
public:
    Matrix() : MatrixBase<M,N>()
    {}

    Matrix(const Matrix<M,N> &m) : MatrixBase<M, N>(m)
    {
    }

    Matrix(const float *d) : MatrixBase<M,N>(d)
    {
    }

    Matrix(const float d[M][N]) : MatrixBase<M, N>(d)
    {
    }

    
    virtual ~Matrix(){}
};
    
    
    
}

#endif /* _EVA_MATRIX_H_ */
