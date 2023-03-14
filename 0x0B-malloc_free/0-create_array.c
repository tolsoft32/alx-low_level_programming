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

	if (size == 0)
		return (NULL);

	ar = (char *)malloc(size * sizeof(char));

	if (ar == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ar[i] = c;

	return (ar);
}
