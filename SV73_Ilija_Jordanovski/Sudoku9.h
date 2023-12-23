#pragma once

/*
	this class describes the game of sudoku.
	fields:
		table				     - 9x9 vector which keeps record of the current state of the game.
							       every field contains a number from 0 to 9, and 0 marks an empty field.
		int (in)validMoveCounter - number of (in)valid moves during a single game.
		int gameCoutner			 - number of games played in the current session.
	member functions:
		Sudoku()	- empty constructor, creates an empty 9x9 vector and sets counters to 0

*/

#include <vector>

class Sudoku9
{
private:
	std::vector<std::vector<unsigned short int>> table;
	unsigned int validMoveCounter;
	unsigned int invalidMoveCounter;
	unsigned int gameCounter;
public:
	Sudoku9();
	Sudoku9(std::vector<std::vector<unsigned short int>> refTable,
		int refValidMoveCounter, int refInvalidMoveCounter,
		int refGameCounter);
	Sudoku9(const Sudoku9& refSudoku);
	std::vector<std::vector<unsigned short int>> getTable();
	unsigned int getValidMoveCount();
	unsigned int getInvalidMoveCount();
	unsigned int getGameCount();
};

