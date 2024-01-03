#pragma once

/*
	this class describes the game of sudoku.
	fields:
		table				     - 9x9 vector which keeps record of the current state of the game.
							       every field contains a number from 0 to 9, and 0 marks an empty field.
		int (in)validMoveCounter - number of (in)valid moves during a single game.
		int gameCoutner			 - number of games played in the current session.
*/

#include <vector>
#include <iostream>
#include <cstddef>

class Sudoku9
{
private:
	using tableVector = std::vector<std::vector<ushort>>;
	tableVector table;
	unsigned int validMoveCounter;
	unsigned int invalidMoveCounter;
	unsigned int gameCounter;
	bool isValidTable(tableVector refTable);
public:
	Sudoku9();
	Sudoku9(tableVector refTable);
	Sudoku9(tableVector refTable,
		int refValidMoveCounter,
		int refInvalidMoveCounter,
		int refGameCounter);
	Sudoku9(const Sudoku9& refSudoku);
	tableVector getTable();
	unsigned int getValidMoveCount();
	unsigned int getInvalidMoveCount();
	unsigned int getGameCount();
	bool isValidMove(const ushort row, const ushort col, const ushort val);
	friend std::ostream& operator<<(std::ostream& os, const Sudoku9 sudoku);
};

