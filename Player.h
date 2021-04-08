#pragma once
#include<iostream>

using namespace std;

class Player
{
private:
	string name;
	int score;
	int moves = 3;
public:
	void SetName(string);
	void IncrementScore(int);
	void DecrementScore(int);
	void DecreaseMoves();
	string GetName();
	int GetScore();
	int GetMoves();
};

