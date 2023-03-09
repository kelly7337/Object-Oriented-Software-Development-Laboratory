#pragma once

class Inter2 {
private:
	int x;
	int y;
public:
	Inter2(){};
	
	//accessors
	int value1() const;

	//mutator
	void value2(int, int);
};

//Inter2::Inter2(int m) : x(m){}
//Inter2::Inter2(int n) : y(n){}

int Inter2::value1() const {
	return x, y;
}

void Inter2::value2(int m, int n) {
	x = m;
	y = n;
}
