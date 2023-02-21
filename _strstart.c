#include "shell.h"

/**
 * starts_with - check if string starts with char
 * @str1: the string to check
 * @str2: the string to look for
 *
 * Return: next char of string or NULL if not found
 */

char *starts_with(const char *str1, const char *str2)
{
	while (*str2)
		if (*str2++ != *str1++)
			return (NULL);
	return ((char *)str1);
}
