#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Board {
	
	Board();

	int dynamicSizeX;
	int dynamicSizeY;

	char** box;

	
	void initialieBoard();
	void printBoard() const;
	void destroyBoard();

};