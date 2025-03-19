#pragma once


struct Player {
	
	int score;
	
	// position
	int posX;
	int posY;

	bool isAlive;
	
	void setPosition(int x, int y);
	void addScore();
	

};

