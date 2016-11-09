/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file string.h
 *
 * 
 * 
 *
 * @author 
 *
 *************************************************************************/
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstdio>

class String
{
public:
    String(const char *str = NULL);
    String(const String &other);
    ~String();

    String &operator=(const String &other);
    String &operator+=(const String &other);
    void print();

private:
    char *m_data;    
};

#endif /* _MYSTRING_H_ */

