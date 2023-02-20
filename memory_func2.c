#include "shell.h"

/**
 * _arrdup - safe array duplicate
 * @src: array to be duplicated
 * Return: pointer to pointer of new array
 */
char **_arrdup(char **src)
{
	char **tmp = _malloc(sizeof(char *) * (_arlen(src) + 2));
	char **_tmp = tmp;

	while (*src)
		*_tmp = _strdup(*src), _tmp++, src++;

	*_tmp = NULL;
	return (tmp);

}
