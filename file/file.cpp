/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file file.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _FILE_C_
#include "file.h"
#include <stdarg.h>

File::File(const char *name)
    : m_name(name),
      m_fp(NULL)
{
    
}

File::~File()
{
    this->close();
}

bool File::open(const char* name, const char *mode)
{
    m_name = name;
    return this->open(mode);
}

bool File::open(const char *mode)
{
    m_fp = fopen(m_name.c_str(), mode);
    return (m_fp != NULL);
}


void File::close()
{
    if (m_fp) {
        fclose(m_fp);
    }
}


int File::write(const char* buffer, size_t size)
{

    return size;
}

int File::write(const char* format, ...)
{
    if (!m_fp) {
        open(m_name.c_str(), "a");
    }

    if (m_fp) {
        va_list ap;
        va_start(ap, format);
        fprintf(m_fp, format, ap);
        va_end(ap);
    }

    return 0;
}


