#pragma once

#include "header.h"

class TicTacToeGame {
private: size_t width; //from 0 to 4
	   int height; //from 0 to 4
	   string player = "X"; //either X or O, default is X
	   vector<string>pieceVect; //keeps track of game pieces with formula from previous lab
	   int moves = 0; //counter for the amount of moves made

public: TicTacToeGame();

	  bool done();
	  bool draw();
	  string storeInput;
	  int prompt(unsigned int& inputX, unsigned int& inputY);
	  int turn();
	  int play();

	  
	  vector<string>movesPX;
	  vector<string>movesPO;

	  //declaring insertion operator as a friend of the class
	  friend ostream& operator << (ostream&, const TicTacToeGame&);
};
