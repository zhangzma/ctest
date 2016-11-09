
/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file Person.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include "UserInfo.h"
#include "ChatInfo.h"
#include "DateInfo.h"


class Persion
{
public:
    Persion(std::string name);
    virtual ~Persion();

private:
    std::string _name;
    int         _calc_tm;
    UserInfo    _self;
    UserInfo    _partner;

    ChatInfo    _chat;
    DateInfo    _date;
};


#endif /* _PERSON_H_ */


