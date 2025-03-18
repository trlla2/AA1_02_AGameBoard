#pragma once


struct Player {
	
	int score;
	
	// position
	int posX;
	int posY;
	
	void setPosition(int x, int y);
	void addScore();
	void movePlayer();

};

