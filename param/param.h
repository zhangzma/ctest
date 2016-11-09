/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file param.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _PARAM_H_
#define _PARAM_H_

enum ept{
    PRM_NONE = 0,
    PRM_INT,
    PRM_FLT
};

template<class T, typename PT>
class ParamT
{
public:
    static const ept vtype = PT;
    ParamT();
    virtual ~ParamT();

private:
    
};


#endif /* _PARAM_H_ */



