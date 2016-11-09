// c01.cc
// 1/2/3/4 三位数
#include <iostream>

int main(int argc, char *argv[])
{
    int count = 0;

    int h, t, n;

    for (h=1; h<5; h++) {
        for (t=1; t<5; t++) {
            for (n=1; n<5; n++) {
                if (h != t && t != n && h != n) {
                    count++;
                    std::cout << h*100+t*10+n << std::endl;
                }
            }
        }
    }

    std::cout << "The count is: " << count << std::endl;
    
    return 0;
}
