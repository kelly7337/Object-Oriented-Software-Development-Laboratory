1. Ermu Lu

2. Two objects are created and the two objects are destroyed.

3. Two objects are created and the object of wrapper class is destroyed. 
   The object of detector on the heap is not destroyed because no delete
   statement is called upon it.

4. Two objects are created and two are destroyed because delete is called 
   upon the pointer variable.

5. One time it is created and destroyed.
   The second wrapper objects will delete the detector object, that may cause 
   problem if we try to access the pointer variable in the first wrapper object. 
   The first wrapper object.
   
6. Two objects are created.