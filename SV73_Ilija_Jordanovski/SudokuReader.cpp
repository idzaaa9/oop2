#include "SudokuReader.h"

SudokuReader::SudokuReader(std::string refFilename) : filename(refFilename) {}

Sudoku9 SudokuReader::read()
{
	std::ifstream file(filename);
	// if file was not opened correctly, return
	if (!file.is_open()) {
		std::cerr << "error while opening file " << filename << '\n';
	}
}