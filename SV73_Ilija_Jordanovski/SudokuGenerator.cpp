#include "SudokuGenerator.h"

#include "Sudoku9.h"

Sudoku9 SudokuGenerator::fillDiagonalSubgrids()
{
    Utils::tableVector vec = Utils::emptyVector();

    // the subgrids on the main diagonal are subgrid 0, 4, 8
    for (int i = 0; i < 9; i += 3) {
        // set of values we place into the subgrid
        std::vector<ushort> values = {1,2,3,4,5,6,7,8,9};

        // random number generator
        std::random_device rd;
        std::mt19937 gen(rd());

        // shuffle the vector randomly
        std::shuffle(values.begin(), values.end(), gen);

        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                // m * 3 + n goes through every of the 9 members of the vector
                vec[i + m][i + n] = values[m * 3 + n];
            }
        }
    }

    return Sudoku9(vec);
}

Sudoku9 SudokuGenerator::removeCells(Sudoku9 refSudoku, int cellsToRemove)
{
    Utils::tableVector table = refSudoku.getTable();

    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 8); // 8 as in 9 - 1

    while (cellsToRemove != 0) {
        int row = dist(gen);
        int col = dist(gen);

        // if the cell is empty just continue with the loop
        if (table[row][col] == 0) continue;

        // set the cell to the empty value
        table[row][col] = 0;

        --cellsToRemove;
    }

    return Sudoku9(table);
}

/*
    this function generates sudoku puzzles

    first step is to generate a (unique) solvable sudoku by filling diagonal subgrids
    we fill diagonal subgrids because they don't interfere with eachother

    second step is to solve that unique puzzle
    we have methods inside of Sudoku9 class for that

    third step is to remove a certain amount of cells

    that way we have a solvable sudoku 
*/
Sudoku9 SudokuGenerator::generate()
{
    // step 1
    Sudoku9 table(fillDiagonalSubgrids());

    // step 2
    table.solve();

    // step 3
    return removeCells(table, 30);
}