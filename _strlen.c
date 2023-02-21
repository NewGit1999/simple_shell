#include "shell.h"

/**
 * _strlen - find string length
 * @s: the string
 * Return: string length
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}
