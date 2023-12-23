#pragma once

/*
	this class is used for saving a sudoku board into a file.
	fields:
		Sudoku9* sudoku - pointer to the table we want to save.
	member functions:
		SudokuWriter(Sudoku9* refSudoku) - constructor 
		void write(std::string filename) - writes the current table state into a file,
										   prints out an error if the file can not be opened

*/

#include "Sudoku9.h"
#include <fstream>
#include <iostream>

class SudokuWriter
{
private:
	Sudoku9* sudoku;
public:
	SudokuWriter(Sudoku9* refSudoku);
	void write(std::string filename);
};

