// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\PasswordProxy.h"

using namespace std;
int main()
{
	AbstractFile* t = new PasswordProxy();
	t->getSize();
	t->getName();
	return 0;
}

