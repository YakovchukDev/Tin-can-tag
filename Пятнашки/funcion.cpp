#include "Header.h"


void cout_board(int * board, int complexity)
{
	system("CLS");

	for (int i = 0; i < complexity; i++)
	{
		cout << " ";
		int k = sqrt(complexity);
		if (i % k == 0) cout << endl << endl << "   ";
		if (board[i] < 10) cout << " ";
		if (board[i] == 0) cout << "   ";
		else cout << board[i] << "  ";
	}
	cout << endl;
}

void filling_out(int * board, int complexity, int &index)
{
	bool check = false;
	for (int i = 0; i < complexity; i++)
	{
		int number = rand() % complexity;
		for (int j = 0; j < i; j++)
		{
			if (board[j] == number)
			{
				check = true;
				break;
			}
		}
		if (check == false)
		{
			board[i] = number;
			if (number == 0) index = i;
		}
		else
		{
			check = false;
			i--;
		}
	}
}

void game_move(int change, int &index, int * board, int complexity)
{
	if (index + change >= 0 && index + change < complexity)
	{
		int k = board[index + change];
		board[index + change] = board[index];
		board[index] = k;
		index = index + change;
	}
}