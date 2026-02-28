#ifndef PLAYER
#define PLAYER
#include <iostream>

class Player {
private:
	char playerSymbol = ' ';
public:
	void playerMove(int &row, int &column);
	char getPlayerSymbol();
	void setPlayerSymbol(char symbol);
};

#endif
