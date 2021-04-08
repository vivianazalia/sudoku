#pragma once
#include"ICommand.h"
#include"Board.h"

class UndoRedo : public ICommand
{
private:
	Board* board;
	int tileIndex;
	char number;
public:
	UndoRedo(Board &_board, int _tileIndex, char _number) : board(&_board) {
		tileIndex = _tileIndex;
		number = _number;
	}

	void Execute() {
		board->SetTile(tileIndex, number);
	}

	void Undo() {
		board->SetTile(tileIndex, '.');
	}
};

