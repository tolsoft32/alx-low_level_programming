#include <stdio.h>
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

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		b_ten = b_ten << 1;
		if (b[i] == '1')
			b_ten = b_ten | 1;
	}
	return (b_ten);
}
