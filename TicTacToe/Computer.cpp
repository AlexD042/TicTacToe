#include "Computer.h"

void Computer::computerMove(int& row, int& column) {

}

int Computer::minimax(char board[3][3], int depth, bool isMaximizingPlayer, Player player) {
	int score = evaluate(board, player);
    
    // Maximizing or minimizing player won
    if (score == 10 || score == -10) {
        return score;
    }

    // Tie
    if (isMovesLeft(board) == false) {
        return 0;
    }

    //

}

int Computer::evaluate(char board[3][3], Player player) {
    char computerSymbol = getComputerSymbol();
    char playerSymbol = player.getPlayerSymbol();

    // Horizontal Check
    for (int row = 0; row < 3; row++) {
        if ((board[row][0] == computerSymbol) && (board[row][1] == computerSymbol) && (board[row][2] == computerSymbol)) {
            return 10;
        }
        else if ((board[row][0] == playerSymbol) && (board[row][1] == playerSymbol) && (board[row][2] == playerSymbol)) {
            return -10;
        }
    }

    // Vertical Check
    for (int column = 0; column < 3; column++) {
        if ((board[0][column] == computerSymbol) && (board[1][column] == computerSymbol) && (board[2][column] == computerSymbol)) {
            return 10;
        }
        else if ((board[0][column] == playerSymbol) && (board[1][column] == playerSymbol) && (board[2][column] == playerSymbol)) {
            return -10;
        }
    }

    // Diagonal Check (Bottom Left to Top Right)
    if ((board[2][0] == computerSymbol) && (board[1][1] == computerSymbol) && (board[0][2] == computerSymbol)) {
        return 10;
    }
    else if ((board[2][0] == playerSymbol) && (board[1][1] == playerSymbol) && (board[0][2] == playerSymbol)) {
        return -10;
    }

    // Diagonal Check (Top Left to Bottom Right)
    if ((board[0][0] == computerSymbol) && (board[1][1] == computerSymbol) && (board[2][2] == computerSymbol)) {
        return 10;
    }
    else if ((board[0][0] == playerSymbol) && (board[1][1] == playerSymbol) && (board[2][2] == playerSymbol)) {
        return -10;
    }

    // Neither computer or player won
    return 0;
}

bool Computer::isMovesLeft(char board[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == '-') {
				return true;
			}
		}
	}
	return false;
}

char Computer::getComputerSymbol() {
	return computerSymbol;
}

void Computer::setComputerSymbol(char symbol) {
	computerSymbol = symbol;
}