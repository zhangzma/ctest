/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file fence.h
 *
 * Abstract
 *
 * Detail
 *
 * @author Author zhanghaibo@bjfz.cc
 *
 *************************************************************************/
#ifndef _FENCE_H_
#define _FENCE_H_


class Polygon
{
public:
    Polygon(int count)
    {
        _count = count;
    }
    
    virtual ~Polygon() {}

    int count()
    {
        return _count;
    }

private:
    int _count;
};

class Fence
{
public:
    Fence(int count) : 
        _polygon(count)
    {

    }

    virtual ~Fence(){}
    Polygon &polygon(int id)
    {
        return _polygon;
    }

private:
    Polygon _polygon;
};




#endif /* _FENCE_H_ */





