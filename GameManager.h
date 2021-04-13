#pragma once
#include"Board.h"
#include"ICommand.h"
#include"CommandManager.h"
#include"Player.h"
#include"Color.h"

class GameManager
{
private: 
	Board board;
	CommandManager cmd;
	Player player;
	Color color;
	bool isMatching;
	int tileIndex;
	char number;
public:
	void StartGame();
	void Input();
	bool IsMatching();
	void CheckWin();
};

