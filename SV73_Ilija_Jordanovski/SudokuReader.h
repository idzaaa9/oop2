#pragma once

/*
	this class is used for loading a table from a file.
	fields:
		std::string filename - name of the file we will read from
	member functions:
		SudokuReader(std::string filename) - constructor
		Sudoku9 read() - returns a table from the given file, 
						 if data is not valid throws an error
*/

#include "Sudoku9.h"
#include <fstream>
#include <iostream>

class SudokuReader
{
private:
	std::string filename;
public:
	SudokuReader(std::string refFilename);
	Sudoku9 read();
};

