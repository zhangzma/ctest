// 
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char s1[] = "Shager";
    char s2[40];
    strcpy(s2, s1);

    std::cout << "sizeof(s1): " << sizeof(s1) << std::endl;

    char *pdata = new char(sizeof(s1));

    std::cout << "sizeof(pdata): " << sizeof(pdata) << std::endl;

    return 0;
}

