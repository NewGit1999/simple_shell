#include "shell.h"

/**
 * interactive_mode - check if shell is in interactive mode
 * @info: atrguments
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
