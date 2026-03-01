#ifndef COMPUTER
#define COMPUTER

class Computer {
private:
	char computerSymbol = ' ';
public:
	void computerMove();
	char getComputerSymbol();
	void setComputerSymbol(char symbol);
};

#endif
