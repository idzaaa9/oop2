#include "SudokuWriter.h"

SudokuWriter::SudokuWriter(Sudoku9* refSudoku) : sudoku(refSudoku) {}

void SudokuWriter::write(std::string filename)
{
	std::ofstream file(filename);
	// if we can not open the file properly, just return
	if (!file.is_open()) {
		std::cerr << "error while opening file " << filename << '\n';
		return;
	}
	std::vector<std::vector<unsigned short int>> table = sudoku->getTable();
	// iterate through the table, write every int with a whitespace for easier reading later
	for (const std::vector<unsigned short int> row : table) {
		for (const unsigned short int i : row) {
			file << i << " ";
		}
		file << '\n';
	}
	// close the file and return
	file.close();
	return;
}
