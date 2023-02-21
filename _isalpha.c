#include "shell.h"

/**
 *_isalpha - check for alphabetic char
 *@c: char to check
 *Return: 1 if alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
