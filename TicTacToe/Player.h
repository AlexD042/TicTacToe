#ifndef PLAYER
#define PLAYER
#include <iostream>

class Player {
private:
	char playerSymbol = ' ';
public:
	void playerMove(char board[3][3], int &row, int &column);
	char getPlayerSymbol();
	void setPlayerSymbol(char symbol);
};

#endif
