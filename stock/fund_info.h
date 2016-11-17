/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file fund_info.h
 *
 * Fund基本信息
 *
 * 
 *
 * @author Zhanghb zhaingbo@foxmail.com
 *
 *************************************************************************/
#ifndef _FUND_INFO_H_
#define _FUND_INFO_H_

#include <string>
using std::string;

class FundInfo
{
public:
    FundInfo(cosnt string &name)
        : _name(name)
    {

    }

    virtual ~FundInfo()
    {
    }

private:
    string _name;
};


#endif /* _FUND_INFO_H_ */



