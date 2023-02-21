#include "shell.h"

/**
 * _strcat - concatenate 2 strings
 * @dest: string destination
 * @src: source string
 *
 * Return: destination
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
