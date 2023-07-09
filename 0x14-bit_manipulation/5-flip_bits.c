#include <stdio.h>
#include "main.h"

/**
 * flip_bits - flip to get the number need from one to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bit to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			count++;
		m = m >> 1;
		n = n >> 1;
	}

	return (count);
}
