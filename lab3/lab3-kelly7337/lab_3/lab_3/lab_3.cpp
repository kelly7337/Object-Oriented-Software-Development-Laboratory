#include "header.h"
#include "game_board.h"


//error and indications on how to fix it
int usage(string progName, string progInfo) {
	cout << "Usage Error:" << progName << progInfo;
	return failure_incorrect_amount_of_arguments;
}



int main(int argc, char* argv[])
{
	//checking that correct amount of arguments was passed in
	if (argc == correct_amount_of_arguments) {

		if (string(argv[failure_incorrect_amount_of_arguments]) != "TicTacToe") {
			return usage(argv[0], " <game_name>");
		}
		else {
			TicTacToeGame current;

			return current.play();
		}
	}

	//if passed in arguments are not program name
	else {
		return usage(argv[0], " <game_name>");
	}
}


//Tic Tac Toe Game Constructor
TicTacToeGame::TicTacToeGame() : width(5), height(5), player("X") {
	//populating the vector of pieces
	for (int h = height - 1; h >= 0; h--) {
		for (int w = 0; w < width; w++) {
			pieceVect.push_back(" ");
		}
	}
}


//the insertion operator
ostream& operator << (ostream& stream, const TicTacToeGame& ttt) {

	for (int h = ttt.height - 1; h >= 0; h--) {
		cout << h; 
		for (int w = 0; w < ttt.width; w++) {
			cout << ttt.pieceVect[ttt.width * h + w];
		}
		cout << endl;
	}
	cout << " " << 0 << 1 << 2 << 3 << 4 << endl;
	return stream;
}
