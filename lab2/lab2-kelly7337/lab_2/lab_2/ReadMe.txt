Name: Ermu Lu
Lab2

1. Errors:
   (1) In GameBoard.cpp, I used istringstream incorrectly, and then I fixed it.
   (2) In GameBoard.cpp's reading function, I forgot to intialize the counter variable,
       and then I fixed it.
   (3) I forgot to include <fstream>, and then I got an error when I was using getline,
       and then I fixed it.
   
  
2. Warnings:
   (1) In main function's if condition, I got "== maybe is required but used =", and
       then I fixed this.
   (2) A warning: conversion from 'size_t' to 'int', possible loss of data.
       It is OK. I know that if the size is greater than MAX_INT, then I have 
       a possible denial of service (because the loop would loop forever). 
       However the numbers are small here, so it is not a problem.


3. Tests:
   (1) Input: lab_2.exe tic-tac-toe.txt
       Return: The output is the expected response.
       X X O
       O X
       X O O

   (2) Input: lab_2.exe gomoku.txt
       Return: The output is the expected response.
         O   O   O   O
       O   O   O   O
         O   O   O   O


       X   X   X   X
         X   X   X   X
       X   X   X   X

   (3) Input: lab_2.exe blankLinesGomoku.txt
       Return:  The output is the expected response.
         O   O       O
       O   O       O
         O       O   O


       X       X
         X   X   X   X
           X   X   X

       In the input file, lines 1, 5, 9, 13, 17, and 21 are removed.

   (4) Input: lab_2.exe blankLinesTicTacToe.txt
       Return: The output is the expected response.
       X X O
       O X
           O

   (5) Input: lab_2.exe emptyFile.txt
       Return: In response to this input, it returns the following error message 
       "Error: Board Dimensions could not be extracted from this file."
       This is the expected response to the input.

   (6) Input: lab_2.exe badFormTicTacToe
       Return: The output is the expected response.
       X X O
       O X
       X O O

   (7) Input: lab_2.exe badFormGomoku
       Return: The output is the expected response.
         O   O   O   O
       O   O   O   O
         O   O   O   O


       X       X   X
                 X   X
       X       X   X

   