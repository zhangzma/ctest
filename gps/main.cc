// point.h
#include "point.h"
#include <string>
#include <vector>
#include <fstream>

using std::vector;

void convert(const point_s &point);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: gps point.dat" << std::endl;
        return -1;
    }

    vector<point_s> pvec;
    point_s point;

    std::string file(argv[1]);
    std::ifstream in;
    open_file(in, file);

    while (in >> point) {
        pvec.push_back(point);
        convert(point);
    }

    // get the home position
    point_s home = pvec[0];
    std::cout << "=============== home position ===============" 
              << std::endl << home << std::endl;
    // std::cout << "=============== all point ===============" << std::endl;
    // pvec.erase(pvec.begin());
    // print_all(pvec.begin(), pvec.end());
    
    // for (size_t i = 0; i < pvec.size(); i++) {
    //     std::cout << "Current Point: " << i+1 << std::endl;
    //     std::cout << std::endl << std::endl;
    // }
   
    return 0;
}

void convert(const point_s &point)
{
    double dval;

    struct _latlon
    {
        int    deg;
        int    min;
        double sec;
    } lat, lon;

    dval     = point.lat;
    lat.deg  = (int)dval;
    dval    -= lat.deg;
    dval    *= 60;
    lat.min  = (int)(dval);
    dval    -= lat.min;
    dval    *= 60;
    lat.sec  = dval;

    dval     = point.lon;
    lon.deg  = (int)dval;
    dval    -= lon.deg;
    dval    *= 60;
    lon.min  = (int)(dval);
    dval    -= lon.min;
    dval    *= 60;
    lon.sec  = dval;

    char msg[255];
    // 36°40'55.95"N 117°8'1.05"E
    sprintf(msg, "%d°%d'%.4f\"N, %d°%d'%.4f\"E",
            lat.deg, lat.min, lat.sec,
            lon.deg, lon.min, lon.sec);
    std::cout << msg << std::endl;
}


void calc_bearing(vector<point_s> &pvec)
{
    // get the home position
    point_s home = pvec[0];
    std::cout << "=============== home position ===============" 
              << std::endl << home << std::endl;
    std::cout << "=============== all point ===============" << std::endl;
    pvec.erase(pvec.begin());
    print_all(pvec.begin(), pvec.end());
    
    for (size_t i = 0; i < pvec.size(); i++) {
        std::cout << "Current Point: " << i+1 << std::endl;
        calc_home_bearing(home, pvec[i]);
        std::cout << std::endl << std::endl;
    }
}


void test()
{
    point_s home;
    point_s curr;

    std::cout << "Input home point(lat, lon, alt):" << std::endl;
    std::cin >> home;

    std::cout << "Input curr point(lat, lon, alt):" << std::endl;
    std::cin >> curr;

    std::cout << "Home:" << home << std::endl;
    std::cout << "Curr:" << curr << std::endl;
}

