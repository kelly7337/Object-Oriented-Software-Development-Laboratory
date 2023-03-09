Lab 5 Readme

1. Name: Ermu Lu

2. Warnings/Errors:
   No errors or warnings were encountered when building the program.

3. Tests:
   Tests are involved all the commands and how well the program tolerates whitespace and 
   extra characters, all tests pass.

   (1) Tesing for quit
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  q

       Test 1 passes

   (2) Testing touch command and ls command
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls


       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  touch file1.txt

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls
       file1.txt

       Test 2 passes

   (3) Testing cat command, ds command, and testing cat command followed by -a, and testing wq
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  cat file1.txt
       Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
       hello world
       :wq

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ds file1.txt
       hello world

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  cat file2.txt
       cat failed
       For help with invoking cat enter: help cat
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  cat file1.txt -a
       hello world
       Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving
       hello world
       1
       2
       3            
       :wq

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ds file1.txt
       hello worldhello world
       1
       2
       3           

       Test 3 passes
   
   (4) Testing the cp command
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  cp file1.txt file2

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls
       file1.txt           file2.txt


       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ds file2.txt
       hello worldhello world
       1
       2
       3

       Test 4 passes

   (5) Testing the rn command
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls
       file1.txt           file2.txt

 
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  rn file2.txt renamedfile2

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls
       file1.txt           renamedfile2.txt

       Test 5 passes

   (6) Testing that creating a file with invalid extension doesn't work
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  touch image1.pdf
       touch failed
       For help with invoking touch enter: help touch

       Test 6 passes

   (7) Testing what happens if you try to create two files at once
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  touch image1.img image2.img
       touch failed
       For help with invoking touch enter: help touch
       Test 7 passes

  (8) Testing cat command on image file
      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  cat image1.img
      Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
      XXXXXXXXX3
      :wq

      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  ds image1.img
      XXX
      XXX
      XXX

      Test 8 passes

  (9) Creating and adding data to a password protecting file. Also testing what happens if you put invalid password.
      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  touch image2.img -p
      Create your password here: 123

      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  cat image2.img
      Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
      XXXX2
      :wq
      Please enter password for image2.img: 124
      Incorrect password
      cat failed
      For help with invoking cat enter: help cat

      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  cat image2.img
      Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving
      XXXX2
      :wq
      Please enter password for image2.img: 123

      Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
      $  ds image2.img
      Please enter password for image2.img: 332
      XX
      XX

      Test 9 passes

  (10) Testing the cp command on image file with password
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  cp image2.img image3

       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls
       image2.img          image3.img


       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ds image3.img
       Please enter password for image3.img: 332
       XX
       XX

       Test 10 passes

  (11) Testing ls-m
       Please input command, q to quit, help for list of commands, or help followed by a command name for more information about that command
       $  ls -m
       Please enter password for image2.img: 123
       image2.img              image   4
       Please enter password for image3.img: 332
       image3.img              image   4
       newfile.txt             text    21

       Test 11 passes.
       