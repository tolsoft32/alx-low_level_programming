#include <stdio.h>
#include "main.h"

/**
 * set_bit - set the value of a bit to 1 at a given index
 * @n: pointer to the number set to the bit
 * @index: the index to set to bit from 0
 * Return: 1 if operation successful, -1 if error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int pk;

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	pk = 1 << index;
	*n  = (*n | pk);
	return (1);
}
