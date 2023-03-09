// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	AbstractFile* t = new TextFile("t.txt");
	vector<char> x = { 'h', 'o' };
	t->write(x);
	cout << t->getSize();
	cout << t->getName();
	///std::ifstream myfile("aaa.txt");
	return 0;
}


