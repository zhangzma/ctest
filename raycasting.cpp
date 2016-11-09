/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file raycasting.cpp
 *
 * 射线法求解点与多边形的位置关系
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "raycasting.h"

typedef struct
{
    double x;
    double y;
}point;

typedef struct
{
    int numpoint;
    point *pointlist; 
}polygon;

int raycasting(polygon *pol, point *ref)
{
    int count = 0;
    for (int i=0; i<pol->numpoint; ++i) {
        point *p1 = pol->pointlist+i;
        point *p2 = (i == pol->numpoint-1) ?
            pol->pointlist : pol->pointlist+i+1;

        if ((p1->y - ref->y) * (p2->y - ref->y) < 0) {
            double t  = (ref->y - p1->y) / (p2->y - p1->y);
            double xt = p1->x + t*(p2->x-p1->x);
            
            if (ref->x == xt)
                return ONSIDE;
            if (ref->x < xt)
                ++count;
        }
    }
    
    return count%2?INSIDE:OUTSIDE;
}
