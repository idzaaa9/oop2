#include "SudokuReader.h"

SudokuReader::SudokuReader(std::string refFilename) : filename(refFilename) {}

/*
	args: none
	rtype: std::vector<std::vector<unsigned short int>> with the current state of the board
*/
std::vector<std::vector<unsigned short int>> SudokuReader::read()
{
	std::ifstream file(filename);
	// if file was not opened correctly, return
	if (!file.is_open()) {
		std::cout << "error while opening file " << filename << '\n';
	}

	std::vector<std::vector<unsigned short int>> returnVec;
	std::string line;
	while(std::getline(file, line)) {
		std::vector<unsigned short int> lineVec;
		std::istringstream str(line);

		int val;
		while (str >> val) {
			lineVec.push_back(val);
		}

		returnVec.push_back(lineVec);
	}

	file.close();
	return returnVec;
}