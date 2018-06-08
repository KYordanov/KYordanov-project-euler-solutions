// P12 Highly divisible triangular number.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>

#define SIZE_OF_COMB_SET 4
#define NUM_OF_PRIMES 10
#define START_TRI_NUM_IND 100
#define STOP_TRI_NUM_IND 20000

int primes[NUM_OF_PRIMES] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int primeFactor[NUM_OF_PRIMES] = { 0 };

void primeFactorization(int num, int primeIndex)
{
	if (primeIndex < NUM_OF_PRIMES)
	{
		if (num % primes[primeIndex] != 0)
			primeFactorization(num, primeIndex + 1);
		else
		{
			primeFactor[primeIndex]++;
			if (num / primes[primeIndex] != 1)
				primeFactorization(num / primes[primeIndex], 0);
		}

	}
	else
	{
		memset(primeFactor, 0, sizeof(primeFactor)); // invalid, number too big
	}
}

int howManyDivisors(long long Num)
{
	int divisors = 1;
	memset(primeFactor, 0, sizeof(primeFactor));
	primeFactorization(Num, 0);
	for (size_t i = 0; i <= NUM_OF_PRIMES; i++)
		if (primeFactor[i] != 0)
			divisors *= primeFactor[i] + 1;

	return divisors;
}

bool isTriangular(long long num)
{
	int tryTriNum = (int)sqrt(2 * num);
	if (num == (tryTriNum * (tryTriNum + 1) / 2))
		return true;
	else
		return false;
}

int main()
{
	long long triNum = START_TRI_NUM_IND*(START_TRI_NUM_IND+1)/2;
	for (int i = START_TRI_NUM_IND+1; i < STOP_TRI_NUM_IND; i++)
	{
		triNum += i;
		if(500 < howManyDivisors(triNum))
			if (true)
				if (isTriangular(triNum))
					std::cout << triNum << std::endl;

	}
	system("pause");
	return 0;
}

