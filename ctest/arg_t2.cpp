/****************************************************************************
 *
 *   Copyright (c) 2015 Eva Information and Technology Co., Ltd.
 *   All rights reserved.
 *
 ***************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdarg>

namespace eva {
	void foo(char* pszdest, int destlen, const char* pszformat, ...);
} // eva

int main(int argc, char const *argv[])
{
	const int DEST_LEN = 256;
	char pszdest[DEST_LEN];
	eva::foo(pszdest, DEST_LEN, "%04d-%02d-%02d", 2015, 6, 4);
	std::cout << "Today is " << pszdest << std::endl;

	return 0;
}

void eva::foo(char* pszdest, int destlen, const char* pszformat, ...)
{ 
	va_list args; 
	va_start(args, pszformat); 
	_vsnprintf(pszdest, destlen, pszformat, args); 
	va_end(args); 
}
