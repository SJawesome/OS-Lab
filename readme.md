# # Authors: Durreshahwar Arif, Sarah Long, Ibaada Arif, Jay Patel 

# # Operating Systems Lab 2

# # Shell Manual 

To Run this just type make in your terminal to compile and after use ./myshell to run the shell

When the shell is invoked with an external batchfile with the command line argument “myshell batchfile” containing a set of commands, the shell will read through the content of the batchfile and display the results until the end-of-file is reached. The shell also supports I/O-redirection on either stdin and/or stdout, through the command line program_name arg1 arg2 < inputfile > outputfile, where the stdin FILE stream is replaced by inputfile and stdout FILE is replaced by outputfile. The shell further supports the background execution of programs, for example, an ampersand at the end of the command line returns the command line prompt instantly after the start of that program. Lastly, the command line prompt contains the pathname of the current directory. Below is a list of all the internal commands the shell program supports:

1. cd <directory> - This allows the current directory to be changed to another directory selected by the user. If the directory selected is not present, the current directory will be reported, and if the directory does not exist an error is printed. 
2. clr - This allows to clear the screen
3. dir <directory> - This command provides a list of the contents of the directory 
4. environ - This command provides a list of all the environment strings 
5. echo <comment> - This command will allow user text to display by a new line
6. help - This command displays the user manual 
7. pause - This command is the pause operation of the shell and can be interrupted by pressing the “enter” button
8. quit - This command quits the shell 
9. shell =<pathname>/myshell is the full path used for the executable
