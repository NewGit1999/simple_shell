#include "shell.h"

/**
 * _strcpy - copy string
 * @dest: string destination
 * @src: source source
 *
 * Return: destonation string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
