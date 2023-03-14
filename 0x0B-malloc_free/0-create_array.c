#include "main.h"
#include <stdlib.h>

/**
 * create_array - create arrays of chars initialized with unsigned int.
 * char - character of an array
 * @size: for count of array
 * @c: the character
 * Return: size of array initialize or NULL
 */
char *create_array(unsigned int size, char c)
{
	char ar;
	unsigned int i;

	i = 0;
	if (size != 0)
		ar = malloc(size * sizeof(c));
	else
		return (NULL);
	if (ar == NULL)
		return (NULL);
	while (i < size)
	{
		ar[i] = c;
		i++;
	}
	return (ar);
}
