1. name: Ermu Lu
   Lab3


2. Error:
   In game_board.cpp, I got "The declaration is incompatible with the contents 
   of the header file". And then I changed the function from int to bool. And
   then it fixed.


   Warnings:
   (1) In game_board.cpp, in TicTacToeGame::turn(), when I the creat the method 
   to move the piece to the square, I got "Subexpression may overflow before 
   being assigned to wider type". But later it disappeared. So it maybe 
   a false positive.
   (2) In game_board.cpp, in TicTacToeGame::prompt(), I got 
   "'TicTacToeGame::prompt': not all control paths return a value". I should add
   the return. And then it fixed.


3. Test(file names):
   (1) input: lab_3.exe TicTacToe
       output: It prints out the board, indicates which player's turn 
       it is and prompts the user for coordinates.
       It is the expected output.

   (2) input: lab_3.exe aaaaaa
       output: It prints out usage error.
       It is the expected output.

   (3) input: lab_3.exe
       output: It prints out usage error.
       It is the expected output.


4. Test(game):
   (1) input: valid input(coordinates within a range of 1 - 3)
       output: It prints out the past and current moves before prompting 
       the next player for the coordinates.
       It is the expected output.

   (2) input: invalid width coordinates(4,1)
       output: It print out the error message "Enter a set of valid (x,y)
       coordinates such as '1,1' or 'quit' to exit the game."
       It is the expected output.

   (3) input: invalid height coordinates(1,4)
       output: It print out the error message "Enter a set of valid (x,y)
       coordinates such as '1,1' or 'quit' to exit the game."
       It is the expected output.

   (4) input: invalid coordinates with 0 or negative numbers(-1,-1)
       output: It print out the error message "Enter a set of valid (x,y)
       coordinates such as '1,1' or 'quit' to exit the game."
       It is the expected output.

   (5) input: invalid coordinates(1,2,3)
       output: It print out the error message "Enter a set of valid (x,y)
       coordinates such as '1,1' or 'quit' to exit the game."
       It is the expected output.

   (6) input: aaaa
       output: It print out the error message "Enter a set of valid (x,y)
       coordinates such as '1,1' or 'quit' to exit the game."
       It is the expected output.

   (7) input: quit
       output: It prints out the message "t turn(s) was/were played 
       before the user quit." and with the appropriate number t of turns played. 
       It is the expected output.
