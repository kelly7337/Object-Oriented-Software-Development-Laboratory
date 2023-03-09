#include "T_Header.h"
#include "G_Header.h"
#include "Header.h"

using namespace std;

//usage function returns message in case of error and indications on how to fix it
int usage(string progName, string progInfo) {
	cout << "Usage Error:" << progName << progInfo << endl;
	return failure_incorrect_amount_of_arguments;
}

int main(int argc, char* argv[])
{
	//checking that correct amount of arguments was passed in
	if (argc == correct_amount_of_arguments || argc == correct_amount_of_arguments_with_dim || argc == correct_amount_of_arguments_with_dim_with_winVal) {

		GameBase* game;
		GameBase* singular = 0;

		try {
			game = GameBase::whichGame(argc, argv);
		}
		catch (bad_alloc) {
			cerr << "bad_alloc caught";
			return bad_alloc_ret;
		}

		if (game) {
			return (*game).play();
		}
		else {
			cerr << "Unknown Game Name: Please enter <TicTacToe> or <Gomoku>";
			return unknownGame;
		}

	}
	else {
		return usage(argv[0], " <game_name>");
	}
}
