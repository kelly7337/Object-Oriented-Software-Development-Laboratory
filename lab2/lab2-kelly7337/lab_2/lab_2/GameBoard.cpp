#include "header.h"
#include "GameBoard.h"
using namespace std;

//function for reading in dimensions of a game board
int dimensions(ifstream& ref, unsigned int& row, unsigned int& col) {
	string firstLine;
	if (getline(ref, firstLine)) {
		istringstream iss(firstLine);
		if (iss >> row && iss >> col) {
			return success;
		}
		else {
			return failure_to_extract_board_dimensions;
		}
	}
	else {
		return failure_to_read_line;
	}
}

//function for reading in game pieces
int reading(ifstream& ifref, vector<game_piece>& piecesVect, unsigned int width, unsigned int height) {
	string pieceDef;
	string exColor;
	string exName;
	string exDisplay;
	size_t exRow;
	size_t exCol;
	int counter = 0;

	while (getline(ifref, pieceDef)) {
		istringstream iss(pieceDef);

		if (iss >> exColor && iss >> exName && iss >> exDisplay
			&& iss >> exCol && iss >> exRow) {
			
			piece_color tempColor = convertString(exColor);
			if (tempColor == invalid_color) {
				continue;
			}
			else {
				//skip line if it doesn't work with game board dimensions
				if (exRow >= width || exCol >= height) {
					continue;
				}
				else {
					int index = width * exRow + exCol;
					
					piecesVect[index].colorOfPiece = tempColor;
					piecesVect[index].piece_name = exName;
					piecesVect[index].piece_display = exDisplay;
					counter = counter + 1;
				}
			}
		}
	}
	if (counter >= 1) {
		return success;
	}
	else {
		return failure_to_read_game_piece;
	}
}

//function for printing out pieces on a game board
int printing(vector<game_piece>& piecesVect, size_t height, size_t width) {
	if (piecesVect.size() != (height * width)) {
		return failure_to_respect_board_dimensions;
	}
	else {
		for (int h = height - 1; h >= 0; h--) {
			for (unsigned int w = 0; w < width; w++) {
				game_piece tempGP = piecesVect[width * h + w];
				cout << tempGP.piece_display << " ";
			}
			cout << endl;
		}
		return success;
	}
}
