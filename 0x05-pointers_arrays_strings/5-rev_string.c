#include "main.h"

/**
 * rev_string - Reverse a string
 * @s: String to be modified
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, c, j;
	char *a, aux;

	a = s;

	while (s[c] != '\0')
	{
		c++;
	}
	for (j = 1; j < c; j++)
	{
		a++;
	}

	for (i = 0; i < (c / 2); i++)
	{
		aux = s[i];
		s[i] = *a;
		*a = aux;
		a--;
	}
}
