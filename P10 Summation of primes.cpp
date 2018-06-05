// Summation of primes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <ctime>
#include <math.h>

bool isPrime(int n)
{
	if (n <= 3)
		return n > 1;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;
	else
		for (int i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		return true;
}

void findPrimeNumbers(long findIn, std::list<long>& primes)
{
	for (long i = 2; i < findIn; i++)
	{
		if (isPrime(i))
		{
			primes.push_back(i);
		}

	}
}

int main()
{
	std::list<long> primes;
	std::list<long>::iterator it;
	long findPrimesSmallerThan = 2000000;
	clock_t begin = clock();

	findPrimeNumbers(findPrimesSmallerThan, primes);

	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time elapsed " << (double)elapsed << "sec \n";

	long long sum = 0;

	for (it = primes.begin(); it != primes.end(); it++)
	{
		sum += *it;
	}
	std::cout << sum << std::endl;

	system("pause");
    return 0;
}

