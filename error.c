#include "shell.h"
#include "error.h"

/**
 * print_error - print error message
 * @prog: command
 * @cmdr: pointer to error
 * @msg: error message
 *
 * Return: none
 */

void print_error(char *prog, int *cmdr, char *msg)
{
	char *numcmd;
	static int *cmdsrun;
	static char *progname;

	if (!msg)
	{
		cmdsrun =  cmdr;
		progname = prog;
		return;
	}
	if (!cmdr || !prog)
	{
		_write(-1, NULL, 0);
		_write(2, progname, _strlen(progname) + 1);
		_write(2, ": ", 2);
		numcmd = itoa(*cmdsrun);
		_write(2, numcmd, _strlen(numcmd));
		free(numcmd);
		_write(2, ": ", 2);
		_write(2, prog, _strlen(prog));
		_write(2, ": ", 2);
		_write(2, msg, _strlen(msg));
		_write(2, "\n", 1);
		_write(2, NULL, 0);
	}
}
