// main.cc
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI           = 3.141592654;
const double RAD_TO_DEG   = 180 / PI;
const double DEG_TO_RAD   = PI / 180;
const double LATLON_TO_CM = 1.113195f;

struct position_s {
    double lat;                  // 纬度
    double lon;                  // 精度
    double alt;                  // 高度
};

double
constrain_double(double amt, double min, double max)
{
    if (isnan(amt)) {
        return (min+max)*0.5f;
    }

    return ((amt < min) ? min : ((amt > max) ? max : amt));
}

double
longitude_scale(const struct position_s &global_pos)
{
    double scale = cos(global_pos.lat * DEG_TO_RAD);
    return constrain_double(scale, 0.01f, 1.00f);
}


double calc_distance(const struct position_s &origin,
                     const struct position_s &dest)
{
    double y = (dest.lat - origin.lat) * LATLON_TO_CM * 1E7;
    double x = (dest.lon - origin.lon) * LATLON_TO_CM * 1E7 * longitude_scale(dest);
    double bearing = atan2(y, x);

    return bearing * RAD_TO_DEG;
}

int main(int argc, char *argv[])
{
    struct position_s origin = {36.6666666, 117.0, 5800.0};
    std::cout << "Origin's lat = " << origin.lat
              << ", lon = " << origin.lon
              << ", alt = " << origin.alt
              << std::endl;

    struct position_s home = {
        origin.lat + 0.522E-3f,
        origin.lon + 0.522E-3f,
        origin.alt
    };

    std::cout << "Home's lat = " << home.lat
              << ", lon = " << home.lon
              << ", alt = " << home.alt
              << std::endl;

    std::cout << setprecision(8)
              << "lat = " << origin.lat  << std::endl;

    std::cout << "bearing = " << calc_distance(origin, home) << std::endl;
    
    return 0;
}


