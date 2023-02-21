#include <stdio.h>
/**
 * main - Entry point
 * return -void if program works
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}

	_putchar("\n");
}
