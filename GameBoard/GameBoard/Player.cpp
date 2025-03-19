#include "Player.h"


Player::Player() {
	isAlive = true;
	score = 0;

	posX = 0;
	posY = 0;
}

void Player::addScore() {
	score++; // add 1 to score
}

void Player::setPosition(int x, int y) {
	posX = x; 
	posY = y;
}

