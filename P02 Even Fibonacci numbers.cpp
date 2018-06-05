// Even Fibonacci numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int prevFibTerm = 1, currFibTerm = 2, newFibTerm = 0;
	int sumOfEven = 0;
	while (true) // browse through all Fibonacci sequence
	{
		std::cout << currFibTerm << '\n';
		if (currFibTerm > 4000000)
			break;
		if (currFibTerm % 2 == 0)
			sumOfEven += currFibTerm;
		// Calc new Term
		newFibTerm = prevFibTerm + currFibTerm;
		prevFibTerm = currFibTerm;
		currFibTerm = newFibTerm;
	}
	std::cout << sumOfEven << '\n';
	system("pause");
    return 0;
}
