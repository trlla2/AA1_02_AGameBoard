#include "Board.h"

Board::Board() {
	ifstream archive("config.txt"); //Open config.txt
	
	if (!archive.is_open()) {
		cout << "ERROR: No config file"; // Throw error if couldn't open

		return;
	}

	archive >> dynamicSizeX >> dynamicSizeY; // reed X and Y positions
	
	archive.close(); // close conig.txt
}

void Board:: initialieBoard() {
	
	box = new char* [dynamicSizeX]; // Create new array

	for (int i = 0; i < dynamicSizeX; ++i)
	{
		box[i] = new char[dynamicSizeY];
	}

	//give each box a value

	// fill array
	for (int i = 0; i < dynamicSizeX; i++) {
		for (int j = 0; j < dynamicSizeY; j++) {
			// Verify if is wall
			if (i == 0 || i == dynamicSizeX - 1 || j == 0 || j == dynamicSizeY - 1) {
				box[i][j] = 'M';
			}
			else {

				box[i][j] = '.';
			}
		}
	}
}

void Board::printBoard() const {
	for (int i = 0; i < dynamicSizeX; i++) {
		cout << " ___ ";
	}
	std::cout << std::endl;
	for (int i = 0; i < dynamicSizeX; i++) {

		for (int j = 0; j < dynamicSizeY; j++) {
			std::cout << "|   |";
		}
		std::cout << std::endl;
		for (int j = 0; j < dynamicSizeY; j++) {
			std::cout << "| " << box[dynamicSizeX][dynamicSizeY] << " |";
		}
		std::cout << std::endl;
		for (int j = 0; j < dynamicSizeY; j++) {
			std::cout << "|___|";
		}
		std::cout << std::endl;
	}
}

void Board::destroyBoard() {
	for (int i = 0; i < dynamicSizeX; i++) {
		delete[] box[i];
	}
	delete[] box;
}