#include "shell.h"
#define l(x) _strlen((x))

/**
 * handle_exit - set exit code
 * @cmd: arguments
 * Return: exit code
*/

int handle_exit(char **cmd)
{
	int exitstatus = 0, i = 0, str_in = 0;
	char *msg, *smn;

	if (cmd[1])
	{
		while (cmd[1][i])
		{
			if (!('0' <= cmd[1][i] && '9' >= cmd[1][i]))
				str_in = 1;
			i++;
		}
		if (str_in)
		{
			errno = -1;
			msg = _malloc(_strlen("numeric argument required ") + _strlen(cmd[1]) + 4);
			_strcpy(msg, "numeric argument required ");
			smn = _malloc(_strlen("exit: ") + _strlen(cmd[1]) + 4);
			_strcpy(smn, "exit: "), _strcat(smn, cmd[1]);
			print_error(smn, NULL, msg);
			free(msg), free(smn);
			exitstatus = 2;
		}
		else if (_atoi(cmd[1]) < 0)
		{
			errno = -1;
			msg = _malloc(_strlen("numeric argument required ") + _strlen(cmd[1]) + 4);
			_strcpy(msg, "numeric argument required ");
			smn = _malloc(_strlen("exit: ") + _strlen(cmd[1]) + 4);
			_strcpy(smn, "exit: "), _strcat(smn, cmd[1]);
			print_error(smn, NULL, msg);
			free(msg), free(smn);
			exitstatus = 2;
		}
		else
			exitstatus = _atoi(cmd[1]) % 256;

	}
	return (exitstatus);
}

/**
 * handle_bin - handle built-in commands
 * @cmd: arguments
 * @head: first node
 *
 * Return: 0 if built-in command executed or 1 if not
 */

int *handle_bin(char **cmd, alias **head)
{
	int *ret = _malloc(2 * sizeof(int));

	ret[0] = 1, ret[1] = 266;
	if (!cmd)
		return (ret);
	if (!_strcmp(cmd[0], "exit"))
		ret[0] = 0, ret[1] = handle_exit(cmd);
	else if (!_strcmp(cmd[0], "env") || !_strcmp(cmd[0], "printenv"))
		_printenv(), ret[0] = 0;
	else if (!_strcmp(cmd[0], "\n"))
		ret[0] = 0;
	else if (!_strcmp(cmd[0], "setenv"))
	{
		if (_arlen(cmd) != 3)
			errno = -2, print_error(cmd[0], NULL, "Syntax error");
		else
			_setenv(cmd[1], cmd[2], 0);
		ret[0] = 0;
	}
	else if (!_strcmp(cmd[0], "unsetenv"))
	{
		if (_arlen(cmd) != 2)
			errno = -2, print_error(cmd[0], NULL, "Syntax error");
		else
			_unsetenv(cmd[1]);
		ret[0] = 0;
	}
	else if (!_strcmp(cmd[0], "cd"))
		_chdir(_arlen(cmd) > 1 ? cmd[1] : NULL), ret[0] = 0;
	else if (!_strcmp(cmd[0], "history"))
		print_history(), ret[0] = 0;
	else if (!_strcmp(cmd[0], "help"))
		print_help(_arlen(cmd) > 1 ? cmd[1] : NULL), ret[0] = 0;
	else if (!_strcmp(cmd[0], "alias"))
		handle_alias(cmd, head), ret[0] = 0;

	if (!ret[0] && ret[1] == 266)
		free_pp(cmd);
	return (ret);
}
