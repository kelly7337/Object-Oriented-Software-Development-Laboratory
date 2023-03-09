#pragma once

//numeration for the different array
enum indices { programName, inFile, numArg };

//enumeration for the different success and failure values
enum result { success = 0, failure_to_open_file = 1, failure_incorrect_amount_of_arguments = 2 };