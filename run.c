#include "shell.h"

/**
 * runscript - run a file if executable
 * @name: filename
 * Return: 0 on sucess and -1 on faliure
 */

int runscript(char *name)
{
	char *path = NULL, *currentdir = NULL;
	int fd, i, cmdlen;
	size_t len = 0;
	char *input, **cmds, *errmsg, **cmds2;
	alias *head = NULL;

	if (name[0] != '.' && name[0] != '~' && name[0] != '/')
	{
		currentdir = _getenv("PWD");
		path = _malloc(_strlen(currentdir) + _strlen(name) + 4);
		_strcpy(path, currentdir);
		_strcat(path, "/"), _strcat(path, name);
	}
	else
		path = name;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		errno = -3;
		errmsg = _malloc(_strlen("No such file or directory ") + _strlen(name) + 4);
		_strcpy(errmsg, "No such file or directory ");
		print_error(name, NULL, errmsg);
		free(errmsg), free(path);
		return (127);
	}
	free(path);

	get_input(&input, &len, &cmds, fd), find_n_rep(&(cmds[0]), "\n", ";");
	parse_args(cmds[0], ";", &cmds2, 0), free(input), free_pp(cmds);

	i = 0, cmdlen = _arlen(cmds2);
	while (i < cmdlen)
		exec_cmd(cmds2, i, &head), i++;
	free_pp(cmds2);
	return (0);
}
