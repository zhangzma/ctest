#ifndef _Err_
#define _Err_

#include <iostream>
using namespace std;

/* #include <new.h> */

class OutOfMemory
{
public:
    OutOfMemory(){
        cout << "out of meme." << endl;
    }
};

int my_Handler(size_t size)
{

    throw OutOfMemory();
    return 0;
};

/* _PNH old_handler = _set_new_handler(my_Handler); */

//The type _PNH is a pointer to a function that returns type int and takes a single argument of type size_t.
//The _set_new_handler function returns the address of the previous new handler. 

class OutOfBound
{
public:
    OutOfBound(){
        cout << "out of bound." << endl;
    }
};

#endif

