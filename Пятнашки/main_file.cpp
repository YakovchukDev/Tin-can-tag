#include "Header.h"

void game(int * board, int complexity, int &index)
{
	cout << endl;
	bool check = false;
	while (check == false)
	{
		cout_board(board, complexity);
		cout << endl << "Push the button in the yak side you want to resemble" << endl;
		cout << "\t  |W|" << endl << "\t|A|S|D|" << endl;
		cout << "Your choose:";
		int move;
		do 
		{
			move = _getch();
		} while ((char)move != 'w' && (char)move != 'W' && (char)move != 'a' && (char)move != 'A' && (char)move != 's' && (char)move != 'S' && (char)move != 'd' && (char)move != 'D');
		cout << (char)move << endl;

		switch ((char)move)
		{
		case 'W':
		{
			move = 'w';
			break;
		}
		case 'A':
		{
			move = 'a';
			break;
		}
		case 'S':
		{
			move = 's';
			break;
		}
		case 'D':
		{
			move = 'd';
			break;
		}
		}

		switch ((char)move)
		{
		case 'w':
		{
			game_move(-1 * sqrt(complexity), index, board, complexity);
			break;
		}
		case 'a':
		{
			game_move(-1, index, board, complexity);
			break;
		}
		case 's':
		{
			game_move(sqrt(complexity), index, board, complexity);
			break;
		}
		case 'd':
		{
			game_move(1, index, board, complexity);
			break;
		}
		}
		int qaunter = 0;
		for (int i = 0; i < complexity-1; i++)
		{
			if (board[i] == i + 1) qaunter++;
		}
		if (qaunter == complexity-1) check = true;
	}
}

int main()
{
	srand(time(0));
	
	cout << "Input size table(3/9): ";
	int complexity;
	do
	{
		cin >> complexity;
	} while (complexity > 9 || complexity < 3);
	complexity = pow(complexity, 2);
	system("CLS");
	int * board = new int [complexity];
	int index;
	filling_out(board, complexity, index);

	game(board, complexity, index);

	cout << endl << "    " << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
	cout << endl << "    " << (char)179 << " YOU WIN " << (char)179;
	cout << endl << "    " << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217;
	
	system("pause");
}