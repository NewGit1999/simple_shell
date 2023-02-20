#ifndef HELP_H
#define HELP_H

#include "shell.h"

#define exit_h1 "\texit usage: exit status \n\t"
#define exit_h2 "Exits the shell with or without an integer status \n\t"
#define exit_h3 "Last command executed before shell terminates \n"
#define exit_h (exit_h1 exit_h2 exit_h3)

#define alias_h1 "\talias usage: alias [name[='value'] ...] \n\t"
#define alias_h2 "alias: Prints a list of all aliases, one per line, in the form name='value' \n\t"
#define alias_h3 "alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value' \n\t"
#define alias_h4 "alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value \n\t"
#define alias_h5 "or overwrites the KEY with new VALUE. \n"
#define alias_h (alias_h1 alias_h2 alias_h2 alias_h3 alias_h4 alias_h5)

#define unset_h1 "\tunsetenv usage: unsetenv VARIABLE \n\t"
#define unset_h2 "Remove an environment variable \n\t"
#define unset_h3 "Prints syntax error on sterr on failure\n"
#define unset_h (unset_h1 unset_h2 unset_h3)

#define set_h1 "\tsetenv usage: setenv VARIABLE VALUE \n\t"
#define set_h2 "Initialize a new environment variable, or modify an existing one \n\t"
#define set_h3 "Prints syntax error on stderr on failure \n"
#define set_h (set_h1 set_h2 set_h3)

#define history_h1 "\thistory usage: history \n\t"
#define history_h2 "Displays history of commands in shell \n"
#define history_h (history_h1 history_h2)

#define help_h1 "\thelp usage: help COMMAND \n\t"
#define help_h2 "Displays helpful info about builtins \n"
#define help_h (help_h1 help_h2)

#define env_h1 "\tenv usage: env \n\t"
#define env_h2 "Prints out the current envirornment variables. \n"
#define env_h (env_h1 env_h2)

#define cd_h1 "\tcd usage: cd [DIRECTORY]\n\t"
#define cd_h2 "If no argument is given to cd the command must be interpreted like cd $HOME \n\t"
#define cd_h3 "cd - changes directory to the precious directory \n\t"
#define cd_h4 "the environment variable PWD is updated when cd is used \n"
#define cd_h (cd_h1 cd_h2 cd_h3 cd_h4)

#define ghelp1 "\nSimple Shell \tVersion 1-ALX Software Engineering Team Project(Yasmine B. Ali & Selasi S. Kporvie) \n"
#define ghelp2 "These shell commands are defined in the custom shell. \n"
#define ghelp3 "Type `help' to see this list. \n"
#define ghelp4 "Type `help name' to find out more about the function `name'. \n"
#define ghelp5 "\nThe following commands are defined: \n"
#define ghelp6 "\n\talias [name[='value'] ...]\thelp \n"
#define ghelp7 "\tcd [DIRECTORY]            \thistory \n"
#define ghelp8 "\tenv			      \tsetenv [VARIABLE] [VALUE] \n"
#define ghelp9 "\texit [status]             \tunsetenv [VARIABLE] \n"
#define ghelp (ghelp1 ghelp2 ghelp3 ghelp4 ghelp5 ghelp6 ghelp7 ghelp8 ghelp9)

#endif
