#ifndef TICTACTOEBOARD
#define TICTACTOEBOARD

#include <iostream>
#include <cctype>

class TicTacToeBoard {
private:
	char board[3][3] = {
		{'-', '-', '-'},
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
	int playerChosenRow = 0;
	int playerChosenColumn = 0;
	int computerChosenRow = 0;
	int computerChosenColumn = 0;
public:
	void run();
	void drawBoard();
	bool checkForWin(char board[3][3], char symbol);
	char getBoardChar(char board[3][3], int row, int column);
	void setBoardChar(char board[3][3], int row, int column, char newChar);
};

#endif
