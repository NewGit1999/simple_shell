#include "shell.h"

/**
 * free_pp - free pointer to pointer
 * @a: double pointer to be freed
 */

void free_pp(char **a)
{
	char **_a = a;

	if (!a)
		return;

	while (*_a)
	{
		free(*_a);
		_a++;
	}
	free(a);
}

/**
 * _arlen - find length of list
 * @a: first node
 * Return: lenght
 */

int _arlen(char **a)
{
	int i = 0;

	if (!a)
		return (i);

	while (*a)
		i++, a++;
	return (i);
}

/**
 * trim_spaces - trim string space
 * @str: pointer to the string to be edited
 * @strt: string to be trimed
 */

void trim_spaces(char **str, char *strt)
{
	char *new = _malloc(sizeof(char) * 1), *_str = strt, *tmp;
	int first = 1, count = 1, index = 0;

	*new = '\0';
	while (*_str)
	{
		if (*_str == ' ' && first)
			_str++;
		else if (*_str == ' ' && count)
			count++, _str++;
		else if (*_str != ' ')
		{
			tmp = _malloc(sizeof(char) * (_strlen(new) + 3));
			if (!tmp)
				exit(-1);
			_strcpy(tmp, new);
			if (count > 1)
				tmp[index] = ' ', index++;

			tmp[index] = *_str;
			tmp[index + 1] = '\0';
			free(new);
			first = 0, count = 1, new = tmp, index++, _str++;
		}
	}
	*str = new;
}

/**
 * _malloc - allocates memory and returns a pointer to it
 * @size: no. of bytes to be allocated
 * Return: a generic pointer allocated or -1 on faliure
 */

void *_malloc(unsigned int size)
{
	char *pointer = malloc(size);
	void *_pointer = NULL;
	unsigned int i = 0;

	if (!pointer)
	{
		print_error(NULL, NULL, "ERROR ALLOCATING MEMORY");
		exit(-1);
	}
	while (i < size)
	{
		pointer[i] = '\0';
		i += 1;
	}
	_pointer = (void *)pointer;
	return (_pointer);
}
/**
 * _realloc - rallocates a memory location and returns a pointer
 * @ptr: pointer to null terminated memory block
 * @size: new size
 *
 * Return: a generic pointer reallocated memory or -1 on faliure
 */

void *_realloc(void *ptr, unsigned int size)
{
	char *_pointer = (char *)_malloc(size), *_ptr = (char *)ptr;
	void *pointer = NULL;
	int i = 0;

	if (!_ptr)
	{
		pointer = _pointer;
		return (pointer);
	}
	while (_ptr[i])
	{
		_pointer[i] = _ptr[i];
		i += 1;
	}
	_pointer[i] = '\0';
	pointer = (void *)_pointer;
	free(ptr);
	return (pointer);
}
