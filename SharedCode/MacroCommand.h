#pragma once

#include <vector>
#include "AbstractCommand.h"
class AbstractFileSystem;
class AbstractParsingStrategy;

class MacroCommand : public AbstractCommand {

public:
	MacroCommand(AbstractFileSystem* s);

	virtual int execute(std::string s) override;
	virtual void displayInfo() override;


	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);

private:
	AbstractFileSystem* system;

	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strat;

};


