// studio_8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "studio_8.h"
#include <cstdlib>
using namespace std;

//inter2::inter2(int x, int y) 
//    : x_(0), y_(0){}


int main()
{
    /*inter2 t(30);
    cout << t.value1() << endl;
    return 0;*/

    Inter2 m; // default construction
    cout << "m.x =" << m.x() << " and m.y =" << m.y() << endl;
    m.x(7).y(3); // chained use of mutator functions
    cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
    Inter2 n(m); // copy construction
    cout << "n.x = " << n.x() << " and n.y = " << n.y() << endl;

    
}

