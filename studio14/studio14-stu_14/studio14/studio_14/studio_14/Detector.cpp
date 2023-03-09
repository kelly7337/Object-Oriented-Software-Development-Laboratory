#include "detector.h"
#include <iostream>
using namespace std;

unsigned Detector::s_i_ = 0;

unsigned Detector::get_i() {
	return i_;
}

Detector::Detector() {
	i_ = s_i_;
	s_i_ = s_i_ + 1;
	cout << "Detector(); adds: ";
	cout << this << "; ";
	cout << "i: " << this->i_ << endl;
}

Detector::~Detector() {
	cout << "~Detector(); adds: ";
	cout << this << "; ";
	cout << "i: " << this->i_ << endl;
}