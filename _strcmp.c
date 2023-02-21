#include "shell.h"

/**
 * _strcmp - compare 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: - if s1 < s2, + if s1 > s2, 0 equal
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
