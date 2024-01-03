#include "Sudoku9.h"

#define EMPTY 0

// function which goes through every member of the vector and checks if it is in the 0-9 range
bool Sudoku9::isValidTable(tableVector refTable)
{
	for (std::vector<ushort> row : table) {
		for (ushort val : row) {
			if (val < 0 || val > 9) return false; 
		}
	}

	return true;
}


Sudoku9::Sudoku9() : table(9, std::vector<ushort>(9, 0)),
					 validMoveCounter(0), 
					 invalidMoveCounter(0),
					 gameCounter(0) {}

Sudoku9::Sudoku9(tableVector refTable,
				int refValidMoveCounter = 0,
				int refInvalidMoveCounter = 0,
				int refGameCounter = 0) : 
				 table(refTable.begin(), refTable.end()), validMoveCounter(refValidMoveCounter),
				 invalidMoveCounter(refInvalidMoveCounter), gameCounter(refGameCounter){}

Sudoku9::Sudoku9(tableVector refTable) : 
				 table(refTable.begin(), refTable.end()), validMoveCounter(0), invalidMoveCounter(0), gameCounter(0) 
				 {
					if (!isValidTable(refTable))
						table = tableVector(9, std::vector<ushort>(9, 0));
				 }

Sudoku9::Sudoku9(const Sudoku9& refSudoku) : 
	table(refSudoku.table.begin(), refSudoku.table.end()),
	validMoveCounter(refSudoku.validMoveCounter),
	invalidMoveCounter(refSudoku.invalidMoveCounter),
	gameCounter(refSudoku.gameCounter) {}

Sudoku9::tableVector Sudoku9::getTable() { return table; }

unsigned int Sudoku9::getValidMoveCount() { return validMoveCounter; }

unsigned int Sudoku9::getInvalidMoveCount() { return invalidMoveCounter; }

unsigned int Sudoku9::getGameCount() { return gameCounter; }

/*
	args:  ushort row - value of row we want to check
		   ushort col - value of column we want to check
		   ushort val - value we want to input
	rtype: bool - true if move is valid, false if not
	a move is valid if there are no duplicate values in the same row, column, or 3x3 square
*/
bool Sudoku9::isValidMove(const ushort row, const ushort col, const ushort val)
{
	// if the field already has a value, then the move is not valid
	if (table[col][row]) {
		std::cout << "na tacno tom polju je zauzeto";
		return false;
	}
	// check if val is in the row
	for (int i = 0; i < 9; ++i){
		if (table[col][i] == val){
		std::cout << "u istoj koloni ima vrednost " << val ;
		return false;
		}
	}
	// check if val is in the column
	for (int i = 0; i < 9; ++i) {
		if (table[i][row] == val){
			 std::cout << "u " << row << " redu  " << i << "koloni ima vrednost" << val;
			 return false;
		}
	}
	// check the 3x3 squares
	int subgridRow = 3 * (row / 3);
	int subgridCol = 3 * (col / 3);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; i < 3; ++i) {
			if (table[subgridCol + i][subgridRow+j] == val){
				std::cout << "u istom gridu ima vrednost";
				return false;
			} 
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const Sudoku9 sudoku)
{
	for (int i = 0; i < 9; ++i) {
		if (i > 0 && i % 3 == 0)
			os << "---+---+---" << std::endl;

		for (int j = 0; j < 9; ++j) {
			if (j > 0 && j % 3 == 0)
				os << "|";
			
			if (sudoku.table[i][j] == EMPTY) {
				os << ' ';
				continue;
			}
			os << sudoku.table[i][j];
		}
		os << '\n';
	}

	return os;
}
