// Project Euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

int main()
{
	std::list<int> multiplesOf3_5;
	std::list<int>::iterator it;
	int sumOfMul = 0;
	for (size_t i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			multiplesOf3_5.push_back(i);
	}
	for (it = multiplesOf3_5.begin(); it != multiplesOf3_5.end(); it++)
	{
		sumOfMul += *it;
	}
	std::cout << sumOfMul << '\n';
	system("pause");
    return 0;
}

