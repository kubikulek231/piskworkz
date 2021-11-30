#pragma once
#include <string>
using namespace std;
void get_player_name(int player_num, bool guest, string& player1_name, string& player2_name);
void new_game(int& rows, int& cols, int& streak_num, bool& guest, string& player1_name, string& player2_name);
