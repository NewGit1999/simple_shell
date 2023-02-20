#include "shell.h"

/**
 * get_input - gets input from the command line
 * @input: pointer to input string
 * @inputlen: pointer to input len
 * @cmds: pointer to array of arguments
 * @fd: file discriptor
 *
 * Return: lenght of input
 */

int get_input(char **input, size_t *inputlen, char ***cmds, int fd)
{
	int len;

	if (isatty(0) && !fd)
		write(1, "$ ", 2);
	len = _getline(input, inputlen, fd);
	if (len == -1)
	{
		free(*input);
		write(1, "\n", 1);
		exit(0);
	}
	(*input)[len - 1] = '\0';
	parse_args(*input, ";", cmds, 0);
	return (len - 1);
}
