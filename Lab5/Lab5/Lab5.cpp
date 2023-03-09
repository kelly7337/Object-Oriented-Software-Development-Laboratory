// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include <algorithm>
#include <iterator>
#include "..\..\\SharedCode\AbstractCommand.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileVisitor.h"
#include "..\..\\SharedCode\AbstractParsingStrategy.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\TouchCommand.h"

using namespace std;

int main(int argc, char* arg[])
{
	// allocate all objects needed
	AbstractFileFactory* ff = new SimpleFileFactory();
	AbstractFileSystem* fs = new SimpleFileSystem();
	AbstractCommand* com1 = new CatCommand(fs);
	AbstractCommand* com2 = new LSCommand(fs);
	AbstractCommand* com3 = new RemoveCommand(fs);
	AbstractCommand* com4 = new DisplayCommand(fs);
	AbstractCommand* com5 = new CopyCommand(fs);
	AbstractCommand* com6 = new MacroCommand(fs);

	//test

	ImageFile* image = new ImageFile("image.img");
	TextFile* test = new TextFile("test.txt");

	fs->addFile("root/dir/", test);
	fs->addFile("root/", image);
	fs->openFile("root/dir/test.txt");


	CommandPrompt cmd;
	cmd.setFileSystem(fs);
	cmd.setFileFactory(ff);
	cmd.addCommand("cat", com1);
	cmd.addCommand("ls", com2);
	cmd.addCommand("rm", com3);
	cmd.addCommand("ds", com5);
	cmd.addCommand("cp", com6);

	// run the command prompt
	cmd.run();



	// clean up dynamically allocated resources
	delete ff;
	delete fs; // all files are destroyed here (in the file system destructor)
	delete com1;
	delete com2;
	delete com3;
	delete com4;
	delete com5;
	delete com6;
	return 0;
}

