#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


int usage(string progName, string progInfo);
void lowercase(string& inputString);



enum result {
	success = 0, failure_to_open_file = 1, failure_incorrect_amount_of_arguments = 2,
	failure_to_extract_board_dimensions = 3, failure_to_read_line = 4, failure_to_read_game_piece = 5,
	failure_to_respect_board_dimensions = 6
};
