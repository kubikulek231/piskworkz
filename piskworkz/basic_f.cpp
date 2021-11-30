#pragma once
#include "file_f.h"
#include <iostream>
#include "stdio.h"
#include "conio.h"
#include <string>
#include <fstream>
// outputs a pseudo-random number 0 or 1 from time
bool rand_number()
{
	long long time_num = time(nullptr);
	double rand_num = (time_num % 10);
	rand_num /= 10;
	return static_cast<int>(round(rand_num));
}

// scanf stucks in a loop on wrong type of user input, this is a fix
// scans for a int value, if the inputted value is not int, sets error to true
int scan_1int(bool& error)
{
	int n = 0, num_ok;
	char c;

	num_ok = scanf("%d", &n);
	if (num_ok != 1)
	{
		scanf("%c", &c);
		std::cout << "  Error! Wrong user input, you must enter a number.\n";
		error = true;
		return n;
	}
	error = false;
	return n;
}

// for 2 user inputted numbers
// scanf stucks in a loop on wrong type of user input, this is a fix
// scans for a int value, if the inputted value is not int, sets error to true

void scan_2int(bool& error, int& lrows, int& lcols)
{
	int num_ok;
	char ch;
	int r;
	int c;

	num_ok = scanf("%d %d", &r, &c);
	if (num_ok != 2)
	{
		scanf("%c", &ch);
		std::cout << "  Error! Wrong user input, you must enter a number.\n";
		error = true;
	}
	else
	{
		lrows = r;
		lcols = c;
		error = false;
	}
}
