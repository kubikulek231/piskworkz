#pragma once
#include "game_setup.h"
#include <iostream>
#include "stdio.h"
#include "conio.h"
#include <string>
#include <ctime>
#include <fstream>
#include "basic_f.h"

using namespace std;

void get_player_name(int player_num, bool guest, string& player1_name, string& player2_name)
{
	std::string player_name(100, ' ');
	bool error = false;
	bool input_error = false;
	while (true)
	{
		input_error = false;
		error = false;
		cout << "  Leave blank and press ENTER key to play as a guest.\n";
		printf("  Enter the name of player %d: ", player_num);
		getline(cin, player_name);
		// play as a guest
		if (player_name.empty() == 1)
		{
			player_name = "Guest_2";
			if (player_num == 1)
			{
				player_name = "Guest_1";
			}
			guest = true;
			break;
		}
		// forbidden player_name
		if (player_name == "Guest_1" || player_name == "Guest_2")
		{
			cout << "  Error! You can not use this name!.\n";
			error = true;
		}
		// player_name too long
		if (player_name.length() > 14 && error == false)
		{
			cout << "  Error! Maximal number of characters is 14.\n";
			error = true;
		}
		// player_name too short
		if (player_name.length() < 3 && error == false)
		{
			cout << "  Error! Name must contain of at least 3 characters.\n";
			error = true;
		}
		// player_name whitespaces only
		if (error == false)
		{
			for (int i = 0, w = 0; i < player_name.length(); ++i)
			{
				if (player_name[i] == ' ') (w++);
				if (w >= player_name.length())
				{
					cout << "  Error! Name must not contain whitespaces only.\n";
					error = true;
				}
			}
		}
		// player_name wrong input
		if (error == false)
		{
			for (int i = 0, w = 0; i < player_name.length(); ++i)
			{
				if (player_name[i] == '\n')
				{
					cout << "  Error! Name contains \\n.\n";
					error = true;
				}
			}
		}
		// convert whitespaces to underscores
		for (int i = 0, w = 0; i < player_name.length(); ++i)
		{
			if (player_name[i] == ' ') (player_name[i] = '_');
		}
		if (error == false && input_error == false)
		{
			break;
		}
	}
	if (player_num == 1)(player1_name = player_name);
	if (player_num == 2)(player2_name = player_name);
}

// setups a new game
// user input: rows, cols, streak_num
void new_game(int& rows, int& cols, int& streak_num, bool& guest, std::string& player1_name, std::string& player2_name)
{
	bool error = false;
	bool input_error = false;
	while (true)
	{
		input_error = false;
		error = false;
		std::cout << "  Enter the number of rows: ";
		rows = scan_1int(input_error);

		if (rows > 99 && input_error == false)
		{
			std::cout << "  Error! Maximal row number can not exceed 99.\n";
			error = true;
		}
		if (rows < 3 && input_error == false)
		{
			std::cout << "  Error! Number of rows can not be less than 3.\n";
			error = true;
		}
		if (error == false && input_error == false)
		{
			break;
		}
	}
	while (true)
	{
		input_error = false;
		error = false;
		std::cout << "  Enter the number of columns: ";
		getchar();
		cols = scan_1int(input_error);
		if (cols > 99 && input_error == false)
		{
			std::cout << "  Error! Maximal column number can not exceed 99.\n";
			error = true;
		}
		if (cols < 3 && input_error == false)
		{
			std::cout << "  Error! Number of columns can not be less than 3.\n";
			error = true;
		}

		if (error == false && input_error == false)
		{
			break;
		}
	}
	while (true)
	{
		input_error = false;
		error = false;
		std::cout << "  Enter the streak number: ";
		getchar();
		streak_num = scan_1int(input_error);
		// streak value can not be higher than highest of rows, cols
		int max_streak = (cols > rows) ? cols : rows;
		if (streak_num > max_streak && input_error == false)
		{
			printf("  Error! Streak number can not exceed %d.\n", max_streak);
			error = true;
		}
		if (streak_num < 3 && input_error == false)
		{
			std::cout << "  Error! Streak number can not be less than 3.\n";
			error = true;
		}

		if (error == false && input_error == false)
		{
			break;
		}
	}
	getchar();
	get_player_name(1, guest, player1_name, player2_name);
	get_player_name(2, guest, player1_name, player2_name);
}