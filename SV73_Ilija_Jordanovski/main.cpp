#include "Sudoku9.h"
#include "SudokuWriter.h"
#include "SudokuReader.h"
#include "SudokuGenerator.h"

#include <iostream>
#include <cstdlib>

void clearConsole()
{
	#ifdef _WIN32
    // for windows
    std::system("cls");
	#elif __linux__
    // for linux
    std::system("clear");
	#endif
}

int main()
{
	clearConsole();

	std::string settingFilename, solutionFilename;
	
	std::cout << "enter the setting filename: ";
	std::cin >> settingFilename;

	std::cout << "\nenter the solution filename: ";
	std::cin >> solutionFilename;

	Sudoku9 sudoku;
	bool menuLoop = true;

	unsigned short choice;

	while (menuLoop) {
		clearConsole();
		std::cout << "1) generate a new setting\n";
		std::cout << "2) load setting from file\n";
		std::cout << "3) exit\n";
		std::cout << ">> ";
		std::cin >> choice;

		switch (choice) {
			case 1:
				sudoku = SudokuGenerator::generate();
				break;
			case 2:
				sudoku = Sudoku9(SudokuReader::read(settingFilename));
				break;
			case 3:
				return 0;
			default:
				continue;
		}
		break;
	}

	Sudoku9 solution;
	while (menuLoop) {
		clearConsole();
		std::cout << "1) solve the puzzle yourself\n";
		std::cout << "2) get the puzzle answer\n";
		std::cout << "3) exit\n";
		std::cout << ">> ";
		std::cin >> choice;

		switch (choice) {
			case 1:
				solution = Sudoku9(SudokuReader::read(solutionFilename));
				break;
			case 2:
				solution = sudoku;
				if (solution.solve()) {
					clearConsole();
					SudokuWriter::write(solution, solutionFilename);
					std::cout << "answer in file " << solutionFilename;
					return 0; 
				}
				clearConsole();
				std::cout << "puzzle is not solvable";
				return 0;
				break;
			case 3:
				return 0;
			default:
				continue;
		}

		clearConsole();

		std::cout << "valid moves: " << solution.getValidMoveCount();
		std::cout << "\ninvalid moves: " << solution.getInvalidMoveCount();
		std::cout << "\nnumber of tries for this puzzle: " << solution.getGameCount();
		std::cout << "\n\n1)try again";
		std::cout << "\npress anything else to quit";
		std::cout << "\n>> ";
		std::cin >> choice;

		switch (choice) {
			case 1:
				continue;
				break;
			default:
				return 0;
		}
	}


	return 0;
}