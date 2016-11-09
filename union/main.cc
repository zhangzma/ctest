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
#include <iostream>
using namespace std;

typedef union {
    unsigned short sval;
    unsigned int   ival;
    float          fval;
    char           cval[4];
} setvalue;


typedef struct _s_t
{
    setvalue val;
    int      type;
}st;


enum TYPE{
    
};

int main(int argc, char *argv[])
{
    setvalue val;
    val.cval[0] = 178;
    val.cval[1] = 4;
    val.cval[2] = 0;
    val.cval[3] = 0;


    std::cout << "sizeof(val)" << sizeof(val) << std::endl;

    std::cout << val.sval << std::endl;
    std::cout << val.fval << std::endl;


    st tval;


    tval.type = 1;
    tval.val.ival = 0x89;
    
    return 0;
}

