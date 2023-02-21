#include "shell.h"

/**
 * dup_chars - duplicate chars
 * @pathstr: string containing path to file
 * @start: string starting index
 * @stop: string ending index
 *
 * Return: new string
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}
