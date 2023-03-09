#pragma once

#include "AbstractCommand.h"
class AbstractFileSystem;

class CatCommand : public AbstractCommand {

public:
	CatCommand(AbstractFileSystem* s);

	virtual int execute(std::string s) override;
	virtual void displayInfo() override;

private:
	AbstractFileSystem* system;

};
