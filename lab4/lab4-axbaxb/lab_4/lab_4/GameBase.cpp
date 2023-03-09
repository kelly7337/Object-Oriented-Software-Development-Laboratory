#include "GameBase_Header.h"
#include "Header.h"
#include "T_Header.h"
#include "G_Header.h"


//fxn that prompts the user for input and turns it into appropriate x and y coordinates
int GameBase::prompt(unsigned int& inputX, unsigned int& inputY)
{
	cout << "Player " << player << " Turn" << endl;
	cout << "Enter Row, Column Numbers: "; cin >> storeInput;

	//if user quits game
	if (storeInput == "quit") {
		return user_quit_game;
	}

	//for each character from the stored input, replace commas with space
	for (char& c : storeInput) {
		if (c == ',') {
			c = ' ';
		}
	}

	//if more than 2 numbers are inputed
	int count = 0;
	for (char& d : storeInput) {
		if (d == ' ') {
			count++;
		}
	}
	if (count > 1) {
		cout << "Enter a set of valid (x,y) coordinates such as '1,1' or 'quit' to exit the game." << endl;
		return incorrect_input_value;
	}


	//then wrap the string in a istringstream
	istringstream iss(storeInput);
	int tempX = 0;
	int tempY = 0;

	//if the extraction failed go into this if loop
	if (!(iss >> tempX >> tempY)) {
		cout << "Enter a set of valid (x,y) coordinates such as '1,1' or 'quit' to exit the game." << endl;
		return incorrect_input_value;
	}

	//ONLY IF the extraction succeeded
	if (tempX > 0 && tempX < boardWidth - 1) {
		if (tempY > 0 && tempY < boardHeight - 1) {
			//if the input coordinates are not taken already
			if (pieceVect[boardWidth * tempY + tempX] == " ") {
				inputX = tempX;
				inputY = tempY;
			}
			else {
				cout << "Enter a set of valid (x,y) coordinates that have not been filled already." << endl;
				return incorrect_input_value;
			}
		}
		else {
			cout << "Enter a set of valid (x,y) coordinates such as '1,1' or 'quit' to exit the game." << endl;
			return incorrect_input_value;
		}
	}
	else {
		cout << "Enter a set of valid (x,y) coordinates such as '1,1' or 'quit' to exit the game." << endl;
		return incorrect_input_value;
	}
	return success;
}

int GameBase::play() {

	//printing out the empty game board
	print();

	while (true) {

		//calling turn method
		int r = turn();

		if (r == user_quit_game) {
			if (moves == 1) {
				cout << moves << " turn was played before the user quit.";
			}
			else {
				cout << moves << " turns were played before the user quit.";
			}
			return user_quit_game;
		}

		//if done method returns true
		if (done() == true) {
			cout << "Player " << player << " won.";
			return success;
		}

		//if draw method returns true
		if (draw() == true) {
			cout << moves << " turns were played and no winning moves remain. The game is a draw.";
			return game_is_a_draw;
		}

	}
}

GameBase* GameBase::whichGame(int argc, char* argv[])
{
	if (string(argv[gameName]) == "TicTacToe") {
		GameBase* now = new TicTacToeGame();
		return now;
	}
	else if (string(argv[gameName]) == "Gomoku") {
		GameBase* now;
		if (correct_amount_of_arguments_with_dim == argc) {
			now = new GomokuGame(stoi(argv[2]));
		}
		else if (correct_amount_of_arguments_with_dim_with_winVal == argc) {
			now = new GomokuGame(stoi(argv[2]), stoi(argv[3]));
		}
		else {
			now = new GomokuGame();
		}
		return now;
	}
	else {
		GameBase* now = 0;
		return now;
		//error message should be called here
	}
}