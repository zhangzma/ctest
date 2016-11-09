/* ioc.c */
#include <stdio.h>

#define _IOC(type,nr) ((type)|(nr))
#define _PX4_IOC(x,y) _IOC(x,y)

#define _DEVICEIOCBASE		(0x100)
#define _DEVICEIOC(_n)		(_PX4_IOC(_DEVICEIOCBASE, _n))

#define DEVIOCGDEVICEID	_DEVICEIOC(2)

int main(int argc, char *argv[])
{
    printf("_DEVICEIOCBASE  = 0x%x\n", _DEVICEIOCBASE);
    printf("DEVIOCGDEVICEID = 0x%x\n", DEVIOCGDEVICEID);

    return 0;
}

