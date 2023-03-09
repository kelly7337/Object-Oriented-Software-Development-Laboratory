1. Ermu Lu

2. It throw a exception of type const char*.
   If I fail to catch the thrown exception, the program will optimize try-catch.

3. I should write the out_of_range exception first.
   Because if it is out of bound, there will be no returning data in divideSquaredElements() function.

4. when dividing 0, try will trow an int exception.