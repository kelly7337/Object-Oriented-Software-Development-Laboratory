1. Ermu Lu

2. in header.h:

class Detector
{
private:
    unsigned int a;
    unsigned int b = 0;


public:
    Detector(unsigned int a, unsigned int b);
    ~Detector();
};



   in source.cpp:

#include "header.h"
#include <iostream>
using namespace std;

// Detector constructor
Detector::Detector(unsigned int a, unsigned int b)
{
    a = b;
    b++;
    cout << "Detector\n" << &a << "\n" << &b << "\n" << a << endl;
}

Detector::~Detector()
{
    cout << "~Detector\n" << &a << "\n" << &b << "\n" << a << endl;
}  


3. As soon as the shared_ptr goes out of scope, 
   the object gets destructed and the code ends up with a dangling reference.

4. The last shared_ptr.
   shared_ptr will automatically destroy the object it points to 
   when all the shared_ptr that point to the object are destroyed 
   or reassigned to something else.
   Multiple times.
   Aliases to it will become dangling.

5. More objects being destroyed.
   The shared_ptr remembers the pointer type used during construction. 
   When the shared_ptr is destructed, it calls delete on the stored pointer.

7. Vectors stored on the stack will be cleaned up (memory free) when they 
   go out of scope.

   