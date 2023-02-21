#include "shell.h"

/**
 * _strchr - find char in string
 * @s: string to be checked
 * @c: char to look for
 *
 * Return: the string
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
