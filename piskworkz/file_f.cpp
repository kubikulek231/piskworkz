#pragma once
#include "file_f.h"
#include <iostream>
#include "stdio.h"
#include "conio.h"
#include <string>
#include <fstream>

std::string file_read_line(int line_num)
{
	// creates a file if it does not exist
	std::string return_string;
	int i = 0;
	std::string line;
	std::ifstream myfile("leaderboard.cfg");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			i++;
			if (i == line_num) (return_string = line);
		}
		myfile.close();
		// if the number of lines is lower than line_num
		if (line_num > i) (return_string = "0");
	}

	else std::cout << "No leaderboard entries!\n";

	return return_string;
}

int file_player_num()
{
	int player_num;
	std::ifstream myfile("leaderboard.cfg");
	std::string line;
	int i = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			i++;
		}
		myfile.close();
		// if the number of lines is lower than line_num
	}
	return i / 2;
}

int file_write_score(std::string new_name)
{
	int player_num = file_player_num();
	auto name_arr = new std::string[player_num];
	auto score_arr = new int[player_num];

	// get all the names and wins from leaderboard.txt
	for (int i = 1; i < player_num + 1; i++)
	{
		// every odd line is a string
		name_arr[i - 1] = file_read_line(i * 2 - 1);
		// every even line is a number
		score_arr[i - 1] = std::stoi(file_read_line(i * 2));
	}
	bool name_found = false;
	for (int i = 1; i < player_num + 1; i++)
	{
		// if the name is already in the leaderboard, add 1 to it's score value
		if (name_arr[i - 1] == new_name)
		{
			name_found = true;
			score_arr[i - 1]++;
			// if there's a value with the lower score in front of it in the array, swap them
			if (score_arr[i - 2] < score_arr[i - 1] && i > 1)
			{
				// old values get stored
				std::string temp_name = name_arr[i - 2];
				int temp_score = score_arr[i - 2];
				// old values get overwrited by new ones
				name_arr[i - 2] = name_arr[i - 1];
				score_arr[i - 2] = score_arr[i - 1];
				// stored old values are writed to the old position of new ones
				name_arr[i - 1] = temp_name;
				score_arr[i - 1] = temp_score;
			}
		}
	}
	// overwrite the text file with the values from arrays
	std::ofstream myfile("leaderboard.cfg", std::ios::trunc);
	for (int i = 1; i < player_num + 1; i++)
	{
		myfile << name_arr[i - 1];
		myfile << "\n";
		myfile << score_arr[i - 1];
		myfile << "\n";
	}

	// if it's a new name, append it to the text file
	if (name_found == false)
	{
		myfile << new_name;
		myfile << "\n";
		myfile << 1;
		myfile << "\n";
	}
	myfile.close();
	delete[] name_arr;
	delete[] score_arr;
	return 0;
}