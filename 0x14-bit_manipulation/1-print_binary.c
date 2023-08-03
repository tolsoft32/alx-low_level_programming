#include <stdio.h>
#include "main.h"

/**
 * print_binary - function that print binary representation of a number
 * @n: number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mark = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	int sign = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mark)
	{
		if (n & mark)
		{
			_putchar('1');
			sign = 1;
		}
		else if (sign)
		{
			_putchar('0');
		}

		mark = mark >> 1;
	}
}
