// Largest prime factor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

void findPrimeNumbers(int findIn,std::list<int>& primes)
{
	bool currNumNotPrime = false;
	// find prime numbers
	for (size_t i = 2; i < findIn; i++)
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
	int findPrimesSmallerThan = 10000;
	findPrimeNumbers(findPrimesSmallerThan, primes);
	for (it = primes.end(), it--; it != primes.begin(); it--)
	{
		if (600851475143 % *it == 0)
		{
			std::cout << *it << '\n';
			break;
		}
	}
	system("pause");

	/* Print list primes
	std::cout << "All primes smaller than " << findPrimesSmallerThan << " = " << primes.size() << '\n';
	for (it = primes.begin(); it != primes.end(); it++)
	{
		std::cout << "[" << *it << "]";
	}
	*/
    return 0;
}
