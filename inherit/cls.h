/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file cls.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _CLS_H_
#define _CLS_H_

#include <iostream>

class Base
{
public:
    Base() {
        _ival = 10;
    }
    virtual ~Base(){}

public:
    void pb()
    {
        std::cout << "Base::pb()." << std::endl;
    }
    
private:
    int _ival;

};

class Derive : Base
{
public:
    Derive() {}
    virtual ~Derive() {}

public:
    void pd()
    {
        std::cout << "Derive::pd()." << std::endl;
        std::cout << _ival << std::endl;
        pb();
    }
};



#endif /* _CLS_H_ */



