/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file file.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _FILE_H_
#define _FILE_H_
#include <string>
#include <cstdio>
using std::string;

class File
{
public:
    File(const char *name);
    virtual ~File();
    
    bool open(const char* name, const char *mode);
    bool open(const char* mode);
    void close();

    // int read();
    int write(const char* buffer, size_t size);
    int write(const char* format, ...);

private:
    string  m_name;
    FILE   *m_fp;
};


#endif /* _FILE_H_ */



