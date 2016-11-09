// print.cc
// ################################################################################
// #
// #   Copyright (c) 2015 www.bjfz.com. All rights reserved.
// #
// # 说明：
// ################################################################################

#include <iostream>
#include <string>

/**
 * Print a string
 * @param str -- the information
 */
void printString(const std::string& str)
{
    std::cout << str << std::endl;
}

int main(int argc, char *argv[])
{
    std::string str("Hello World");
    printString(str);
    
    return 0;
}

