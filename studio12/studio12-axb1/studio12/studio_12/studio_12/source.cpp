#include "header.h"
#include <iostream>
using namespace std;

Student::Student(void) {
	cout << "Student" << endl;
}
Student::~Student(void) {
	cout << "~Student" << endl;
}

Derived::Derived(void) {
	cout << "Derived" << endl;
}

void Student::SetName()
{
	cout << "Student" << endl;
}
void Derived::SetName()
{
	cout << "Derived" << endl;
}