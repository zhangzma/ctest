/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file gardener.cc
 *
 * Gardener类实现
 *
 * 概述：
 *     0. std::string辅助类，根据指定的需求格式化字符串数据
 *     1. 对std::string进行修剪处理
 *     2. 将std::string转化成int/float/double等类型。
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _GARDENER_C_
#include "gardener.h"
#include <iostream>
#include <sstream>

Gardener::Gardener(const std::string &str)
    : _str_orig(str),
      _str(str),
      _trim(TRIM_NONE)
{
    
}

Gardener::~Gardener()
{

}

Date Gardener::get_date()
{
    std::istringstream iss(_str);
    uint16_t year(2016);
    int16_t  month(01), day(01);
    if (_str.find('-') != std::string::npos) {
        iss >> year >> month >> day;
        month = month < 0? -month : month;
        day   = day < 0 ? -day : day;

    } else {
        // TODO: 对于"11/02/2006"格式的日期暂时采用该处理方案。
        char c;
        iss >> month >> c >> day >> c >> year;
    }

    Date date(year, month, day);    
    return date;
}

/**************************************************************************
 **                    Protected Functions
 *************************************************************************/
void Gardener::trim()
{
    switch (_trim) {
    case TRIM_SPACE:
        trim_space();
        break;
    case TRIM_COMMA:
        trim_comma();
        break;
    case TRIM_QUOTATION:
        trim_quotation();
        break;
    case TRIM_ALL_SYMBAL:
        trim_all_symbal();
        break;
    case TRIM_DATE:
        trim_date();
        break;
    default:
        // trim_auto();
        break;
    }
}

void Gardener::trim_symbal(char ch)
{
    // _str = _str_orig;
    std::string::size_type pos = 0;
    while (pos = _str.find(ch), pos != std::string::npos) {
        _str.erase(pos, 1);
    }
}

void Gardener::trim_space()
{
    trim_symbal(' ');
}

void Gardener::trim_comma()
{
    trim_symbal(',');
}

void Gardener::trim_quotation()
{
    trim_symbal('"');
}

void Gardener::trim_all_symbal()
{
    std::cout << "trim_all_symbal() no implement" << std::endl;
}

void Gardener::trim_date()
{
    std::cout << "trim_date() no implement" << std::endl;
}

void Gardener::trim_auto()
{
    std::cout << "trim_auto() no implement" << std::endl;
}

std::istream& operator>>(std::istream& s, Gardener& c)
{
    s >> c._str_orig;
    c._str = c._str_orig;
    c.trim_space();
    c.trim_comma();
    c.trim_quotation();

    return s;
}

std::ostream& operator<<(std::ostream& s, Gardener& c)
{
    c.trim_space();
    s << c._str;
    return s;
}

