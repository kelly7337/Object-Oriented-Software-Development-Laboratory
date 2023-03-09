#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

enum result {
	success = 0, //if game is won
	failure_incorrect_amount_of_arguments = 1,
	correct_amount_of_arguments = 2,
	correct_amount_of_arguments_with_dim = 3,
	correct_amount_of_arguments_with_dim_with_winVal = 4,
	user_quit_game = 5,
	game_is_a_draw = 6,
	incorrect_input_value = 7,
	bad_alloc_ret = 8,
	unknownGame = 9
};

enum places {
	gameName = 1
};

int usage(string progName, string progInfo);
