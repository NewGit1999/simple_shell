#include "shell.h"

/**
 * _memset - fill memory with constant no. of bytes
 * @s: address to fill
 * @b: memory to be filled with
 * @n: no. of bytes to fill
 *
 * Return: filled memory
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees memory filled
 * @pp: string freed
 * Return: none
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocate memory block
 * @ptr: allocated memory block
 * @old_size: no. of bytes of allocated memory
 * @new_size: no. of bytes to reallocate
 *
 * Return: reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
