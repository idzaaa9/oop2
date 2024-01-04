#pragma once

#include <algorithm>
#include <random>

#include "Sudoku9.h"
#include "utils/Utils.hpp"

class SudokuGenerator
{
private:
    static Sudoku9 fillDiagonalSubgrids();
    static Sudoku9 removeCells(Sudoku9 refSudoku, int cellsToRemove);
public:
    static Sudoku9 generate();
};