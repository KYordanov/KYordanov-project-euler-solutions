// 10001st prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <ctime>

void findPrimeNumbers(int findUntillIndex, std::list<int>& primes)
{
	bool currNumNotPrime = false;
	// find prime numbers
	for (size_t i = 2; primes.size() <= findUntillIndex; i++)
	{
		for (size_t j = 2; j < i; j++)
		{
			currNumNotPrime = false;
			if (i % j == 0)
			{
				// i is not prime
				currNumNotPrime = true;
				break;
			}
		}
		if (currNumNotPrime == false)
		{
			primes.push_back(i);
		}

	}
}

int main()
{
	std::list<int> primes;
	std::list<int>::iterator it;
	int findPrime = 10001;
	clock_t begin = clock();
	
	findPrimeNumbers(findPrime, primes);

	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time elapsed " << (double)elapsed << "sec \n";

	it = primes.begin();
	std::advance(it, 10000);
	std::cout << "10001st prime number is " << *it << '\n';
	/*std::cout << "All primes smaller than " << findPrimesSmallerThan << " = " << primes.size() << '\n';
	for (it = primes.begin(); it != primes.end(); it++)
	{
		std::cout << "[" << *it << "]";
	}*/

	system("pause");
    return 0;
}

