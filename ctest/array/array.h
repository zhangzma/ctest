// array.h
// Copyright (c) 2015 www.eva-tec.com

#ifndef _ARRAY_H_
#define _ARRAY_H_

class CArray
{
public:
    const static int NUM = 3;

    CArray(double a[NUM][NUM]);
    CArray();
    void print();
    virtual ~CArray();

    CArray& operator=(const CArray &rhs);
    const CArray operator+(const CArray &rhs);


private:
    double elems[NUM][NUM];
};

#endif /* _ARRAY_H_ */
