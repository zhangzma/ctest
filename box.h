// box.h
// 定义盒子Box类，要求具有以下成员：长、宽、高分别为x,y,z，
// 可设置盒子形状； 可计算盒子体积；可计算盒子的表面积。 

#ifndef _BOX_H_
#define _BOX_H_

class CBox
{
public:
    CBox(float length, float width, float high);
    virtual ~CBox();

    float get_area();
    float get_volum();
    bool  is_cube();
    void  print_info();

private:
    float _length;
    float _width;
    float _high;
};

#endif /* _BOX_H_ */
