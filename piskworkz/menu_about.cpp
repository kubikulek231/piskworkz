#include "menu_about.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
using namespace std;
// opens about
void about()
{
	system("cls");
	cout << "         _                 _   \n";
	cout << "        | |               | |  \n";
	cout << "    __ _| |__   ___  _   _| |_ \n";
	cout << "   / _` | '_ \\ / _ \\| | | | __|\n";
	cout << "  | (_| | |_) | (_) | |_| | |_ \n";
	cout << "   \\__,_|_.__/ \\___/ \\__,_|\\__|\n";
	cout << endl;
	cout << endl;
	cout << "  piskworkz - A simple tic tac toe like style of a game with terminal interface made in C++.\n";
	cout << "              Made as a project for a subject called Computers and programming 1 in the first\n";
	cout << "              semester of bachelor study at VUT FEKT by Jakub Lepik and Vojtech Mucha.\n";
	cout << endl;
	/*
	cout << "                                                                    #########################\n";
	cout << "                                                                    #########################\n";
	cout << "                                                                    ####        #############\n";
	cout << "                                                                    ############        .####\n";
	cout << "                                                                    ############   ##########\n";
	cout << "                                                                    ############  .##########\n";
	cout << "                                                                    ############  .##########\n";
	cout << "                                                                    ############  .##########\n";
	cout << "                                                                    ############  .##########\n";
	cout << "                                                                    #########################\n";
	cout << "                                                                    #########################\n";
	*/
	cout << "  Press ENTER to get back to the menu. ";
	getch();
}