#include "list.h"

template<class T>
LinearList<T>::LinearList(int size)
{
	this->size = size;
	length = 0;
	elements = new T[size];
};

template<class T>
LinearList<T>::~LinearList()
{
    std::cout << "destroy the linearlist. size = " 
              << size << "\t" << length << std::endl;
	delete[] elements;
};

template<class T>
LinearList<T> & LinearList<T>::clearList()
{
	delete[] elements;
	elements = new T[size];
	return *this;
};

template<class T>
bool LinearList<T>::listEmpty()const
{
	return length == size;
};

template<class T>
int LinearList<T>::listLength()const
{
	return length;
};

template<class T>
bool LinearList<T>:: getElem(int k, T &x)const
{
	if (k < 1 || k > length)
	{
		throw OutOfBound();
		return false;
	}

	x = elements[k - 1];
	return true;
};

template<class T>
int LinearList<T>:: locateElem(T const &x)const
{
	for (int i = 0; i < length; i++)
		if (elements[i] == x)
			return ++i;

	return 0; //if LinearList does not exist x;
}

template<class T>
T LinearList<T>:: priorElem(T const &x)const
{
	int k = locateElem(x);

	if (k)
	{
		return elements[k - 2];
	}

	return 0;
};

template<class T>
T LinearList<T>:: nextElem(T const &x)const
{
	int k = locateElem(x);

	if (k)
	{
		return elements[k];
	}

	return 0;
};

template<class T>
LinearList<T> &LinearList<T>:: listInsert(int k, T const x)
{
	if (k < 1 || k > size) {
		throw OutOfBound();
		return *this;
	}

	length++;
    int j = length < size ? length : size - 1;
	for (; j >= k; j--) {
		elements[j] = elements[j - 1];
    }

	elements[k - 1] = x;
	return *this;
};

template<class T>
LinearList<T> & LinearList<T>::listDelete(int k)
{
	if (k < 1 || k > length) {
		throw OutOfBound();
		return *this;
	}

	for (int j = k - 1; j < length; j++)
		elements[j] = elements[j + 1];

	length--;
	return *this;
};
