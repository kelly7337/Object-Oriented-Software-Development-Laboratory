#include <iostream>
#include <sstream>
#include "MacroCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* s) : system(s), strat(nullptr) {}

void MacroCommand::displayInfo() {

	this->strat->displayInfo();			

}

int MacroCommand::execute(string s) {
	vector<string> inputs;
	try {										
		inputs = strat->parse(s);				
	}
	catch (...) {								
		return incorrectCommandArgs;
	}

	int i = 0;												
	for (AbstractCommand* command : commands) {				
		int outcome = command->execute(inputs[i]);
		++i;
		if (outcome != success) {
			return outcome;
		}
	}

	return success;
}


void MacroCommand::addCommand(AbstractCommand* command) {
	commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	this->strat = strategy;
}