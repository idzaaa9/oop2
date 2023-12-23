#include "Sudoku9.h"

Sudoku9::Sudoku9() : table(9, std::vector<unsigned short int>(9, 0)),
					 validMoveCounter(0), 
					 invalidMoveCounter(0),
					 gameCounter(0) {}

Sudoku9::Sudoku9(std::vector<std::vector<unsigned short int>> refTable,
				int refValidMoveCounter,
				int refInvalidMoveCounter,
				int refGameCounter) : 
				 table(refTable), validMoveCounter(refValidMoveCounter),
				 invalidMoveCounter(refInvalidMoveCounter), gameCounter(refGameCounter){}

Sudoku9::Sudoku9(const Sudoku9& refSudoku) : 
	table(refSudoku.table),
	validMoveCounter(refSudoku.validMoveCounter),
	invalidMoveCounter(refSudoku.invalidMoveCounter),
	gameCounter(refSudoku.gameCounter) {}

std::vector<std::vector<unsigned short int>> Sudoku9::getTable() { return table; }

unsigned int Sudoku9::getValidMoveCount() { return validMoveCounter; }

unsigned int Sudoku9::getInvalidMoveCount() { return invalidMoveCounter; }

unsigned int Sudoku9::getGameCount() { return gameCounter; }