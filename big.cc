#include<stdio.h>

typedef unsigned char * char_point;

char_point int_cp(int &i)
{  
    printf("i: %d\n", i);
    printf("&i: %p\n", &i);
    printf("(c_p)&i: %p\n", (char_point) &i);
    char_point cp = (char_point) &i;
    return cp;
}


char_point float_cp(float &f)
{
    printf("f: %f\n", f);
    printf("&f: %p\n", &f);
    printf("(c_p)&f: %p\n", (char_point) &f);
    char_point cp = (char_point) &f;
    return cp;
}

void endian(char_point cp, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("0x%x\n", cp[i]);
    }
}

int main()
{
    int i = 0x21893678;
    float f = 913.45678f;   
   
    endian(int_cp(i), sizeof(i));
    printf("== == == ===  =   ==== === = == = == \n");
    endian(float_cp(f), sizeof(f));
}
