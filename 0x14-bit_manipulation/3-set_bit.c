#include <stdio.h>
#include "main.h"

/**
 * set_bit - set a bit value to 1 at a given index
 *
 * @n: pointer to the number to set the bit in
 * @index: The index of the bit to set starting from 0
 * Return: 1 if it worked and -1 if error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1 << index);

	return (1);
}