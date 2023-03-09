#pragma once


#include "AbstractCommand.h"
class AbstractFileFactory;
class AbstractFileSystem;

class LSCommand : public AbstractCommand {

public:
	LSCommand(AbstractFileSystem* s);

	virtual int execute(std::string s) override;
	virtual void displayInfo() override;

private:
	AbstractFileSystem* system;

};
