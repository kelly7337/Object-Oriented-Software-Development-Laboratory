#include <iostream>
#include <iomanip>
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include "AbstractFileSystem.h"



using namespace std;

LSCommand::LSCommand(AbstractFileSystem* s) : system(s) {}

void LSCommand::displayInfo() {
	cout << "The ls command displays all files currently within the system" << endl;
	cout << "Invoke the default ls command: ls" << endl;
	cout << "Invoke the ls metadata command to display one file per line and show metadata: ls -m" << endl;
}

int LSCommand::execute(string s) {
	set<string> fileNames = system->getFileNames();					
	if (s.size() == 0) {											
		int count = 0;
		for (auto name = fileNames.begin(); name != fileNames.end(); ++name) {
			cout << left << setw(20) << *name;						
			++count;
			if (count % 2 == 0) {
				cout << endl;
			}
		}
		cout << endl;
	}
	else {
		if (s == "-m") {

			AbstractFileVisitor* vis = new MetadataDisplayVisitor;				
			for (auto name = fileNames.begin(); name != fileNames.end(); ++name) {

				AbstractFile* file = system->openFile(*name);

				file->accept(vis);											

				system->closeFile(file);									

			}
			delete vis;														
		}
		else {								
			return incorrectCommandArgs;
		}
	}
	return success;
}