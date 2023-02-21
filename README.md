# 0x16. C - Simple Shell
## Background Context
* A simple UNIX command interpreter.
![shell](https://user-images.githubusercontent.com/85158665/219971433-f2b21b08-f3c0-491d-a13b-f925b05660f0.jpeg)
^ “The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier
## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:
### General
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of `main`
* How does the shell use the `PATH` to find the programs
* How to execute another program with the `execve` system call
* How to suspend the execution of a process until one of its children terminates
* What is `EOF` / “end-of-file”?
## Requirements
### General
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))
* Write a `README` with the description of your project
* You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://github.com/moby/moby/blob/master/AUTHORS)
## More Info
### Output
* Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)
## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Testing
Your shell should work like this in interactive mode:
```

```
And also in non-interactive mode:
```

```
## Tasks
```
0. Betty would be proud
```
Code passes Betty checks.
```
1. Simple shell 0.1
```
* UNIX command line interpreter
Usage: `simple_shell`
The shell:
* Displays a prompt and waits for the user to type a command.
* The prompt is displayed again each time a command has been executed.
* The command line always ends with a new line.
* If an executable cannot be found, prints an error message and displays the prompt again.
* Handles the “end of file” condition (`Ctrl+D`)
```
2. Simple shell 0.2
```
Simple shell 0.1 +
* Handle command lines with arguments
```
3. Simple shell 0.3
```
Simple shell 0.2 +
* Handle the `PATH`
* `fork` must not be called if the command doesn’t exist
```
4. Simple shell 0.4
```
Simple shell 0.3 +
* Implement the `exit` built-in, that exits the shell
* Usage: `exit`
* You don’t have to handle any argument to the built-in `exit`
```
5. Simple shell 1.0
```
Simple shell 0.4 +
* Implement the `env` built-in, that prints the current environment
```
6. Simple shell 0.1.1
```
Simple shell 0.1 +
* Custom `getline` function
* Use a buffer to read many chars at once and call the least possible the `read` system call
* Use of `static` variables
* Global `getline` function not used
Not implemented:
* Cursor movement
```
7. Simple shell 0.2.1
```
Simple shell 0.2 +
* Custom `strtok` function used
