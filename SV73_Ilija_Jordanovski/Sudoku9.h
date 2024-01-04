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
#include <utility>

#include "utils/Utils.hpp"

class Sudoku9
{
private:
	Utils::tableVector table;
	unsigned int validMoveCounter;
	unsigned int invalidMoveCounter;
	unsigned int gameCounter;
	bool isValidTable(Utils::tableVector refTable);
public:
	Sudoku9();
	Sudoku9(Utils::tableVector refTable);
	Sudoku9(Utils::tableVector refTable,
		unsigned int refValidMoveCounter,
		unsigned int refInvalidMoveCounter,
		unsigned int refGameCounter);
	Sudoku9(const Sudoku9& refSudoku);
	Utils::tableVector getTable() const;
	unsigned int getValidMoveCount() const;
	unsigned int getInvalidMoveCount() const;
	unsigned int getGameCount() const;
	bool isValidMove(const int row, const int col, const ushort val);
	bool isSolved();
	std::pair<ushort, ushort> findEmptyPosition();
	bool solve();
	bool validate();
	friend std::ostream& operator<<(std::ostream& os, const Sudoku9 sudoku);
	Sudoku9& operator=(const Sudoku9& other);
};

