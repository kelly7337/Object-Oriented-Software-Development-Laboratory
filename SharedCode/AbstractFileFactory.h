#pragma once
// studio 18 - file factory interface declared here

#include <string>
#include "../SharedCode/AbstractFile.h"

class AbstractFileFactory {

public:
	virtual AbstractFile* createFile(std::string name) = 0;


};