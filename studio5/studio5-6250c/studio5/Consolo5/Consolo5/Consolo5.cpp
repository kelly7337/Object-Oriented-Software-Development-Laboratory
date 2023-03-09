// Consolo5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



//void mySwap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

void mySwap(int* const& p, int* const& q) {
    int* m = p;
    *p = *q;
    *q = *m;
    cout << "mySwap Version 2" << endl;
}


//void mySwap(int*& p, int*& q) {
//    int* m = p;
//    p = q;
//    q = m;
//    cout << "mySwap Version 1" << endl;
//}


int main()
{
    int a = 1, b = 2;
    int* p = &a, * q = &b;
    int* const m = &a;
    int* const n = &b;
    cout << a << endl;
    cout << b << endl;
    mySwap(m, n);
    cout << a << endl;
    cout << b << endl;
   /* cout << "mySwap Version 1" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << p << endl;
    cout << q << endl;*/
}

