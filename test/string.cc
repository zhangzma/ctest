/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file string.cc
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "mystring.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

String::String(const char *str)
{
    if (str != NULL) {
        int len = sizeof(str);
        m_data = new char(len+1);
        strcpy(m_data, str);
    } else {
        m_data = NULL;
    }
}

String::String(const String &other)
{
    if (other.m_data != NULL) {
        int len = sizeof(other.m_data);
        m_data = new char(len+1);
        strcpy(m_data, other.m_data);
    } else {
        m_data = NULL;
    }
}


String::~String()
{
    if (m_data != NULL) {
        delete m_data;
    }
}

String &String::operator=(const String &other)
{
    if (&other != this) {
        if (other.m_data != NULL) {
            int len = sizeof(other.m_data);
            m_data = new char(len+1);
            strcpy(m_data, other.m_data);
        } else {
            m_data = NULL;
        }        
    }

    return *this;
}

String& String::operator+=(const String &other)
{
    int len  = sizeof(m_data);
    len     += sizeof(other.m_data);

    char *pdata = new char(len+1);
    strcpy(pdata, m_data);
    strcpy(pdata+sizeof(m_data), other.m_data);

    delete m_data;
    m_data = pdata;
    
    return *this;
}

void String::print()
{
    if (m_data != NULL) {
        std::cout << m_data << std::endl;
    } else {
        std::cout << "String is NULL." << std::endl;
    }
}

int main(int argc, char *argv[])
{
    char *str = "HelloWorld";
    String S1(str);
    String S2(S1);
    String S3;

    S3 = S2;

    S1.print();
    S2.print();
    S3.print();

    S3 += S2;
    S3.print();

    return 0;
}

