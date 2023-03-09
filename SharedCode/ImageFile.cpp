#include "ImageFile.h"
#include <iostream>

using namespace std;

ImageFile::ImageFile(string name) : name(name), size(0) {}


ImageFile::ImageFile(string name, ImageFile& toCopy) : name(name), size(toCopy.size), contents(toCopy.contents) {}


unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}


string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> vec) {			
	while (vec.back() == '\n') {					
		vec.pop_back();
	}
	char size = vec.back();							
	this->size = size;								

	int intSize = charToInt(size);					

	int sizeSquared = intSize * intSize;			
	// check for size mismatch
	if (sizeSquared != vec.size() - 1) {
		this->size = 0;
		contents.clear();
		return imageFileSizeMismatch;
	}
	contents.clear();
	for (int i = 0; i < vec.size() - 1; ++i) {
		if (vec[i] != ' ' && vec[i] != 'X') {		// check that all "pixels" are 'X' or ' ' 
			this->size = 0;
			contents.clear();
			return invalidImagePixel;
		}
		else {
			contents.push_back(vec[i]);
		}
	}


	return success;
}


int ImageFile::charToInt(char c) {
	c -= 48;
	int i = static_cast<int>(c);
	return i;
}


int ImageFile::append(vector<char> newVec) {
	return cannotAppend;
}


vector<char> ImageFile::read() {

	return contents;
}



void ImageFile::accept(AbstractFileVisitor* vis) {
	vis->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string& s) {
	s += ".img";
	AbstractFile* newFile = new ImageFile(s, *this);
	return newFile;
}