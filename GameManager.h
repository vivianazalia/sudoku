#pragma once
#include"Board.h"
#include"ICommand.h"
#include"CommandManager.h"
#include"Player.h"

class GameManager : public ICommand
{
private: 
	Board board;
	CommandManager cmd;
	Player player;
	bool isMatching;
	int tileIndex;
	char number;
public:
	void StartGame();
	void Input();
	bool IsMatching();
	void Execute();
	void Undo();
	void Redo();
};

