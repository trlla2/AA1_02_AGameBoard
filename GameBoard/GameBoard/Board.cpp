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

	vector<pair<int, int>> emptyBoxes; //Vector with all the empty Boxes

	// fill array
	for (int i = 0; i < dynamicSizeX; i++) {
		for (int j = 0; j < dynamicSizeY; j++) {
			// Verify if is wall
			if (i == 0 || i == dynamicSizeX - 1 || j == 0 || j == dynamicSizeY - 1) {
				box[i][j] = 'W';
			}
			else {
				box[i][j] = '.';

				emptyBoxes.push_back(make_pair(i, j)); // push empty positions to vector
			}
		}
	}

	if (!emptyBoxes.empty()) { // check if there is empty boxes

		int maxSpikes =  emptyBoxes.size() * 0.1; // 10%  of spikes
		int maxGems = emptyBoxes.size() * 0.25; // 25% of gems

		int numSpikes = GenerateClampedRandom(0, maxSpikes); // generate num of Spikes
		int numGems = GenerateClampedRandom(0, maxGems); // generate num of Gems

		std::random_shuffle(emptyBoxes.begin(), emptyBoxes.end()); // shufle empty Boxes

		for (int i = emptyBoxes.size() - 1; i > 0; i--) { // spawn spikes and gems on emptyBoxes
			if (numSpikes > 0) {
				numSpikes--;
				box[emptyBoxes[i].first][emptyBoxes[i].second] = 'S'; // Spike
				emptyBoxes.pop_back();
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