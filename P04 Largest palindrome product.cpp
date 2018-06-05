// Largest palindrome product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <ctime>

bool isPalindrome(int check)
{
	std::string numStr = std::to_string(check);
	std::string::iterator front = numStr.begin(), back = numStr.end();
	back--;
	bool isPalindrome = true;

	while (std::distance(front, back) > 0)
	{
		if (*front != *back)
		{
			isPalindrome = false;
			break;
		}
		front++;
		back--;
	}
	return isPalindrome;
}

int main()
{
	std::list<int> palindromes;
	std::list<int>::iterator it;
	int firstMul, secMul, largestPalndrome = 0;
	bool largestPalindromeFound = false;
	clock_t begin = clock();
	for (firstMul = 999; firstMul > 800; firstMul--)
	{
		for (secMul = 990; secMul > 800; secMul -= 11) // Palindrome is multiple of 11
		{
			if (isPalindrome(firstMul*secMul))
			{
				std::cout << "Palindrome found: " << firstMul*secMul;
				std::cout << " made by multiplyng " << firstMul << " and " << secMul << '\n';
				palindromes.push_back(firstMul*secMul);
			}
		}
	}

	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Palindromes found for " << elapsed << "sec \n";
	palindromes.sort();
	std::cout << "Palindromes found : " << palindromes.size() << '\n';
	for (it = palindromes.begin(); it != palindromes.end(); it++)
	{
		std::cout << "[" << *it << "]";
	}
	std::cout << '\n';
	//std::cout << palindromes. << "made by multilpying "'\n';
	
	system("pause");
    return 0;
}

