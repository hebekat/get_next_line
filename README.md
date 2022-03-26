# get_next_line
get_next_line is a 42-University (https://42.fr/) project. The goal is to write a function that returns a line read from a file descriptor given a variable buffersize


Requirements:

•Repeated calls (e.g., using a loop) to your get_next_line() function 
should let you read the text file pointed to by the file descriptor,one line at a time.

•Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.

•Make sure that your function works as expected both when reading a file and whenreading from the standard input.

•Please note that the returned line should include the terminating\ncharacter,except if the end of file was reached and does not end with a \n character.

•Your header fileget_next_line.hmust at least contain the prototype of theget_next_line() function.

•Add all the helper functions you need in theget_next_line_utils.c file.

•Because you will have to read files inget_next_line(), add this option to yourcompiler call:-D BUFFER_SIZE=nIt will define the buffer size forread().The buffer size value will be modified by your peer-evaluators and the Moulinettein order to test your code.

•You will compile your code as follows (a buffer size of42is used as an example):cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

•We consider thatget_next_line()has an undefined behavior if the file pointed toby the file descriptor changed since the last call whereas read() didn’t reach the end of file.
  
•We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.
  
