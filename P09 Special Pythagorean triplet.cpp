// Special Pythagorean triplet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>

int main()
{
	for (int a = 100; a < 400; a++)
		for (int b = 100; b < 400; b++)
			if ((a+b+(pow(pow(a,2)+pow(b,2),0.5))) == 1000)
				std::cout << "a = " << a << " ; b = " << b << std::endl;

	system("pause");
    return 0;
}

