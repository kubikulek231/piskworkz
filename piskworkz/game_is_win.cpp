#include "array_f.h"
#include <iostream>
using namespace std;
// defines winner
// uses local variables: cols, rows
bool is_win(int* arr, int winstreak, bool player, int point_r, int point_c, int cols, int rows)
{
	bool win = false;
	int scanned_val = (player == 0) ? 1 : 2;
	int maxcols = cols;
	int maxrows = rows;
	int current_streak = 0;

	// scans for vertical streak
	int c = point_c;
	current_streak = 0;
	for (int r = point_r - winstreak; r <= point_r + winstreak; r++)
	{
		if (r > 0 & r <= maxrows)
		{
			if (get_arr_val(arr, r, c, cols) == scanned_val)
			{
				current_streak++;
				if (current_streak == winstreak)
				{
					std::cout << "vertical";
					return true;
				}
			}
			else (current_streak = 0);
		}
	}
	// scans for horizontal streak
	int r = point_r;
	current_streak = 0;
	for (c = point_c - winstreak; c <= point_c + winstreak; c++)
	{
		if (c > 0 & c <= maxcols)
		{
			if (get_arr_val(arr, r, c, cols) == scanned_val)
			{
				current_streak++;
				if (current_streak == winstreak)
				{
					std::cout << "horizontal";
					return true;
				}
			}
			else (current_streak = 0);
		}
	}
	// scans for diagonal streak from lower left corner to upper right corner
	r = point_r - winstreak;
	current_streak = 0;
	for (c = point_c - winstreak; c <= point_c + winstreak; c++)
	{
		if (c > 0 & c <= maxcols)
		{
			if (r > 0 & r <= maxrows)
			{
				if (get_arr_val(arr, r, c, cols) == scanned_val)
				{
					current_streak++;
					if (current_streak == winstreak)
					{
						std::cout << "diagonal lower left";
						return true;
					}
				}
			}
			else (current_streak = 0);
		}
		else (current_streak = 0);
		r++;
	}

	// scans for diagonal streak from upper left corner to lower right corner
	r = point_r + winstreak;
	current_streak = 0;
	for (c = point_c - winstreak; c <= point_c + winstreak; c++)
	{
		if (c > 0 & c <= maxcols)
		{
			if (r > 0 & r <= maxrows)
			{
				if (get_arr_val(arr, r, c, cols) == scanned_val)
				{
					current_streak++;
					if (current_streak == winstreak)
					{
						cout << "diagonal upper left";
						return true;
					}
				}
			}
			else (current_streak = 0);
		}
		else (current_streak = 0);
		r--;
	}
	return false;
}