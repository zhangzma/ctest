// point.cc
#include "point.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

const double PI = 3.1415926535897932384626433832795;

template<typename T>
T abs(T val)
{
    return val > 0 ? val : -val;
}

bool isnan(double amt)
{
    const double EPSON = 0.0000001;
    return (abs(amt) < EPSON);
}



/**
 * 浮点数约束
 * @param amt -- current value
 * @param min -- min limit
 * @param max -- max limit
 * @return
 */
double constrain_double(double amt, double min, double max)
{
    if (isnan(amt)) {
        return (min+max)*0.5;
    }

    return ((amt < min) ? min : ((amt > max) ? max : amt));
}

double longitude_scale(const point_s &pos)
{
    double scale = cos(pos.lat * (double)DEG_TO_RAD);
    std::cout << "longitude scale: " 
              << scale << std::endl;
    return constrain_double(scale, 0.01f, 1.00f);
}

double rad2deg(double rad)
{
    return rad * RAD_TO_DEG;
}

// 
double get_home_bearing(double lat, double lon, double lon_scale)
{
    double bearing = atan2(lon*(double)LATLON_TO_CM*lon_scale,
                           lat*(double)LATLON_TO_CM);
    std::cout << "bearing(rad): "<< bearing << std::endl;

    double bearing_deg = rad2deg(bearing);
    std::cout << "bearing(deg): "<< bearing_deg << std::endl;
    
    if (bearing < 0.0) {
        bearing += 2*PI;
    }

    return bearing;
}

void calc_home_bearing(const point_s &home, const point_s &curr)
{
    point_s delta = curr - home;
    std::cout << "delta: " << delta << std::endl;
    get_home_bearing(delta.lat, delta.lon, longitude_scale(curr));
}


point_s operator-(const point_s &lft, const point_s &rhs)
{
    point_s delta;
    delta.lat = lft.lat - rhs.lat;
    delta.lon = lft.lon - rhs.lon;
    delta.alt = lft.alt - rhs.alt;
    
    return delta;
}


//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////
std::istream& operator>>(std::istream& in, point_s &point)
{
    // in.clear();
    in >> point.lat >> point.lon >> point.alt;
    // in.clear();
    return in;
}

std::ostream& operator<<(std::ostream& out, const point_s &point)
{
    out << "(" << std::setprecision(11)
        << point.lat << ", " 
        << point.lon << ", "
        << point.alt << ")";
    
    return out;
}

std::ifstream& open_file(std::ifstream &in, const std::string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());
    
    return in;
}

