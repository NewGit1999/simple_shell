#include "shell.h"

/**
 * is_delim - check if char is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 *
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
