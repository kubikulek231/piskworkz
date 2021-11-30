
#include <conio.h>
#include <iostream>

#include "array_f.h"
#include "basic_f.h"
#include "file_f.h"
#include "game_is_win.h"

using namespace std;
// requires and evaluates user's input of coordinates
// uses local variables: player_name, row_num, col_num, cols, rows
void enter_cor(int* arr, string player_name, int& row_num, int& col_num, int cols, int rows)
{
	row_num = 0;
	col_num = 0;
	// outer loop
	while (true)
	{
		bool input_error;
		bool error;
		// inner loop
		while (true)
		{
			input_error = false;
			error = false;
			cout << "  | Enter coordinates <row, column>: ";
			scan_2int(input_error, row_num, col_num);
			if (col_num < 1 && input_error == false)
			{
				printf("  | Error! Entered number of columns can not be lower than 1!\n");
				error = true;
			}
			if (col_num > cols && input_error == false)
			{
				printf("  | Error! Entered number of columns exceeds maximum (%d)!\n", cols);
				error = true;
			}
			if (row_num < 1 && input_error == false)
			{
				printf("  | Error! Entered number of rows can not be lower than 1!\n");
				error = true;
			}
			if (row_num > rows && input_error == false)
			{
				printf("  | Error! Entered number of rows exceeds maximum (%d)!\n", rows);
				error = true;
			}

			// if no error, breaks through the inner loop and continues
			if (error == false && input_error == false)
			{
				break;
			}
		}
		while (true)
		{
			// scans for the value of element with given coordinates
			int chosen_value = get_arr_val(arr, row_num, col_num, cols);
			// if the coordinates are already occupied by player 1 or 2
			if (chosen_value != 0)
			{
				// figures out who occupies the coordinates
				printf("  | Error! These coordinates are already occupied by %s!\n", player_name.c_str());
				error = true;
			}

			// breaks through the inner loop and continues
			break;
		}
		// if no error, breaks through the inner loop and continues
		if (error == false && input_error == false)
		{
			break;
		}
	}
}


// prints hotbar
// uses local variables: player, player1_name, player2_name, round_num
void print_hotbar(bool player, string player1_name, string player2_name, int& round_num)
{
	string player_name = (player + 1 == 1) ? player1_name : player2_name;
	round_num++;
	cout << endl;
	string string_val = " ";
	if (player + 1 == 1) (string_val = "x");
	if (player + 1 == 2) (string_val = "o");
	printf("  | Player: %s(%s) | Round: %d |\n", player_name.c_str(), string_val.c_str(), round_num);
}

// starts the game
// uses local variables: arr, winstreak, round_num, player, player1_name, player2_name, cols, rows, col_num, row_num
void start_game(int* arr, int winstreak, int& round_num, bool& player, string player1_name, string player2_name,
	int cols, int rows, int col_num, int row_num)
{
	// "randomly" choose starting player
	player = rand_number();
	string player_name = (player + 1 == 1) ? player1_name : player2_name;
	printf("\n  Player %s starts first!\n", player_name.c_str());
	cout << endl;
	cout << "  Press ENTER to start the game.";
	getch();

	round_num = 0;
	while (true)
	{
		system("cls");
		print_board(arr, cols, rows);
		print_hotbar(player, player1_name, player2_name, round_num);

		// if game reached max numbers of round
		if (round_num > cols * rows)
		{
			cout << endl;
			cout << "  It's a tie!\n";
			cout << endl;
			break;
		}

		// requires and evaluates user's input of coordinates
		enter_cor(arr, player_name, row_num, col_num, cols, rows);

		// sets the element with chosen coordinates to value according to player
		edit_arr_val(arr, row_num, col_num, player + 1, cols);

		// figures out if player <player> has won
		if (is_win(arr, winstreak, player, row_num, col_num, cols, rows))
		{
			system("cls");
			print_board(arr, cols, rows);
			print_hotbar(player, player1_name, player2_name, round_num);
			string player_name = (player + 1 == 1) ? player1_name : player2_name;
			cout << endl;
			cout << "  Congratulations!\n";
			printf("  Player %s has won the game! \n", player_name.c_str());
			cout << endl;
			if (player_name == "Guest_1" || player_name == "Guest_2")
			{
				cout << "  This game was won by a guest. This score will not be added to the leaderboard! \n";
				cout << endl;
				break;
			}
			cout << "  Score was saved to a leaderboard!\n";
			file_write_score(player_name);
			break;
		}
		// swap the player
		player = !player;
	}
}