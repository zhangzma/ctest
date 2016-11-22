/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file gardener.h
 *
 * Gardener（园丁）类
 *
 * 一个string辅助类。详见gardener.cc
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _GARDENER_H_
#define _GARDENER_H_

#include "type.h"
#include "date.h"
#include <string>
#include <sstream>

class Gardener
{
public:
    Gardener(const std::string &str = "");
    virtual ~Gardener();
    Date get_date();

    template<typename T>
    T get_value()
    {
        trim();
        std::istringstream iss(_str);
        T num;
        iss >> num;
        return num;    
    }

public:
    typedef enum e_trim_t{
        TRIM_NONE = 0,
        TRIM_SPACE,
        TRIM_COMMA,
        TRIM_QUOTATION,
        TRIM_ALL_SYMBAL,
        TRIM_DATE,
        TRIM_AUTO
    }trim_t;

friend std::istream& operator>>(std::istream&, Gardener&);
friend std::ostream& operator<<(std::ostream&, Gardener&);

protected:
    void trim();
    void trim_symbal(char ch);
    void trim_space();
    void trim_comma();
    void trim_quotation();
    void trim_all_symbal();
    void trim_date();
    void trim_auto();
    
private:
    std::string _str;
    std::string _str_orig;
    trim_t      _trim;
};

#endif /* _GARDENER_H_ */

