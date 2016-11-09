// 

#include <iostream>
#include <iomanip>


using namespace std;

class Point
{
public:
    Point(double x, double y)
        : _x(x), _y(y) {}
    virtual ~Point(){}

friend ostream &operator<<(ostream& out, const Point &p)
    {
        out << p._x << "\t" << p._y << std::endl;
    }

private:
    double _x;
    double _y;
};

const uint16_t PEAK_COUNT = 4;
Point points[PEAK_COUNT] = {
    {30.397716923893, 114.454607612644},
    {30.397733049931, 114.454469656809},
    {30.397615336370, 114.454450579706},
    {30.397605293022, 114.454595704549}
};


int main(int argc, char *argv[])
{
    for (int i=0; i<PEAK_COUNT; i++) {
        std::cout << setprecision(15)
                  << points[i] << std::endl;
    }

    return 0;
}
