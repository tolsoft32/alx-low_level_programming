#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 *
 * @n: Set the pointer to clear the bit.
 * @index: the index to clear starting 0
 * Return: 1 if it worked , or -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n >= sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1 << index);
	return (1);
}
