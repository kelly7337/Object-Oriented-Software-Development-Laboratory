1. Name: Ermu Lu
   lab4

2. Warnings: None.
   Errors: I used to have an error caused by index out of bound 
           of the vector.

3. Tests

   Main function test:

	Case 1) Input: lab_4.exe TicTacToe
	Response: Starts the game appropriately which is what we expect.
	It prints out the board, indicates which player's turn it is and 
	prompts the user for coordinates.

	Case 2) Input: lab_4.exe and some other string such as "aaa".
	Response: It prints out the following usage error. "Usage Error:
	lab_4.exe <game_name>". 
	This is the expected response.

	Case 3) Input: lab_4.exe and a space
	Response: It prints out the following usage error. "Usage Error:
	lab_4.exe <game_name>". 
	This is the expected response.

	Case 4) Input: lab_4.exe
	Response: It prints out the following usage error. "Usage Error:
	lab_4.exe <game_name>". 
	This is the expected response.


   Tic tac toc function tests:
	
	Case 1) Input: 1,1 or other coordinates within a range of 1 - 3
	Response: Places the appropriate piece (X or O) in the coordinates 
	entered by the user and prints out their past and current moves 
	before prompting the next player for the coordinates they would like 
	to place their piece in.

	Case 2) Input: a random string such as "aaa"
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 3) Input: out of range width coordinates such as 4,1
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 4) Input: out of range height coordinates such as 1,4
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 5) Input: invalid negative coordinates such as (-1,2)
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 6) Input: invalid character coordinates such as !
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 7) Input: valid coordinates along with invalid characters
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 8) Input: quit
	Response: It prints out the following message: "t turn(s) was/were 
	played before the user quit." with the appropriate number t of 
	turns played. This is the expected response from the program.

	Case 9) Input: a set of three or more appropriate or innapropriate 
	               coordinates such as "1,2,3"
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 10) Input: a decimal coordinate such as "1.5,1"
	Response: It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.


   Gomoku game function tests:
	
	Case 1) Input coordinates out of bounds such as 99,99
	Response:  It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 2)	Negative input coordinates
	Response:  It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 3) Excessive amount of input coordinates
	Response:  It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 4) Inappropriate input (such as the string "aaa")
	Response:  It prints the following error message which is what 
	we expect from the program."Enter a set of valid (x,y) coordinates 
	such as '1,1' or 'quit' to exit the game." And it repeats
	whose turn it is, and prompts the user to enter appropriate 
	coordinates.

	Case 5) Valid coordinates
	Reponse: It adds the B/W to the according coordinate to the board, 
	then prints
	"Gomoku turn method is being called
	Gomoku done method is being called
	Gomoku draw method is being called
	Player t Turn", where t is the according player's turn. 

	Case 6) Input stating the user quit
	Response: It prints "t turn was played before the user quit." 
	where t is the correct number of turns that had been played at
	the point of quitting. 

	Case 7) Correct coordinates to reach a draw
	Response:  It prints "t turns were played and no winning moves 
	remain. The game is a draw." where t is the number of turns that 
	it took to get a draw (the product of w*h). 
	This was the expected response.

	Case 8) Correct coordinates to reach a win
	Reponse: It prints "Player X won." where X is the player 
	who won and terminates the game. 
	This was the expected response.