/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file main.cc
 *
 * stock测试代码
 *
 * 概述：
 *    1. test_date()
 *    2. test_daily_record()
 *    3. test_fund()
 *
 * @author ZhangHb zhaingbo@foxmail.com
 *
 *************************************************************************/
#define _MAIN_C_
#include "fund.h"
#include "gardener.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

void test_gardener();
void test_fund();


int main(int argc, char *argv[])
{
    // test_gardener();
    // test_date();
    // test_daily_record();
    test_fund();

    return 0;
}

void test_gardener()
{
    std::cout << "========== Class Gardener' tests ==========" << std::endl;
    std::cout << "Please input the date: " << std::endl;
    Gardener sdate;
    Gardener sop, shp, slp, sep;

    ifstream in;
    in.open("data.txt");
    if (in) {
        in >> sdate >> sop >> shp >> slp >> sep;
    }
    std::cout << sdate.get_date() << std::endl;
    std::cout << sop.get_value<float>() << std::endl;
}


void test_date()
{
    std::cout << "========== Class Date' tests ==========" << std::endl;
    Date date(2016, 11, 16);
    std::cout << date << std::endl;

    Date date2(2016, 11, 17);

    std::cout << (date < date2) << std::endl;

    Date d3(date2);
    std::cout << d3 << std::endl;

    std::cout << "========== End of tests ==========" << std::endl;
}

void test_daily_record()
{
    std::cout << "========== Class Date' tests ==========" << std::endl;
    Date date(2016, 11, 16);
    DailyRecord dr(date);
    dr.set_price(15.0, 15.9, 14.5, 15.2);

    Date date2(2016, 11, 17);
    DailyRecord dr2(date2);
    dr2.set_price(13.0, 17.9, 14.5, 14.2);
    
    std::cout << dr << std::endl;
    std::cout << dr2 << std::endl;    
    std::cout << (dr < dr2) << std::endl;
}

void test_fund()
{
    std::cout << "========== Fund Date' tests ==========" << std::endl;
    Fund f("300");

    Date date(2016, 11, 16);
    DailyRecord dr(date);
    dr.set_price(15.0, 15.9, 14.5, 15.2);
    f.add_record(dr);

    Date date2(2016, 11, 17);
    DailyRecord dr2(date2);
    dr2.set_price(13.0, 17.9, 14.5, 14.2);
    f.add_record(dr2);
    std::cout << f << std::endl;

    f.read_file("2005-2012.dat");
    std::cout << "f.size() = " << f.size() << std::endl;
    // f.read_file("data.txt");
}

