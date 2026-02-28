#include "Player.h"

void Player::playerMove(int &row, int &column) {	
	while (true) {
		std::cout << "Enter a row (1, 2, or 3): ";
		std::cin >> row;

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

		// check if user entered a correct integer
		if (row != 1 && row != 2 && row != 3) {
			std::cout << "Invalid input. Please enter an integer 1, 2, or 3.\n";
			continue;
		}

		// all checks passed
		break;
	}



	while (true) {
		std::cout << "Enter a column (1, 2, or 3): ";
		std::cin >> column;

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

		// check if user entered a correct integer
		if (column != 1 && column != 2 && column != 3) {
			std::cout << "Invalid input. Please enter an integer 1, 2, or 3.\n";
			continue;
		}

		// all checks passed
		break;
	}
}

char Player::getPlayerSymbol() {
	return playerSymbol;
}

void Player::setPlayerSymbol(char symbol) {
	playerSymbol = symbol;
}