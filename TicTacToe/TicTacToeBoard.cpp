#include "TicTacToeBoard.h"
#include "Player.h"
#include "Computer.h"

void TicTacToeBoard::run() {
	Player player1;
	Computer computer1;
	bool isRunning = true;

	std::cout << "Welcome to tic tac toe in c++\n";

	char chosenSymbol;
	while (true) {
		std::cout << "Please choose a symbol ('X' or 'O'): ";
		std::cin >> chosenSymbol;
		
		// check for input fail
		if (!std::cin) {
			std::cout << "Invalid input.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// check for if user enetered more than one character
		if (std::cin.get() != '\n') {
			std::cout << "Invalid input. Please enter only one character.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// check if user entered a correct character
		std::toupper(chosenSymbol);
		if (chosenSymbol == 'X' || chosenSymbol == 'O') {
			std::cout << "You chose: " << chosenSymbol << '\n';
			break;
		}
		else {
			std::cout << "Please enter only 'X' or 'O'.\n";
		}
	}
	player1.setPlayerSymbol(chosenSymbol);
	if (chosenSymbol == 'X') {
		computer1.setComputerSymbol('O');
	}
	else {
		computer1.setComputerSymbol('X');
	}
	

	drawBoard();

	while(isRunning) {
		player1.playerMove(playerChosenRow, playerChosenColumn);
		setBoardChar(board, playerChosenRow - 1, playerChosenColumn - 1, player1.getPlayerSymbol()); // -1 since the array is 0-indexed
		drawBoard();
		if (checkForWin(board, player1.getPlayerSymbol())) {
			std::cout << "you win";
			isRunning = false;
		}
	}
}

void TicTacToeBoard::drawBoard() {
	std::cout << "\n   |   |   \n"
			  << " " << getBoardChar(board, 0, 0) << " | " << getBoardChar(board, 0, 1) << " | " << getBoardChar(board, 0, 2)
			  << "\n___|___|___\n"
			  << "   |   |   \n"
			  << " " << getBoardChar(board, 1, 0) << " | " << getBoardChar(board, 1, 1) << " | " << getBoardChar(board, 1, 2)
			  << "\n___|___|___\n"
		      << "   |   |   \n"
			  << " " << getBoardChar(board, 2, 0) << " | " << getBoardChar(board, 2, 1) << " | " << getBoardChar(board, 2, 2)
			  << "\n   |   |   \n";
}


// getter method
char TicTacToeBoard::getBoardChar(char board[3][3], int row, int column) {
	return board[row][column];
}

// setter method
void TicTacToeBoard::setBoardChar(char board[3][3], int row, int column, char newChar) {
	board[row][column] = newChar;
}

bool TicTacToeBoard::checkForWin(char board[3][3], char symbol) {
	// Horizontal Check
	for (int row = 0; row < 3; row++) {
		int column = 0;
		if ((board[row][column] == symbol) && (board[row][column + 1] == symbol) && (board[row][column + 2] == symbol)) {
			return true;
		}
	}

	// Vertical Check
	for (int column = 0; column < 3; column++) {
		int row = 0;
		if ((board[row][column] == symbol) && (board[row + 1][column] == symbol) && (board[row + 2][column] == symbol)) {
			return true;
		}
	}

	// Diagonal Check (Bottom Left to Top Right)
	if ((board[2][0] == symbol) && (board[1][1] == symbol) && (board[0][2] == symbol)) {
		return true;
	}

	// Diagonal Check (Top Left to Bottom Right)
	if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol)) {
		return true;
	}

	return false;
}