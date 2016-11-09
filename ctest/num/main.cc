/*
  5*M + 2*F + 0.1*C = 120
  M + F + C = N
 */ 
#include <iostream>

int count(int m, int f, int c)
{
    return 5*m + 2*f + (int)(0.1*c);
}

bool is_120(int m, int f, int c)
{
    return (120 == count(m, f, c));
}


int main(int argc, char *argv[])
{
    int m, f, c;
    int n;
    bool noResult = true;

    std::cout << "Please input the people's count: " << std::endl;
    std::cin >> n;

    for (int c=0; c<=n; c=c+10) {
        for (int m=0; m<=n-c; m++) {
            f = n - c - m;
            if (is_120(m, f, c)) {
                std::cout << m << "\t"
                          << f << "\t"
                          << c << std::endl;
                noResult = false;
            }
        }
    }

    if (noResult) {
        std::cout << "No Output." << std::endl;
    }
    
    return 0;
}
