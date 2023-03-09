#include <iostream>
#include <sstream>
#include "DisplayCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* s) : system(s) {}

void DisplayCommand::displayInfo() {
	cout << "The display command is used to print the contents of a file" << endl;
	cout << "To display the formatted file, use command: ds <filename>" << endl;
	cout << "To display the unformatted version of a file, use command: ds <filename> -d" << endl;
}

int DisplayCommand::execute(string s) {

	istringstream iss(s);
	string fileName;
	iss >> fileName;						
	if (!iss) {
		return incorrectCommandArgs;
	}

	AbstractFile* file = system->openFile(fileName);
	if (file == nullptr) {							
		return invalidFileName;
	}


	string extraCommand;					
	iss >> extraCommand;



	if (iss) {								

		string tooMuch;
		if (iss >> tooMuch) {				
			return incorrectCommandArgs;
		}

		if (extraCommand == "-d") {			
			// unformatted
			vector<char> contents = file->read();
			for (char c : contents) {		
				cout << c;
			}
			cout << '\n';
		}
		else {								
			system->closeFile(file);		
			return incorrectCommandArgs;
		}
	}
	else {									

		BasicDisplayVisitor* displayer = new BasicDisplayVisitor();		
		file->accept(displayer);			
		delete displayer;					
	}


	system->closeFile(file);
	return success;
}
