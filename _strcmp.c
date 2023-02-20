#include "shell.h"

/**
 * _strcmp - compare 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if true, 0 if false
 */

int _strcmp(char *s1, char *s2)
{
	if (!s1 && s2)
		return (-1);
	if (!s2 && s1)
		return (-1);

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++, s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);

}
