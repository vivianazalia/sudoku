#include "GameManager.h"
#include "UndoRedo.h"
#include<iostream>

using namespace std;

void GameManager::StartGame() {
	string name;

	board.ResetBoard();

	isMatching = board.CheckMatch();

	board.RandomFileGame();

	cout << "--> Player's Name : ", cin >> name;
	player.SetName(name);
	player.IncrementScore(0);

	board.DisplayBoard();
}

void GameManager::Input() {
	int choice;

	cout << "\n--> SCORE : " << player.GetScore() << endl;
	cout << "--> MOVES : " << player.GetMoves() << endl;

	cout << "\nInputNumber(1) Undo(2) Redo(3) : "; cin >> choice;

	if (choice == 1)
	{
		cout << "Which tile index do you choose? : "; cin >> tileIndex;

		if (board.CheckTileAvailable(tileIndex))
		{
			cout << "Enter a number 1- 9 : "; cin >> number;

			cmd.ExecuteCommand(new UndoRedo(board, tileIndex, number));

			//cmd.ShowUndoStack();

			if (!board.CheckValidInput(tileIndex, number))
			{
				player.DecrementScore(5);
				player.DecreaseMoves();
				cout << "Wrong number!" << endl;
			}
			else
			{
				player.IncrementScore(10);
			}
		}
		else
		{
			cout << "Tile has been set! Please choose other tile!" << endl;
		}
	}
	else if (choice == 2)
	{
		cmd.UndoCommand();
	}
	else if (choice == 3)
	{
		cmd.RedoCommand();
	}

	board.DisplayBoard();

	//cmd.ShowUndoStack();

	isMatching = board.CheckMatch();

	CheckWin();
}

bool GameManager::IsMatching() {
	return isMatching;
}

void GameManager::CheckWin() {
	cout << endl;
	if (player.GetMoves() <= 0 && isMatching == false)
	{
		cout << "\t\t\t    GAME OVER " << endl;
		cout << "\t\t\t    Score : " << player.GetScore() << endl;
		isMatching = true;
	}
	else if (player.GetMoves() > 0 && isMatching == true)
	{
		cout << "\t\t\t    YOU'RE WIN " << endl;
		cout << "\t\t\t    Score : " << player.GetScore() << endl;
	}
}