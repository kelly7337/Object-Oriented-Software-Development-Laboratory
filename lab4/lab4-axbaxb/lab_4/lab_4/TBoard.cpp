#include "Header.h"
#include "T_Header.h"

//Tic Tac Toe Game Constructor
TicTacToeGame::TicTacToeGame() {
	//populating the vector of pieces
	boardHeight = 5; boardWidth = 5;
	for (int h = boardHeight - 1; h >= 0; h--) {
		for (int w = 0; w < boardWidth; w++) {
			pieceVect.push_back(" ");
		}
	}
}

//definition of the insertion operator for Tic Tac Toe
ostream& operator << (ostream& stream, const TicTacToeGame& t) {
	//print out the board from top left to bottom right
	for (int h = t.boardHeight - 1; h >= 0; h--) {
		stream << h; //printing y column labels here
		for (int w = 0; w < t.boardWidth; w++) {
			stream << t.pieceVect[t.boardWidth * h + w];
		}
		stream << endl;
	}
	stream << " " << 0 << 1 << 2 << 3 << 4 << endl;
	return stream;
}


//function that checks if the game is over or not so if 3 in horizontal vertical, or diagonal line
bool TicTacToeGame::done() {


	//if in a vertical line
	for (int x = 1; x < boardWidth - 1; x++) {
		bool allSame = pieceVect[boardWidth * (boardHeight - 2) + x] != " ";
		for (int y = boardHeight - 2; y > 1; y--) {
			if (pieceVect[boardWidth * y + x] != pieceVect[boardWidth * (y - 1) + x]) {
				allSame = false;
			}
		}
		if (allSame) {
			return allSame;
		}
	}

	//if in a horizontal line
	for (int y = boardHeight - 2; y > 0; y--) {
		bool allSame = pieceVect[boardWidth * y + 1] != " ";
		for (int x = 1; x < boardWidth - 2; x++) {
			if (pieceVect[boardWidth * y + x] != pieceVect[boardWidth * y + x + 1]) {
				allSame = false;
			}
		}
		if (allSame) {
			return allSame;
		}
	}

	//if in a diagonal line
	bool allSame = pieceVect[boardWidth * 1 + 1] != " ";
	for (int x = 1, y = 1; x < boardWidth - 2 && y < boardHeight - 2; x++, y++) {
		if (pieceVect[boardWidth * y + x] != pieceVect[boardWidth * (y + 1) + (x + 1)]) {
			allSame = false;
		}
	}
	if (allSame) {
		return allSame;
	}
	allSame = pieceVect[boardWidth * (boardHeight - 2) + 1] != " ";
	for (int x = 1, y = boardHeight - 2; x < boardWidth - 2 && y > 1; x++, y--) {
		if (pieceVect[boardWidth * y + x] != pieceVect[boardWidth * (y - 1) + (x + 1)]) {
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


//keeps track of which player's turn it is
int TicTacToeGame::turn() {

	if (moves % 2 == 1) {
		player = player1; //X
	}
	else { //same as saying (moves % 2 == 0)
		player = player2; //O
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

void TicTacToeGame::print()
{
	cout << *this;
}