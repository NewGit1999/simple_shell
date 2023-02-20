#include "shell.h"

/**
 * itoa - print any number
 * @n : the number
 * Return: stringized number
 */

char *itoa(int n)
{
	int length, j, k, digit1, tmp2, i = 0;
	unsigned int num;
	char *nums = _malloc(num_len((n > 0) ? n : -1 * n) + 2);

	if (!nums)
		return (NULL);
	if (n < 0)
		n *= -1, *(nums + i) = '-', i++;
	num = n, length = num_len(num), j = length - 1;
	if (num == 0)
		nums[i] = 48, i++;
	else
	{
		while (j >= 0)
		{
			if (num % pow_b(10, j) == 0 && j != 0)
			{
				nums[i] = (48 + num / pow_b(10, j)), i++;
				for (k = j; k > 0; k--)
					nums[i] = 48, i++;
				j = -1;
			}
			else
			{
				digit1 = num / pow_b(10, j);
				nums[i] = digit1 + 48, i++;

				tmp2 = num;
				num -= pow_b(10, j) * digit1;
				if (num_len(tmp2) - num_len(num) == 2)
					nums[i] = 48, i++, j--;
				j--;
			}
		}
	}
	return (nums);
}
