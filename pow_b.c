#include "shell.h"

/**
 * pow_b - exponent of a number to its base
 * @base : base
 * @power : exponent (power)
 *
 * Return: int
 */

int pow_b(unsigned int base, int power)
{
	int i, prod = 1;

	for (i = 0; i < power; i++)
	{
		prod = prod * base;
	}
	return (prod);
}
