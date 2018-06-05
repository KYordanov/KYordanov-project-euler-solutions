// Sum square difference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

int main()
{
	int sumOfTheSqu = 0, squOfTheSum = 0;
	clock_t begin = clock();
	for (size_t i = 0; i <= 100; i++)
	{
		sumOfTheSqu += i * i;
		squOfTheSum += i;
	}
	squOfTheSum = squOfTheSum * squOfTheSum;
	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time elapsed " << (double)elapsed << "sec \n";

	std::cout << squOfTheSum << " - " << sumOfTheSqu  << " = " << squOfTheSum - sumOfTheSqu << '\n';

	system("pause");
    return 0;
}

