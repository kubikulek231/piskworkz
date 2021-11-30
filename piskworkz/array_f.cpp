#pragma once
#include "array_f.h"
#include <iostream>
#include "stdio.h"
#include "conio.h"
#include <string>
#include <fstream>
// defines a "fake" 2d array of rows*cols size
// uses local variables: rows, cols
int* define_arr(int value, int rows, int cols)
{
	int m = rows;
	int n = cols;

	auto arr = new int[m * n];

	// goes through the array
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// defines each value of array
			*(arr + i * n + j) = value;
		}
	}

	return arr;
}

// prints out array into a block
// uses local variables: rows, cols
void print_arr(int* arr, int rows, int cols)
{
	std::cout << "printing out the board array:\n";
	std::cout << std::endl;

	int m = rows;
	int n = cols;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// prints out each value
			std::cout << *(arr + i * n + j)
				<< " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// edits value of given array element (rows, cols)
// uses local variables: cols
void edit_arr_val(int* arr, int r, int c, int newval, int cols)
{
	int arraycols = cols;
	*(arr + (r - 1) * arraycols + c - 1) = newval;
}

// gets value of given array element (rows, cols)
// uses local variables: cols
int get_arr_val(int* arr, int r, int c, int cols)
{
	int arraycols = cols;
	int value = *(arr + (r - 1) * arraycols + c - 1);
	return value;
}

// gets value of given array element (rows, cols)
// uses local variables: cols, rows
void print_board(int* arr, int cols, int rows)
{
	int maxcols = cols;
	int maxrows = rows;
	int index = 0;

	// prints out first row with identifiers
	printf("     ");
	for (int c = 1; c <= maxcols; c++)
	{
		// puts a whitespace before number if it has 2 decimals
		if (c >= 10)
		{
			printf(" %d ", c);
		}
		else
		{
			printf(" %d  ", c);
		}
	}

	printf("\n");
	// defines whether it's a row with xs and os
	bool rowtype = true;
	// for each row
	for (int r = 1; r <= maxrows * 2 + 1; r++)
	{
		// for each column
		for (int c = 1; c <= maxcols; c++)
		{
			// do this if it's NOT a row with xs and os
			if (rowtype == 1)
			{
				// if it's the first column
				if (c == 1)
				{
					printf("    ");
				}
				printf("|---");
			}
			// do this if IT IS a row with xs and os
			else
			{
				// if it's the first column, print identifier
				if (c == 1)
				{
					// puts a whitespace before number if it has 2 digits
					if (r / 2 >= 10)
					{
						printf("  %d", r / 2);
					}
					else
					{
						printf("   %d", r / 2);
					}
				}
				// prints the exact value of the element
				int int_value = *(arr + index);
				// for each value prints a whitespace, x or o
				std::string string_val = " ";
				if (int_value == 1) (string_val = "x");
				if (int_value == 2) (string_val = "o");
				printf("| %s ", string_val.c_str());
				index++;
			}
			// if it's the last column
			if (c == cols)
			{
				printf("|");
			}
		}
		rowtype = !rowtype;
		printf("\n");
	}
}
