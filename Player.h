#pragma once
#include<iostream>

using namespace std;

class Player
{
private:
	string name;
	int score;
	int moves;
public:
	void SetName(string);
	string GetName();
	int GetScore();
	int GetMoves();
	void IncrementScore(int);
	void DecrementScore(int);
	void DecreaseMoves();
	void ResetData();
};

