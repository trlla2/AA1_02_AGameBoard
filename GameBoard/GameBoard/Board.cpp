#include "Board.h"

Board::Board() {
	ifstream archive("config.txt"); //Open config.txt
	
	if (!archive.is_open()) {
		cout << "ERROR: No config file"; // Throw error if couldn't open

		return;
	}

	archive >> dynamicSizeX >> dynamicSizeY; // reed X and Y positions

	box = new char* [dynamicSizeX][dynamicSizeY];
	
	archive.close(); // close conig.txt

	//give each box a value

	// fill array
	for (int i = 0; i < dynamicSizeX; i++) {
		for (int j = 0; j < dynamicSizeY; j++) {
			// Verifi if is wall
			if (i == 0 || i == dynamicSizeX - 1 || j == 0 || j == dynamicSizeY - 1) {
				box[i][j] = 'M';
			}
			else {
				
				box[i][j] = '.';
			}
		}
	}

}