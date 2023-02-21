#include "shell.h"

/**
 * free_buffer - free node
 * @ptr: nodeto free
 * Return: 1 if freed, 0 otherwise
 */
int free_buffer(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
