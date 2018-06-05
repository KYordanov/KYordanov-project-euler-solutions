// Smallest multiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>

#define NUM_OF_PRIMES 10
const int primes[NUM_OF_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int primeFactor[NUM_OF_PRIMES] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void showUniqueFactorization(int primeFactor[])
{
	for (size_t i = 0; i < NUM_OF_PRIMES; i++)
		if (primeFactor[i] != 0)
			std::cout << primes[i] << '^' << primeFactor[i] << '\n';
}

void uniqueFactorization(int num, int primeIndex)
{
	if (num % primes[primeIndex] != 0)
		uniqueFactorization(num, primeIndex + 1);
	else
	{
		primeFactor[primeIndex]++;
		if (num / primes[primeIndex] != 1)
			uniqueFactorization(num / primes[primeIndex], 0);
	}
}

bool satisfying(int numToCheck)
{
	bool satisfying = true;
	for (size_t i = 1; i <= 20; i++)
	{
		if (numToCheck % i != 0)
		{
			satisfying = false;
			break;
		}
	}
	return satisfying;
}

int main()
{
	/*
	clock_t begin = clock();
	for (size_t i = 100000; i < 100000000; i++)
	{
		if (satisfying(i*20))
		{
			std::cout << i * 20 << " is multiple of 1..20\n";
		}
	}
	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time elapsed " << elapsed << "sec \n";	// ~3.5 sec 0.o
	*/

	int holdPrimeFactor[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	clock_t begin = clock();
	for (size_t i = 2; i <= 20; i++)
	{
		memset(primeFactor, 0, sizeof(primeFactor));	// clean for every num
		uniqueFactorization(i, 0);
		for (size_t j = 0; j < NUM_OF_PRIMES; j++)
			if (primeFactor[j] > holdPrimeFactor[j])	// keep only the highest power of the prime
				holdPrimeFactor[j] = primeFactor[j];
	}
	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time elapsed " << (double)elapsed << "sec \n";
	showUniqueFactorization(holdPrimeFactor);

	system("pause");
    return 0;
}
