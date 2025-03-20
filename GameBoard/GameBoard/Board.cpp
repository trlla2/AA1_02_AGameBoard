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

void Board:: initialieBoard(Player* player) {
	
	box = new char* [dynamicSizeX]; // Create new array

	for (int i = 0; i < dynamicSizeX; ++i)
	{
		box[i] = new char[dynamicSizeY];
	}

	//give each box a value
	int emptyBoxesSize = 0;


	// fill array
	for (int i = 0; i < dynamicSizeX; i++) {
		for (int j = 0; j < dynamicSizeY; j++) {
			// Verify if is wall
			if (i == 0 || i == dynamicSizeX - 1 || j == 0 || j == dynamicSizeY - 1) {
				box[i][j] = 'W'; // Wall
			}
			else {
				box[i][j] = '.'; // Empty box

				emptyBoxesSize++;
			}
		}
	}

	int maxSpikes = emptyBoxesSize * 0.1; // 10%  of spikes
	int maxGems = emptyBoxesSize * 0.25; // 25% of gems


	if (maxSpikes > 0) {
		numSpikes = GenerateClampedRandom(0, maxSpikes); // generate num of Spikes
	}
	else
	{
		numSpikes = 1; // Forced to atlest have 1 spike
	}

	if (maxGems > 0) {
		numGems = GenerateClampedRandom(0, maxGems); // generate num of Gems
	}
	else
	{
		numGems = 1; // Forced to atlest have 1 gem
	}

	int leftSpikes = numSpikes; // contains num of left spikes to print
	int leftGems = numGems; // contains num of left gems to print

	bool playerSpawned = false; // check if player is Spawned

	while ((leftSpikes > 0 || leftGems > 0 || !playerSpawned)) {
		int randomXPos = GenerateClampedRandom(0, dynamicSizeX - 1); // Get random position from boad
		int randomYPos = GenerateClampedRandom(0, dynamicSizeY - 1);

		if (box[randomXPos][randomYPos] == '.'){ // if is empty 
			if (leftSpikes > 0) { //Spawn all spikes
				leftSpikes--;
				box[randomXPos][randomYPos] = 'S'; // Spike
			}
			else if (leftGems > 0) { //Spawn all Gems
				leftGems--;
				box[randomXPos][randomYPos] = 'G'; // Gem
			}
			else { //Spawn Player
				box[randomXPos][randomYPos] = 'P'; // Player
				player->setPosition(randomXPos, randomYPos);
				playerSpawned = true;
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
			std::cout << "| " << box[i][j] << " |";
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