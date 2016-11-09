/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file UserInfo.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "UserInfo.h"

float UserInfo::scale = 0.5;

UserInfo::UserInfo()
    : _app(1.0),
      _edu(0.0),
      _val(0.0)
{

}

UserInfo::~UserInfo()
{

}

float UserInfo::calc_grade()
{
    return scale * (_app + _edu + _val);
}

float UserInfo::correction_app(float app)
{
    float new_value = app - 2;

    if (new_value < 0) {
        new_value = 1.0;
    }

    return new_value;
}
