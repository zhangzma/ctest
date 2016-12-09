
#include <stdio.h>

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;

uint16_t compound(uint8_t *data)
{
    return ((data[1] << 8) | data[0]);
}

int main(int argc, char *argv[])
{
    uint8_t data[2] = {0x12, 0x34};
    uint8_t *pdata = data;
    printf("data = 0x%04X\n", compound(data));
    printf("pdata = 0x%04X\n", compound(pdata));
    return 0;
}


