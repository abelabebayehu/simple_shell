Simple Shell

Description

This project involves building a simple Unix shell as part of the curriculum. The shell provides a command-line interface that allows users to interact with the operating system by executing commands. The shell is a basic interpreter that reads user input, executes commands, and handles errors.

To try out the shell project, follow these steps:

1. Clone the Repository
Start by cloning the repository to your local machine using the following command:

bash
Copy code
git clone https://github.com/abelabebayehu/simple_shell.git

2. Navigate to the Project Directory

Change your directory to the cloned repository:

bash
Copy code
cd simple_shell

3. Compile the Code
   
Compile the shell program using gcc with the specified flags:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

4. Run the Shell
   
You can now run the shell in interactive mode by typing:

bash
Copy code
./hsh

To run the shell in non-interactive mode, you can pipe commands into it:

bash
Copy code
echo "/bin/ls" | ./hsh

5. Exiting the Shell

In interactive mode, type exit to exit the shell:

bash

Copy code

($) exit


6. Additional Information
   
For further details on how the shell works, refer to the rest of this README.md file.

The shell supports both interactive and non-interactive modes:

•	Interactive Mode: The shell displays a prompt, waits for the user to type a command, executes the command, and repeats.

•	Non-Interactive Mode: The shell reads commands from a file or pipe, executes them, and then exits.

Features
•	Prompt Display: The shell displays a prompt (#cisfun$) and waits for user input.

•	Single-word Commands: The shell can execute simple commands with no arguments (e.g., /bin/ls).

•	Error Handling: If a command cannot be executed, the shell prints an error message and prompts the user again.

•	End of File (EOF) Handling: The shell handles the Ctrl+D input to exit gracefully.

Requirements

•	Programming Language: C

•	Compiler: gcc, using the following options: -Wall -Werror -Wextra -pedantic -std=gnu89

•	Code Style: The code adheres to the Betty coding style.

•	Memory Management: The shell is free of memory leaks.

•	File Structure:

o	No more than 5 functions per file.

o	All header files are include guarded.

Allowed Functions and System Calls

The shell project only uses the following functions and system calls:

•	access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write.

Compilation and Execution

To compile the shell, use the following command:

bash

Copy code

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage

•	Interactive Mode:

bash

Copy code

./hsh

The shell will display a prompt (#cisfun$). You can type commands like /bin/ls, and the shell will execute them.

•	Non-Interactive Mode: You can pipe commands into the shell:

bash

Copy code

echo "/bin/ls" | ./hsh

The shell will execute the command and then exit.

Example Session

bash

Copy code

$ ./hsh

#cisfun$ /bin/ls

file1 file2 file3

#cisfun$ /bin/pwd

/home/user

#cisfun$ /bin/echo "Hello, World!"

Hello, World!

#cisfun$ exit

$

Project Structure

•	main.c: Contains the main function, which initializes the shell loop.

•	input.c: Contains the function for reading user input.

•	exec.c: Contains the function for executing commands.

•	shell.h: Header file with function prototypes and necessary includes.

Authors

•	Abel Abebayehu

•	Dr. Hiwot Wondale

August 2024
Acknowledgments
•	Special thanks to the curriculum developers and peers for their support and guidance.
License
This project is licensed under the MIT License.
