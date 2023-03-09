

#include "game_board.h"

//checks if the game is over or not so if 3 in horizontal vertical, or diagonal line
bool TicTacToeGame::done() {


	//if in a vertical line
	for (int x = 1; x < width - 1; x++) {
		bool allSame = pieceVect[width * (height - 2) + x] != " ";
		for (int y = height - 2; y > 1; y--) {
			if (pieceVect[width * y + x] != pieceVect[width * (y - 1) + x]) {
				allSame = false;
			}
		}
		if (allSame) {
			cout << "yo" << endl;
			return allSame;
		}
	}

	//if in a horizontal line
	for (int y = height - 2; y > 0; y--) {
		bool allSame = pieceVect[width * y + 1] != " ";
		for (int x = 1; x < width - 2; x++) {
			if (pieceVect[width * y + x] != pieceVect[width * y + x + 1]) {
				allSame = false;
			}
		}
		if (allSame) {
			cout << "yo2" << endl;
			return allSame;
		}
	}

	//if in a diagonal line
	bool allSame = pieceVect[width * 1 + 1] != " ";
	for (int x = 1, y = 1; x < width - 2 && y < height - 2; x++, y++) {
		if (pieceVect[width * y + x] != pieceVect[width * (y + 1) + (x + 1)]) {
			allSame = false;
		}
	}
	if (allSame) {
		return allSame;
	}
	allSame = pieceVect[width * (height - 2) + 1] != " ";
	for (int x = 1, y = height - 2; x < width - 2 && y > 1; x++, y--) {
		if (pieceVect[width * y + x] != pieceVect[width * (y - 1) + (x + 1)]) {
			allSame = false;
		}
	}
	if (allSame) {
		return allSame;
	}

	return false;
}

//returns true if there is a tie, returns false otherwise
bool TicTacToeGame::draw() {
	if (moves == 9 && done() == false) {
		return true;
	}
	else {
		return false;
	}
}


//prompts the user for input and turns it into appropriate x and y coordinates
int TicTacToeGame::prompt(unsigned int& inputX, unsigned int& inputY) {

	cout << "Player " << player << " Turn" << endl;
	cout << "Enter Row, Column Numbers: "; cin >> storeInput;

	//if user quits game
	if (storeInput == "quit") {
		return user_quit_game;
	}

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

	//the extraction succeeded
	if (tempX > 0 && tempX < width - 1) {
		if (tempY > 0 && tempY < height - 1) {
			//if the input coordinates are not taken already
			if (pieceVect[width * tempY + tempX] == " ") {
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

//keeps track of which player's turn it is
int TicTacToeGame::turn() {

	if (moves % 2 == 1) {
		player = "X";
	}
	else {
		player = "O";
	}

	int res;
	unsigned int x, y;
	while (true) {
		res = prompt(x, y);
		if (res == success) {
			break;
		}
		if (res == user_quit_game) {
			return user_quit_game;
		}
	}

	//if it gets here then a valid move has been made so moves is incremented
	moves += 1;

	//the method should move the piece to the square
	pieceVect[height * static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(y) + x] = player;
	string move = to_string(x) + "," + to_string(y);
	if (player == "X") {
		movesPX.push_back(move);
	}
	else {
		movesPO.push_back(move);
	}

	//print out the updated game board with operator
	cout << "" << endl;
	cout << *this << endl;

	//print out a single line showing the valid moves that have been made
	if (player == "X") {
		cout << "Player X's Moves: ";
		for (size_t p = 0; p < movesPX.size(); p++) {
			string xmoveToPrint = movesPX[p];
			if (movesPX.size() == 1 || p == movesPX.size() - 1) {
				cout << xmoveToPrint;
			}
			if (movesPX.size() > 1 && p < movesPX.size() - 1) {
				cout << xmoveToPrint << " ; ";
			}
		}
		cout << endl << endl;
	}

	if (player == "O") {
		cout << "Player O's Moves: ";
		for (size_t p = 0; p < movesPO.size(); p++) {
			string ymoveToPrint = movesPO[p];
			if (movesPO.size() == 1 || p == movesPO.size() - 1) {
				cout << ymoveToPrint;
			}
			if (movesPO.size() > 1 && p < movesPO.size() - 1) {
				cout << ymoveToPrint << " ; ";
			}
		}
		cout << endl << endl;
	}
	return success;
}

int TicTacToeGame::play() {

	//cout the empty game board
	cout << *this << endl;


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
