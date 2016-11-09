/* 
 * main.c
 * Test the left shift.
 */

#include <cstdio>



#define LEFT_SHIFT(val, bit) \
    ((val) << (bit*2))

typedef unsigned int uint32; 

void XOR(unsigned int &val, uint32 bit)
{
    val |= bit;
}

void AOR(uint32 &val, uint32 bit)
{
    val &= bit;
}

uint32 clear_mode(uint32 pin)
{
    uint32 flag = 0x3 << (pin*2);
    flag = ~flag;
    return flag;
}


int main(int argc, char *argv[])
{
    uint32 reg = LEFT_SHIFT(0x3, 4);

    printf("reg = 0x%08x\n", reg);

    XOR(reg, 0xF);
    printf("reg = 0x%08x\n", reg);

    printf("~0x00 = 0x%08x\n", ~0x00);

    printf("clear_mode(3)=0x%08x\n", clear_mode(3));


    return 0;
}

