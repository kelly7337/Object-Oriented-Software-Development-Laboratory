#include "header.h"
#include "GamePieces.h"
using namespace std;

//function that turns piece color into a string
string allLowercase(piece_color col) {
	if (col == red) {
		return "red";
	}
	if (col == black) {
		return "black";
	}
	if (col == white) {
		return "white";
	}
	if (col == invalid_color) {
		return "invalid color";
	}
	if (col == no_color) {
		return "no color";
	}
	if (col == blue) {
		return "blue";
	}
	else {
		return "no color";
	}
}

//function that turns string into a piece color
piece_color convertString(string col) {
	if (col == "red") {
		return red;
	}
	if (col == "black") {
		return black;
	}
	if (col == "white") {
		return white;
	}
	if (col == "no color") {
		return no_color;
	}
	if (col == "blue") {
		return blue;
	}
	else {
		return invalid_color;
	}
}

//constructor for game piece
game_piece::game_piece(piece_color c, string n, string d) : colorOfPiece(c), piece_name(n), piece_display(d) {}