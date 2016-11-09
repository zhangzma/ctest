/**************************************************************************
 *
 *   Copyright (c) 2016 www.bjfz.cc. All rights reserved.
 *
 * @file polygon.cpp
 *
 * Abstract
 *
 * Detail
 *
 * @author Author email
 *
 *************************************************************************/
#include "polygon.h"

Polygon::Polygon()
{

}

Polygon::~Polygon()
{

}

void Polygon::add_point(const Point &point)
{
    bool exist = false;
    vector<Point>::iterator beg = _points;
    while (beg != _points.end()) {
        if ((*beg) == point) {
            exist = true;
            break;
        }
        beg++;
    }

    // 若无此点则添加
    if (!exist) {
        _points.push_back(point);
    }
}

void Polygon::delete_point(const Point &point)
{
    vector<Point>::iterator beg = _points;
    while (beg != _points.end()) {
        if ((*beg) == point) {
            _points.erase(beg);
            break;
        }
        beg++;
    }
}

bool Polygon::in_polygon(const Point &p)
{
    e_point_status status;
    int count = 0;

    for (i = 0, j = _nums-1; i < _nums; j = i++) {
        if (((piont[i]._y > point._y) != (poin[j]>testy)) &&
            (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) /
             (verty[j]-verty[i]) + vertx[i]))
            c = !c;
    }

    for (int i = 0; i< _nums; i++) {
        Point p1 = _points[i];
        Point p2 = _points[(i+1)%_nums];

        if ((p1.y > p.y) != (p2.y > p.y)) {
            double k  = (p.y - p1.y) / (p2.y - p1.y);
            double xt = p1.x + k*(p2.x - p1.x);
            
            if (p.x == xt) {
                status = E_ONSIDE;
                break;
            } else if (p.x < xt) {
                ++count;
            }
        }
    }

    status = (count % 2) ? E_INSIDE : E_OUTSIDE;
    
    return (status != E_OUTSIDE);
}

/**
 * 将一个凹多边形完全分解成几个凸多边形。
 */
void Polygon::decompose_convex()
{
    // FIXME: 将凹多边形完全分解成凸多边形
    if (!_concave) {
        return ;
    }
}

void Polygon::analyze_concave()
{
    if (total_point() < 4) {
        _concave = false;
        return ;
    }
    // FIXME: 分析N边形的凹凸性
    // N > 3
}

void Polygon::check_concave()
{
    _concave = false;
    vector<Point>::iterator beg = _points;
    while (beg != _points.end()) {
        if ((*beg).is_concave()) {
            _concave = true;
            break;
        }
        beg++;
    }
}

bool Polygon::is_concave()
{
    return _concave;
}

bool Polygon::is_convex()
{
    return !_concave;
}

