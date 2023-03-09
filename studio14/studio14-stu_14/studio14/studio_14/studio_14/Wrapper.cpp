#include "detector.h"
#include "Wrapper.h"
#include <iostream>
using namespace std;

Wrapper::Wrapper()
	: d_p_(0), del_(true) {
	d_p_ = new Detector();
	cout << "Wrapper()" << endl;
}

Wrapper::~Wrapper() {
	if (del_) delete d_p_;
	cout << "~Wrapper()" << endl;
}

Wrapper::Wrapper(const Wrapper& w)
	: del_(true), d_p_(nullptr) {
	d_p_ = new Detector();
	*d_p_ = *w.d_p_;
	cout << "cpy_Wrapper()" << endl;
}