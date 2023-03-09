#include "header.h"
#include <iostream>
using namespace std;

// Detector constructor
Detector::Detector(unsigned int a, unsigned int b)
{
    a = b;
    b++;
    cout << "Detector\n" << &a << "\n" << &b << "\n" << a << endl;
  
}

Detector::~Detector()
{
    cout << "~Detector\n" << &a << "\n" << &b << "\n" << a << endl;

}



