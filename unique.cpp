
#include <iostream>
#include <vector>
// #include <numberic>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    vector<char> svec;
    char         ch;
    std::cout << "Please input some char: (Ctrl+Z to end)" << std::endl;
    while (cin >> ch) {
        svec.push_back(ch);
    }
    sort(svec.begin(), svec.end());
    vector<char>::iterator new_end = unique(svec.begin(), svec.end());
    svec.erase(new_end, svec.end());

    std::cout << "\nThe svec is: " << std::endl;
    vector<char>::iterator it = svec.begin();
    while (it != svec.end()) {
        std::cout << *it++ << " ";
    }

    return 0;
}

