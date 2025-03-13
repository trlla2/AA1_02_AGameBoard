#pragma once


struct Player {
	
	int score;
	
	// position
	int posX;
	int posY;
	
	void setPosition();
	void addScore();
	void movePlayer();

};

