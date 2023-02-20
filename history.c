#include "shell.h"

/**
 * write_history - write history of commands
 * @history: command to be stored in the history list
 * Return: 0 on success and 1 in faliure
 */

int write_history(char *history)
{
	char *filename, *h = _getenv("HOME");
	char *tmp = NULL;
	ssize_t w, fd;
	int len = _strlen(history);

	filename = _malloc(_strlen(h) + _strlen(".shell.history") + 4);
	_strcpy(filename, h), _strcat(filename, "/.shell.history");
	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0640);
	free(filename);
	if (fd < 0)
		return (1);
	if (len)
	{
		tmp = _malloc(len + 4);
		_strcpy(tmp, history), _strcat(tmp, "\n");
		w = write(fd, tmp, len + 1);
		if (w < 0)
		{
			close(fd);
			free(tmp);
			return (1);
		}
		free(tmp);
	}
	close(fd);
	return (0);
}


/**
 * print_history - print history
 * Return: 0 on success and 1 in faliure
 */

int print_history(void)
{
	char *filename, *h = _getenv("HOME");
	char *history = _malloc(4);
	int fd, w = 1;
	int counter = 0;
	char *istr =  NULL;


	filename = _malloc(_strlen(h) + _strlen(".shell.history") + 4);
	_strcpy(filename, h);
	_strcat(filename, "/.shell.history");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	while (w > 0)
	{
		counter++;
		w = read(fd, history, 1);
		if (w > 0)
		{
			_write(-1, NULL, 0), _write(1, "   ", 3);
			istr = itoa(counter);
			_write(1, istr, _strlen(istr)),	_write(1, "  ", 2);
			_write(1, NULL, 0), free(istr);
		}
		_write(-1, NULL, 0);
		while (w > 0 && *history != '\n')
		{
			_write(1, history, _strlen(history));
			w = read(fd, history, 1);
		}
		if (w > 0 && *history == '\n')
			_write(1, "\n", 1);
		_write(1, NULL, 0);
	}
	free(filename);
	free(history);
	close(fd);
	return (1);
}
