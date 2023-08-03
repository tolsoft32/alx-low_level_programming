#include "main.h"

/**
 * binary_to_uint - function that convert binary to unsigned integer
 * @b: pointer to the string 0 and 1
 *
 * Return: the converted number or 0
 * if char is not between 0 and 1 or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int b_ten;

	if (!b)
	{
		return (0);
	}
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
		{
			return (0);
		}
		b_ten = 2 * b_ten + (b[i] - '0');
	}
	return (b_ten);
}
