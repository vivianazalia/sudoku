#pragma once
#include"Board.h"

class GameManager
{
private: 
	Board board;
	bool isMatching;
public:
	void StartGame();
	void Input();
	bool IsMatching();
};

