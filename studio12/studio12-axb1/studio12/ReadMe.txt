1.Ermu Lu

2.Output:
  Student
  Student
  Derived
  ~Student
  ~Student
  When a member function is called with a derived class object, 
  the compiler first looks to see if that member exists in the derived class. 
  If not, it begins walking up the inheritance chain and checking whether the 
  member has been defined in any of the parent classes. It uses the first one it finds.

3. Non-virtual functions are resolved statically at Compile-time, 
   While Virtual functions are resolved dynamically at Run-time. 

4. Virtual(reference/pointer) goes by the created object type;
   virtual(object) goes by the caller.

5. There are more constructors than calls to new and delete.
   Making base class destructor virtual guarantees that the object of derived class 
   is destructed properly.

6. Method calls by value.
   Passing arguments by value.("Slicing" refers to the inability of the base copy 
   constructor to distinguish exact type matches from derived classes. The only way
   to invoke slicing is to invoke the base copy constructor. Typically this occurs 
   when passing arguments by value)
   