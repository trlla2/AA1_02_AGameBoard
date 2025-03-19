#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Random.h"

using namespace std;

struct Board {
	
	Board();

	int dynamicSizeX;
	int dynamicSizeY;

	char** box;

	int numGems;
	
	void initialieBoard();
	void printBoard() const;
	void destroyBoard();

};