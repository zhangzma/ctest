// eva_vector.h

#include <cstring>
#include <cmath>

#ifndef __EXPORT
#define __EXPORT
#endif /* __EXPORT */

namespace eva {

template<unsigned int  N>
class __EXPORT VectorBase
{
public:
    VectorBase() : data{} {
    }

    VectorBase(const VectorBase<N> &v) {
        memcpy(data, v.data, sizeof(data));
    }

    VectorBase(const float d[N]) {
        memcpy(data, d, sizeof(data));
    }

    virtual ~VectorBase(){}

    float &operator()(const unsigned int i)
    {
        return data[i];
    }

    /**
     * gets the length of this vector.
     */
    float length()
    {
        float len = 0.0f;
        for (unsigned int i = 0; i < N; i++) {
            len += data[i] * data[i];
        }
        
        return sqrt(len);
    }

    
public:
    float data[N];
};

/**
 * Vector向量类
 */
template<unsigned int N>
class Vector : public VectorBase<N>
{
public:
    Vector() : VectorBase<N>() {}
    Vector(const Vector &v) : VectorBase<N>(v) {}
    Vector(const float d[N]) : VectorBase<N>(d) {}
    
    virtual ~Vector(){}
};

    
    
} // end of eva

