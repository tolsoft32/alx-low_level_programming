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
	unsigned long int xor_res = n ^ m;
	unsigned int count = 0;

	while (xor_res != 0)
	{
		count += xor_res & 1;
		xor_res >>= 1;
	}

	return (count);
}
