

#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    Detector dector(a, b);
   /* shared_ptr<unsigned int> t = std::make_shared<unsigned int>(a.get());
    shared_ptr<int> b;*/
    unsigned int* ptr_to_a = &a;
    auto a_shared_ptr = shared_ptr <int >(ptr_to_a);
    return 0;
}

