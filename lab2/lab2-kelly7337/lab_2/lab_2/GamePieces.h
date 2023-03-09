#pragma once

#include "header.h"
using namespace std;


enum piece_color { red, black, white, invalid_color, no_color, blue };

struct game_piece {
	piece_color colorOfPiece;
	string piece_name;
	string piece_display;
	game_piece(piece_color, string, string);
};

string allLowercase(piece_color current);
piece_color convertString(string current);