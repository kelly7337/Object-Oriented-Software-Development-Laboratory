#pragma once

#include "AbstractCommand.h"
class AbstractFileSystem;

class CopyCommand : public AbstractCommand {

public:
	CopyCommand(AbstractFileSystem* s);

	virtual int execute(std::string s) override;
	virtual void displayInfo() override;

private:
	AbstractFileSystem* system;

};