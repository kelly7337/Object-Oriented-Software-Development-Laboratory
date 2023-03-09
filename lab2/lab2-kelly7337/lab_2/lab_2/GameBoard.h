#pragma once

#include "header.h"
#include "GamePieces.h"
using namespace std;


int dimensions(ifstream& ref, unsigned int& row, unsigned int& col);
int reading(ifstream& ifref, vector<game_piece>& piecesVect, unsigned int width, unsigned int height);
int printing(vector<game_piece>&, size_t height, size_t width);