#include <iostream>
#include <sstream>
#include "CopyCommand.h"
#include "AbstractFileSystem.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* s) : system(s) {}

void CopyCommand::displayInfo() {
	cout << "The copy command copies an existing file into a new file of a different name" << endl;
	cout << "Invoke the copy command with: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string s) {

	istringstream iss(s);
	string fileToCopy;
	iss >> fileToCopy;						
	if (!iss) {								
		return incorrectCommandArgs;
	}

	AbstractFile* fileToCopy_ptr = system->openFile(fileToCopy);		
	if (fileToCopy_ptr == nullptr) {
		return fileDoesNotExist;
	}

	string newFileName;							
	iss >> newFileName;
	if (!iss) {									
		system->closeFile(fileToCopy_ptr);
		return incorrectCommandArgs;
	}

	string extra;
	iss >> extra;								
	if (iss) {
		system->closeFile(fileToCopy_ptr);
		return incorrectCommandArgs;
	}

	AbstractFile* newFile = fileToCopy_ptr->clone(newFileName);		
	int addOutcome = system->addFile(newFileName, newFile);			
	if (addOutcome != success) {									
		delete newFile;
		system->closeFile(fileToCopy_ptr);
		return unableToAddFile;
	}


	system->closeFile(fileToCopy_ptr);
	return success;
}