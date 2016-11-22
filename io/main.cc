// istream::getline example
#include <iostream>     // std::cin, std::cout
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

typedef unsigned short uint16_t;
typedef signed short   int16_t;

void trim_symbal(std::string &_str, char ch)
{
    std::string::size_type pos = 0;
    while (pos = _str.find(ch), pos != std::string::npos) {
        _str.erase(pos, 1);
    }
}

int main(int argc, char *argv[])
{
    string sdate;
    string sop, shp, slp, sep;


    ifstream in;
    in.open(argv[1]);
    if (in) {
        in >> sdate >> sop >> shp >> slp >> sep;
    }
    
    istringstream iss(sdate);
    uint16_t year(2016);
    int16_t  month(01), day(01);
    if (sdate.find('-') != std::string::npos) {
        iss >> year >> month >> day;
        month = month < 0? -month : month;
        day   = day < 0 ? -day : day;
        std::cout << "-" << std::endl;

    } else {
        char c;
        std::cout << sdate << "/" << std::endl;
        iss >> month >> c >> day >> c >> year;
    }

    std::cout << year << ":"
              << month << ":"
              << day << std::endl;
    
    // trim_symbal(sop, '"');
    // trim_symbal(sop, ',');
    
    // std::cout << sdate << "\t"
    //           << sop << "\t" 
    //           << shp << "\t" 
    //           << slp << "\t" 
    //           << sep << "\t" 
    //           << std::endl;

    return 0;
}
