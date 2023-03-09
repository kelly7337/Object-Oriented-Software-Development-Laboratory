// console6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> squareElement(vector<int> &v, unsigned int a) {
    if (a > v.size() && a < 0) throw "index is not in the range";
    v[a] = v[a] * v[a];
    return v;
}


int divideSquaredElements(vector<int>& v, int a, int b) {
    vector<int> m = squareElement(v, a);
    vector<int> n = squareElement(v, b);
    if (n[b] == 0) throw "dividing by 0!";
    int x = m[a] / n[b];
    return x;
}



int main()
{
    vector<int> v = { 3, 4, 5, 6, 7 };
    unsigned int a = 6;
    
    //squareElement(v, a);
    try {
        v = squareElement(v, a);
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    
    }
    catch(const char* m) {
        cout << m << endl;
    }


    return 0;
}


