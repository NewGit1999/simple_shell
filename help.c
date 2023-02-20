#include "help.h"

/**
 * print_help - print help command
 * @arg: arguments
 * Return: none
 */

void print_help(char *arg)
{
	int fd = 1;

	_write(-1, NULL, 0);

	if (!arg)
		_write(1, ghelp, _strlen(ghelp));
	else if (!_strcmp(arg, "help"))
		_write(1, help_h, _strlen(help_h));
	else if (!_strcmp(arg, "set"))
		_write(1, set_h, _strlen(set_h));
	else if (!_strcmp(arg, "unset"))
		_write(1, unset_h, _strlen(unset_h));
	else if (!_strcmp(arg, "history"))
		_write(1, history_h, _strlen(history_h));
	else if (!_strcmp(arg, "env"))
		_write(1, env_h, _strlen(env_h));
	else if (!_strcmp(arg, "cd"))
		_write(1, cd_h, _strlen(cd_h));
	else if (!_strcmp(arg, "alias"))
		_write(1, alias_h, _strlen(alias_h));
	else if (!_strcmp(arg, "exit"))
		_write(1, exit_h, _strlen(exit_h));
	else if (!_strcmp(arg, "setenv"))
		_write(1, set_h, _strlen(set_h));
	else if (!_strcmp(arg, "unsetenv"))
		_write(1, unset_h, _strlen(unset_h));
	else
	{
		_write(2, "No help found for ", 18), fd = 2;
		_write(2, arg, _strlen(arg));
		_write(2, "\n", 1);
	}
	_write(fd, NULL, 0);
}
