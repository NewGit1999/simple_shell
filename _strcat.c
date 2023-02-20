#include "shell.h"

/**
 * _strcat - concatinate 2 strings
 * @dest: string destination
 * @src: source string
 *
 * Return: concatinated string
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
		*p++ = *src++;

	*p = '\0';

	return (dest);
}
