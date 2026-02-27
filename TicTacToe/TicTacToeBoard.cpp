#include "TicTacToeBoard.h"

void TicTacToeBoard::run() {
	drawBoard();
	setBoardChar(board, 1, 1, 'X');
	drawBoard();
}

void TicTacToeBoard::drawBoard() {
	std::cout << "\n   |   |   \n"
			  << " " << getBoardChar(board, 0, 0) << " | " << getBoardChar(board, 0, 1) << " | " << getBoardChar(board, 0, 2)
			  << "\n___|___|___\n"
			  << "   |   |   \n"
			  << " " << getBoardChar(board, 1, 0) << " | " << getBoardChar(board, 1, 1) << " | " << getBoardChar(board, 1, 2)
			  << "\n___|___|___\n"
		      << "   |   |   \n"
			  << " " << getBoardChar(board, 1, 0) << " | " << getBoardChar(board, 2, 1) << " | " << getBoardChar(board, 2, 2)
			  << "\n   |   |   ";
}

char TicTacToeBoard::getBoardChar(char board[3][3], int row, int column) {
	return board[row][column];
}

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