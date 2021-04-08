#include "Board.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

void Board::DisplayBoard() {
	system("cls");
	cout << "====================================================================" << endl;
	cout << "				SUDOKU                                " << endl;
	cout << "====================================================================" << endl;
	cout << "\n\t   1     2     3     4     5     6     7     8     9   " << endl;
	cout << "\t   |     |     |     |     |     |     |     |     |   " << endl;
	cout << "\t_______________________________________________________" << endl;

	for (int i = 0; i < INDEX; i++)
	{
		cout << "\t|     |     |     |     |     |     |     |     |     | " << endl;
		cout << "\t";
		for (int j = 0; j < INDEX; j++)
		{
			cout << "|  " << grid[i][j] << "  ";
		}
		cout << "|--" << ((i+1)*9) << endl;
		cout << "\t|     |     |     |     |     |     |     |     |     | " << endl;
		cout << "\t_______________________________________________________" << endl;
	}
}

char Board::GetTiles(int number) {
	row = number / 9;
	if (number % 9 == 0)
	{
		row = row - 1;
		column = 8;
	}
	else
	{
		column = number % 9 - 1;
	}

	return grid[row][column];
}

char Board::GetBufferTile(int number) {
	row = number / 9;
	if (number % 9 == 0)
	{
		row = row - 1;
		column = 8;
	}
	else
	{
		column = number % 9 - 1;
	}

	return buffer[row][column];
}

void Board::SetTile(int tileIndex, char numberInput) {
	row = tileIndex / 9;
	if (tileIndex % 9 == 0)
	{
		row = row - 1;
		column = 8;
	}
	else
	{
		column = tileIndex % 9 - 1;
	}
	grid[row][column] = numberInput;
}

bool Board::CheckMatch() {
	for (int i = 0; i < INDEX; i++)
	{
		for (int j = 0; j < INDEX; j++)
		{
			if (grid[i][j] != buffer[i][i])
			{
				return false;
			}
		}
	}
	return true;
}

bool Board::CheckTileAvailable(int tileIndex) {
	if (GetTiles(tileIndex) == '.')
	{
		return true;
	}

	return false;
}

bool Board::CheckValidInput(int tileIndex, int inputNumber) {
	if (inputNumber == GetBufferTile(tileIndex))
	{
		return true;
	}

	return false;
}

void Board::ResetBoard() {
	for (int i = 0; i < INDEX; i++)
	{
		for (int j = 0; j < INDEX; j++)
		{
			grid[i][j] = '.';
		}
	}
}

void Board::RandomFileGame() {
	srand(time(0));
	int random = rand() % 3;
	if (random == 0)
	{
		file.open("file1.txt", ios::in);
	}
	else if (random == 1)
	{
		file.open("file2.txt", ios::in);
	}
	else if (random == 2)
	{
		file.open("file3.txt", ios::in);
	}
	
	while (!file.eof())
	{
		for (int i = 0; i < INDEX; i++)
		{
			for (int j = 0; j < INDEX; j++)
			{
				file >> buffer[i][j];
			}
		}
	}
	file.close();
	RandomNumber();
}

void Board::RandomNumber() {
	srand(time(0));
	for (int i = 0; i < 40; i++)
	{
		int random = rand() % 81;
		SetTile(random, GetBufferTile(random));
	}
}

