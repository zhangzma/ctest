/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file UserInfo.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _USERINFO_H_
#define _USERINFO_H_

class UserInfo
{
public:
    UserInfo();
    virtual ~UserInfo();

    float calc_grade();

    static float correction_app(float app);
public:
    float _app;
    float _edu;
    float _val;

    static float scale;
};

#endif /* _USERINFO_H_ */



