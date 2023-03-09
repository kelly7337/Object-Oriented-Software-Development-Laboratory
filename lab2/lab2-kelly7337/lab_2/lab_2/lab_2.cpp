#include "header.h"
#include "GamePieces.h"
#include "GameBoard.h"
using namespace std;


//usage function returns message in case of error and indications on how to fix it
int usage(string progName, string progInfo) {
	cout << "Usage Error:" << progName << progInfo;
	return failure_incorrect_amount_of_arguments;
}

int main(int argc, char* argv[]) {

	if (argc == failure_incorrect_amount_of_arguments) { 
		ifstream inFile(argv[1]);

		//check if it is valid and print error message if unable to open file
		if (!inFile.is_open()) {
			cerr << "the following input file cannot be opened:" << argv[1] << endl;
			return failure_to_open_file;
		}
		else { //if opening of the file is successful
			unsigned int width;
			unsigned int height;
			int returnEl = dimensions(inFile, width, height);
			//if not able to extract board dimensions, keep calling dimensions until success or end of file
			while (returnEl == failure_to_extract_board_dimensions) {
				returnEl = dimensions(inFile, width, height);
			}
			if (returnEl == failure_to_read_line) {
				cout << "Error: Board Dimensions could not be extracted from this file." << endl;
				return failure_to_extract_board_dimensions;
			}
			//if able to extract board dimensions
			if (returnEl == success) {
				vector<game_piece> newV;
				size_t wh = width * height;
				for (size_t i = 0; i < wh; i++) {
					newV.push_back(game_piece(no_color, "", " "));
				}
				//if the function is unable to read any game piece
				if (reading(inFile, newV, width, height) != success) {
					cout << "Error: Failure to read game piece" << endl;
					return failure_to_read_game_piece;
				}
				//if the function is able to read at least one game piece
				else {
					return printing(newV, height, width);
				}
			}
		}

	}
	else {
		return usage(argv[0], "<input_file>");
	}
	return success;
}

void lowercase(string& inputString) {
	for (int i = 0; i < inputString.size(); ++i) {
		char current = inputString[i];
		if (current <= 90 && current >= 65) {
			current = current + 32;
			inputString[i] = current;
		}
		else {
		}
	}
}