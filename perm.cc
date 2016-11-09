// perm.cc

#include <iostream>

template<typename T>
inline void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void perm(T list[], int k, int m)
{
    int i;
    if (k == m) {
        for (i = 0; i < m; i++) {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        for (i=k; i<m; i++) {
            swap(list[k], list[i]);
            perm(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    int list[3] = {1, 2, 3};
    perm(list, 0, 3);

    return 0;
}

