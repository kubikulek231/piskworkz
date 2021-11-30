#pragma once
// requires and evaluates user's input of coordinates
// uses local variables: player_name, row_num, col_num, cols, rows
void enter_cor(int* arr, string player_name, int& row_num, int& col_num, int cols, int rows);
// prints hotbar
// uses local variables: player, player1_name, player2_name, round_num
void print_hotbar(bool player, string player1_name, string player2_name, int& round_num);
// starts the game
// uses local variables: arr, winstreak, round_num, player, player1_name, player2_name, cols, rows, col_num, row_num
void start_game(int* arr, int winstreak, int& round_num, bool& player, string player1_name, string player2_name,
	int cols, int rows, int col_num, int row_num);
