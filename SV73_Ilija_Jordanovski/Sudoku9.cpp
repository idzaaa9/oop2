#include "Sudoku9.h"
#define EMPTY 0

// function which goes through every member of the vector and checks if it is in the 0-9 range
bool Sudoku9::isValidTable(Utils::tableVector refTable)
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

Sudoku9::Sudoku9(Utils::tableVector refTable,
				unsigned int refValidMoveCounter = 0,
				unsigned int refInvalidMoveCounter = 0,
				unsigned int refGameCounter = 0) : 
				 table(refTable.begin(), refTable.end()), validMoveCounter(refValidMoveCounter),
				 invalidMoveCounter(refInvalidMoveCounter), gameCounter(refGameCounter) {}

Sudoku9::Sudoku9(Utils::tableVector refTable) : 
				 table(refTable.begin(), refTable.end()), validMoveCounter(0), invalidMoveCounter(0), gameCounter(0) 
				 {
					if (!isValidTable(refTable))
						table = Utils::tableVector(9, std::vector<ushort>(9, 0));
				 }

Sudoku9::Sudoku9(const Sudoku9& refSudoku) : 
	table(refSudoku.table.begin(), refSudoku.table.end()),
	validMoveCounter(refSudoku.validMoveCounter),
	invalidMoveCounter(refSudoku.invalidMoveCounter),
	gameCounter(refSudoku.gameCounter) {}

Utils::tableVector Sudoku9::getTable() const { return Utils::tableVector(table.begin(), table.end()); }

unsigned int Sudoku9::getValidMoveCount() const { return validMoveCounter; }

unsigned int Sudoku9::getInvalidMoveCount() const { return invalidMoveCounter; }

unsigned int Sudoku9::getGameCount() const { return gameCounter; }

/*
	args:  ushort row - value of row we want to check
		   ushort col - value of column we want to check
		   ushort val - value we want to input
	rtype: bool - true if move is valid, false if not
	a move is valid if there are no duplicate values in the same row, column, or 3x3 square
*/
bool Sudoku9::isValidMove(const int col, const int row, const ushort val)
{
	// if the field already has a value, then the move is not valid
	if (table[col][row] != 0) {
		return false;
	}
	// check if val is in the row
	for (int i = 0; i < 9; ++i) {
		if (table[col][i] == val) {
		return false;
		}
	}
	// check if val is in the column
	for (int i = 0; i < 9; ++i) {
		if (table[i][row] == val) {
			 return false;
		}
	}
	// check the 3x3 squares
	int subgridRow = 3 * (row / 3);
	int subgridCol = 3 * (col / 3);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (table[subgridCol + i][subgridRow + j] == val){
				return false;
			} 
		}
	}

	return true;
}

/*
	args: none
	rtype: boolean which represents if sudoku is solved or not

	if the sudoku is solved, no rows or columns hold duplicate values inside of them,
	also none of the 3x3 subgrids hold duplicate values

	we represent every row and column using an array of booleans
	let's say we get value i from the table vector
	to check if the value i is present in the current row, we check if currentRow[i] is equal to true
	if it is, there are duplicates in the row and the sudoku is not valid
	if it is not, i is not present in the row for now and we set currentRow[i] to true

	same logic applies for columns

	same logic is applied to subgrids, we just change the loops
*/
bool Sudoku9::isSolved()
{
	// checking rows and columns
	for (int i = 0; i < 9; ++i) {
		bool currentRow[9] = {false};
		bool currentCol[9] = {false};
		for (int j = 0; j < 9; ++j) {
			if (currentRow[table[i][j] - 1]) {
				return false;
			}
			currentRow[table[i][j] - 1] = true;

			if (currentCol[table[i][j] - 1]) {
				return false;
			}
			currentCol[table[i][j] - 1] = true;
		}
	}

	// checking subgrids
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			bool currentSubgrid[9] = {false};

			for (int m = i; m < i + 3; ++m) {
				for (int n = j; n < j + 3; ++n) {
					if (currentSubgrid[table[m][n] - 1]) {
						return false;
					}
					currentSubgrid[table[m][n] - 1] = true;
				}
			}
		}
	}

	return true;
}

/*
	args: none
	rtype: pair (column, row) with coordinates of the first empty field
*/
std::pair<ushort, ushort> Sudoku9::findEmptyPosition()
{
	for (ushort row = 0; row < 9; ++row) {
		for (ushort col = 0; col < 9; ++col) {
			if (table[col][row] == EMPTY) {
				return std::make_pair(col, row);
			}
		}
	}

	return std::make_pair(9, 9);
}

/*
	args: none
	rtype: bool which represents if sudoku is solved or unsolvable

	this function tries every number for every position recursively until it finds a solution
*/
bool Sudoku9::solve()
{	
	// check if sudoku is solved
	//if (isSolved()) return true;

	// find the first empty position
	std::pair<ushort, ushort> emptyField = findEmptyPosition();

	ushort col = emptyField.first, row = emptyField.second;

	// if the sudoku is full but there are no empty fields return true;
	if (col == 9) return true;

	for (int i = 1; i <= 9; ++i) {
		// we try placing number i in every cell
		if (isValidMove(col, row, i)) {
			table[col][row] = i;

			// check if the current solution is valid
			if (solve()) return true;

			// if this move didn't solve the sudoku, backtrack
			table[col][row] = 0;
		}
	}

	// if the sudoku is unsolvable, just return
	return false;
}

/*
	this function checks the puzzle user inputed.
	if there are empty fields in the field, return false

	for every valid or non-valid move, increase the counter fields
*/
bool Sudoku9::validate()
{
	Sudoku9 temp;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			ushort val = table[i][j];
			if (val == 0) return false;
			else if (temp.isValidMove(i, j, val)) {
				++validMoveCounter;
			}
			else {
				++invalidMoveCounter;
			}
		}
	}
	++gameCounter;
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

Sudoku9& Sudoku9::operator=(const Sudoku9& other)
{
	if (this->table != other.table) {
		table = other.table;
	}
	return *this;
}
