#include "../Sudoku9.h"
//#include "../utils/Utils.hpp"
#include "../SudokuReader.h"
#include "../SudokuWriter.h"

#include <iostream>

bool isValidMoveTest()
{
	Sudoku9 test(SudokuReader::read("test.txt"));

    // test for valid move
    if (!test.isValidMove(0, 0, 5)) {
        std::cerr << "error while testing validity of a valid move" << '\n';
        return false;
    }
    // tests for non valid moves

    // 2 numbers in the same field
    if (test.isValidMove(1, 3, 4)) {
        std::cerr << "error while testing 2 numbers in the same field" << '\n';
        return false;
    }
    // 2 same numbers in the same row
    else if (test.isValidMove(1, 0, 4)) {
        std::cerr << "error while testing 2 numbers in the same row" << '\n';
        return false;
    }
    // 2 same numbers in the same column
    else if (test.isValidMove(0, 1, 3)) {
        std::cerr << "error while testing 2 numbers in the same column" << '\n';
        return false;
    }
    // 2 same numbers in a 3x3 subgrid
    else if (test.isValidMove(0, 4, 4)) {
        std::cerr << "error while testing 2 numbers in the same subgrid" << '\n';
        return false;
    }
    return true;
}

bool isSolvedTest()
{
    // checking for a valid sudoku
    Sudoku9 validTest;
    validTest.solve();

    if (!validTest.isSolved()) {
        std::cerr << "error while testing validity of a valid sudoku" << '\n';
        std::cout << validTest << '\n';
        return false;
    }

    // checking for an invalid sudoku
    Utils::tableVector invalidTable = validTest.getTable();
    invalidTable[0][0] = 2;
    Sudoku9 invalidTest(invalidTable);
    if (invalidTest.isSolved()) {
        std::cerr << "error while testing validity of an invalid sudoku\n";
        std::cout << invalidTest << '\n';
        return false;
    }

    return true;
}

int main() {
    std::cout << "testing the isValidMove method: " << isValidMoveTest() << '\n';
    std::cout << "testing the isSolved method: " << isSolvedTest() << '\n';

    Utils::tableVector tv = {
        {0,0,3,9,6,2,1,0,0},
        {0,0,0,4,0,0,8,7,2},
        {1,2,0,0,0,0,0,0,9},
        {9,5,0,0,0,4,0,3,0},
        {2,0,6,0,0,0,4,0,8},
        {0,4,0,3,0,0,0,9,1},
        {3,0,0,0,0,0,0,8,6},
        {5,1,8,0,0,7,0,0,0},
        {0,0,9,8,2,5,7,0,0}
    };

    Sudoku9 test(tv);
    test.solve();

    std::cout << test << '\n';
    std::cout << test.isSolved();

    return 0;
}