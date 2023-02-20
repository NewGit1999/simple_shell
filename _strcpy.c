#include "shell.h"

/**
 * *_strcpy - copy string
 * @dest: destination string
 * @src: source string
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	if (!dest)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}
