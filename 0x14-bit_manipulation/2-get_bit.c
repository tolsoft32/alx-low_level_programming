#include <stdio.h>
#include "main.h"
/**
 * get_bit - Set the value of a bit to 1 at a given index
 * @n: number of times pointer is set to the bit
 * @index: bit to get starting from 0
 * Return: 1 if operation is successful, -1 otherwise
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	if ((n & mask) != 0)
		return (1);
	else
		return (0);
}
