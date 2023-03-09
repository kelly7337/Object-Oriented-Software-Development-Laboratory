#pragma once

#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;



	virtual void displayInfo() = 0;		// must be defined by derived classes to display information for macro commands
};



