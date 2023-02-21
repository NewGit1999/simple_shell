# 0x16. C - Simple Shell
## Background Context
* A simple UNIX command interpreter.
![shell](https://user-images.githubusercontent.com/85158665/219971433-f2b21b08-f3c0-491d-a13b-f925b05660f0.jpeg)
^ “The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier
## Learning Objectives
At the end of this project, it is expected to be able to explain to anyone, without the help of Google:
### General
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a `pid` and a `ppid`
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of `main`
* How does the shell use the `PATH` to find the programs
* How to execute another program with the `execve` system call
* How to suspend the execution of a process until one of its children terminates
* What is `EOF` / “end-of-file”?
## Requirements`
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
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ /bin/ls
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
$ exit
vagrant@ubuntu-focal:~/simple_shell$
```
And also in non-interactive mode:
```
vagrant@ubuntu-focal:~/simple_shell$ echo "/bin/ls" | ./hsh
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
vagrant@ubuntu-focal:~/simple_shell$
```
## Tasks
```
0. Betty would be proud
```
Code passes Betty checks.
* Run `betty *` to verify
```
1. Simple shell 0.1
```
* UNIX command line interpreter
* Usage: `simple_shell`
* The shell:
* Displays a prompt and waits for the user to type a command.
* The prompt is displayed again each time a command has been executed.
* The command line always ends with a new line.
* If an executable cannot be found, prints an error message and displays the prompt again.
* Handles the “end of file” condition (`Ctrl+D`)
*gif here*:
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
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ /bin/ls
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
$ ls
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
$ ls -l /tmp
total 20
drwx------ 3 root root 4096 Feb 21 06:57 snap-private-tmp
drwx------ 3 root root 4096 Feb 21 06:57 systemd-private-66e4732a88ba4d62b85b74050f0d0ead-ModemManager.service-8vrZtj
drwx------ 3 root root 4096 Feb 21 06:57 systemd-private-66e4732a88ba4d62b85b74050f0d0ead-systemd-logind.service-09pvYi
drwx------ 3 root root 4096 Feb 21 06:57 systemd-private-66e4732a88ba4d62b85b74050f0d0ead-systemd-resolved.service-iInQXh
drwx------ 3 root root 4096 Feb 21 06:57 systemd-private-66e4732a88ba4d62b85b74050f0d0ead-systemd-timesyncd.service-a6bQAf
$ ^C
$
vagrant@ubuntu-focal:~/simple_shell$
```
```
4. Simple shell 0.4
```
Simple shell 0.3 +
* Implement the `exit` built-in, that exits the shell
* Usage: `exit`
* You don’t have to handle any argument to the built-in `exit`
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ exit
vagrant@ubuntu-focal:~/simple_shell$
```
```
5. Simple shell 1.0
```
Simple shell 0.4 +
* Implement the `env` built-in, that prints the current environment
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ env
SHELL=/bin/bash
PWD=/home/vagrant/simple_shell
LOGNAME=vagrant
XDG_SESSION_TYPE=tty
MOTD_SHOWN=pam
HOME=/home/vagrant
LANG=C.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=10.0.2.2 56291 10.0.2.15 22
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=vagrant
SHLVL=1
XDG_SESSION_ID=12
XDG_RUNTIME_DIR=/run/user/1000
SSH_CLIENT=10.0.2.2 56291 22
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
SSH_TTY=/dev/pts/0
OLDPWD=/home/vagrant
_=./hsh
$
```
```
6. Simple shell 0.1.1
```
Simple shell 0.1 +
* Custom `getline` function
* Use a buffer to read many chars at once and call the least possible the `read` system call
* Use of `static` variables
* Global `getline` function not used
* [\_getline](./_getline.c)
	* Not implemented:
* Cursor movement
```
7. Simple shell 0.2.1
```
Simple shell 0.2 +
* Custom `strtok` function used
* [\_strtok](./_strtok.c)
```
8. Simple shell 0.4.1
```
Simple shell 0.4 +
* handle arguments for the built-in `exit`
* Usage: `exit status`, where status is an integer used to `exit` the shell
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ exit 98
vagrant@ubuntu-focal:~/simple_shell$ echo $?
98
vagrant@ubuntu-focal:~/simple_shell$
```
```
9. setenv, unsetenv
```
Simple shell 1.0 +
* Implement the `setenv` and `unsetenv` builtin commands
	* `setenv`
		* Initialize a new environment variable, or modify an existing one
		* Command syntax: `setenv VARIABLE VALUE`
		* Should print something on stderr on failure
	* `unsetenv`
		* Remove an environment variable
		* Command syntax: `unsetenv VARIABLE`
		* Should print something on stderr on failure
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ setenv SOME_VAR 13
$ echo $SOME_VAR
13
$ unsetenv SOME_VAR
$ echo $SOME_VAR

$
```
```
10. cd
```
Simple shell 1.0 +
* Implement the builtin command `cd`:
	* Changes the current directory of the process.
	* Command syntax: `cd [DIRECTORY]`
	* If no argument is given to `cd` the command must be interpreted like `cd $HOME`
	* Handles the command `cd -`
	* Environment variable `PWD` is updated when you change directory
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ pwd
/home/vagrant/simple_shell
$ cd
$ pwd
/home/vagrant
$ cd -
$ pwd
/home/vagrant/simple_shell
$
```
```
11. ;
```
Simple shell 1.0 +
* Handles the commands separator `;`
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /hbtn ; ls /var
ls: cannot access '/hbtn': No such file or directory
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /var ; ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
ls: cannot access '/hbtn': No such file or directory
$ ls /var ; ls /hbtn ; ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
ls: cannot access '/hbtn': No such file or directory
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$
```
```
12. && and ||
```
Simple shell 1.0 +
* Handle the `&&` and `||` shell logical operators
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ ls /var && ls /var
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /hbtn && ls /var
ls: cannot access '/hbtn': No such file or directory
$ ls /var && ls /var && ls /var && ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
ls: cannot access '/hbtn': No such file or directory
$ ls /var && ls /var && ls /var && ls /hbtn && ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
ls: cannot access '/hbtn': No such file or directory
$
$ ls /var || ls /var
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /hbtn || ls /var
ls: cannot access '/hbtn': No such file or directory
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var
ls: cannot access '/hbtn': No such file or directory
ls: cannot access '/hbtn': No such file or directory
ls: cannot access '/hbtn': No such file or directory
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ ls /hbtn || ls /hbtn || ls /hbtn || ls /var || ls /var
ls: cannot access '/hbtn': No such file or directory
ls: cannot access '/hbtn': No such file or directory
ls: cannot access '/hbtn': No such file or directory
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$
```
```
13. alias
```
Simple shell 1.0 +
* Implement the `alias` builtin command
* Usage: `alias [name[='value'] ...]`
	* `alias`: Prints a list of all aliases, one per line, in the form `name='value'`
	* `alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`
	* `alias name='value' [...]`: Defines an alias for each name whose `value` is given. If `name` is already an alias, replaces its value with `value`
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ alias lister='ls -l'
$ alias pathfinder="pwd"
$ alias shouter=echo
$ alias
lister='ls -l'
pathfinder='pwd'
shouter='echo'
$ alias shouter
shouter='echo'
$ alias pathfinder
pathfinder='pwd'
$ lister
total 204
-rw-rw-r-- 1 vagrant vagrant   136 Feb 21 18:00 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  4021 Feb 21 18:00 README.md
-rw-rw-r-- 1 vagrant vagrant   397 Feb 21 18:00 _atoi.c
-rw-rw-r-- 1 vagrant vagrant  1041 Feb 21 18:00 _getline.c
-rw-rw-r-- 1 vagrant vagrant   835 Feb 21 18:00 _itoa.c
-rw-rw-r-- 1 vagrant vagrant   290 Feb 21 18:00 _strcat.c
-rw-rw-r-- 1 vagrant vagrant   356 Feb 21 18:00 _strcmp.c
-rw-rw-r-- 1 vagrant vagrant   391 Feb 21 18:00 _strcmpd.c
-rw-rw-r-- 1 vagrant vagrant   421 Feb 21 18:00 _strcmps.c
-rw-rw-r-- 1 vagrant vagrant   280 Feb 21 18:00 _strcpy.c
-rw-rw-r-- 1 vagrant vagrant   357 Feb 21 18:00 _strdup.c
-rw-rw-r-- 1 vagrant vagrant   267 Feb 21 18:00 _strlen.c
-rw-rw-r-- 1 vagrant vagrant  1205 Feb 21 18:00 _strtok.c
-rw-rw-r-- 1 vagrant vagrant   819 Feb 21 18:00 _write.c
-rw-rw-r-- 1 vagrant vagrant  3028 Feb 21 18:00 alias.c
-rw-rw-r-- 1 vagrant vagrant  2355 Feb 21 18:00 built_in.c
-rw-rw-r-- 1 vagrant vagrant   901 Feb 21 18:00 cd.c
-rw-rw-r-- 1 vagrant vagrant  2982 Feb 21 18:00 env_func.c
-rw-rw-r-- 1 vagrant vagrant   707 Feb 21 18:00 error.c
-rw-rw-r-- 1 vagrant vagrant   915 Feb 21 18:00 error.h
-rw-rw-r-- 1 vagrant vagrant   539 Feb 21 18:00 execute.c
-rw-rw-r-- 1 vagrant vagrant  2039 Feb 21 18:00 expansions.c
-rw-rw-r-- 1 vagrant vagrant   829 Feb 21 18:00 file_path.c
-rw-rw-r-- 1 vagrant vagrant  1067 Feb 21 18:00 help.c
-rw-rw-r-- 1 vagrant vagrant  2814 Feb 21 18:00 help.h
-rw-rw-r-- 1 vagrant vagrant  1697 Feb 21 18:00 history.c
-rwxrwxr-x 1 vagrant vagrant 41760 Feb 21 18:00 hsh
-rw-rw-r-- 1 vagrant vagrant   557 Feb 21 18:00 input.c
-rw-rw-r-- 1 vagrant vagrant  3240 Feb 21 18:00 linked_lists.c
-rw-rw-r-- 1 vagrant vagrant  2121 Feb 21 18:00 memory_func1.c
-rw-rw-r-- 1 vagrant vagrant   334 Feb 21 18:00 memory_func2.c
-rw-rw-r-- 1 vagrant vagrant   268 Feb 21 18:00 num_len.c
-rw-rw-r-- 1 vagrant vagrant  1143 Feb 21 18:00 parser.c
-rw-rw-r-- 1 vagrant vagrant   272 Feb 21 18:00 pow_b.c
-rw-rw-r-- 1 vagrant vagrant  1081 Feb 21 18:00 run.c
-rw-rw-r-- 1 vagrant vagrant  3723 Feb 21 18:00 shell.c
-rw-rw-r-- 1 vagrant vagrant  2575 Feb 21 18:00 shell.h
-rw-rw-r-- 1 vagrant vagrant    74 Feb 21 18:00 sometest
-rw-rw-r-- 1 vagrant vagrant  1267 Feb 21 18:00 str_func.c
-rw-rw-r-- 1 vagrant vagrant    10 Feb 21 18:00 test_ls_2
-rw-rw-r-- 1 vagrant vagrant   672 Feb 21 18:00 unalias.c
$ shouter $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ pathfinder
/home/vagrant/simple_shell
$
```
```
14. Variables
```
Simple shell 1.0 +
* Handle variables replacement
* Handle the `$?` variable
* Handle the `$$` variable
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ ls /var
backups  cache  crash  lib  local  lock  log  mail  opt  run  snap  spool  tmp
$ echo $?
0
$ echo $$
25100
$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ exit
vagrant@ubuntu-focal:~/simple_shell$
```
```
15. Comments
```
Simple shell 1.0 +
* Handle comments (`#`)
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ echo $$ # ls -la
25146
$ exit
vagrant@ubuntu-focal:~/simple_shell$
```
```
16. File as input
```
Simple shell 1.0 +
* Usage: `simple_shell [filename]`
* The shell can take a file as a command line argument
* The file contains all the commands that your shell should run before exiting
* The file should contain one command per line
* In this mode, the shell should not print a prompt and should not read from `stdin`
```
vagrant@ubuntu-focal:~/simple_shell$ cat test_ls_2
ls
pwd
ls
vagrant@ubuntu-focal:~/simple_shell$ ./hsh test_ls_2
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
/home/vagrant/simple_shell
AUTHORS    _getline.c  _strcmp.c   _strcpy.c  _strtok.c  built_in.c  error.c    expansions.c  help.h     input.c        memory_func2.c  pow_b.c  shell.h     test_ls_2
README.md  _itoa.c     _strcmpd.c  _strdup.c  _write.c   cd.c        error.h    file_path.c   history.c  linked_lists.c  num_len.c                                                                                                           run.c     sometest    unalias.c
_atoi.c    _strcat.c   _strcmps.c  _strlen.c  alias.c    env_func.c  execute.c  help.c        hsh        memory_func1.c  parser.c                                                                                                            shell.c  str_func.c
vagrant@ubuntu-focal:~/simple_shell$
```
## Error Messages
* Handles errors when commands fail and prints error message to `stderr`
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ nonexistent
./hsh: 1: nonexistent: not found
$ cd nodirectory
./hsh: 2: cd: nodirectory: No such file or directory
$ alias notset
./hsh: 3: alias: notset: not found
$ setenv noneset
./hsh: 4: setenv: Syntax error
$ unsetenv none
$ exit notint
./hsh: 6: exit: notint: numeric argument required
vagrant@ubuntu-focal:~/simple_shellu$
```
## Help
* Enter `help` in shell to get more info on built-in functions
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ help

Simple Shell    Version 1-ALX Software Engineering Team Project(Yasmine B. Ali & Selasi S. Kporvie)
These shell commands are defined in the custom shell.
Type `help' to see this list.
Type `help name' to find out more about the function `name'.

The following commands are defined:

        alias [name[='value'] ...]      help
        cd [DIRECTORY]                  history
        env                             setenv [VARIABLE] [VALUE]
        exit [status]                   unsetenv [VARIABLE]
$ help alias
        alias usage: alias [name[='value'] ...]
        alias: Prints a list of all aliases, one per line, in the form name='value'
        alias: Prints a list of all aliases, one per line, in the form name='value'
        alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
        alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value
        or overwrites the KEY with new VALUE.
$ help cd
        cd usage: cd [DIRECTORY]
        If no argument is given to cd the command must be interpreted like cd $HOME
        cd - changes directory to the precious directory
        the environment variable PWD is updated when cd is used
$ help env
        env usage: env
        Prints out the current envirornment variables.
$ help exit
        exit usage: exit status
        Exits the shell with or without an integer status
        Last command executed before shell terminates
$ help history
        history usage: history
        Displays history of commands in shell
$ help help
        help usage: help COMMAND
        Displays helpful info about builtins
$ help setenv
        setenv usage: setenv VARIABLE VALUE
        Initialize a new environment variable, or modify an existing one
        Prints syntax error on stderr on failure
$ help unsetenv
        unsetenv usage: unsetenv VARIABLE
        Remove an environment variable
        Prints syntax error on sterr on failure
$
```
## Bugs
* Unable to print alias in the form `alias lister` if lister is an alias with a flag like `'ls -l'`. WOrks fine if alias is not a flag.
```
vagrant@ubuntu-focal:~/simple_shell$ ./hsh
$ alias lister='ls -l'
$ lister
total 204
-rw-rw-r-- 1 vagrant vagrant   136 Feb 21 18:00 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  4021 Feb 21 18:00 README.md
-rw-rw-r-- 1 vagrant vagrant   397 Feb 21 18:00 _atoi.c
-rw-rw-r-- 1 vagrant vagrant  1041 Feb 21 18:00 _getline.c
-rw-rw-r-- 1 vagrant vagrant   835 Feb 21 18:00 _itoa.c
-rw-rw-r-- 1 vagrant vagrant   290 Feb 21 18:00 _strcat.c
-rw-rw-r-- 1 vagrant vagrant   356 Feb 21 18:00 _strcmp.c
-rw-rw-r-- 1 vagrant vagrant   391 Feb 21 18:00 _strcmpd.c
-rw-rw-r-- 1 vagrant vagrant   421 Feb 21 18:00 _strcmps.c
-rw-rw-r-- 1 vagrant vagrant   280 Feb 21 18:00 _strcpy.c
-rw-rw-r-- 1 vagrant vagrant   357 Feb 21 18:00 _strdup.c
-rw-rw-r-- 1 vagrant vagrant   267 Feb 21 18:00 _strlen.c
-rw-rw-r-- 1 vagrant vagrant  1205 Feb 21 18:00 _strtok.c
-rw-rw-r-- 1 vagrant vagrant   819 Feb 21 18:00 _write.c
-rw-rw-r-- 1 vagrant vagrant  3028 Feb 21 18:00 alias.c
-rw-rw-r-- 1 vagrant vagrant  2355 Feb 21 18:00 built_in.c
-rw-rw-r-- 1 vagrant vagrant   901 Feb 21 18:00 cd.c
-rw-rw-r-- 1 vagrant vagrant  2982 Feb 21 18:00 env_func.c
-rw-rw-r-- 1 vagrant vagrant   707 Feb 21 18:00 error.c
-rw-rw-r-- 1 vagrant vagrant   915 Feb 21 18:00 error.h
-rw-rw-r-- 1 vagrant vagrant   539 Feb 21 18:00 execute.c
-rw-rw-r-- 1 vagrant vagrant  2039 Feb 21 18:00 expansions.c
-rw-rw-r-- 1 vagrant vagrant   829 Feb 21 18:00 file_path.c
-rw-rw-r-- 1 vagrant vagrant  1067 Feb 21 18:00 help.c
-rw-rw-r-- 1 vagrant vagrant  2814 Feb 21 18:00 help.h
-rw-rw-r-- 1 vagrant vagrant  1697 Feb 21 18:00 history.c
-rwxrwxr-x 1 vagrant vagrant 41760 Feb 21 18:00 hsh
-rw-rw-r-- 1 vagrant vagrant   557 Feb 21 18:00 input.c
-rw-rw-r-- 1 vagrant vagrant  3240 Feb 21 18:00 linked_lists.c
-rw-rw-r-- 1 vagrant vagrant  2121 Feb 21 18:00 memory_func1.c
-rw-rw-r-- 1 vagrant vagrant   334 Feb 21 18:00 memory_func2.c
-rw-rw-r-- 1 vagrant vagrant   268 Feb 21 18:00 num_len.c
-rw-rw-r-- 1 vagrant vagrant  1143 Feb 21 18:00 parser.c
-rw-rw-r-- 1 vagrant vagrant   272 Feb 21 18:00 pow_b.c
-rw-rw-r-- 1 vagrant vagrant  1081 Feb 21 18:00 run.c
-rw-rw-r-- 1 vagrant vagrant  3723 Feb 21 18:00 shell.c
-rw-rw-r-- 1 vagrant vagrant  2575 Feb 21 18:00 shell.h
-rw-rw-r-- 1 vagrant vagrant    74 Feb 21 18:00 sometest
-rw-rw-r-- 1 vagrant vagrant  1267 Feb 21 18:00 str_func.c
-rw-rw-r-- 1 vagrant vagrant    10 Feb 21 18:38 test_ls_2
-rw-rw-r-- 1 vagrant vagrant   672 Feb 21 18:00 unalias.c
$ alias
lister='ls -l'
$ alias lister
./hsh: 4: alias: ls: not found
./hsh: 4: alias: -l: not found
$
```
## Future Tasks
1. Implement use of cursor
2. Implement use of symbols like `*`, `\` and ```
3. Display colours
4. Implement `tabs` for autocomplete
5. Implement more built-in functions
6. Improve `README.md` and `help` pages
7. Refactor code
## Authors
* Yasmine Ben Ali
* Selasi S. Kporvie
