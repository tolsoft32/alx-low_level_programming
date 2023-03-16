#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * string_nconcat - declaring cocatenation of two strings
 * @s1: string one
 * @s2: string two for cocatenation
 * @n: numbers or length of times strings access memory
 * Return: if the function fail, otherwise a pointer to return
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;

	usigned int length = n, index;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (index = 0; s1[index]; index++)
		length++;

	concat = malloc(sizeof(char) * (length + 1));

	if (concat == NULL)
		return (NULL);

	length = 0;

	for (index = 0; s1[index]; index++)
		concat[length++] = s1[index];

	for (index = 0; s2[index] && index < n; index++)
		concat[length++] = s2[index];

	concat[length] = '\0';

	return (concat);
}
