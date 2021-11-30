#include "menu_leaderboard.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include "file_f.h"

using namespace std;
// opens leaderboard
void leaderboard()
{
	system("cls");
	cout << "   _                _           _                         _ \n";
	cout << "  | |              | |         | |                       | |\n";
	cout << "  | | ___  __ _  __| | ___ _ __| |__   ___   __ _ _ __ __| |\n";
	cout << "  | |/ _ \\/ _` |/ _` |/ _ \\ '__| '_ \\ / _ \\ / _` | '__/ _` |\n";
	cout << "  | |  __/ (_| | (_| |  __/ |  | |_) | (_) | (_| | | | (_| |\n";
	cout << "  |_|\\___|\\__,_|\\__,_|\\___|_|  |_.__/ \\___/ \\__,_|_|  \\__,_|\n";
	cout << endl;
	cout << endl;
	cout << "  Top 10 players:\n";
	cout << endl;
	cout << "  POS                 NAME                              WINS\n";
	//cout << "  ----------------------------------------------------------\n";
	cout << endl;
	int j = 1;
	for (int i = 1; i < 11; i++)
	{
		// every odd line is a string
		string name = file_read_line(i * 2 - 1);
		// every even line is a number
		int wins = stoi(file_read_line(i * 2));
		if (wins != 0)
		{
			// print position
			printf("  %d", i);
			if (i > 9) (cout << "                  ");
			else (cout << "                   ");

			printf("%s", name.c_str());
			for (int i = 0; i < 14 - name.length(); i++)
			{
				cout << " ";
			}
			if (wins <= 9)(cout << " ");
			if (wins <= 99)(cout << " ");
			if (wins <= 999)(cout << " ");
			cout << "                    ";
			printf("%d\n", wins);
		}
		else
		{
			if (i > 9) (printf("  %d                  -                                    -\n", i));
			else (printf("  %d                   -                                    -\n", i));
		}
	}
	//cout << "  ----------------------------------------------------------\n";
	cout << endl;
	cout << endl;
	cout << "  Press ENTER to get back to the menu. ";
	getch();
}
