// usage.cc
#include <iostream>
#include <cstdio>
using namespace std;

#define warnx printf

void usage()
{
    warnx("usage: sdlog2 {start|stop|status|on|off} [-r <log rate>] [-b <buffer size>] -e -a -t -x\n"
          "\t-r\tLog rate in Hz, 0 means unlimited rate\n"
          "\t-b\tLog buffer size in KiB, default is 8\n"
          "\t-e\tEnable logging by default (if not, can be started by command)\n"
          "\t-a\tLog only when armed (can be still overriden by command)\n"
          "\t-t\tUse date/time for naming log directories and files\n"
          "\t-x\tExtended logging");
}


int main(int argc, char *argv[])
{
    usage();

    std::cout << std::endl;
    std::cout << "End" << std::endl;
    
    return 0;
}

