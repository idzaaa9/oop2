#include "SudokuWriter.h"

/*
	args: std::string filename - name of the file in which we save the sudoku
		  Sudoku9& refSudoku - sudoku we are saving
	rtype: void
	prints an error if file can't be opened
*/
void SudokuWriter::write(Sudoku9& refSudoku, std::string filename)
{
	std::ofstream file(filename);
	
	// if we can not open the file properly, just return
	if (!file.is_open()) {
		std::cerr << "error while opening file " << filename << '\n';
		return;
	}
	Utils::tableVector table = refSudoku.getTable();
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
