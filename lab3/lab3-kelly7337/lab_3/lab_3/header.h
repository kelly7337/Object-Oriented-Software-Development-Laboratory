#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <sstream>
using namespace std;

enum result {
	success = 0, failure_incorrect_amount_of_arguments = 1, correct_amount_of_arguments = 2,
	user_quit_game = 3, game_is_a_draw = 4, incorrect_input_value = 5
};

int usage(string progName, string progInfo);
