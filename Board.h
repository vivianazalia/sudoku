#pragma once
#include<fstream>

using namespace std;

class Board
{
private:
	const static int INDEX = 9;
	char grid[INDEX][INDEX];
	char buffer[INDEX][INDEX];
	int row, column;
	fstream file;
	char GetBufferTile(int);
public:
	void DisplayBoard();

	char GetTiles(int);

	void SetTile(int tileIndex, char inputNumber);

	int GetRow(int);

	int GetColumn(int);

	bool CheckMatch();

	bool CheckHorizontal(int row, char inputNumber);

	bool CheckVertical(int, char);

	bool CheckGroupMatch();

	bool CheckTileAvailable(int tileIndex);

	bool CheckValidInput(int, int);

	void ResetBoard();

	void RandomFileGame();

	void RandomNumber();
};

