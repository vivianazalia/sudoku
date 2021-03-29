#include"GameManager.h"
#include<iostream>

GameManager gm;

int main() {
	gm.StartGame();

	while (!gm.IsMatching())
	{
		gm.Input();
	}

	return 0;
}