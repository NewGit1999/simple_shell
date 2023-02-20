#include "shell.h"

/**
 * _getline - get line of string from file
 * @lnptr: variable to store string
 * @size: number of strings stored
 * @fd: file to read from
 *
 * Return: the lenghh of lnptr or -1 on failure
 */

int _getline(char **lnptr, size_t *size, int fd)
{
	char buffer[BUFFER_t + 1];
	int r = BUFFER_t, len = 0, mode = isatty(0);
	char *tmp;

	*lnptr = (char *)_malloc(4);
	**lnptr = '\0';
	while (r == BUFFER_t)
	{
		if (*lnptr && len > 0)
			if ((*lnptr)[len - 1] == '\n' && mode)
				break;
		r = read(fd, buffer, BUFFER_t);
		if (r < 0 && errno == EINTR)
		{
			**lnptr = '\n',	*(*lnptr + 1) = '\n', len = 2;
			return (len);
		}
		if (r < 0)
			exit(-1);
		if (r == 0 && mode)
			return (-1);
		tmp = _realloc(*lnptr, len + r + 4);
		*size = len + r + 4, *lnptr = tmp;
		buffer[r] = '\0', _strcat(*lnptr, buffer), len += r;
		if (!mode)
			find_n_rep(lnptr, "\n", ";");
	}
	if (!mode)
	{
		tmp = _realloc(*lnptr, _strlen(*lnptr) + 3);
		*lnptr = tmp;
		(*lnptr)[len] = '\n', (*lnptr)[len + 1] = '\0';
	}
	return (len);
}
