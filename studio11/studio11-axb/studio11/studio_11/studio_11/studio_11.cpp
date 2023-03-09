
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std;

class Student {
public:
    std::string name;
    unsigned int ID;
    std::vector<int> vec_of_nums{ 10, 20, 30,40, 50, 60 };
    
};


int main()
{
    std::ifstream inputFile("input.txt");
    Student i;
    i.name = "ErmuLu";
    i.ID = 502043;

    std::copy(i.vec_of_nums.begin(),
        i.vec_of_nums.end(),
        ostream_iterator<int>(cout, " "));

    std::sort(i.vec_of_nums.begin(),
        i.vec_of_nums.end(), [](auto const& l, auto const& r) {
        return std::get<2>(l) > std::get<2>(r);
        });
}


