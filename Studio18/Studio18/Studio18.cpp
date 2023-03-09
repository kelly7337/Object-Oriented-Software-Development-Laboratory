// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
using namespace std;

int main()
{
	AbstractFileFactory* a = new SimpleFileFactory();
	AbstractFileSystem* b = new SimpleFileSystem();
	a->createFile("t.txt");
	b->openFile("a.img");
	return 0;
}
