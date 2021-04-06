#pragma once
#include<iostream>

using namespace std;

class Player
{
private:
	string name;
	int score;
public:
	void SetName(string);
	void IncrementScore(int);
	void DecrementScore(int);
	string GetName();
	int GetScore();
};

