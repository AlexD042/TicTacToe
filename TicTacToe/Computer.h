#ifndef COMPUTER
#define COMPUTER

#include "Player.h" // for evaluation function

class Computer {
private:
	char computerSymbol = ' ';
public:
	void computerMove(char board[3][3], int& row, int& column, Player player);
	int minimax(char board[3][3], int depth, bool isMaximizingPlayer, Player player);
	int evaluate(char board[3][3], Player player);
	bool isMovesLeft(char board[3][3]);
	char getComputerSymbol();
	void setComputerSymbol(char symbol);
};

#endif
