#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>

using namespace std;

int main()
{
    std::vector<int> v{1, 2, 3, 4 };
    std::forward_list<int> l1{ 5, 6, 7};
    std::list<int> l2{ 8 };
    std::deque<int> d{ 9, 10, 11 };
    for (int& x : v) {
        cout << x << " ";
    }
    for (int& a : l1) {
        cout << a << " ";
    }
    for (int& b : l2) {
        cout << b << " ";
    }
    for (int& c : d) {
        cout << c << " ";
    }
}