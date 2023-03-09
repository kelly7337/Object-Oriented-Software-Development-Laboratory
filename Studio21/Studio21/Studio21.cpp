// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"
#include "../../SharedCode/CommandPrompt.h"

using namespace std;
int main()
{
	AbstractFileFactory* a = new SimpleFileFactory();
	AbstractFileSystem* b = new SimpleFileSystem();
	AbstractCommand* com = new TouchCommand(a, b);
	TextFile* test = new TextFile("test.txt");
	b->addFile("", test);
	CommandPrompt run;
	delete a;
	delete b;

	return 0;
}

