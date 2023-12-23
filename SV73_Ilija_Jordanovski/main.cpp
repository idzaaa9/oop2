#include "Sudoku9.h"
#include "SudokuWriter.h"

int main()
{
	SudokuWriter* sw = new SudokuWriter(new Sudoku9());
	sw->write("test.txt");
	return 0;
}