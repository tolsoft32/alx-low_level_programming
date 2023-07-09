#include <stdio.h>
#include "main.h"

/**
 * get_bit - Sets the value of a bitto 1 at a given index
 * @n: number of times pointer is set to the bit
 * @index: bit to get starting from 0.
 *
 * Return: 1 if operation is successful, -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int a;

	if (index > 63)
		return (-1);

	x = 1 << index;
	*n = (*n | a);

	return (-1);
}
