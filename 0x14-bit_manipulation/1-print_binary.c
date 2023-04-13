#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary representative of a number
 *
 * @n: The number to to print in binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int count = 0;
	int i;

	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> 1;

		if (current & 1)
		{
			_putchar('1');
			count++;
			{
				_putchar('1');
				count++;
			}

			else if (count)
				_putchr('0');
		}

		if (!count)
			_putchar('0');
	
	}
}
