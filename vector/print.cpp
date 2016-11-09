// print.cpp

#include <iostream>

template<typename T, unsigned int N>
void printValues(const T (&array)[N])
{
    for (int i=0; i<N; i++) {
        std::cout << array[i] << "\t";
    }
}

int main(int argc, char *argv[])
{
    int a[3] = {1, 3, 5};
    printValues(a);
    return 0;
}

