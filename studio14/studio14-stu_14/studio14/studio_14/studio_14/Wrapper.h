#pragma once
#include "detector.h"
using namespace std;

class Wrapper {
public:
	Wrapper();
	Wrapper(const Wrapper& w);
	~Wrapper();
private:
	Detector* d_p_;
	bool del_;
};
