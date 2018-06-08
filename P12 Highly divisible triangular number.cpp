// P12 Highly divisible triangular number.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>

#define SIZE_OF_COMB_SET 4
#define NUM_OF_PRIMES 10

int primes[NUM_OF_PRIMES] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
//int primeFactor[NUM_OF_PRIMES] = { 0 };

bool isTriangular(long long num)
{
	int tryTriNum = (int)sqrt(2 * num);
	if (num == (tryTriNum * (tryTriNum + 1) / 2))
		return true;
	else
		return false;
}

void trimComb(int *comb)
{
	int mul = 1;
	for (size_t i = 0; i < NUM_OF_PRIMES; i++)
	{
		if (mul >= 500)
			comb[i] = 0;
		else
			mul *= comb[i] + 1;
	}
	
}

int calcMul(int *comb)
{
	int mul = 1;
	for (size_t i = 0; i < NUM_OF_PRIMES; i++)
	{
		mul *= comb[i] + 1;
	}
	return mul; // 2^9 = 512 target divisors
}

void printComb(int *comb)
{
	for (size_t i = 0; i < NUM_OF_PRIMES; i++)
	{
		std::cout << comb[i] << " ";
	}
	std::cout << std::endl;
}

long long calcComb(int *comb)
{
	long long highlyDevNum = 1;
	for (size_t i = 0; i < NUM_OF_PRIMES; i++)
	{
			highlyDevNum *= pow(primes[i], comb[i]);
	}
	return highlyDevNum;
}

void doCombs(int *comb, int index)
{
	if (index >= 10)
	{
		int muls = calcMul(comb);
		trimComb(comb);
		if (500 < muls)
		{
			long long highlyDevNum = calcComb(comb);
			if (isTriangular(highlyDevNum))
			{
				std::cout << highlyDevNum << ":  ";
				printComb(comb);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < 3; i++)
		{
			comb[index] = i;
			doCombs(comb, index + 1);
		}
	}
}

int main()
{
	int combs[NUM_OF_PRIMES] = { 0 };

	doCombs(combs, 0);
	system("pause");
	return 0;
}

