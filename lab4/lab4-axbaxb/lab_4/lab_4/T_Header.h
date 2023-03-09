#pragma once
#include "GameBase_Header.h"


class TicTacToeGame : public GameBase {

	//declaring insertion operator as a friend of the class
	friend ostream& operator << (ostream&, const TicTacToeGame&);

	//players for this game
	string player1 = "X";
	string player2 = "O";

public:
	//constructor
	TicTacToeGame();

	//functions and methods
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();

};
