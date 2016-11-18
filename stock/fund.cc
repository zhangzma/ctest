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
#include <fstream>
#include <cstdio>
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
    std::string sdate, sop, shp, slp, sep;
    std::ifstream infile;
    infile.open(fn);
    if (infile) {
        while (!infile.eof()) {
            infile >> sdate >> sop >> shp >> slp >> sep;
            std::cout << sdate << "\t"
                      << sop << "\t"
                      << shp << "\t"
                      << slp << "\t"
                      << sep << std::endl;    
        }
        infile.close();
    }
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
