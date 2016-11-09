
#ifndef _LinearList_
#define _LinearList_

#include <iostream>
#include "err.h"

using namespace std;

template<class T>
class LinearList
{
private:
	T *elements;
	int size;
	int length;

public:
	LinearList(int size = 10);
	~LinearList();

	LinearList<T> &  clearList();
	bool listEmpty()const;
	int listLength()const;
	bool getElem(int k, T &x)const;
	int locateElem(T const &x)const;
	T priorElem(T const &x)const;
	T nextElem(T const &x)const;
	LinearList<T>   &listInsert(int k, T const x);
	LinearList<T>   &listDelete(int k);

friend ostream &operator<<(ostream &os, LinearList<T> &L)
	{
		if (L.length > 0) {
			for (int i = 0; i < L.length; i++) {
				os << L.elements[i] << "\t";
            }
		} else {
			os << "list is empty" << endl;
		}

		return os;
	};
};

#endif
