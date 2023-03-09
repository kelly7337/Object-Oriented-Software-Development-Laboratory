#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "lab1.h"
using namespace std;


//Declare and define a function for parsing an input file
int parsing(vector<string>& vec, char* file) {

	//open the file
	ifstream inFile(file);

	//check if it is valid
	if (!inFile.is_open()) {
		cerr << "the input file cannot be opened :" << file << endl;
		return failure_to_open_file;
	}

	string store;

	//push back the string into the vector that was passed as the first parameter
	while (inFile >> store) {
		vec.push_back(store);
	}

	//close the file
	inFile.close();

	return success;
}

//Declare and define a helpful "usage message" function
int usage() {
	cout << "Use wrong! Please enter a program name and file name.";
	return failure_incorrect_amount_of_arguments;
}


int main(int argc, char* argv[]) {

	//Declare a vector of C++ style strings
	vector<string> v;

	if (argc == 2) {
		parsing(v, argv[inFile]);
		//return success;
	}
	else {
		return usage();
	}

	//Declare a vector of integers
	vector<int> vi;

	//Iterate through the vector of strings
	for (size_t i = 0; i < v.size(); ++i) {
		string temp = v[i];
		int count = 0;
		int x = 0;
		
		for (size_t j = 0; j < temp.size(); ++j) {
			//for strings that contain only numeric digit characters
			if (isdigit(temp[j])) {
				++count;
			}
		}
		if (count == temp.size()) {
			istringstream iss(temp);
			iss >> x;
			vi.push_back(x);
		}
		//for strings that that contain any other (non-digit) characters
		else {
			cout << temp << endl;
		}
	}
	//iterating through the vector of integers and printing out each integer in it
	for (size_t k = 0; k < vi.size(); ++k) {
		cout << vi[k] << endl;
	}

	return success;
}