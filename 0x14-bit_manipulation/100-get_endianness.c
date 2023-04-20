#include "main.h"
#include <stdio.h>

/**
 * get_endianness - check the endianesse
 * Return: 0 if if bif endianess, 1 if little endianess
 */
int get_endianness(void)
{
	int i;
	char *test;

	i = 1;
	test = (char *)&i;
	return ((int)test[0]);
}
