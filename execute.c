#include "shell.h"

/**
 * execute - execute a process with a child
 * @tmp: pointer to pointer of child process
 * Return: 0 on sucess and 127 on failure
 */

int execute(char **tmp)
{
	struct stat cmdinfo;
	char *fpath = NULL;
	int exitstat = 0;

	if (!tmp)
		return (exitstat);
	fpath = get_file_path(tmp[0]);
	if (stat(fpath, &cmdinfo) == 0 && cmdinfo.st_mode & S_IXUSR)
		exitstat = execve(fpath, tmp, environ);
	else
	{
		exitstat = 127;
		errno = -4;
		print_error(tmp[0], NULL, "not found");
	}
	free(fpath);
	return (exitstat);
}
