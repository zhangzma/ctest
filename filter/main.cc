
#include "filter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float get_data();

int main(int argc, char *argv[])
{
	float data;
	srand((unsigned)time(NULL));

	pf new_data = get_data;

	for (int i=0; i<100; i++) {
		data = filter::median(new_data, 1.0f);

		std::cout << data << std::endl;

		// if ((i+1) % 5 == 0) {
		// 	std::cout << std::endl;
		// }
	}

	std::cout << std::endl;

    return 0;
}

float get_data()
{
	static float data = rand() % 1000;
	float coefficient = (rand() % 100) / 100.0 - 0.5;
	data += coefficient*data/100.0;

	// return coefficient;
	return data;
}

