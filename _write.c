#include "shell.h"

/**
 * _write - write to field descriptor
 * @fd: field descriptor
 * @inp: string to write
 * @len: number of chars in string
 *
 * Return: -100 when no queue, 100 when sucessfully write to
 */

int _write(int fd, char *inp, int len)
{

	static char writeque[BUFFER_t];
	static int nque;
	int i;

	if (fd < 0)
	{
		nque = 0;
		return (-100);
	}
	if (inp)
	{
		if ((len + nque) >= BUFFER_t)
		{
			if (write(fd, writeque, BUFFER_t) == -1)
			{
				print_error(NULL, NULL, "problem writing");
				exit(-1);
			}
			nque = 0;
		}
		i = 0;
		while (i < len)
		{
			writeque[nque + i] = inp[i];
			i++;
		}
		writeque[nque + i] = '\0';
		nque += len;
		return (100);
	}
	if (!inp)
		if (write(fd, writeque, nque) == -1)
		{
			print_error(NULL, NULL, "problem writing");
			exit(-1);
		}
	return (0);
}
