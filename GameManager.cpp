#include "GameManager.h"
#include<iostream>

using namespace std;

void GameManager::StartGame() {
	board.ResetBoard();

	isMatching = false;

	board.RandomFileGame();
	board.DisplayBoard();
}

void GameManager::Input() {
	int inputTileIndex;
	char inputNumber;

	cout << "Which tile index do you choose? : "; cin >> inputTileIndex;

	if (board.CheckTileAvailable(inputTileIndex))
	{
		cout << "Enter a number 1- 9 : "; cin >> inputNumber;

		if (board.CheckValidInput(inputTileIndex, inputNumber))
		{
			board.SetTile(inputTileIndex, inputNumber);
		}
		else
		{
			cout << "Wrong number!" << endl;
			//undo option
		}
	}
	else
	{
		cout << "Tile has been set! Please choose other tile!" << endl;
	}

	board.DisplayBoard();

	isMatching = board.CheckMatch();
}

bool GameManager::IsMatching() {
	return isMatching;
}
