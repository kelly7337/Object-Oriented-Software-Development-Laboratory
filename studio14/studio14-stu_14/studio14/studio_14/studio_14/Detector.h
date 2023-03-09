#pragma once
using namespace std;

class Detector {
public:
	Detector();
	~Detector();
	unsigned get_i();
private:
	unsigned i_;
	static unsigned s_i_;
};
