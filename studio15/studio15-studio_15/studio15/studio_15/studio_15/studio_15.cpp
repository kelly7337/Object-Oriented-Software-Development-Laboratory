

#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = 3;
    int& la = a;
    int& lb = b;
    int&& ra = 20;
    int&& rb = 30;
    cout << a << endl;
    cout << b << endl;
    cout << la << endl;
    cout << lb << endl;
    cout << ra << endl;
    cout << rb << endl;

}



