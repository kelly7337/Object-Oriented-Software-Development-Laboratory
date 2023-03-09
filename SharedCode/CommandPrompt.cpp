#include <iostream>
#include <utility>
#include <sstream>
#include <iomanip>

#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


using namespace std;

CommandPrompt::CommandPrompt() : system(nullptr), factory(nullptr) {}			// set system and factory to be null initially

void CommandPrompt::setFileSystem(AbstractFileSystem* system) {
	this->system = system;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* f) {
	this->factory = f;
}

int CommandPrompt::addCommand(string s, AbstractCommand* command) {

	int beforeInsert = static_cast<int>(commands.size());				// get size of map prior to insert

	this->commands.insert({ s,command });								// attempt to insert

	int expectedSize = beforeInsert + 1;

	if (commands.size() == expectedSize) {								// if size is what we expect, insert was successful
		return success;
	}
	else {
		return unableToInsert;
	}

}

void CommandPrompt::listCommands() {
	int i = 1;				// iterating variable used to keep track of when to add a new line

	for (auto curr = commands.begin(); curr != commands.end(); ++curr) {

		cout << left << setw(20) << (*curr).first;
		if (i % 2 == 0) {							// if this is the second command in a row, add a new line
			cout << endl;
		}
		++i;
	}
	cout << endl;
}

string CommandPrompt::prompt() {

	cout << endl << "Please input command, q to quit, help for list of commands, or help followed by a command for more information about that command" << endl;
	cout << "$  ";
	string input;
	getline(cin, input);
	return input;

}

int CommandPrompt::run() {

	while (true) {


		string rawInput = prompt();				// get the user input

		istringstream getInput(rawInput);

		bool oneWord = true;					// bool to keep track of whether or not input is a single word
		string input;
		getInput >> input;
		if (!getInput) {		// if no input is input by the user
			cout << "Error: no user input detected" << endl;
			continue;
		}

		string testForMoreWords;					// testing for more than one word
		if (getInput >> testForMoreWords) {
			oneWord = false;
		}

		if (input == "q" && oneWord) {						// if user input "q", quit
			return quit;
		}


		else if (input == "help" && oneWord) {				// if user input "help", list commands
			this->listCommands();
		}

		else {

			if (oneWord) {													

				auto command = this->commands.find(input);					
				if (command == commands.end()) {							
					cout << "Error: " << input << " not found as a command" << endl;
				}
				else {														
					int executeOutcome = (*command).second->execute("");	
					if (executeOutcome != success) {						
						cout << (*command).first << " failed" << endl;
						cout << "For help with invoking " << (*command).first << " enter: help " << (*command).first << endl;
					}
				}


			}
			else {															

				istringstream iss(rawInput);									
				string first;
				iss >> first;												
				string moreInput;
				if (first == "help") {										
					iss >> moreInput;											
					auto command = this->commands.find(moreInput);				
					string tooMuch;
					if (iss >> tooMuch) {
						cout << "To use help command, input must appear as: help <command_name>" << endl;
						continue;
					}


					if (command == commands.end()) {						
						cout << "Error: " << moreInput << " not found as a command" << endl;
					}
					else {													
						(*command).second->displayInfo();
					}
				}
				else {														
					auto command = this->commands.find(first);				
					if (command == commands.end()) {						
						cout << "Error: " << first << " not found as a command" << endl;
					}
					else {													
						// get everything else out of iss
						string other;
						while (iss) {										
							iss >> other;
							moreInput += other;
							moreInput += " ";
							other = "";
						}
						
						int lastSpace = static_cast<int>(moreInput.size()) - 2;
						moreInput.replace(lastSpace, 2, "");


						int executeOutcome = (*command).second->execute(moreInput);	
						if (executeOutcome != success) {						
							cout << (*command).first << " failed" << endl;
							cout << "For help with invoking " << (*command).first << " enter: help " << (*command).first << endl;
						}
					}
				}

			}
		}
	}
}