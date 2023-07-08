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
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);


	*n |= 1UL << index;

	return (1);
}
