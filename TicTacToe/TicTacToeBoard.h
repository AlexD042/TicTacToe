#ifndef TICTACTOEBOARD
#define TICTACTOEBOARD
#include <iostream>

class TicTacToeBoard {
private:
	char board[3][3] = {
		{'-', '-', '-'},
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
public:
	void run();
	void drawBoard();
	bool checkForWin(char board[3][3], char symbol);
	char getBoardChar(char board[3][3], int row, int column);
	void setBoardChar(char board[3][3], int row, int column, char newChar);
};

#endif
