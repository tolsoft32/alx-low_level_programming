#include "main.h"
#include <stdio.h>

/**
 * get_endianness - function that check the endianness
 *
 * Return: 0is system is big endian,
 * 1 if system is little endian
 */
int get_endianness(void)
{
	unsigned int ptr = 1;
	char *c = (char *)&ptr;

	if (c)
		return (1);
	else
		return (0);
}
