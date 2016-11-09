// box.cpp

#include "box.h"

CBox::CBox(float length, float width, float high)
    : _length(length), _width(width), _high(high)
{
}

CBox::~CBox()
{
}

float CBox::get_area()
{
    float front = _length * _high;
    float up    = _length * _width;
    float left  = _width * _high;
    float area  = (front + up + left) * 2;
    return area;
}

float CBox::get_volum()
{
    return _length * _length * _width;
}

bool CBox::is_cubie(args) const
{
    
}
