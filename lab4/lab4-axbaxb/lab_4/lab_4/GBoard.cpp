#include "Header.h"
#include "G_Header.h"

//Gomoku Game Constructor
GomokuGame::GomokuGame() {
	//populating the vector of pieces
	inArow = 5;
	boardHeight = 19; boardWidth = 19;
	for (int h = boardHeight; h > 0; h--) {
		for (int w = 0; w < boardWidth; w++) {
			pieceVect.push_back(" ");
		}
	}
	//sets the longest string length to the length of the longest player by comparing player 1 and 2
	//GomokuGame::longest = (player1.length() < player2.length() ? player1.length() : player2.length());
}

GomokuGame::GomokuGame(unsigned int dim)
{
	if (dim >= 3) {
		if (dim == 3) {
			inArow = 3;
		}
		else if (dim == 4) {
			inArow = 4;
		}
		else {
			inArow = 5;
		}
		boardHeight = dim;
		boardWidth = dim;
		for (int h = boardHeight; h > 0; h--) {
			for (int w = 0; w < boardWidth; w++) {
				pieceVect.push_back(" ");
			}
		}
	}
	else {
		dim = 19;
	}
}


GomokuGame::GomokuGame(unsigned int dim, unsigned int winVal)
{
	if (dim >= 3) {
		inArow = winVal;
		boardHeight = dim;
		boardWidth = dim;
		for (int h = boardHeight; h > 0; h--) {
			for (int w = 0; w < boardWidth; w++) {
				pieceVect.push_back(" ");
			}
		}
	}
	else {
		dim = 19;
		winVal = 5;
	}
}


//definition of the insertion operator for Gomoku
ostream& operator << (ostream& stream, const GomokuGame& g) {
	//print out the board from top left to bottom right
	for (int h = g.boardHeight - 1; h >= 0; h--) {
		stream << left << setw(2) << h + 1; //printing y column labels here
		for (int w = 0; w < g.boardWidth; w++) {
			if (w <= 9) {
				stream << g.pieceVect[g.boardWidth * h + w] << " ";
			}
			else {
				stream << right << setw(2) << g.pieceVect[g.boardWidth * h + w] << " ";
			}
		}
		stream << endl;
	}
	cout << "X ";
	for (int colLabel = 1; colLabel <= g.boardWidth; colLabel++) {
		if (colLabel <= 9) {
			stream << colLabel << " ";
		}
		else {
			stream << setw(2) << colLabel << " ";
		}
	}
	cout << endl;
	return stream;
}


//function that checks if the game is over or not so if 5 in horizontal vertical, or diagonal line
bool GomokuGame::done() {

	//if in a vertical line
	for (int x = 0; x < boardWidth; x++) {
		int adjSame = 0; //counter for adjacent pieces that are the same
		for (int y = boardHeight - 1; y >= 1; y--) {
			string s = pieceVect[boardWidth * y + x];
			if (!all_of(s.begin(), s.end(), isspace) &&
				pieceVect[boardWidth * y + x] == pieceVect[boardWidth * (y - 1) + x]) {
				adjSame += 1;
				cout << "adjSame Vertical is: " << adjSame << endl;
				if (adjSame == (inArow - 1)) {
					return true;
				}
			}
			else {
				adjSame = 0;
			}
		}
	}

	//if in a horizontal line
	for (int y = boardHeight - 1; y >= 0; y--) {
		int adjSame = 0; //counter for adjacent pieces that are the same
		for (int x = 0; x < boardWidth - 1; x++) {
			string s = pieceVect[boardWidth * y + x];
			if (!all_of(s.begin(), s.end(), isspace) &&
				pieceVect[boardWidth * y + x] == pieceVect[boardWidth * y + x + 1]) {
				adjSame += 1;
				cout << "adjSame Horizontal is: " << adjSame << endl;
				if (adjSame == (inArow - 1)) {
					return true;
				}
			}
			else {
				adjSame = 0;
			}
		}
	}



	//Check for top half of right to left diagonals
	for (int yStart = 0; yStart < boardHeight - (inArow - 1); yStart++) {
		string currentPiece = pieceVect[boardWidth * yStart + 0];
		int counter = 1;
		for (int x = 1, y = yStart + 1; x < boardWidth && y < boardHeight; x++, y++) {
			if (currentPiece == pieceVect[boardWidth * y + x]) {
				counter++;
			}
			else {
				counter = 1;
				currentPiece = pieceVect[boardWidth * y + x];
			}

			if (counter == inArow && currentPiece != " ") {
				return true;
			}
		}
	}

	//Check for bottom half of right to left diagonals
	for (int xStart = 0; xStart < boardWidth - (inArow - 1); xStart++) {
		string currentPiece = pieceVect[boardWidth * 0 + xStart];
		int counter = 1;
		for (int x = xStart + 1, y = 1; x < boardWidth && y < boardHeight; x++, y++) {
			if (currentPiece == pieceVect[boardWidth * y + x]) {
				counter++;
			}
			else {
				counter = 1;
				currentPiece = pieceVect[boardWidth * y + x];
			}


			if (counter == inArow && currentPiece != " ") {
				return true;
			}
		}
	}

	//Check for top half of left to right diagonals
	for (int yStart = 0; yStart < boardHeight - (inArow - 1); yStart++) {
		string currentPiece = pieceVect[boardWidth * yStart + 18];
		int counter = 1;
		for (int x = 17, y = yStart + 1; x < boardWidth && y < boardHeight; x--, y++) {
			if (currentPiece == pieceVect[boardWidth * y + x]) {
				counter++;
			}
			else {
				counter = 1;
				currentPiece = pieceVect[boardWidth * y + x];
			}

			if (counter == inArow && currentPiece != " ") {
				return true;
			}
		}
	}
	//Check for bottom half of left to right diagonals
	for (int xStart = (inArow - 1); xStart < boardWidth; xStart++) {
		string currentPiece = pieceVect[boardWidth * 0 + xStart];
		int counter = 1;
		for (int x = xStart - 1, y = 1; x < boardWidth && y < boardHeight; x--, y++) {
			if (currentPiece == pieceVect[boardWidth * y + x]) {
				counter++;
			}
			else {
				counter = 1;
				currentPiece = pieceVect[boardWidth * y + x];
			}


			if (counter == inArow && currentPiece != " ") {
				return true;
			}
		}
	}
	return false;
}


//returns true if there is a tie, returns false otherwise
bool GomokuGame::draw() { //361 moves means all 19x19 cells are filled
	if (moves == 361 && done() == false) {
		return true;
	}
	else {
		return false;
	}
}

int GomokuGame::prompt(unsigned int& inputX, unsigned int& inputY) {
	//EXTRA CREDIT BEGINNING

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
	if (tempX > 0 && tempX <= boardWidth) {
		if (tempY > 0 && tempY <= boardHeight) {
			//if the input coordinates are not taken already
			if (pieceVect[boardWidth * (tempY - 1) + (tempX - 1)] == " ") {
				inputX = tempX - 1;
				inputY = tempY - 1;
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

int GomokuGame::turn()
{
	if (moves % 2 == 1) {
		player = player2;
	}
	else { //same as saying (moves % 2 == 0)
		player = player1;
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
	pieceVect[boardHeight * y + x] = player;
	string move = to_string(x) + "," + to_string(y);

	//print out the updated game board with operator
	cout << "" << endl;
	print();

	return success;
}

void GomokuGame::print()
{
	cout << *this;
}