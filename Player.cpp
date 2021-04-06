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

string Player::GetName() {
	return name;
}

int Player::GetScore() {
	return score;
}
