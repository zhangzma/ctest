/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file gardener.h
 *
 * 一个string辅助类
 *
 * 概述：
 *     1. 对std::string进行修剪处理
 *     2. 将std::string转化成int/float/double等类型。
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _GARDENER_H_
#define _GARDENER_H_

#include "type.h"
#include "date.h"
#include <string>

class Gardener
{
public:
    Gardener(const std::string &str);
    virtual ~Gardener();

    Date get_date();


public:
    enum _trim_t{
        TRIM_NONE = 0,
        TRIM_SPACE,
        TRIM_QUOTATION,
        TRIM_ALL_SYMBAL,
        TRIM_DATE
    };

    // static std::string all_symbal = " \"";

friend std::istream& operator>>(std::istream&, Gardener&);
friend std::ostream& operator<<(std::ostream&, const Gardener&);

private:
    std::string _str;
    std::string _str_orig;
};


#endif /* _GARDENER_H_ */



