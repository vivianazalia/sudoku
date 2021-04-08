#include "Player.h"

void Player::SetName(string n) {
	name = n;
}

void Player::IncrementScore(int s) {
	score += s;
}

void Player::DecrementScore(int s) {
	score -= s;

	if (score <= 0)
	{
		score = 0;
	}
}

void Player::DecreaseMoves() {
	moves--;
}

string Player::GetName() {
	return name;
}

int Player::GetScore() {
	return score;
}

int Player::GetMoves() {
	return moves;
}

void Player::ResetData() {
	score = 0;
	moves = 3;
}

//4210191021 - Intan Putri K W