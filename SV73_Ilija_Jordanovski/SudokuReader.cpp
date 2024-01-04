#include "SudokuReader.h"

/*
	args: std::string filename name of the file we are reading from
	rtype: std::vector<std::vector<unsigned short int>> with the current state of the board
*/
Utils::tableVector SudokuReader::read(std::string filename)
{
	std::ifstream file(filename);
	// if file was not opened correctly, return an empty vector
	if (!file.is_open()) {
		std::cout << "error while opening file " << filename << '\n';
		return std::vector<std::vector<ushort>>(9, std::vector<ushort>(9, 0));
	}

	Utils::tableVector returnVec;
	std::string line;
	while(std::getline(file, line)) {
		std::vector<unsigned short int> lineVec;
		std::istringstream str(line);

		int val;
		while (str >> val) {
			lineVec.push_back(val);
			if (val < 0 || val > 9) return Utils::emptyVector();
		}

		returnVec.push_back(lineVec);
	}

	file.close();
	return returnVec;
}