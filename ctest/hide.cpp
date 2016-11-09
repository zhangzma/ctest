// hide.cpp
#include <iostream>

class Base
{
public:
    Base(){}
    virtual ~Base(){}

    virtual void f() const
    {}
};

class Drive : public Base
{
public:
    Drive() : Base()
    {}
    virtual ~Drive(){}

    virtual void f();
};

int main(int argc, char *argv[])
{
    
    return 0;
}

