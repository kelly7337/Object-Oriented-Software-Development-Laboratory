#pragma once
#include "GameBase_Header.h"


class GomokuGame : public GameBase {

	//declaring insertion operator as a friend of the class
	friend ostream& operator << (ostream&, const GomokuGame&);

	//players for this game
	string player1 = "B";
	string player2 = "W";
	//number of adjacent pieces that are the same

public:
	int inArow;
	//constructor
	GomokuGame();
	GomokuGame(unsigned int dim);
	GomokuGame(unsigned int dim, unsigned int winVal);

	string inputCriteria; //for the input dimensions and number of same adjacents needed for a win

	//functions and methods
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print();
	int prompt(unsigned int& inputX, unsigned int& inputY);
	//int promptCriteria(unsigned int& inputDim, unsigned int& inputDimY, unsigned int& inputWin);

};