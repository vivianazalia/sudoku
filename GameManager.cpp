#include "GameManager.h"
#include<iostream>

using namespace std;

void GameManager::StartGame() {
	string name;

	board.ResetBoard();

	isMatching = false;

	board.RandomFileGame();

	cout << "--> Player's Name : ", cin >> name;
	player.SetName(name);
	player.IncrementScore(0);

	board.DisplayBoard();
}

void GameManager::Input() {
	int choice;

	cout << "Which tile index do you choose? : "; cin >> tileIndex;

	if (board.CheckTileAvailable(tileIndex))
	{
		cout << "Enter a number 1- 9 : "; cin >> number;

		cmd.ExecuteCommand(this);

		board.DisplayBoard();

		if (!board.CheckValidInput(tileIndex, number))
		{
			player.DecrementScore(5);
			cout << "Wrong number!" << endl;
			cout << "Undo (1)" << endl;
			cout << "Choose option : "; cin >> choice;

			if (choice == 1)
			{
				//undo option
				cmd.UndoCommand(this);
			}
		}
		else
		{
			player.IncrementScore(10);
		}

		board.DisplayBoard();
	}
	else
	{
		cout << "Tile has been set! Please choose other tile!" << endl;
	}

	cout << "--> SCORE : " << player.GetScore() << endl;

	isMatching = board.CheckMatch();
}

bool GameManager::IsMatching() {
	return isMatching;
}

void GameManager::Execute() {
	board.SetTile(tileIndex, number);
}

void GameManager::Undo() {
	board.SetTile(tileIndex, '.');
}

void GameManager::Redo() {

}
