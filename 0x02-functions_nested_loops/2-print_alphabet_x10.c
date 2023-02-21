#include "main.h"
/**
 * print_alphabet_x10 - function that print alphabet in lowercase
 * Return -always 0;
 */
void print_alphabet_x10(void)
{
	char c;
	int i = 0;

	for (i = 'a'; i <= 'z'; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
	}

}
