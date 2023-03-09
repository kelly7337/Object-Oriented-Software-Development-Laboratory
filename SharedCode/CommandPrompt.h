#pragma once


#include <map>
#include <string>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class AbstractCommand;



class CommandPrompt {
public:
	CommandPrompt();								
	void setFileSystem(AbstractFileSystem*);		
	void setFileFactory(AbstractFileFactory*);		
	int addCommand(std::string s, AbstractCommand*);	

	int run();										// controls the program flow

protected:
	void listCommands();							
	std::string prompt();							


private:
	std::map<std::string, AbstractCommand*> commands;	
	AbstractFileSystem* system;							
	AbstractFileFactory* factory;						

};
