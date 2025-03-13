#pragma once

struct Board {

	int dynamicSizeX;
	int dynamicSizeY;

	char* board;


	void initialieBoard();
	void printBoard();
	void destroyBoard();

};