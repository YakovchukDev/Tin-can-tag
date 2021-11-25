#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <conio.h>
#include <ctime>
#include <stdio.h>

using namespace std;

void cout_board(int * arr, int complexity);

void filling_out(int * board, int complexity, int &index);

void game_move(int change, int &index, int * board, int complexity);