#include "shell.h"

/**
 * _strcmps - alternate custom strcmp
 * @fstring: fstring
 * @sub: subset
 * Return: 1 on success and -1 on faliur
 */

int _strcmps(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub && *fstring)
	{
		if (*sub != *fstring)
			return (-1);
		sub++, fstring++;
	}
	return (1);
}
