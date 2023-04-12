#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: A pointer to a string of 0 and 1
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 * Otherwise - The converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0, multi = 1;
	int len;

	if (b == '\0')
		return (0);

	for (len = 0; b[len];)
		len++;

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		num += (b[len] - '0') * multi;
		multi *= 2;
	}

	return (num);
}
