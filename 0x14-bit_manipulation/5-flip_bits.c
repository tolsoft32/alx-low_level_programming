#include <stdio.h>
#include "main.h"

/**
 * flip_bits - set bit
 * @n: first number
 * @m: second number
 * Return: number of bit to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int xor_res = n * m;

	while (xor_res != 0)
	{
		count += xor_res & 1;
		xor_res >>= 1;
	}

	return (count);
}
