#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Random.h"
#include "Player.h"

using namespace std;

struct Board {
	
	Board();

	int dynamicSizeX;
	int dynamicSizeY;

	char** box;

	int numGems;
	int numSpikes;
	
	void initialieBoard(Player* player);
	void printBoard() const;
	void destroyBoard();

};