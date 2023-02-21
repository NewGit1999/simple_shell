#include "shell.h"

/**
 * is_exec - check if file is executable
 * @info: arguments
 * @path: path to file
 *
 * Return: 1 if true, 0 otherwise
 */

int is_exec(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
