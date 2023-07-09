#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets the value  of bit to 0 at a given index
 * @n: pointer to which to clear bit
 * @index: the index of bit to clear
 *
 * Return: 1if operation successful, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
