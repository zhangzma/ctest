
#include <iostream>

enum ShapeColor { RED, GREEN, BLUE };

// 一个表示几何形状的类
class Shape
{
public:
    // 所有的形状都要提供一个函数绘制它们本身
    virtual void draw(ShapeColor color = RED) const = 0;

    void d(ShapeColor color) const
    {
        switch (color) {
        case RED:
            std::cout << "Draw a RED ";
            break;

        case GREEN:
            std::cout << "Draw a GREEN ";
            break;

        case BLUE:
            std::cout << "Draw a BLUE ";
            break;

        default:
            ;
        }
    }
};

class Rectangle: public Shape
{
public:
    // 注意：定义了不同的缺省参数值 ---- 不好!
    virtual void draw(ShapeColor color = GREEN) const
    {
        d(color);
        std::cout << "Rectangle." << std::endl;
    }
};

class Circle: public Shape
{
public:
    virtual void draw(ShapeColor color) const
    {
        d(color);
        std::cout << "Circle." << std::endl;
    }
};

