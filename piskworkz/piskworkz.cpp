
/*
 * piskworkz - a simple terminal tic tac toe style game written in c++
 * made by Jakub Lepik and Vojtech Mucha
 *
*/

#include "piskworkz.h"

#include <conio.h>

#include "array_f.h"
#include "basic_f.h"
#include "game_setup.h"
#include "menu_about.h"
#include "menu_leaderboard.h"
#include "game_start.h"


/* TODO
 * BUG FIXES!
 * all the required functions done
 * single player - play against a computer = > implement some kind of an algorithm
 */


using namespace std;


void main()
{
	// enters the main menu
	{
		while (true)
		{
			bool exit = false;
			int option = 0;
			system("cls");
			cout << "         _     _                        _         \n";
			cout << "        (_)   | |                      | |        \n";
			cout << "   _ __  _ ___| | ____      _____  _ __| | __ ____\n";
			cout << "  | '_ \\| / __| |/ /\\ \\ /\\ / / _ \\| '__| |/ /|_  /\n";
			cout << "  | |_) | \\__ \\   <  \\ V  V / (_) | |  |   <  / / \n";
			cout << "  | .__/|_|___/_|\\_\\  \\_/\\_/ \\___/|_|  |_|\\_\\/___|\n";
			cout << "  | |                                             \n";
			cout << "  |_|             by Jakub Lepik and Vojtech Mucha\n";
			cout << endl;
			cout << endl;
			cout << "  1 - Start game\n";
			cout << "  2 - Leaderboard\n";
			cout << "  3 - About\n";
			cout << "  4 - Exit\n";
			cout << endl;

			while (true)
			{
				bool error = false;
				bool input_error = false;
				cout << "  Select an option: ";
				option = scan_1int(input_error);
				if (option > 4 && input_error == false)
				{
					printf("  Error! There's no such option (%d).\n", option);
					error = true;
				}
				if (option < 1 && input_error == false)
				{
					printf("  Error! There's no such option (%d).\n", option);
					error = true;
				}
				if (option == 1 && input_error == false)
				{
					int rows = 0;
					int cols = 0;
					int streak_num = 0;
					int round_num = 0;
					bool player = false;
					int col_num = 0, row_num = 0;
					string player1_name;
					string player2_name;
					bool guest;
					// setups a new game
					// user input: rows, cols, streak_num
					new_game(rows, cols, streak_num, guest, player1_name, player2_name);
					// defines a "fake" 2d array of rows*cols size
					// uses global variable: rows, cols
					int* board_arr = define_arr(0, rows, cols);
					// starts the game with all the global variables
					// user coordinates input
					start_game(board_arr, streak_num, round_num, player, player1_name, player2_name, cols, rows, col_num,
						row_num);
					// deletes the created array (memory handling)
					delete[] board_arr;
					cout << "  Press ENTER to get back to the menu. ";
					getch();
					break;
				}
				if (option == 2 && input_error == false)
				{
					leaderboard();
					break;
				}
				if (option == 3 && input_error == false)
				{
					about();
					break;
				}
				if (option == 4 && input_error == false)
				{
					exit = true;
					break;
				}
			}
			if (exit == true)
			{
				break;
			}
		}
	}

}
