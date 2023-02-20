#include "shell.h"

/**
 * _strtok - tokenize string
 * @str: string to be tokenized
 * @delimeter: token delimiter
 * @whichf: which strcmp to use, 0 for strcmpd, and 1 for strcmps
 *
 * Return: a character pointer to the current delimited token
 */

char *_strtok(char *str, const char *delimeter, int whichf)
{
	static char *save;
	char *_new = NULL;
	int i = 0, (*func)(char *, const char *), loc;

	func = (whichf == 0) ? _strcmpd : _strcmps;
	loc = (whichf) ? _strlen(delimeter) - 1 : 0;
	if (!str || !*str)
	{
		if (!save || !*save)
			return (NULL);

		while (func(save + i, delimeter) != 1 && *(save + i) != '\0')
			i++;
		if (*(save + i) == '\0')
		{
			_new = save, save = NULL;
			return (_new);
		}
		_new = save;
		*(save + i) = '\0';
		save = save + i + loc + 1;

		return (_new);

	}
	while (func(str + i, delimeter) != 1 && *(str + i) != '\0')
		i++;

	if (*(str + i) == '\0')
	{
		save = NULL;
		return (str);
	}
	save = str + i + loc + 1;
	*(str + i) = '\0';
	return (str);
}
