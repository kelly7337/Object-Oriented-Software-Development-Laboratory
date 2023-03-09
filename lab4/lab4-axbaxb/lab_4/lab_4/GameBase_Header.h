#pragma once
#include "Header.h"

class GameBase {

	//dimensions and containers of board and board pieces
protected: int boardWidth = 0; //width of the board so x
		 int boardHeight = 0; //height of the board so y
		 int index; //vector index (boardWidth * y + x)
		 int longest; //to store the length of longest string
		 int moves; //counter for the amount of moves made
		 string storeInput; //for the input of user
		 vector<string>pieceVect; //will be X, O, B or W
		 string player = " "; //for either 1 or 2 since will not only be B, W, X or O
		 string player1; //X or B
		 string player2; //O or W

		 //methods and functions
public: virtual void print() = 0;
	  virtual bool done() { return false; };
	  virtual bool draw() { return false; };
	  virtual int turn() = 0;
	  int prompt(unsigned int& inputX, unsigned int& inputY);
	  int play();
	  static GameBase* whichGame(int argc, char* argv[]);

};