#include <stdio.h>
#include "main.h"

/**
 * get_endianness - return endianess of machine
 *
 * Return: 0 for big endian , 1 for little endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *endian_ptr = (char *)&x;

	if (*endian_ptr)
		return (1);
	else
		return (0);
}
