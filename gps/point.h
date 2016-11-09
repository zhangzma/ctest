// point.h

#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
// using namespace std;

typedef struct _point {
    double lat;
    double lon;
    float  alt;
}point_s, *ppoint_s;

#define LATLON_TO_M  0.01113195f
#define LATLON_TO_CM 1.113195f
#define DEG_TO_RAD   0.017453292519943295769236907684886f
#define RAD_TO_DEG   57.295779513082320876798154814105f


void calc_home_bearing(const point_s &home, const point_s &curr);
// double longitude_scale(const point_s &pos);

// point_s operator+(point_s &lft, const point_s &rhs);
point_s operator-(const point_s &lft, const point_s &rhs);
// 
std::istream& operator>>(std::istream& in, point_s &point);
std::ostream& operator<<(std::ostream& out, const point_s &point);

// 
std::ifstream& open_file(std::ifstream &in, const std::string &file);

template<typename T>
void print_all(T beg, T end)
{
    while (beg != end) {
        std::cout << *beg++ << std::endl;
    }
    std::cout << std::endl << std::endl;
}


#endif /* _POINT_H_ */
