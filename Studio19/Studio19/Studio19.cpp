// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TextFile.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	AbstractFile* t = new TextFile("t.txt");
	vector<char> x = { 'h', 'o' };
	t->write(x);
	t->read();
	return 0;
}
