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

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "utils/Utils.hpp"

class SudokuReader
{
public:
	static Utils::tableVector read(std::string filename);
};

