// main.cc
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream &open_file(ifstream &in, const string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());

    return in;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: test ch-ph-tb.data" << std::endl;
        return -1;
    }

    // init the map
    map<string, string> chph;
    ifstream in;
    open_file(in, argv[1]);
    string ch, ph;
    while (in >> ch >> ph) {
        chph[ch] = ph;
    }

    // input a word.
    std::cout << "Please input some words: " << std::endl;
    std::cin >> ch;

    // find the ph.
    map<string, string>::iterator it = chph.find(ch);
    if (it != chph.end()) {
        std::cout << it->first << "\t" << it->second << std::endl;
    }
    else {
        std::cout << "No this char: " << ch << std::endl;
    }

    return 0;
}

