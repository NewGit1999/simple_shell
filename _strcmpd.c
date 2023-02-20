#include "shell.h"

/**
 * _strcmpd - custom strcmp
 * @fstring: fstring
 * @sub: subset
 *
 * Return: 1 on success and -1 on faliur
 */

int _strcmpd(char *fstring, const char *sub)
{
	if (!fstring || !sub)
		return (-1);
	if (!*fstring)
		return (-1);
	if (_strlen(fstring) < _strlen(sub))
		return (-1);
	while (*sub)
	{
		if (*sub == *fstring)
			return (1);
		sub++;
	}
	return (-1);
}
