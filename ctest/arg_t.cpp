/**
 * File Name: arg_t.cpp
 *
 * 测试变参函数
 *
 */
#include <iostream>

namespace eva {
	void print(int count, ...);
} // eva

int main(int argc, char const *argv[])
{
	int a = 1, b = 2, c = 3, d = 4;
	eva::print(4, a, b, c, d);

	return 0;
}

void eva::print(int count, ...)
{
	int *pi = &count;

	std::cout << "Argument count is: " << count << std::endl;
	for (int i = 0; i < count; ++i)
	{
		std::cout << *(++pi) << std::endl;
	}
}
