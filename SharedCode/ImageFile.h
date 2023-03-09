#pragma once
// Image file class declaration here
#include "AbstractFile.h"


class ImageFile : public AbstractFile {


public:
	ImageFile(std::string name);					
	ImageFile(std::string name, ImageFile& toCopy);	


	virtual unsigned int getSize() override;
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::string getName() override;

	virtual void accept(AbstractFileVisitor* vis) override;	


	int charToInt(char c);				
	char size;							

	virtual AbstractFile* clone(std::string& s) override;		


private:
	std::string name;
	std::vector<char> contents;





};