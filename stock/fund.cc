/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file fund.cc
 *
 * Fund
 *
 * 
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _FUND_C_
#include "fund.h"
#include <stdio.h>
using std::set;
using std::string;


Fund::Fund(const std::string& name)
    : _name(name)
{
    
}

Fund::~Fund()
{
    
}

void Fund::add_record(const DailyRecord &r)
{
    _records.insert(r);
}

std::ostream& operator<<(std::ostream& os, const Fund& f)
{
    os << "########## Hushen300 ##########" << std::endl;
    std::set<DailyRecord>::iterator beg = f._records.begin();
    while (beg != f._records.end()) {
        os << *beg++ << std::endl;
    }
    
    return os;
}
