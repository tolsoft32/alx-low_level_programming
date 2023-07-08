#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - convert binary to unsigned int
 * @b: pointer to string of 0 or 1 character
 *
 * Return: the converted number, 0 if one
 * or more character is in stringwhich is not 0 or 1
 * or if string is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int output = 0;
	unsigned int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		output = output << 1;
		if (b[i] == '1')
			output = output | 1;
	}
	return (output);
}
