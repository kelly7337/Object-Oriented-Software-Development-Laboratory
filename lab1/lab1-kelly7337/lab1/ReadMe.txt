name: Ermu Lu
lab1


1. errors or warnings:
   (1) I forgot to put quotes when showing the output and the output is a string.
   (2) I output vecotr directly with cout, but it is wrong. I should use for loop to print it.

2. test:
   (1) I input some string and digits in input_file.txt.
       It printed out all of the strings first and in the same order as I input, 
       without the  digit characters.And those are print at the end.
       This is as expected.
   (2) I input only string.
       It prints out all of the strings of the input_file in their respective order.
       This is as expected.
   (3) I input only digits.
       It prints out all of the digits of the input_file in their respective order.
       This is as expected.
   (4) I input only program name, without the input_file name.
       It printed "Use wrong! Please enter a program name and file name.".
       This is as expected.
   (5) I input wrong file name.
       It printed "the input file cannot be opened :".
       This is as expected.
   (6) echo %errorlevel%
       return 0.
       This is as expected.