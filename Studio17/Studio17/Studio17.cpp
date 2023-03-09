// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include <iostream>
using namespace std;


int main()
{
	AbstractFile* i = new ImageFile("i.img");
	vector<char> s = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	i->write(s);
	cout << i->getSize();
	cout << i->getName();

	return 0;
}

