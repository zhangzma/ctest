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
#include "gardener.h"
#include <fstream>
#include <cstdio>
#include <string.h>
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

void Fund::read_file(const char* fn)
{
    std::ifstream infile;
    Gardener sdate;
    Gardener sop, shp, slp, sep;
    
    infile.open(fn);
    if (infile) {
        char sink[1024];
        infile.getline(sink, 1024);
        reset();

        while (!infile.eof()) {
            infile >> sdate >> sop >> shp >> slp >> sep;
            DailyRecord dr(sdate.get_date());
            dr.set_price(sop.get_value<float>(), shp.get_value<float>(), 
                         slp.get_value<float>(), sep.get_value<float>());

            this->add_record(dr);
        }
        infile.close();

        // std::cout << *this << std::endl;
    }
}

uint32_t Fund::size() const
{
    return _records.size();
}


std::ostream& operator<<(std::ostream& os, const Fund& f)
{
    os << "########## " << f._name << " ##########" << std::endl;
    std::set<DailyRecord>::iterator beg = f._records.begin();
    while (beg != f._records.end()) {
        os << *beg++ << std::endl;
    }
    
    return os;
}

/**************************************************************************
 **                    Protected Functions
 *************************************************************************/
void Fund::reset()
{
    _records.clear();
}
